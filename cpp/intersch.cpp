#include <iostream>
using namespace std;

int timer[100001][1];
int n,ans,start,endss;

int main(){
	cin >> n;
	for(int i =0 ;i<n;i++){
		cin >> timer[i][0];
		cin >> timer[i][1];
	}
	for(int i =0 ;i<n;i++){
		ans=1;
		start = timer[i][0];
		endss = timer[i][0];
		for(int j=1 ; j<n;j++){
			if(timer[j][0]>=endss){
				ans++;
				endss= timer[j][0];
			}
		}
	}
	cout << ans << endl;
}
