#include <iostream>
using namespace std;

int main(void)
{
    int money, i;
    cin>>money;
    int change[3] = {1,3,4};
    int ar[money+1];
    for(i=1;i<money+1;i++)
    {
        ar[i] = 500;
    }

    ar[0] = 0;
    int j, num;
    for(i=1;i<=money;i++)
    {
        for(j=0;j<3;j++)
        {
            if(i>=change[j])
            {
                num = ar[i-change[j]] + 1;
                if(num<ar[i])
                ar[i] = num;
            }
        }
    }

    //for(i=0;i<=money;i++)
    cout<<ar[money];

    
    return 0;
}
