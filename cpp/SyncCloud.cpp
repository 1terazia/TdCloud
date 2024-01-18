#include "SyncCloud.h"
#include "ScanDir.h"
void td_cloud::SyncCloud::Sync() {
    std::cout << "Sync..." << std::endl;
    std::vector<std::string> files;
    scan_dir(path_, files);
    for (const std::string& file : files) {
        if (archive_.count(file) || need_to_send_.count(file))
            continue;
        need_to_send_.insert(file);
    }
}
void td_cloud::SyncCloud::SetPath(const std::string &path) {
    path_ = path;
}
void td_cloud::SyncCloud::Clear() {
    for (const std::string &file : need_to_send_) {
        archive_.insert(file);
    }
    need_to_send_.clear();
}
