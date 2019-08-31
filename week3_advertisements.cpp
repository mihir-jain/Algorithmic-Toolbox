#include <iostream>
using namespace std;

int main(void)
{
    int64_t n,i;
    cin>>n;
    int64_t a[n],b[n];
    for(i=0;i<n;i++)
    cin>>a[i];

    for(i=0;i<n;i++)
    cin>>b[i];
    int64_t j;
    int64_t temp,max;
    for(i=0;i<n;i++)
    {
        max = a[i];
        for(j=i;j<n;j++)
        {
            if(a[j]>max)
            {
                max = a[j];
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                
                
            }
        }
    }    
    
    
    for(i=0;i<n;i++)
    {
        max = b[i];
        for(j=i;j<n;j++)
        {
            if(b[j]>max)
            {
                max = b[j];
                temp = b[j];
                b[j] = b[i];
                b[i] = temp;
            
                
            }   
        }
      
    }

    int64_t sum = 0;
    for(i=0;i<n;i++)
    sum = sum + a[i]*b[i];
        
    cout<<sum;
    return 0;
}