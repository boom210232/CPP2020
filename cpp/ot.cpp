#include <stdio.h>
#include<iostream>
using namespace std;

int deadline[100000],need[100000];
int daydead,dayneed,total,ot;

int main()
{
    cin >> total;
    for (int i = 0;i<total;i++){
    cin >> daydead >> dayneed;
    deadline[i] = daydead;
    need[i] = dayneed;
    }
    for (int j = 0;j<total;j++){
        if(need[j] - deadline[j] > 10){
            ot += (need[j] - deadline[j]) * 1000;
        } 
    }
    cout << ot;
}
