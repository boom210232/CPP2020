#include <iostream>
#include <queue>
#include <set>
#include <iterator>

using namespace std;

int Nloop, Battle, healthpoint, green_sum = 0, blue_sum = 0, scoregreen, scoreblue,blue, green;
multiset<int, greater<int>> ScG, ScB;
queue<int> teamblue, teamgreen;

int main()
{
    cin >> Nloop;
    while(Nloop--) {
        ScB.clear();
        ScG.clear();
        cin >> Battle >> scoregreen >> scoreblue;
        while (scoregreen--) {
            cin >> healthpoint;
            ScG.insert(healthpoint);
        }
        while (scoreblue--) {
            cin >> healthpoint;
            ScB.insert(healthpoint);        
        }
        while (!ScB.empty() && !ScG.empty()) {
            int sizes = min(Battle, (int)min(ScB.size(), ScG.size()));
            for (int i=0; i<sizes; i++) {
                auto scoreblue = ScB.begin();
                auto scoregreen = ScG.begin();
                teamgreen.push(* scoregreen);
                teamblue.push(* scoreblue);
                ScG.erase(scoregreen);
                ScB.erase(scoreblue); 
            }
            for (int i=0; i<sizes; i++) {
                green = teamgreen.front();
                blue = teamblue.front();
                teamgreen.pop();
                teamblue.pop();
                if (blue > green) {
                    ScB.insert(blue-green);
                } 
				else if (green > blue) {
                    ScG.insert(green-blue);
                } 

            }
        }
        multiset<int,greater<int>>::iterator iterat;
        if (ScG.empty() && ScB.empty()) {
            cout << "green and blue died" << endl;
            if (Nloop!=0) cout << endl;
            continue;
        } else if (ScB.empty()) {
            cout << "green wins" << endl;
            for(iterat=ScG.begin(); iterat!=ScG.end(); iterat++) {
                cout << *iterat << endl;
            }
        } else {
            cout << "blue wins" << endl;
            for(iterat=ScB.begin(); iterat!=ScB.end(); iterat++) {
                cout << *iterat << endl;
            }
        }
        if (Nloop!=0) {
        	cout << endl;
		}
    }
}
