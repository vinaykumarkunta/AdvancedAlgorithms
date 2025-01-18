#include<iostream>
#include<array>
using namespace std;

int columnsoutput(int given_sparse_matrix[4][5]){
	int columns;
	for (int i=0;i<4;i++){
		for (int j=0;j<5;j++){
			if(given_sparse_matrix[i][j]!=0){
				columns++;
			}
		}
	}
	return columns;
}

void output_matrix_generation(int columns, int given_sparese_matrix[4][5]){
	int sparse_output_matrix[3][columns];
	int k=0; 
	int i=0;
	while (i<4){
		int j=0;
		while(j<5){
			if(given_sparese_matrix[i][j]!=0){
				sparse_output_matrix[0][k] = i;  
                sparse_output_matrix[1][k] = j;  
                sparse_output_matrix[2][k] = given_sparese_matrix[i][j];  
                k++;  
			}
		 j++;
		}
		i++;
	}

	
	for(int i=0 ;i<3; i++)  
    {  
        for(int j=0; j<columns; j++)  
        {  
            cout<< sparse_output_matrix[i][j];  
            cout<<"\t"; 
        }  
        cout<<"\n";  
    }  
}

int main(){
	int columns = 0; 
	int given_sparse_matrix [4][5]= 
	{
		{0,0,3,0,4},
		{0,0,5,7,0},
		{0,0,0,0,0},
		{0,2,6,0,0}
	};
 	columns= columnsoutput(given_sparse_matrix);
	output_matrix_generation(columns,given_sparse_matrix);
}