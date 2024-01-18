#include "TdCloud.h"

int main(int argc, char* argv[]) {
    std::string number;
    std::string password;
    std::cout << "Enter phone number: " << std::flush;
    std::cin >> number;
    std::cout << "Enter authentication password: " << std::flush;
    std::cin >> password;
    td_cloud::TdCloud cloud(number, password);
    cloud.Start("./test");
}
