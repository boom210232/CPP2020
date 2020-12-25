#include <iostream>
#include <algorithm>
using namespace std;

int n, d, r, x , ot;
int morning[101], afternoon[101],hours;
int main() {

	while (cin >> n >> d >> r) {
		if(n==0 || d==0 || r==0) break;
		ot = 0;

		for (int i = 1; i <= n; i++) {
			cin >> x;
			morning[i-1] =x;
		}
		sort(morning, morning + n);
		for (int i = 1; i <= n; i++) {
			cin >> x;
			afternoon[i-1] =x;
		}
		sort(afternoon, afternoon + n, greater<int>());

		for (int i = 1; i <= n; i++) {
			hours = morning[i-1]+afternoon[i-1];
			if (hours > d)
				ot += (hours-d)*r;
		}

		cout << ot << endl;
	}
}
