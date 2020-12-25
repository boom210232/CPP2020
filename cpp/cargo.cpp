#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int N, S, Q, i, j, k, carry, MINT ,cases;
queue<int> station[105];
stack<int> cv;

int main() {
    int cases;
    cin >> cases;
    while(cases--) { 
        cin>> N >> S >> Q;
        for(i = 1; i <= N; i++) {
            int n, x;
            cin >> n;
            while(n--) {
                cin >> x;
                station[i-1].push(x-1);
            }
        }
        carry = 0;
		MINT = 0;
        while(true) {
            while(!cv.empty() && ((cv.top() == carry) || (Q > station[carry].size()))) {
                    if(carry != cv.top()){
                    	station[carry].push(cv.top());
					}                      
                cv.pop();
                MINT++;
            }
            while((S > cv.size()) && (!station[carry].empty())){
                cv.push(station[carry].front());
                station[carry].pop();
                MINT++;
            }
            int emp = cv.empty();
            for(i = 1; i <= N; i++)
                emp &= station[i-1].empty(); // con str cr.tonkla SKE16
            if(emp)
                break;
            carry++;
            MINT += 2;
            carry %= N;
        }
        cout<<MINT<<endl;
    }

}
