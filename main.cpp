/*
    Name: Chen, Isaac, 2002582920, CS 135 1001, Assignment 7
    Description: Creating a C++ program that takes in a file
    as input and then calculates student informations
    Input: grades file, selection of what to do
    Output: Whatever option you want about student info
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <sstream>

// Global variable used to create an array of size
// MAX_STUDENTS.
const int MAX_STUDENTS = 1000;

int getIntegerInput(int min, int max);
void enterData();
void displayData(std::string nameArr[], int gradeArr[], int arrSize);
void calculateInfo(std::string nameArr[], int gradeArr[], int arrSize);
void sortArr(std::string nameArr[], int gradeArr[], int arrSize);
int searcher(std::string nameArr[], int gradeArr[], int arrSize);
int searcher(std::string nameArr[], int gradeArr[], int arrSize, 
             std::string name);
void update(std::string nameArr[], int gradeArr[], int arrSize);

int main() {
    // Use the following variables and make sure to comment each.
    std::string names[MAX_STUDENTS] = {};
    int grades[MAX_STUDENTS] = {};
    int count = 0;
    std::ifstream inputFile("grades.txt");
    // TODO: YOUR CODE GOES HERE!

    std::string line = " ";
    int input = 0, index = 0;

    // The filler of arrays
    while (std::getline(inputFile, line)) {
        int whereHyphen = line.find(" - ");
        names[index] = line.substr(0, whereHyphen);
        grades[index] = stoi(line.substr(whereHyphen + 3));
        index++;
        count++;
    }

    // The doer of stuff
    input = getIntegerInput(1, 7);
    // The casing of input
    while(true) {
        switch (input) {
            case 1:
                enterData();
                input = getIntegerInput(1, 7);
                break;
            case 2:
                displayData(names, grades, count);
                input = getIntegerInput(1, 7);
                break;
            case 3:
                calculateInfo(names, grades, count);
                input = getIntegerInput(1, 7);
                break;
            case 4:
                sortArr(names, grades, count);
                input = getIntegerInput(1, 7);
                break;
            case 5:
                searcher(names, grades, count);
                input = getIntegerInput(1, 7);
                break;
            case 6:
                update(names, grades, count);
                input = getIntegerInput(1, 7);
                break;
            case 7:
                break;   
            }
            if (input == 7) {
                std::cout << "Exiting...";
                break;  
            }
        }
    // The ending of stuff
    inputFile.close();
    return 0;
}
// Grabs your input
int getIntegerInput(int min, int max) {
	int numInput = 0;
	do {
        // the list of options
        std::cout << "1. Enter student data" << std::endl;
        std::cout << "2. Display all grades" << std::endl;
        std::cout << "3. Calculate average, highest, lowest"<<std::endl;
        std::cout << "4. Sort grades" << std::endl;
        std::cout << "5. Search for a student" << std::endl;
        std::cout << "6. Update a student's grade" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";
		std::cin >> numInput;

        // the tester of okaer
		if (std::cin.fail() || numInput < min || numInput > max) {
			std::cout << std::endl;
			std::cout << "Invalid choice. Please try again." <<std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		} else {
			break;
		}
	} while (true);
	
    std::cout << std::endl;
	return numInput;
}

// Enter your data
void enterData() {
    std::cout << "Maximum student limit reached." << std::endl;
}

// Display your data
void displayData(std::string nameArr[], int gradeArr[], int arrSize) {
    std::cout << "Student Grades:" << std::endl;
    std::cout << "-----------------------------------" << std::endl;
    for (int i = 0; i < arrSize; i++) {
        std::cout << "Name: " << nameArr[i] 
                  << ", Grade: " << gradeArr[i] << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
}

// Calculate it
void calculateInfo(std::string nameArr[], int gradeArr[], int arrSize) {
    int lowestGrade = gradeArr[1], highestGrade = gradeArr[1];
    int whereLowest = 0, whereHighest = 0;
    double sum = 0;

    for (int i = 0; i < arrSize; i++) {
        if (highestGrade < gradeArr[i]) {
            highestGrade = gradeArr[i];
            whereHighest = i;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        if (lowestGrade > gradeArr[i]) {
            lowestGrade = gradeArr[i];
            whereLowest = i;
        }
    }
    for (int i = 0; i < arrSize; i++) {
        sum += gradeArr[i];
    }
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Average Grade: " << sum/arrSize << std::endl;
    std::cout << "Highest Grade: " << highestGrade
              << " (" << nameArr[whereHighest] << ")" << std::endl;
    std::cout << "Lowest Grade: " << lowestGrade
              << " (" << nameArr[whereLowest] << ")" << std::endl;
}

// Quick sorter of death
// poo
void sortArr(std::string nameArr[], int gradeArr[], int arrSize) {
    bool swapped = true; 
    while(swapped) {
        swapped = false; // every time it is reset to false
        for(int i = 1; i < arrSize; i++) {
            if (gradeArr[i-1] > gradeArr[i]) {
                std::swap(gradeArr[i-1], gradeArr[i]);
                std::swap(nameArr[i-1], nameArr[i]);
                swapped = true; // if something needed to be swapped
                // it continues
            }
        }
    }
    std::cout << "Grades sorted successfully." << std::endl;
}

// Searcher
int searcher(std::string nameArr[], int gradeArr[], int arrSize) {
    std::string temp = " ", last = " ", first = " ", name = " ";
    int whereSpace = 0;
    std::cout << "Enter the name of the student to search: ";
    std::cin >> name;
    std::cout << std::endl;
    // Splits in the input
    // finds last or first name match
    for (int i = 0; i < arrSize; i++) {
        temp = nameArr[i];
        whereSpace = temp.find(' ');
        first = temp.substr(0, whereSpace);
        last = temp.substr(whereSpace + 1);
        if (last == name || first == name) {
            std::cout << "Found: " << nameArr[i] << ", " 
                      << "Grade: " << gradeArr[i] << std::endl;
            return i;
        }
    }
    return -1;
}

// Overloaded function
// because I am lazy
int searcher(std::string nameArr[], int gradeArr[], int arrSize,
             std::string name) {
    std::string temp = " ", last = " ", first = " ";
    int whereSpace = 0;
    // Splits in the input
    // finds last or first name match
    for (int i = 0; i < arrSize; i++) {
        temp = nameArr[i];
        whereSpace = temp.find(' ');
        first = temp.substr(0, whereSpace);
        last = temp.substr(whereSpace + 1);
        if (last == name || first == name) {
            return i;
        }
    }
    // even more comments
    return -1;
}

// We will use an overloaded function to find and replace
void update(std::string nameArr[], int gradeArr[], int arrSize) {
    // Omg I need more comments
    std::string name = " ";
    int newgrade = 0;
    std::cout << "Enter the name of the student to update: ";
    std::cin >> name;
    std::cout << std::endl;
    // here are some comments
    int changeIndex = 0;
    changeIndex = searcher(nameArr, gradeArr, arrSize, name);
    std::cout << "Current Grade: " << gradeArr[changeIndex] <<std::endl;
    std::cout << "Enter new grade: ";
    std::cin >> newgrade;
    std::cout << std::endl;
    gradeArr[changeIndex] = newgrade;
    std::cout << "Grade updated successfully." << std::endl;
}
