#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#include "file_analyzer.h"


bool FileAnalyzer::IsAFile(std::string control_if_file){
    if (control_if_file.find(".txt") != std::string::npos){
        return true;
    } else {
        return false;
    }
}


void FileAnalyzer::FindWord(std::string path) {
    std::string to_search;
    std::cout << "Write the word you want to find" << std::endl;
    std::getline(std::cin, to_search);

    std::string temporary_path;
    if (path.empty()){
        temporary_path = "/";
    } else {
        temporary_path = path;
    }

    this->AddAllTxtFiles(temporary_path);
    this->AddRelevantTxtFiles(temporary_path, to_search);
    this->PrintResults();
}


void FileAnalyzer::AddAllTxtFiles(std::string path) {
    for (const auto& file: std::__fs::filesystem::recursive_directory_iterator(path)){
        if (IsAFile(file.path().string())){
            this->all_files.push_back(file.path().string());
        }
    }
}


void FileAnalyzer::AddRelevantTxtFiles(std::string path, std::string to_find){
    if (this->all_files.empty()){
        std::cerr << "No file was found in the directory given" << std::endl;
    } else {
        for (int i = 0; i < this->all_files.size(); i++){
        std::ifstream is(all_files[i]);

        if (!is.good()){
            continue;
        } else {
            std::string saved_word;
            while (is >> saved_word){
                if (saved_word.find(to_find) != std::string::npos){
                    this->files_containing[all_files[i]]++;
                } else {
                    continue;
                }
            }
        }
    }
    }
}


void FileAnalyzer::PrintResults() {
    if (this->files_containing.empty()){
        std::cerr << "No file contained" << std::endl;
    } else {
        for (const auto& iter: this->files_containing){
        std::cout << "File: " << iter.first << ", times: " << iter.second << std::endl;
        }
    }
    this->ClearData();
}

void FileAnalyzer::ClearData() {
    this->all_files.clear();
    this->files_containing.clear();
}
