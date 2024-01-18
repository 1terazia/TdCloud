#pragma once
#include <boost/filesystem/operations.hpp>
#include <iostream>
using DirIterator = boost::filesystem::directory_iterator;
using FileStatus = boost::filesystem::file_status;
void scan_dir(const std::string& path, std::vector<std::string>& files);
