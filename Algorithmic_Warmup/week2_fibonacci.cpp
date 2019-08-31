#include <iostream>
using namespace std;

int main(void)
{
    int64_t n;
    cin>>n;
    if(n==0)
    {
        cout<< 0;
        return 0;
    }

    if(n==1)
    {
        cout<< 1;
        return 0;
    }
    
    int64_t ar[n];
    ar[0] = 0;
    ar[1] = 1;
    int64_t i;
    for(i=2;i<=n;i++)
    {
        ar[i] =  ar[i-1] + ar[i-2];
    }
    cout<<ar[n]<< " ";

    return 0; 
}
