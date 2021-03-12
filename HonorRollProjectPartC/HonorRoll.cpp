/*
Jacob Choi
2/17/21
Honor Roll OOP
*/

#include <iostream>
#include "student.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
    string name; //name to send to object
    do {
        cout << "Enter name: ";
        std::getline(cin, name);
    } while (name.length() <= 0); //error trap to send basic constructor info to object
    student s(name); //Creating object
    s.setClasses(); //Functions that do all the work
    s.disciplineIssue();
    s.setClassNames();
    s.setClassScores();
    s.calculateAverage();
    s.printOut();
	return 0;
}