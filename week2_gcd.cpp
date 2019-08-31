#include <iostream>
using namespace std;
int64_t gcd(int64_t a, int64_t b);


int main(void)
{
    int64_t a,b;
    cin>>a>>b;
    int64_t g = gcd(a,b);
    cout<<g;
}

int64_t gcd(int64_t a, int64_t b)
{   
    if(a==0)
    return b;
    else if(b==0)
    return a;
    else
    return gcd(b,a%b);
    
    
}
