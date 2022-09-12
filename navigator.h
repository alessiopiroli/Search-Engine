#ifndef NAVIGATOR_H
#define NAVIGATOR_H

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <algorithm>

#include "file_analyzer.h"

class Navigator{
    private:
        std::string path;
        FileAnalyzer my_analyzer;
    
    public:

        Navigator();

        void ShowCommands();

        void ShowCurrentDir();

        bool CheckDirExistence(std::string to_analyze);

        void GoUpDir();

        std::string GoBackDir(std::string path_to_reduce);

        void CleanScreen();
};

#endif