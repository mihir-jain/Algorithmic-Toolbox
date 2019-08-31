#include <iostream>
using namespace std;
int main(void)
{
    int n, i, k;
    //cout<<"Enter length of array: ";
    cin>>n;
    //cout<<"Enter value to be searched: ";
    //cin>>key;
    int ar[n];
    //cout<<"Enter values of array: ";
    for(i=0;i<n;i++)
    cin>>ar[i];
    cin>>k;
    int keys[k];
    for(i=0;i<k;i++)
    cin>>keys[i];
    for(i=0;i<k;i++)
    {
        
        int key = keys[i];
        int low = 0, high = n-1, loc;
        bool flag = false;
        while(low<=high)
        {
            int mid = (low + high)/2;
            if(ar[mid]==key)
            {   
                flag = true;
                loc = mid;
                break;
            }
            else if(ar[mid]<key)
            low = mid + 1;
            else
            high = mid - 1;
        }
        if(flag == false)
        cout<<-1 <<" ";
        else
        cout<<loc << " ";

    }       
    
    return 0;

}
