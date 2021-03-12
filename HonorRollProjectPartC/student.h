#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iomanip>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
class student
{
public:
	student(string x) { //basic constructor that takes in string for name
		name = x;
	}
	const int MAX_GRADE = 120; //constant int for max grade
	void setClasses();
	void disciplineIssue();
	void setClassNames();
	void setClassScores();
	void calculateAverage();
	void printOut();
private: //basic variables needed for functions
	bool discipline;
	string name;
	int classes = 0, average = 0;
	std::vector<int> scores;
	std::vector<string> courses;
};