#include "TdCloud.h"
int main(int argc, char* argv[]) {
    // google::InitGoogleLogging(argv[0]);
    std::string number;
    std::string password;
    std::cout << "Enter phone number: " << std::flush;
    std::cin >> number;
    std::cout << "Enter authentication password: " << std::flush;
    std::cin >> password;
    TdCloud cloud(number, password);
    cloud.loop();
}
