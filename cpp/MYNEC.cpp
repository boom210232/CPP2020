#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool sorted(pair<long , long > &ai, pair<long , long > &bi){
    return (bi.second > ai.second);
}
int N, M, ai, bi,maxnumdis= 0, leftone,rightone,righttwo,i; //ai start bi end
int main()
{  
    cin >> N >> M;
    vector<pair<long, long> > btw2gem;
    for (i = 1; i <= M; i++){
        cin >> ai >> bi;
        btw2gem.push_back(make_pair(ai, bi));
    }
    sort(btw2gem.begin(), btw2gem.end(), sorted);
    maxnumdis++;
    rightone = btw2gem[0].second;
    for (i = 0; i < btw2gem.size(); i++){
        righttwo = btw2gem[i].second;
        leftone = btw2gem[i].first;
        if (rightone < leftone){
            rightone = righttwo;
            maxnumdis++;
        }
    }
    cout << maxnumdis << endl;
}
