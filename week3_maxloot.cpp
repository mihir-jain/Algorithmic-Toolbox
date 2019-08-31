#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    double W, max;;
    int n, i, j;
    cin>>n>>W;
    double dim[n][3];
    for(i=0;i<n;i++)
    {
        cin>>dim[i][0]>>dim[i][1];
        dim[i][2] = (float) dim[i][0]/dim[i][1];
    }
/*
    for(i=0;i<n;i++)
    {
        cout<<dim[i][2]<<" ";
    }
    cout<<"\n";
    
    sorting
    */
    double temp;
    
    for(i=0;i<n;i++)
    {
        max = dim[i][2];
        for(j=i;j<n;j++)
        {
            if(dim[j][2] > max)
            {
                max = dim[j][2];

                temp = dim[i][0];
                dim[i][0] = dim[j][0];
                dim[j][0] = temp;

                temp = dim[i][1];
                dim[i][1] = dim[j][1];
                dim[j][1] = temp;

                temp = dim[i][2];
                dim[i][2] = dim[j][2];
                dim[j][2] = temp;
             
            }
        }
    }

   /* for(i=0;i<n;i++)
    {
        cout<<dim[i][1]<<" ";
    }
*/
    double value = 0.0;

    for(i=0;i<n;i++)
    {
        if((W-dim[i][1])<=0.0)
        {
            //cout<<"\n"<< dim[i][2]<<"\n";
            value = value + W*dim[i][2];
            break;
        }
        else
        {
            value = value + dim[i][0];
            W = W - dim[i][1];
        }
        
    }

    cout << fixed;
    cout << setprecision(3) << value << endl;
    

    return 0;
}