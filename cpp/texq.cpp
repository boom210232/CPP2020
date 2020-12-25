#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int i = 0,tex = 0;
    char string[10000];
    while(gets(string)){
        for(int i = 0;string[i];i++){
            if(string[i] == '\"'){
                tex++;
                if(tex%2 == 0){
				cout << "\'\'";
				}
                else{
				cout << "``";
				}
				
            }
            else {
            	cout << string[i];
			}
		
        }
        cout << endl;
}
}
