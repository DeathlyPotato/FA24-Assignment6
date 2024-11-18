#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>

// Global variable used to create an array of size
// MAX_STUDENTS.
const int MAX_STUDENTS = 1000;

int main() {
    // Use the following variables and make sure to comment each.
    std::string names[MAX_STUDENTS];
    int grades[MAX_STUDENTS];
    int count = 0;
    std::ifstream inputFile("grades.txt");
    // TODO: YOUR CODE GOES HERE!
    inputFile.close();
    return 0;
}
