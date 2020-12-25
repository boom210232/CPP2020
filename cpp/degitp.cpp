#include <iostream>
using namespace std;

int main()
{
     int n, num,reverse = 0, digit ;
     cin >> num;
     n = num;

     do
     {
         digit = num % 10;
         reverse = (reverse * 10) + digit;
         num = num / 10;
     } while (num != 0);

     if (n == reverse) cout << "yes";
     else cout << "no";

}
