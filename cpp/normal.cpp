# include<iostream>
using namespace std;
int main(){
	int a , b,c;

	
	cin >> a >> b;	
	if(a>0 && b>0){
	if(a>b){
		c = a;
	}
	else{
		c =b;
	}
	for(int i = 2 ;i< c; i++){
		while((a%i==0) && (b%i==0)){
			a = a/i;
			b= b/i;
		}
		
	}
	cout << a << "/" << b;	
	} 
	
}
