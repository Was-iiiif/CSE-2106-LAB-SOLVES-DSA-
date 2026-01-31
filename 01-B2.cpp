/*Frequency Counter:
Input:  6
        1 2 1 6 6 6
Output: 1 is 2 times
        6 is 3 times*/
#include<iostream>
using namespace std;
int main()
{
    int mx=100000;
    int n;
    cin>>n;
    int arr[n];
    int temp[mx]={0};
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        temp[arr[i]]++;
    }
    for(int i=0; i<mx; i++)
    {
        if(temp[i]>1)
            cout<<i<<" is "<<temp[i]<<" times\n";
    }
}

