#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    int W, n, i, w;
    cin>>W>>n;
    int weights[n];
    for(i=0;i<n;i++)
    cin>>weights[i];
    vector< vector<int>> values(n+1, vector<int> (W+1));
    for(i=0;i<=n;i++)
    values[i][0] = 0;

    for(i=0;i<=W;i++)
    values[0][i] = 0;

    for(i=1;i<=n;i++)
    {
        for(w=1;w<=W;w++)
        {
            values[i][w] = values[i-1][w];
            if(weights[i-1]<=w)
            {
                int val = values[(i-1)][w-weights[i-1]] + weights[i-1];
                if(val>values[i][w])
                values[i][w] = val;
            }
        }
    }

    cout<<values[n][W];
    


    return 0;
}
