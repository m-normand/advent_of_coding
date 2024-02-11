#include <fstream>
#include <iostream>
#include <string>
#include <vector>

const std::string kINPUT_FILE = "input.txt"; 

int encode_line(const std::string &line)
{
    std::string::const_iterator front_iter = line.cbegin();
    std::string::const_iterator back_iter = line.cend();

    while(
        !(std::isdigit(*front_iter) && std::isdigit(*back_iter))
        && front_iter != back_iter)
    {
        if(!std::isdigit(*front_iter))
        {
            front_iter++;
        }

        if(!std::isdigit(*back_iter))
        {
            back_iter--;
        }
    }
    return std::stoi(std::string({*front_iter, *back_iter}));
}

int main(int argc, char **argv) 
{
    std::ifstream input_file(kINPUT_FILE);
    if(!input_file.is_open()) {
        std::cout << "ERROR: Input file (" << kINPUT_FILE
            << ") not found." << std::endl;
        return 0;
    }

    std::string puzzle_line;
    int puzzle_sum = 0;
    while(std::getline(input_file, puzzle_line))
    {
        puzzle_sum += encode_line(puzzle_line);
    }
    std::cout << "Cablibration value -> " << puzzle_sum << std::endl;
    return 1;
}