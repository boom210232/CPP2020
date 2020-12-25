#include <iostream>
using namespace std;

#define MAXN 1000010

main() {
    int n,m,cdm[MAXN]={0},cdn[MAXN]={0},i,j,same;
    while (cin >> n >> m) {
        if (n==0 && m==0) break;
        for (i=1;i<=n;i++) cin >> cdm[i];
        for (i=1;i<=m;i++) cin >> cdn[i];
		same = 0;
        i = 1;
        j=1;
		while (i<=n && j<=m) {
            while (m>=j && cdm[i]>cdn[j]) j++;
            if (j>m) break;
            if (cdm[i]==cdn[j]) {
                same++; 
				j++;
            }
            i++;
        }
        cout << same << endl;
    }
}	

