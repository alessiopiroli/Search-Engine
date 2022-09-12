#include <iostream> 
#include <string> 
#include <filesystem> 
#include <vector> 
#include <algorithm>

#include "file_analyzer.h"
#include "navigator.h"


Navigator::Navigator(){
    std::string choice;
    ShowCommands();

    while (choice != "exit"){
        std::cout << "command -> ";
        std::getline(std::cin, choice);

        if (choice == "cd"){
            this->GoUpDir();
        } else  if (choice == "cd -"){
            this->path = GoBackDir(this->path);
        } else if (choice == "ls"){
            this->CleanScreen();
            this->ShowCurrentDir();
        } else if (choice == "find"){
            this->my_analyzer.FindWord(this->path);
        } else if (choice == "clear"){
            this->CleanScreen();
        } else if (choice == "exit"){
            continue;
        } else {
            std::cerr << "Command not recognized" << std::endl;
        }
    }
}


void Navigator::ShowCommands(){
    std::cout << "Type 'cd' to go up a directory" << std::endl;
    std::cout << "Type 'cd -' to go back a directory" << std::endl;
    std::cout << "Type 'ls' to display directories" << std::endl;
    std::cout << "Type 'find' to search a word" << std::endl;
    std::cout << "Type 'clear' to clear the screen" << std::endl;
    std::cout << "Type 'exit' to terminate the program" << std::endl;
}


void Navigator::ShowCurrentDir(){
    if (this->path.empty()){
        for (const auto& file: std::__fs::filesystem::directory_iterator("/")){
            std::cout << file.path() << std::endl;
        }
    } else {
        for (const auto& file: std::__fs::filesystem::directory_iterator(this->path)){
            std::cout << file.path() << std::endl;
        }
    }
}


bool Navigator::CheckDirExistence(std::string to_analyze){
    std::vector<std::string> current_directories;
    
    if (this->path.empty()){
        for (const auto& file: std::__fs::filesystem::directory_iterator("/")){
            current_directories.push_back(file.path().string());
        }
    } else {
        for (const auto& file: std::__fs::filesystem::directory_iterator(this->path)){
            current_directories.push_back(file.path().string());
        }
    }

    if (std::find(current_directories.begin(), current_directories.end(), to_analyze) != current_directories.end()){
        return true;
    } else {
        return false;
    }
}


void Navigator::GoUpDir(){
    std::string path_to_add;
    std::cout << "Dir -> ";
    std::getline(std::cin, path_to_add);
    if (CheckDirExistence(this->path + path_to_add)){
        this->path += path_to_add;
    } else {
        std::cerr << "Can not enter such directory" << std::endl;
    }
}


std::string Navigator::GoBackDir(std::string path_to_reduce) {
    if (path_to_reduce == "/" || path_to_reduce.empty()){
        std::cerr << "Can not go back from main directory" << std::endl;
        return path_to_reduce;
    } else {
        int path_to_reduce_size = path_to_reduce.size();

        // this is only used as a fallback
        std::string path_to_reduce_copy = path_to_reduce;
        
        char* path_to_reduce_char = new char[path_to_reduce_size];
        strcpy(path_to_reduce_char, path_to_reduce.c_str());

        int counter = 0;

        for (int i = path_to_reduce_size; i>= 0; i--){
            if (path_to_reduce_char[i] == '/'){
                break;
            }
            counter++;
        }

        if (path_to_reduce_size - counter == 0){
            return "/";
        }

        return path_to_reduce_copy.erase(path_to_reduce_size - counter, counter);
    }
}


void Navigator::CleanScreen() {
    system("clear");
}
