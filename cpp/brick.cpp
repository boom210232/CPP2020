#include <iostream>
#include <cstdio>
using namespace std;
 
int main()
{
	int Brick[10][10],N,X,Y,Z; 
	cin >> N;
	for(int i = 0 ; i<N ; i++){
		for (int i = 0; i<=8; i+=2) for (int j=0; j<=i; j+=2)
			cin >> Brick[i][j];
		for (int i = 0; i<=6; i+=2) for (int j=0; j<=i; j+=2){
			X = Brick[i][j];
			Y = Brick[i+2][j];
			Z = Brick[i+2][j+2];
			Brick[i+1][j+1] = (X-Y+Z)/2;
			Brick[i+2][j+1] = (X-Y-Z)/2;
			Brick[i+1][j] = (X+Y-Z)/2;			
		}
		for (int i = 0; i<=8; i++) {
			for (int j = 0; j <= i; j++){
				printf("%d%c", Brick[i][j], j == i ? '\n' : ' ');
			}
		}
			
	}	
}
