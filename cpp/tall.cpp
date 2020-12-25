#include <iostream>

using namespace std;

int main()
{
    int n,rank;
    cin >> n;
    int height[n];
    for (int i = 0; i < n; i++) cin >> height[i];

    for (int j = 0; j < n; j++)
    {
        rank = 0;
        for (int k = 0; k < n; k++)
        {
            if (height[j] < height[k])
            {
                rank++;
            }
        }
        cout << rank << endl;
    }
}
