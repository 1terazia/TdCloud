#pragma once
#include <unordered_set>
#include <string>
namespace td_cloud {
class SyncCloud {
public:
    SyncCloud() = default;
    SyncCloud(const std::string path,
              const std::unordered_set<std::string>& archive)
        : archive_(archive), path_(path){};
    SyncCloud(const SyncCloud&) = default;
    void Sync();
    void SetPath(const std::string &path);
    void Clear();
    friend class TdCloud;
private:
    std::unordered_set<std::string> need_to_send_;
    std::unordered_set<std::string> archive_;
    std::string path_;
};
}  // namespace td_cloud
