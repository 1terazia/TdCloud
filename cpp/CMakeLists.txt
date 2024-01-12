cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(TdCloud VERSION 1.0 LANGUAGES CXX)

find_package(Td 1.8.23 REQUIRED)
find_package(Boost 1.40 COMPONENTS filesystem REQUIRED)
include_directories( ${Boost_INCLUDE_DIR} )
add_executable(td_cloud main.cpp TdCloud.cpp)
target_link_libraries(td_cloud PRIVATE Td::TdStatic)
target_link_libraries(td_cloud LINK_PUBLIC ${Boost_LIBRARIES})
set_property(TARGET td_cloud PROPERTY CXX_STANDARD 14)