#include<iostream>
#include<array>
using namespace std;

void getindices(int target_number, int array_provided[],int array_length){
	for (int j=0;j<(array_length-1);j++){
		for (int k=(j+1);k<array_length;k++){
			if((array_provided[j]+array_provided[k])==target_number){
				cout<<j;
				cout<<k;
				cout<<"\n";
			}
		}
	}


}

int main() {
	int array_length;
	int array_provided[105];
	int target_number;
	int i=0;
	cout<<"Provide the number of elements of the array";
	cin>>array_length;
	cout<<"Provide the elements of the array";
	while(i<array_length){
		cin>>array_provided[i];
		i++;
	}
	cout<<"Enter the target number";
 	cin>>target_number;
 	getindices(target_number,array_provided,array_length);
}








