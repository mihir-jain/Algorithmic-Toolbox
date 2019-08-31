#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(long long a, long long b) 
{ 
    return (a < b); 
} 

int main(void)
{
    string str;
    
    cin>>str;
    //vector<int> num;
    vector<char> ops;
    long long l = str.length();
    long long i,j,s;
    long long n = (l+1)/2;
    long long mini[n+1][n+1], maxi[n+1][n+1];
    long long k = 0;
    long long num[n];
    /*for(i=0;i<l;i++)
    cout<<str[i]<<" ";
    cout<<"\n";
    */
    for(i=0;i<l;i=i+2)
    {
        //cout<<str[i]<<"\n";
        num[k] = str[i]-48;
        k++;
    }
    for(i=1;i<l;i=i+2)
    {
        //<<str[i]<<"\n";
        ops.push_back(str[i]);
    }

    /*l = ops.size();
    for(i=0;i<n;i++)
    cout<<num[i]<<" ";

    cout<<"\n";

    //l = ops.size();
    for(i=0;i<l;i++)
    cout<<ops[i]<<" ";

    */
    
    k=0;
    for(i=1;i<=n;i++)
    {
        mini[i][i] = num[k];
        maxi[i][i] = num[k];    
        k++;    
    }
    /*for(i=0;i<n;i++)
    cout<<num[i]<<" ";
    cout<<"\n";

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        cout<<maxi[i][j]<<" ";
        cout<<"\n";
    }
*/
    long long t, a,b,c,d;
    for(s=1;s<=n-1;s++)
    {
        for(i=1;i<=n-s;i++)
        {
            j = i + s;
            //min and max            
            mini[i][j] = INT32_MAX;
            maxi[i][j] = INT32_MIN;
            for(k=i;k<=j-1;k++)
            {
                if(ops[k-1]=='+')
                {
                    a = maxi[i][k] + maxi[k+1][j];
                    b = maxi[i][k] + mini[k+1][j];
                    c = mini[i][k] + mini[k+1][j];
                    d = mini[i][k] + maxi[k+1][j];
                }

                if(ops[k-1]=='-')
                {
                    a = maxi[i][k] - maxi[k+1][j];
                    b = maxi[i][k] - mini[k+1][j];
                    c = mini[i][k] - mini[k+1][j];
                    d = mini[i][k] - maxi[k+1][j];
                }

                if(ops[k-1]=='*')
                {
                    a = maxi[i][k] * maxi[k+1][j];
                    b = maxi[i][k] * mini[k+1][j];
                    c = mini[i][k] * mini[k+1][j];
                    d = mini[i][k] * maxi[k+1][j];
                }
                mini[i][j] = min({mini[i][j], a, b, c, d}, comp);
                maxi[i][j] = max({maxi[i][j], a, b, c, d}, comp);
            }
        }
    }
    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        cout<<maxi[i][j]<<" ";
        cout<<"\n";
    }
    */
    cout<<maxi[1][n];
    return 0;

}

