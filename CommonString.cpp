#include <iostream>
#include <vector>
#include <string>
using namespace std;


void longestCommonSubstring(string str1, string str2) {
    int n = str1.length();
    
    
    vector<vector<int>> outputmatrix(n + 1, vector<int>(n + 1, 0));
    int maxLength = 0;  
    int endIndex = 0;   

    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                outputmatrix[i][j] = outputmatrix[i - 1][j - 1] + 1;
                if (outputmatrix[i][j] > maxLength) {
                    maxLength = outputmatrix[i][j];
                    endIndex = i - 1; 
                }
            } else {
                outputmatrix[i][j] = 0;
            }
        }
    }

    
    cout << "2D Grid (DP Table):" << endl;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << outputmatrix[i][j] << " ";
        }
        cout << endl;
    }

    
    string longestSubstring = str1.substr(endIndex - maxLength + 1, maxLength);
    
    cout << "\nThe longest common substring is: " << longestSubstring << " with length " << maxLength << endl;
}

int main() {
    
	
	string str1;
    string str2;
    cout<<"Enter string 1";
    cin>>str1;
    cout<<"Enter string 2";
    cin>>str2;
    cout << "String 1: " << str1 << endl;
    cout << "String 2: " << str2 << endl;

    longestCommonSubstring(str1, str2);

    return 0;
}
