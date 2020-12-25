#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>

using namespace std;
int n, m;
long long a;
set<long long>::iterator nearlow;
set<long long> number;
int main()
{		
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> a;
        number.insert(a);
    }
    for (int j=1; j<=m; j++) {
        cin >> a;

        nearlow = number.lower_bound(a);
        set<long long>::iterator find = number.find(a);
        set<long long>::iterator previous = prev(nearlow);

        if ( a == *find) {
            cout << a << endl;
        } 
		else if(abs(a-*nearlow)>abs(a-*previous) ){
                cout << *previous << endl;
            } 
		else if (abs(a-*previous)>abs(a-*nearlow)) {
            cout << *nearlow << endl;
            } 
		else {
            if (*previous>*nearlow) {
            	cout << *nearlow << endl;
                } 
			else {
            	cout << *previous << endl;
                }

            }
        }
    }

