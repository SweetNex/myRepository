#include <stdio.h>
#include <stdlib.h>

void show_vector(int *vector, int dimension);
void show_matrix(int **matrix, int lines, int columns);
int * allocate_vector(int dimension, int val);
int ** allocate_matrix(int lines, int columns, int val);
int ** generate_matrix_id(int dimension);
void free_matrix(int ** matrix, int lines);
void free_vector(int * vector);

main(){

	int i=0;
    int *vect = allocate_vector(6,2);
    int **matrix = allocate_matrix(4,2,1);
    int **mat_id = generate_matrix_id(2);

	    show_vector(vect,6);
		show_matrix(matrix,4,2);
		printf("\n");
		show_matrix(mat_id,5,5);
		free_vector(vect);
		free_matrix(matrix,4);
		free_matrix(mat_id,5);

	return 0;

}

void show_vector(int *vector, int dimension) {

    int i=0;

    for(i=0;i<dimension;i++)
    {
       printf("valeur %d: %d \n",i,*(vector+i));
    }
}

void show_matrix(int **matrix, int lines, int columns) {

	int i=0,j=0;

	for(i=0;i<lines;i++)
	{
		    printf("(");
		for(j=0;j<columns;j++)
		{
			printf("%d ",i,j,matrix[i][j]);
		}
		    printf(")\n");
	}
}

int * allocate_vector(int dimension, int val) {

     int i=0;
     int *vector = malloc(dimension*(sizeof(int)));

       for(i=0;i<dimension;i++)
       {
           vector[i] = val;
       }
    return vector;
}

int ** allocate_matrix(int lines, int columns, int val) {

	 int i=0,j=0;
	 int ** matrix = malloc(lines*(sizeof(int*)));

	  for(i=0;i<lines;i++) {

	  	 matrix[i] = malloc(columns*(sizeof(int)));

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

void free_vector(int * vector) {

     free(vector);
}

void free_matrix(int ** matrix,int lines) {

	 int i=0;

	 free(matrix);

	  for(i=0;i<lines;i++) {

	  	 free(matrix[i]);

	  }
}
