#include "student.h"

void student::setClasses() {
	string classNum;
	while (classes < 1 || classes > 8) { //Error trapped input
		cout << "How many classes are you taking (Must be between 1 and 8): ";
		std::getline(cin, classNum);
		if (isdigit(classNum[0])) {//Checks if all input is digits
			classes = std::stoi(classNum);//Uses stoi so spaces or special characters does not break program
		}
	}
}

void student::disciplineIssue() { //5% chance of returning a discipline issue
    int seed, number, temp; //Random seeding based on time to make number as random as possible
    srand(time(NULL));
    for (int i = 0; i < rand() % 17 + 1; i++) {
        temp = rand();
    }
    seed = rand();
    srand(seed);
    number = rand() % 100;
    if (number <= 4) { //5/100 will return true
        discipline = true;
    }
    else {
        discipline = false;
    }
}

void student::setClassNames() {
    string temp;
    for (int i = 1; i <= classes; i++) {
        while (true) { //Error trapped name input
            cout << "Enter course " << i << " name (will be truncated to 20 characters): ";
            std::getline(cin, temp);
            if (temp.length() <= 20 && temp.length() > 0) {//If less than 20 and more than 0 it wil function normally
                courses.push_back(temp);
                break;
            }
            else if (temp.length() > 20) { //if more than 20 it will shorten it to 20
                courses.push_back(temp.substr(0, 20));
                break;
            }
            else;
        }
    }
}

void student::setClassScores() {
    string scoreNum;
    int tempScore;
    bool flag = false;
    cout << "Minimum Grade: 0\nMaximum Grade: 120\n"; //Displaying min/max grades
    for (int i = 0; i < classes; i++) {
        while (true) {
            cout << "Enter score for " << courses[i] << ": ";
            std::getline(cin, scoreNum);
            flag = false;
            for (int i = 0; i < scoreNum.length(); i++) {
                if (!isdigit(scoreNum[i])) {//Checks if any nondigits are in the string
                    flag = true;
                    break;
                }
            }
            if (!flag) { //If no non digits are found in string it turns to int and sends to vector
                tempScore = std::stoi(scoreNum);
                if (tempScore >= 0 && tempScore <= MAX_GRADE) {
                    scores.push_back(tempScore);
                    break;
                }
            }
        }
    }
}

void student::calculateAverage() {//Average, pretty self explanatory
    for (int i = 0; i < classes; i++) {
        average += scores[i];
    }
    average /= classes;
}

void student::printOut() { //Prints out all necessary data
    cout << "Name: " << name << endl << endl;
    cout << std::left << "Class  " << std::setw(10) << std::right << "Grade\n";
    for (int i = 0; i < classes; i++) {
        cout << "Class " << i + 1 << std::right << std::setw(10) << scores[i] << "\n";
    }
    cout << "\nAmount of Courses: " << classes << "\nAverage: " << average << "\nDisclipinary Infraction: ";
    if (discipline)
        cout << "YES\n";
    else
        cout << "NO\n";

    if (classes >= 5 && average >= 90 && !discipline) {
        cout << "Congratulations " << name << "! You have made the honor roll\n";
    }
    else {
        cout << "I'm sorry " << name << " but you didn't qualify for the honor roll.\n";
    }
}