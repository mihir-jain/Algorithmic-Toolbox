#include <iostream>
using namespace std;

int main(void)
{
    int i, money;
    int denom[3] = {10,5,1}, num[3];
    cin>>money;
    for(i=0; i<3; i++)
    {
        num[i] = money/denom[i];
        money = money%denom[i];
    }
    int sum =0;
    for(i=0;i<3;i++)
    sum = sum + num[i];
    cout<<sum;
    return 0;
}