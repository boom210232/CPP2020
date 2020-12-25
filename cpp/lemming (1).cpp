#include <iostream>
#include <iterator>
#include <queue>
#include <set>

using namespace std;

int N, B, sg, sb;
int hp;
int green_sum = 0;
int blue_sum = 0;
multiset<int, greater<int>> SG, SB;
queue<int> blueteam, greenteam;

int main()
{
    cin >> N;
    while(N--) {
        SG.clear();
        SB.clear();
        cin >> B >> sg >> sb;
        //green team
        while (sg--) {
            cin >> hp;
            SG.insert(hp);
        }
        //blue team
        while (sb--) {
            cin >> hp;
            SB.insert(hp);        
        }

        while (!SG.empty() && !SB.empty()) {
            int blue, green;
            int teamsize = min(B, (int)min(SB.size(), SG.size()));

            // create team
            for (int i=0; i<teamsize; i++) {
                auto sb = SB.begin();
                auto sg = SG.begin();

                blueteam.push(*sb);
                greenteam.push(*sg);

                SB.erase(sb); 
                SG.erase(sg);
            }
            // battle!
            for (int i=0; i<teamsize; i++) {
                blue = blueteam.front();
                green = greenteam.front();

                blueteam.pop();
                greenteam.pop();

                if (green > blue) {
                    SG.insert(green-blue);
                } else if (blue > green) {
                    SB.insert(blue-green);
                } else {
                    continue;
                }
            }

        }

        multiset<int, greater<int>>::iterator it;
        if (SG.empty() && SB.empty()) {
            cout << "green and blue died" << endl;
            if (N!=0) cout << endl;
            continue;
        } else if (SG.empty()) {
            cout << "blue wins" << endl;
            for(it=SB.begin(); it!=SB.end(); it++) {
                cout << *it << endl;
            }
        } else {
            cout << "green wins" << endl;
            for(it=SG.begin(); it!=SG.end(); it++) {
                cout << *it << endl;
            }
        }
        if (N!=0) cout << endl;
    }
}