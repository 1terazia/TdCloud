#pragma once
#include "SyncCloud.h"
#include "TdCloudClient.h"
namespace td_cloud {
class TdCloud {
public:
    TdCloud(const std::string& phone_number, const std::string& password)
        : client_(phone_number, password) {}
    TdCloud(const TdCloudClient& client, const SyncCloud& sync) = delete;
    void Start(const std::string& path);

private:
    TdCloudClient client_;
    SyncCloud sync_;
};
}  // namespace td_cloud
