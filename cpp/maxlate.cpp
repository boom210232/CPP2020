#include <iostream>
#include <algorithm>
using namespace std;

int day,days,dayd,ot,hours;
int start[100005],dead[100005],dead2[100005];

int main(){
	cin >> day;
	for(int i=0 ; i<day ;i++){
		cin >> days;
		start[i] = days;
		cin >> dayd;
		dead[i] = dayd;
	}
	sort(start, start + day,less<int>());
	sort(dead, dead + day,greater<int>());
	for(int i=0;i<day;i++){
		if(i==0){
			dead2[i] = dead[i];
		}
		else{
			dead2[i] = dead2[i-1]+dead[i];
		}
	}	
	
//	for(int i=0 ; i<day ;i++){
//		cout << start[i] <<" ";	
//	}
//	cout << endl;
//	
//	for(int i=0 ; i<day ;i++){
//		cout << dead2[i]<< " ";	
//	}
//	cout << endl;	
	
	
	

	for (int i = 1; i <= day; i++) {
			hours = dead[i-1]-start[i-1];
			if (hours > 10) ot += (hours)*1000;
		}
	cout << ot << endl;	
		}


