// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I -Problem 1
// Program: CS213-2018-A1-P1
// Purpose: Making Operations With Matrix
// Author:  Ahmed Magdy Ahmed Mostafa & Ahmed Gomma Farouk
// Date:    15 Oct 2018
#include <iostream>
#include <iomanip>
#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
  int* data;       // Pointer to 1-D array that will simulate matrix
  int row, col;
};
void createMatrix (int row, int col, int num[], matrix& mat);
ostream& operator<<(ostream& out,matrix mat);

//student 1  Ahmed Gomma Farouk  20170014
istream& operator>> (istream& in, matrix& mat);// Already implemented
ostream& operator<< (ostream& out, matrix mat);
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);

//student   Ahmed Magdy Ahmed   20170026
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
					    // new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
					     // matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator++ (matrix& mat);   	// Add 1 to each element ++mat
matrix operator-- (matrix& mat);


//__________________________________________

int main()
{

    matrix mat1, mat2;

    int x,scalar;

    for (int z=0;z<=30;z++){

    cout<<"1- print matrix 1 ,matrix 2 ,sum of 2 matrix ,Difference of 2 matrix ,matrix 1 + scalar and matrix 1 -scalar"<<endl;
    cout<<"2- Sum"<<endl;
    cout<<"3- Difference"<<endl;
    cout<<"4- Adding scalar"<<endl;
    cout<<"5- Subtracting scalar"<<endl;
    cout<<"6- ++Matrix"<<endl;
    cout<<"7- --Matrix"<<endl;
    cout<<"Press Any other Number or letter to Exit"<<endl;



    cout<<endl;

    cout<<"Choose a Number : ";

    cin>>x;

    if(x==1){

  int data1 [] = {15,365,14,4,32,6,7,8};

  int data2 [] = {13,213,9,12,9,6,9,5};

  int data3 [] = {10,100,10,100,10,100,10,100};

  matrix mat1, mat2, mat3;

  createMatrix (4, 2, data1, mat1);

  createMatrix (4, 2, data2, mat2);

  createMatrix (4, 2, data3, mat3);

  cout<<"this is mat 1 of data"<<endl;

  cout<<"*********************"<<endl;

  cout<<mat1<<endl;

  cout<<"this is mat 2 of data"<<endl;

  cout<<"*********************"<<endl;

  cout<<mat2<<endl;

  cout<<"*********************"<<endl;

  cout<<"this is the output + data"<<endl;

  cout<<(mat1+mat2);

  cout<<"********************"<<endl;

  cout<<"this is the output - data"<<endl;

  cout<<(mat1-mat2);

  cout<<"**************************"<<endl;

  cout<<"this is the output + scalar"<<endl;

  cout<<(mat1+7);

   cout<<"**************************"<<endl;

  cout<<"this is the output - scalar"<<endl;

  cout<<(mat1-9);


    }

   else if(x==2){
    cout<<endl;

    cout<<"Sum of 2 Matrix "<<endl<<endl;

    cout<<" first matrix "<<endl;

    cin>>mat1;

    cout<<mat1;

    cout<<endl<<"second matrix"<<endl;

    cin>>mat2;

    cout<<mat2;

    cout<<endl;

    mat1+=mat2;

    cout<<endl<<"Sum"<<endl<<endl;

    cout<<mat1;
    }

    else if (x==3){

    cout<<endl;

    cout<<"Difference of 2 Matrix"<<endl<<endl;

    cout<<" first matrix "<<endl;

    cin>>mat1;

    cout<<mat1;

    cout<<endl<<" second matrix"<<endl;

    cin>>mat2;

    cout<<mat2;

    cout<<endl;

    mat1-=mat2;

    cout<<endl<<"Difference"<<endl<<endl;

    cout<<mat1<<endl;
    }

    else if (x==4){

    cout<<endl;

    cout<<"Adding scalar to a Matrix"<<endl<<endl;

    cout<<"Enter a matrix "<<endl;

    cin>>mat1;

    cout<<mat1;

    cout<<"Enter a scalar : ";

    cin>>scalar;

    mat1+=scalar;

    cout<<endl<<"Adding scalar"<<endl<<endl;

    cout<<endl<<mat1<<endl;

    }

    else if (x==5){

    cout<<endl;

    cout<<"Subtracting scalar"<<endl<<endl;

    cout<<"Enter a matrix "<<endl;

    cin>>mat1;

     cout<<mat1;

    cout<<"Enter a scalar : ";

    cin>>scalar;

    mat1-=scalar;

    cout<<endl<<"subtracting scalar"<<endl<<endl;

    cout<<endl<<mat1<<endl;

    }

    else if (x==6){

    cout<<endl;

    cout<<"++Matrix"<<endl;

    cin>>mat1;

    cout<<mat1;

    ++mat1;

    cout<<endl<<"++Matrix"<<endl<<endl;

    cout<<mat1<<endl;
    }

    else if (x==7){

    cout<<endl;

    cout<<"--Matrix"<<endl;

    cin>>mat1;

    cout<<mat1;

    --mat1;

    cout<<endl<<"--Matrix"<<endl<<endl;

    cout<<mat1;
    }

    else {
    cout<<endl<<" Exit"<<endl;
    break;
    }
  }
}



