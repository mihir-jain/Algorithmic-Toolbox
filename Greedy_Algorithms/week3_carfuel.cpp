#include <iostream>
using namespace std;

int main(void)
{
    int d, m, n, i;
    cin>>d;
    cin>>m;
    cin>>n;
    int ar[n+2];
    ar[0] = 0;
    ar[n+1] = d;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }

    /*for(i=0;i<=n+1;i++)
    cout<<ar[i]<<" ";
    cout<<"\n";
    */
   int num = 0;
    int j, initial = ar[0], index =0, final = ar[n+1];
    
    while(initial!=final)
    {   
       // cout<<"Initial:"<<initial<<"\n"<<"Num:"<<num<<"\n";
        bool flag = false;
        for(j=n+1;j>index;j--)
        {
            if((-initial + ar[j]) <=m)
            {
                if(j!=n+1)
                num++;
                initial = ar[j];
                index = j;
                flag = true;
                break;
            }
        }
        if (flag == false)
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<num;
    return 0;
}
