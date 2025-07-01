# Search Engine
A simple command-line "search engine" for navigating directories and finding occurrences of a word in '.txt' files.

## Features
- `cd` : enter a subdirectory
- `cd -` : go back to the previous directory  
- `ls` : list files and folders in the current directory
- `clear` : clear the console screen  
- `exit` : terminate the application

## Prerequisites
- A C++17 compliant compiler
- Standard library support for `<filesystem>`

## Getting started
**Cloning the repository**
```bash
git clone https://github.com/your-username/Search-Engine.git
cd Search-Engine
```
## Creating the executable
```C++
g++ -std=c++17 main.cpp navigator.cpp file_analyzer.cpp -o search-engine
```
## Running the executable
```C++
./search-engine
```

## Usage
- 'cd' to go up a directory
- 'cd -' to go back a directory
- 'ls' to display directories
- 'find' to search a word
- 'clear' to clear the screen
- 'exit' to terminate the program
