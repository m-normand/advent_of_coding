#include <fstream>
#include <iostream>
#include <string>
#include <map>

const std::string kINPUT_FILE = "test_input2.txt";

const std::map<std::string, char> kALPHA_NUMS{
    {"one",'1'},
    {"two",'2'},
    {"three",'3'},
    {"four",'4'},
    {"five",'5'},
    {"six",'6'},
    {"seven",'7'},
    {"eight",'8'},
    {"nine",'9'}};


/** @brief Reads a line of text and returns a 2 digit integer
 *
 * Integer composes of the first and last numerical chars in line
 *
 * @param line read line from the puzzle
 * @returns 2 digit integer
*/
int encode_line_old(const std::string &line)
{
    std::string::const_iterator front_iter = line.cbegin();
    std::string::const_iterator back_iter = line.cend();

    // Loop through line from front and back.
    // Move iterators until an digit is found or
    // iterators equate each other.
    /* NOTE: Prompt assumes that there is at least ONE number */
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
    // Converts two chars into a two digit number
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
        puzzle_sum += encode_line_old(puzzle_line);
    }
    std::cout << "Cablibration value -> " << puzzle_sum << std::endl;
    return 1;
}