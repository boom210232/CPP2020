  
#include <iostream>

using namespace std;

int main()
{
    int n;
	int max = 1000;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    int ans = 0;
    int truck_load = 0;
    for (int j = 0; j < n; j++)
    {
        truck_load += array[j];
        if ( max < truck_load )
        {
            ans++;
			truck_load = array[j];
            
        }
        if (j == n - 1)
        {
            ans++;
        }
    }
    cout << ans;
}
