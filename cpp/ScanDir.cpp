#include "ScanDir.h"
void scan_dir(const std::string& path, std::vector<std::string>& files) {
    std::cout << "Scanning(" << path << ")..." << std::endl;
    DirIterator dir_begin(path);
    DirIterator dir_end;
    for (; dir_begin != dir_end; ++dir_begin) {
        FileStatus file_status = boost::filesystem::status(*dir_begin);
        // LOG(INFO) << "PROCCESSING " << *dir_begin << std::endl;
        switch (file_status.type()) {
            case boost::filesystem::regular_file:
                // LOG(INFO) << "FILE";
                break;
            case boost::filesystem::symlink_file:
                // LOG(INFO) << "SYMLINK";
                break;
            case boost::filesystem::directory_file:
                scan_dir(dir_begin->path().string(), files);
                // LOG(INFO) << "DIRECTORY";
                break;
            default:
                // LOG(INFO) << "OTHER";
                break;
        }
        if (file_status.permissions() & boost::filesystem::owner_read) {
            if (file_status.type() == boost::filesystem::regular_file) {
                files.emplace_back(dir_begin->path().string());
            }
            // LOG(INFO) << "READABLE";
        } else {
            // LOG(INFO) << "SKIP(due to unable to read): " << *dir_begin;
        }
    }
}