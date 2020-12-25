#include <iostream>
using namespace std;
int a[112];
int timess,N,P,Q;
int main()
{
    cin >>timess;
    for(int cases=1; cases<=timess; cases++)
    {
        cin >> N >> P >> Q; // N=egg ,P=risk more than P ,Q= gm of eggs;
        for(int i=0; i<N; i++)
            cin>>a[i];
        int egg=0,summ=0;
        for(int i=0; i<N && i<P; i++)
        {
            summ+=a[i];
            if(summ>Q)
                break;
            egg++;
        }
        cout << "Case " << cases << ": " << egg << endl;
    }
}
