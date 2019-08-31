#include <iostream>
using namespace std;

int main(void)
{
    int64_t n;
    cin>>n;
    int64_t ar[n];
    for(int64_t i =0;i<n;i++)
    {
        cin>>ar[i];
    }
    int64_t max1 = ar[0];
    int64_t i, index;
    
    for(i=1; i<n;i++)
    {
        if(ar[i] > max1)
        {
            max1 = ar[i];
            index = i;
        }
    }
    //cout<<"Max 1: << " << max1 << "\n";
    int64_t max2;
    if(index==0)
        max2 = ar[1];
    else
        max2 = ar[0];

    for(i=0; i<n;i++)
    {
        if(i!=index && ar[i]>max2)
        max2 =  ar[i];
    }
    //cout<<"Max 2: << " << max2 << "\n";
    int64_t prod = max2*max1;
    cout<<prod<<"\n";
    
    return 0;
}