istream& operator>>(istream& in, matrix& mat){ // Get 2 matrix from the user

    cout <<endl<<endl<< "Please Enter rows and columns: ";

    cin >> mat.row >> mat.col;// Get row ,col of  matrix

    mat.data = new int[mat.row * mat.col];

    for(int i = 0 ; i < mat.row ; i++){

        cout <<endl<< "Please Enter data for row " << i+1 << ": ";

        for(int j = 0 ; j < mat.col ; j++){

            cin >> mat.data[i * mat.col + j];// Get elements of matrix
        }
    }
}


ostream& operator<<(ostream& out,matrix mat)
{
    for(int i=0;i<mat.row;i++)
    {
       for(int j=0;j<mat.col;j++){

            out<<mat.data[i*mat.col+j]<< " ";//printing numbers in Matrix Model
     }
     out<<endl;
}
return out;

}

matrix operator+= (matrix& mat1, matrix mat2){ // This operator Add mat1 on mat2

    for (int i=0;i<mat1.row*mat1.col;i++){ // loop on mat1 rows ,cols

    mat1.data[i]+=mat2.data[i];//Add elements of mat1 on mat2
    }
    return mat1;
}

matrix operator-= (matrix& mat1, matrix mat2){// This operator subtract  mat1 from mat2

    for (int i=0;i<mat1.row*mat1.col;i++){// loop on mat1 rows ,cols

    mat1.data[i]-=mat2.data[i];//subtract elements of mat1 from mat2
    }
    return mat1;
}

matrix operator+= (matrix& mat1, int scalar){// This operator Add  mat1 on scalar which the user enter it

    for (int i=0;i<mat1.row*mat1.col;i++){// loop on mat1 rows ,cols

        mat1.data[i]+=scalar;//Add elements of mat1 on scalar number
    }
    return mat1;
}

matrix operator-= (matrix& mat1, int scalar){// This operator subtract mat1 from scalar which the user enter it

    for (int i=0;i<mat1.row*mat1.col;i++){// loop on mat1 rows ,cols

    mat1.data[i]-=scalar;//Add elements of mat1 on scalar number
    }
    return mat1;
}

matrix operator++(matrix& mat1){// This operator Add 1 on mat1

    for (int i=0;i<mat1.row*mat1.col;i++){// loop on mat1 rows ,cols

    mat1.data[i]+=1;//Add 1 on the elements of mat1
    }
    return mat1;

}

matrix operator--(matrix& mat1){// This operator Add 1 on mat1

    for (int i=0;i<mat1.row*mat1.col;i++){// loop on mat1 rows ,cols

    mat1.data[i]-=1;//subtract 1 from  the elements of mat1
    }
    return mat1;
}

void createMatrix (int row, int col, int num[], matrix& mat) {

  mat.row = row;

  mat.col = col;

  mat.data = new int [row * col];

  for (int i = 0; i < row * col; i++)

    mat.data [i] = num [i];
}


matrix operator-(matrix mat1,matrix mat2)
{
    matrix mat5;
    int arr[mat1.row*mat1.col];// size of new mat
    createMatrix(mat1.row,mat1.col,arr,mat5);
    for(int i=0;i<mat1.row*mat1.col;i++)//(loop on mat1 to subtract every element in mat1-mat2)
    {
        mat5.data[i]=mat1.data[i]-mat2.data[i]; // the result of subtract add in new matrix which called mat5
    }
    return mat5;
}

matrix operator+(matrix mat1,matrix mat2)
{
    matrix mat6;
    int arr1[mat1.row*mat1.col]; // size of mat 6
    createMatrix(mat1.row,mat1.col,arr1,mat6);
    for(int i=0;i<mat1.row*mat1.col;i++) // loop to add every element to another in the second matrix
    {
        mat6.data[i]=mat1.data[i]+mat2.data[i];
    }
    return mat6;
}
matrix operator+  (matrix mat1, int scalar)
{
 matrix mat7;
    int arr2[mat1.row*mat1.col];
    createMatrix(mat1.row,mat1.col,arr2,mat7);
    for(int i=0;i<mat1.row*mat1.col;i++)
    {
        for(int j=0;j<mat1.row*mat1.col;j++) // loop to add an any number on the diagonle of matrix
        {
            if(i==j)
            {
                mat7.data[i*mat1.col+j]=mat1.data[i*mat1.col+j]+scalar;
            }
            else
                 mat7.data[i*mat1.col+j]=mat1.data[i*mat1.col+j];
        }
    }
    return mat7;

}
matrix operator-  (matrix mat1, int scalar)
{
 matrix mat8;
    int arr3[mat1.row*mat1.col];//size of new mat
    createMatrix(mat1.row,mat1.col,arr3,mat8);
    for(int i=0;i<mat1.row*mat1.col;i++)
    {
        for(int j=0;j<mat1.row*mat1.col;j++) //loop to matrix 2 to find the i==j
        {
            if(i==j)
            {
                mat8.data[i*mat1.col+j]=mat1.data[i*mat1.col+j]-scalar;
            }
            else
                 mat8.data[i*mat1.col+j]=mat1.data[i*mat1.col+j];
        }
    }
    return mat8;

}






