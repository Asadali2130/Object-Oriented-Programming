#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

void ResizeArray(int num, int *newarray, int size);
void add_new_number(int num, int *newarray, int &size); // Modified the function signature
void add_array(int *newarray, int size);
using namespace std;

int main() {
    int size = 5;
    int *array = new int[size];

    for (int i = 0; i < size; i++) {
        sleep(1);
        srand(time(NULL));
        int a = rand() % 10 + 1;
        array[i] = a;
    }

    cout << "Array before insertion:" << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << array[i];
    }

    int *newarray = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newarray[i] = array[i];
    }

    delete[] array;

    int choice;
    cout << "1.Add new number" << endl;
    cout << "2.Delete a number" << endl;
    cout << "3.Print the array" << endl;
    cout << "4.Print sum of the array" << endl;
    cout << "5.Exit program" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    while (choice != 5) {
        if (choice == 1) {
            int num;
            cout << "Enter the number to enter: ";
            cin >> num;
            add_new_number(num, newarray, size); // Updated the function call
            cout << "Number is added" << endl;
        } else if (choice == 2) {
            int search, position=-1;
            cout << "Enter the number to delete: ";
            cin >> search;

            for (int i = 0; i < size; i++) {
                if (newarray[i] == search) {
                    position = i;
                    break;
                }
            }
            if(position==-1){
                cout<<"Element not found";
            }
            else{
            for (int i =position;i < size - 1; i++) {
                newarray[i] = newarray[i + 1];
            }

            size = size - 1; // Update the size

            cout << "Array after deletion:" << endl;
            for (int i = 0; i < size; i++) {
                cout << " " << newarray[i];
            }
            }
        }
         else if (choice == 3) {
            cout << "Array after insertion:" << endl;
            for (int i = 0; i < size; i++) {
                cout << " " << newarray[i];
            }
        } else if (choice == 4) {
            add_array(newarray, size);
        }

        cout << "1.Add new number" << endl;
        cout << "2.Delete a number" << endl;
        cout << "3.Print the array" << endl;
        cout << "4.Print sum of the array" << endl;
        cout << "5.Exit program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    }

    delete[] newarray;
}

void add_new_number(int num, int *newarray, int &size) { // Modified the function signature
    ResizeArray(num, newarray, size);
    size = size + 1;
}

void ResizeArray(int num, int *newarray, int size) {
    newarray[size] = num;
}

void add_array(int *newarray, int size) {
    int *AddArray = new int[size];
    for (int i = 0; i < size; i++) {
        AddArray[i] = newarray[i] + newarray[i];
    }
    cout << "The sum of array is" << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << AddArray[i];
    }

    delete[] AddArray;
}
