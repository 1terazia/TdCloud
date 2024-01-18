#include "TdCloud.h"
void td_cloud::TdCloud::Start(const std::string& path) {
    client_.Auth();
    td_api::int53 my_id = 0;
    client_.LoadChats();
    client_.GetMyID(my_id);
    client_.Update();
    std::cout << "Start with " << my_id << std::endl;
    sync_.SetPath(path);
    while (true) {
        sync_.Sync();
        client_.SendDir(my_id, path);
        client_.Update();
        sync_.Clear();
        break;
    }
    client_.LogOut();
    client_.Update();
}