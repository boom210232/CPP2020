#include <stack>
#include <iostream>
using namespace std;
int main(){
	int n;
	stack<string> stk;
	cin >> n;
	string cmd , name ;
	for(int i =0 ; i<n ; i++){
		cin >> cmd;
		if(cmd[0] == 'S'){
			cin >> name;
			stk.push(name);
		}
		else if(cmd[0] == 'K' && !stk.empty()){
			stk.pop();	
		} 
		else if(cmd[0] == 'T') {
			cout << "Not in a dream" << endl;
			cout << stk.top() << endl;	
		}
	}
	return 0; 
}  // UVA reang mak 

