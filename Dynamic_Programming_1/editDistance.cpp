#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b) 
{ 
    return (a < b); 
} 

int main(void)
{
    string str1, str2;
    cin>>str1>>str2;
    int l1 = str1.length(), l2 = str2.length(), i, j;
    int score[(l1+1)][(l2+1)];
    j = 0;
    for(i=0;i<=l1;i++)
    score[i][j] = i;

    i = 0;
    for(j=0;j<=l2;j++)
    score[i][j] = j;
    
    int res = 0;
    int ins, del , mat, mismat;
    for(i=1;i<=l1;i++)
    {
        for(j=1;j<=l2;j++)
        {
            ins = score[(i)][(j-1)] + 1;
            del = score[(i-1)][(j)] + 1;
            mismat = score[(i-1)][(j-1)] + 1;
            mat = score[(i-1)][(j-1)] + 0;
            if(str1[(i-1)]==str2[(j-1)])
            {
                score[i][j] = std::min({ins,del, mat}, comp);
                //cout<<str1[i]<< " "<< str2[j]<<"\n";
            }
            else
            {score[i][j] = std::min({ins,del, mismat}, comp);}
            
        }
    }

    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        cout<<score[i][j]<<" ";
        cout<<"\n";
    }
    
    i = l1, j = l2;
    vector<int> first;
    vector<int> second;
    while(i>0 || j>0)
    {
        
        if((i>0) && (score[i][j]==(score[(i-1)][j]+1)))
        {
            first.push_back(str1[i-1]);
            second.push_back(0);
            i--;
        }
        else if((j>0) && (score[i][j]==(score[(i)][(j-1)]+1)))
        {
            first.push_back(0);
            second.push_back(str2[j-1]);
            j--;
        }
        else
        {
            first.push_back(str1[i-1]);
            second.push_back(str2[j-1]);
            i--, j--;
        }

    }
 
     
    int l = max(first.size(),second.size());
    for(i=l-1;i>=0;i--)
    {
        if(first[i]==0)
        cout<<"-"<<" ";
        else
        cout<<(char)first[i]<<" ";
    }

    cout<<"\n";
    for(i=l-1;i>=0;i--)
    {
        if(second[i]==0)
        cout<<"-"<<" ";
        else
        cout<<(char)second[i]<<" ";
    }
    cout<<"\n";
    
    cout<<score[l1][l2];


    return 0;

}
