#include <iostream>
using namespace std;

int main()
{
    int n,time = 0;
    cin >> n;
    int num[n] ;
    for (int i = 0; i < n; i++)
    {
        num[i] = i + 1;
    }

    for (int k = 0; k < n; k++)
    {
        for (int j = k; time < n; j++)
        {
            if (n - 1<j  )
            {
                j = 0;
            }
            if ( n-1>time )
            {
                time++;
				cout << num[j];   
            }
            else if (n-1 == time)
            {
                time++;
				cout << num[j] << endl;
                
            }
        }
        time = 0;
    }
}
