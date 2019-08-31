#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    int n, i, j, x;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
    {
       cin>>ar[i];
    }
    vector<int> v;
    for(i=0;i<n;i++)
    {
        do
        {
            x = ar[i]%10;
            v.push_back(x);
            ar[i] = ar[i] / 10;
        }while(ar[i]!=0);
    }
    sort(v.begin(), v.end(), greater<int>()); 
    int s = v.size();
    for (i=0;i<s;i++)
    cout << v[i];

    return 0;

}