#include <iostream>
using namespace std;

int main(void)
{
    int64_t x, y, i, max, other;
    cin>>x>>y;
    if(x==0 || y==0)
    {
        cout<<0;
        return 0;
    }

    if(x==y)
    {
        cout<<x;
        return 0;
    }
    else if(x>y)
    {
        max = x;
        other = y;
    }
    else
    {   
        max = y;
        other = x;
    }
    //cout<<max<<" "<<other<<"\n";
    int64_t lcm, prod, j = 1;
    for(i=max*j;; i=max*j)
    {
        if(i%other == 0)
        {
            lcm = i;
            break;
        } 
        j++;
    }

    cout<<lcm;
    
    return 0;
}
