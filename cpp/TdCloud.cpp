#include "TdCloud.h"
void td_cloud::TdCloud::Start(const std::string& path) {
    client_.Auth();
    td_api::int53 my_id = 0;
    client_.LoadChats();
    client_.GetMyID(my_id);
    client_.Update();
    std::cout << "Start with " << my_id << std::endl;
    sync_.SetPath(path);
    bool need_to_exit = false;
    while (client_.are_authorized_ && !need_to_exit) {
        sync_.Sync();
        for (const std::string &file : sync_.need_to_send_) {
            client_.SendFile(my_id, file);
        }
        client_.Update();
        sync_.Clear();
    }
    client_.LogOut();
    client_.Update();
}