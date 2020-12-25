#include <iostream>
#include <stack>
using namespace std;

int main() {
	int i, n, car[1000] , Index = 0, current = 0;

	while (true) {
		cin >> n;
		if (n == 0) break;
		
		while (true) {
			cin >> car[0];
			if (car[0] == 0){
				cout << endl;
				break;
			}
			for (i = 1; i < n; i++) {
				cin >> car[i];
			}

			Index = 0; 
			current = 1;
			stack<int> station;
			while(current<=n){
				station.push(current);

				while(!station.empty() && station.top() == car[Index]){
					Index++;
					station.pop();
					if(Index>=n) break;
				}

				current++;
			}

			if(station.empty()){
			cout << "Yes" << endl;
			} 
			else {
				cout << "No" << endl;
			}
		}}}
	


