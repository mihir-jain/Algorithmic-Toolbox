#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void)
{
    int n, num = 0, i, j;
    cin>>n;
    //n = 96234;
    vector<int> arr;
    arr.push_back(0);
    arr.push_back(1);
    int ar[(n+1)];
    int req[(n+1)];
    for(i=1;i<=n;i++)
    req[i] = INT32_MAX;

    ar[1] = 0;
    // Reverse did not work. Let's start from 1 and move onwards to n
    int x = n;
    int flag;
    for(i=2;i<=n;i++)
    {
        flag = 1;
        if((i-1)%1==0)
        {
            num = ar[i-1] + 1;
            if(num < req[i])
            {
                req[i] = num;
                ar[i] = num;  
            }             
        }

        if((i%2)==0)
        {
            num = ar[i/2] + 1;
            if(num < req[i])
            {
                flag = 2;
                ar[i] = num;
                req[i] = num;
            }
        }

        if((i%3)==0)
        {
            num = ar[i/3] + 1;
            if(num < req[i])
            {
                flag = 3;
                ar[i] = num;
                req[i] = num;
            }
        }
        if(flag == 1)
        arr.push_back(1);
        else if(flag == 2)
        arr.push_back(2);
        else
        arr.push_back(3);

    }  

    /*for(i=1;i<=n;i++)
    cout<<ar[i]<<" ";
    cout<<"\n";  
    int l = arr.size();
    cout<<"Length: "<< l << "\n";
    for(i=1;i<l;i++)
    cout<<arr[i]<<" ";
    cout<<"\n";
    */
    vector<int> a;
    a.push_back(n);
    int index = n;
    //cout<<"Index: "<< index <<"\n";
    while(index!=1)
    {
        if(arr[index]==1)
        {
            a.push_back((n-1));
            n = n -1;
            index = index - 1;
     //       cout<<"Index: "<< index <<"\n";
        }
        else if(arr[index]==2)
        {
            a.push_back((n/2));
            n = n/2;
            index = index/2;
       //     cout<<"Index: "<< index <<"\n";
        }
        else if(arr[index]==3)
        {
            a.push_back(n/3);
            n = n/3;
            index = index/3;
         //   cout<<"Index: "<< index <<"\n";
        }
    }
    //a.push_back(1);
    //cout<<"Path: ";
    int l = a.size();
    cout<<l-1<<"\n";
    for(i=l-1;i>=0;i--)
    cout<<a[i]<<" ";
    cout<<"\n";

     
    return 0;
}