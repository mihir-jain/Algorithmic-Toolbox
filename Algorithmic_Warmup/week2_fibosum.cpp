#include <iostream>
using namespace std;

int main(void)
{
    int64_t n, i;
    cin>>n;
    int64_t ar[n+2];
    ar[0]=0;
    ar[1]=1;
    for(i=2;i<=n+2;i++)
    {
        ar[i] = ar[i-1] + ar[i-2];
    }
    cout<<(ar[n+2]-1)%10;
 
    return 0;
}
