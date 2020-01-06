#include <iostream>

using namespace std;

void show_myVector(int * myVector, int dimension);
void show_matrix(int ** matrix, int lines, int columns);
int * allocate_myVector(int dimension, int val);
int ** allocate_matrix(int lines, int columns, int val);
int ** generate_matrix_id(int dimension);
void free_myVector(int * myVector);
void free_matrix(int ** matrix,int lines);


int main(){

     int * myVector = allocate_myVector(6,1);
     int ** matrix = allocate_matrix(2,2,5);

      show_matrix(matrix,2,2);
      show_myVector(myVector,6);

	return 0;

}

void show_myVector(int *myVector, int dimension) {

    int i=0;

    for(i=0;i<dimension;i++)
    {
       cout << "valeur " << i << ": " << myVector[i] << endl;
    }
}

void show_matrix(int **matrix, int lines, int columns) {

	int i=0,j=0;

	for(i=0;i<lines;i++)
	{
		for(j=0;j<columns;j++)
		{
			cout << "valeur (" << i << "," << j << "): " << matrix[i][j] << endl;
		}
	}
}

int * allocate_myVector(int dimension, int val) {

     int i=0;
     int *myVector = new int[dimension];

       for(i=0;i<dimension;i++)
       {
           myVector[i] = val;
       }
    return myVector;
}

int ** allocate_matrix(int lines, int columns, int val) {

	 int i=0,j=0;
	 int ** matrix = new int*[lines];

	  for(i=0;i<lines;i++) {

	  	 matrix[i] = new int[columns];

	  }

	  for(i=0;i<lines;i++) {

	  	 for(j=0;j<columns;j++) {

	  	 	matrix[i][j] = val;

		   }
	  }
	        return matrix;
}

int ** generate_matrix_id(int dimension) {

	 int i=0;
	 int ** matrix = allocate_matrix(dimension,dimension,0);

	  for(i=0;i<dimension;i++) {

	  	 matrix[i][i] = 1;
	  }
	     return matrix;
}

void free_myVector(int * myVector) {

     delete[] myVector;
}

void free_matrix(int ** matrix,int lines) {

	 int i=0;

	 delete[] matrix;

	  for(i=0;i<lines;i++) {

	  	 delete matrix[i];

	  }
}
