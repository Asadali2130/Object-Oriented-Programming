#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter number of rows in array:";
    cin>>n;
    int **array= new int*[n];
    int col_array[n];
    cout<<"Enter the number of columns in row";
    for(int i=0;i<n;i++){
        int col;  
        cin>>col;
        array[i]=new int[col];
        col_array[i]=col;
    }

    cout<<"Enter the numbers in 2D array:";
    for(int i=0;i<n;i++){
        for(int j=0;j<col_array[i];j++){
            cin>>array[i][j];
        }
    }

    cout<<"The required 2D array is:"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<col_array[i];j++){
            cout<<" "<<array[i][j];
            if(j==col_array[i]-1){
                cout<<endl;
            }
        }
    }
    for(int i=0;i<col_array[i];i++){
        delete []array[i];
    }

    delete []array;

}