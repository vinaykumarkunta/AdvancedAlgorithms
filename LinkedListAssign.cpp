#include <iostream>
using namespace std;


class Node
{
    public:
    int row_index;
    int column_index;
    int num;
    Node *next;
};

void new_Node(Node **n, int row_index,int column_index, int num){
	Node *temp = *n;
    Node *r;
    if (temp == NULL)
    {
        temp = new Node();
        temp->row_index = row_index;
        temp->column_index = column_index;
        temp->num = num;
        temp->next = NULL;
        *n = temp;
    }
    
     else
    {
        while (temp->next != NULL)   
            temp = temp->next;
             
        r = new Node();
        r->row_index = row_index;
        r->column_index = column_index;
        r->num = num;
        r->next = NULL;
        temp->next = r;
    }
}
 
 
void printOutput(Node *start)
{
    Node *ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->row_index << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->column_index << " ";
        ptr = ptr->next;
    }
    cout << endl;
    ptr = start;
     
    while (ptr != NULL)
    {
        cout << ptr->num << " ";
        ptr = ptr->next;
    }
}   
    

int main()
{
    int i = 0;
    int given_sparse_matrix[4][5] =
        {
            {0, 0, 3, 0, 4},
            {0, 0, 5, 7, 0},
            {0, 0, 0, 0, 0},
            {0, 2, 6, 0, 0}
        };
Node *initial = NULL;
	while(i<4){
		int j=0;
		while(j<5){
			if (given_sparse_matrix[i][j] != 0)
                new_Node(&initial, i, j,given_sparse_matrix[i][j]);
            j++;
		}
		i++;
	}
	
    printOutput(initial);
 
    return 0;
}