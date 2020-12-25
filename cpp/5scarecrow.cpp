#include<iostream>
using namespace std; // # can't plant PAK LAIKA .plantable
int timess, charact, count;
char arr[112];
int main(){	
	cin >> timess;
	for (int i = 1; i <= timess; i++){
		cin >> charact;
		count = 0;
		for (int j = 0; j < charact; j++){
			cin >> arr[j];
		}
		for (int k = 1; k <= charact;k++){
			if (arr[k-1] == '.'){	
				count++;
				k += 2;
			}
		}
		cout << "Case " << i << ": " << count << endl;
	}
}
