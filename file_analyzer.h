#ifndef FILE_ANALYZER_H
#define FILE_ANALYZER_H

#include <string> // has to stay
#include <vector> // has to stay
#include <map> // has to stay
// #include <fstream> // does not need to stay

class FileAnalyzer{
    private:
        std::vector<std::string> all_files;
        std::map<std::string, int> files_containing;

    public:
        bool IsAFile(std::string control_if_file);

        void FindWord(std::string path);

        void AddAllTxtFiles(std::string path);

        void AddRelevantTxtFiles(std::string path, std::string to_find);

        void PrintResults();

        void ClearData();
};

#endif