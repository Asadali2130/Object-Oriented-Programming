#include <iostream>
using namespace std;

class angle {
    int* degree;
    float* minute;
    char* direction;

public:
    angle() {        //constructor
        degree = new int;
        minute = new float;
        direction = new char;
    }

    angle(int d, float m, char D) {     //constructor with three arguments
        degree = new int(d);
        minute = new float(m);
        direction = new char(D);
    }

    angle(const angle& obj) {     //copy constructor
        degree = new int(*obj.degree);
        minute = new float(*obj.minute);
        direction = new char(*obj.direction);
    }

    void input() {
        int choice;
        cout << "1. Longitude\n2. Latitude\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the degrees (0-180): ";
            cin >> *degree;
            if (*degree < 0 || *degree > 180) {
                cout << "Enter a value between 0 and 180." << endl;
            } else {
                cout << "Enter minutes: ";
                cin >> *minute;
                cout << "Enter the direction (E-W): ";
                cin >> *direction;
                if (*direction != 'E' && *direction != 'W') {
                    cout << "Enter E for East and W for West." << endl;
                }
            }
        } else if (choice == 2) {
            cout << "Enter the degrees (0-90): ";
            cin >> *degree;
            if (*degree < 0 || *degree > 90) {
                cout << "Enter a value between 0 and 90." << endl;
            } else {
                cout << "Enter minutes: ";
                cin >> *minute;
                cout << "Enter the direction (N-S): ";
                cin >> *direction;
                if (*direction != 'N' && *direction != 'S') {
                    cout << "Enter N for North and S for South." << endl;
                }
            }
        }
    }

    void display() {
        cout << *degree << "\xF8" << *minute << *direction << endl;
    }

    ~angle() {
        delete degree;
        delete minute;
        delete direction;
    }
};

int main() {
    angle obj1;
    obj1.input();
    obj1.display();

    angle obj2(obj1);  // calling the copy constructor
    angle obj3(45, 65, 'E');
    obj3.display();

    return 0;
}