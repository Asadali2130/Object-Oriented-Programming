#include <iostream>
#include <string>
using namespace std;

class dayType {
    string* day;
    int* index;
    int* index2;
    int* num;

public:
    dayType() {
        day = new string("");
        index = new int(0);
        index2 = new int(0);
        num = new int(0);
    }

    dayType(string DAY, int I) {
        day = new string(DAY);
        index = new int(I);
        index2 = new int(0);
        num = new int(0);
    }

    dayType(const dayType& obj) {
        day = new string(*obj.day);
        index = new int(*obj.index);
        index2 = new int(*obj.index2);
        num = new int(*obj.num);
    }

    ~dayType() {
        delete day;
        delete index;
        delete index2;
        delete num;
    }

    void setday(string d) {
        *day = d;
    }

    string getday() {
        return *day;
    }

    string getnextday() {
        string Week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (*index == 6) {
            return Week[0];
        } else {
            return Week[*index + 1];
        }
    }

    string getpreviousday() {
        string Week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        if (*index == 0) {
            return Week[6];
        } else {
            return Week[*index - 1];
        }
    }

    string Add() {
        string Week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        cout << "Enter the number of days to add: ";
        cin >> *num;
        *index = (*index + *num) % 7;
        return Week[*index];
    }
};

int main() {
    dayType D, D1("Monday", 4);
    dayType D2(D1);
    string d;
    cout << "Enter the day name (full name with the first capital letter): ";
    cin >> d;
    D.setday(d);

    cout << "The day is: " << D.getday() << endl;
    cout << "Next day: " << D.getnextday() << endl;
    cout << "Previous day: " << D.getpreviousday() << endl;
    char choice;
    cout << "Do you want to add and calculate days (y-n): ";
    cin >> choice;
    if (choice == 'y') {
        cout << "The result is: " << D.Add() << endl;
    }

    cout << "The new calculation" << endl;
    cout << "The day is: " << D1.getday() << endl;
    cout << "Next day: " << D1.getnextday() << endl;
    cout << "Previous day: " << D1.getpreviousday() << endl;

    cout << "The new calculation" << endl;
    cout << "The day is: " << D2.getday() << endl;
    cout << "Next day: " << D2.getnextday() << endl;
    cout << "Previous day: " << D2.getpreviousday() << endl;

    return 0;
}