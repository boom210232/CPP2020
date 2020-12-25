#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int home, l;
    cin >> home >> l;
    int x[home];
    for (int i = 0; i < home; i++)
    {
        cin >> x[i];
    }

    int near = 0;
    for (int i = 0; i < home; i++)
    {
        for (int k = i + 1; k < home; k++)
        {
            int dist = abs( x[k] - x[i]);
            if (dist <= l)
            {
                near++;
            }
        }
    }
    cout << near << endl;
}
