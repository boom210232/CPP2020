#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 100010;
int nextintg[N];
char sTring[N];
 
int main()
{
    int nowlocation, last;
    
    while(fgets(sTring+1, N, stdin) != NULL) {
        nextintg[0] = 0;
		last = 0;
		nowlocation = 0;
        int i = 1;
        while(sTring[i] != '\n') {
            if(sTring[i]==']'){
			nowlocation = last;
			}              
			else if(sTring[i] == '['){
				nowlocation = 0;
			}
            else {
                nextintg[i] = nextintg[nowlocation];
                nextintg[nowlocation] = i;
                if(last == nowlocation)
                    last = i;
                nowlocation = i;
            }
            i++;
       }
        for(i = nextintg[0]; i; i = nextintg[i])
        	cout << sTring[i];
        cout << "\n";
    }
}
