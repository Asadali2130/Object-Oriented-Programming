#include <iostream>
using namespace std;

//function prototypes
void input(int **M1,int **M2,int row,int col);
int Add(int **M1,int **M2,int **ADD,int row,int col);
int Sub(int **M1,int **M2,int **SUB,int row,int col);
int Mul(int **M1,int **M2,int **MUL,int row,int col);
int transpose(int **M1,int **M2,int **Trans1,int **Trans2,int row,int col);
int output(int **M1,int **M2,int **ADD,int **SUB,int **MUL,int **Trans1,int **Trans2,int row,int col);

int main(){
    int row,col;
    int a,b,c,d,e,f;
    cout<<"Enter the number of rows and columns in matrices:";
    cin>>row>>col;
        //Memory allocation of matrices
        int **M1=new int*[row];
        int **M2=new int *[row];
        int **ADD=new int *[row];
        int **SUB=new int *[row];
        int **MUL=new int *[row];
        int **Trans1=new int*[row];
        int **Trans2=new int*[row];

     
     for(int i=0;i<row;i++){
        M1[i]=new int[col];
     }
     for(int i=0;i<row;i++){
        M2[i]=new int[col];
     }
      for(int i=0;i<row;i++){
        ADD[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        SUB[i]=new int[col];
    }
     for(int i=0;i<row;i++){
        MUL[i]=new int[col];
    }
    for(int i=0;i<row;i++){
        Trans1[i]=new int [col];
        Trans2[i]=new int [col];
    }

     //function call
     input(M1,M2,row,col);
    a=Add(M1,M2,ADD,row,col);
    b=Sub(M1,M2,SUB,row,col);
    c=Mul(M1,M2,MUL,row,col);
    d=transpose(M1,M2,Trans1,Trans2,row,col);
    f=output(M1,M2,ADD,SUB,MUL,Trans1,Trans2,row,col);

    //deallocating memory
    for(int i=0;i<row;i++){
        delete[] M1[i];
        delete[] M2[i];
        delete[] ADD[i];
        delete[] SUB[i];
        delete[] MUL[i];
        delete[] Trans1[i];
        delete [] Trans2[i];
    }

    delete []M1;
    delete []M2;
    delete []ADD;
    delete []SUB;
    delete []MUL;
    delete []Trans1;
    delete []Trans2;
}
//function starts
void input(int **M1,int **M2,int row,int col){
    cout<<"Enter the elements in the first matrix:";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>M1[i][j];
        }
    }

     cout<<"Enter the elements in the second matrix:";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>M2[i][j];
        }
    }
    

}

int Add(int **M1,int **M2,int **ADD,int row,int col){


    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ADD[i][j]=M1[i][j]+M2[i][j];
        }
    }

    

}
int Sub(int **M1,int **M2,int **SUB,int row,int col){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            SUB[i][j]=M1[i][j]-M2[i][j];
        }
    }

    

}
int Mul(int **M1,int **M2,int **MUL,int row,int col){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            MUL[i][j]=0;
        }
    }

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            int a=0;
            while(a<row){
            MUL[i][j]+=(M1[i][a]*M2[a][j]);
            a++;
        }
    }
    }

}

int transpose(int **M1,int **M2,int **Trans1,int **Trans2,int row,int col){

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            Trans1[i][j]=M1[j][i];
            Trans2[i][j]=M2[j][i];
        }
    }
}

int output(int **M1,int **M2,int **ADD,int **SUB,int **MUL,int **Trans1,int **Trans2,int row,int col){

    cout<<"First matrix is:"<<endl;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<M1[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }

    cout<<"Second matrix is:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<M2[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }

    cout<<"Addition of matrices:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<ADD[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }

    cout<<"Subtraction of matrices:"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<SUB[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }

    cout<<"Multiplication of matrices:"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<MUL[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }
     
     cout<<"Transpose of first matrix:"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<Trans1[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }

    cout<<"Transpose of second matrix:"<<endl;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<" "<<Trans2[i][j];
            if(j==col-1){
                cout<<endl;
            }
        }
    }
}