#include <iostream>
#include <string>
using namespace std;

int len_regroup=0;

int main()
{	
	
	
    cin >> len_regroup;
    while(len_regroup)
    {	
		string word;
        cin >> word;
        int loop = word.size();
        int Numgroup = loop / len_regroup;
        for (int i = 0; i < loop; i += Numgroup)
        { 
            for (int j = i, k = i + Numgroup -1 ; k>j; j++, k--)
            {
                char temp(word[j]);
                word[j] = word[k];
                word[k] = temp;
            }
        }
        cout << word << endl;
        cin >> len_regroup;
    }
}
