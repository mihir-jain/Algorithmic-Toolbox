#include <iostream>
using namespace std;

void mergesort(int ar[], int l, int r);
void merge(int ar[], int l, int m, int r);
void majority(int ar[], int n);

int main(void)
{
    int n, i;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    mergesort(ar, 0, n-1);
    //for(i=0;i<n;i++)
    //cout<<ar[i]<<" ";

    majority(ar, n);
    return 0;
}

void mergesort(int ar[], int l, int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergesort(ar, l, m);
        mergesort(ar, m+1, r);
        merge(ar, l, m, r);
    }
    return;
}

void merge(int ar[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    int i, j, k;
    for(i=0;i<n1;i++)
    L[i] = ar[l+i];
    for(i=0;i<n2;i++)
    R[i] = ar[m+1+i];
    k = l;
    i = 0, j =0;
    while(i<n1 && j<n2)
    {
        if(L[i]< R[j])
        {
            ar[k] = L[i];
            k++;
            i++;
        }
        else
        {
            ar[k] = R[j];
            k++, j++;
        }
        
    }
    while(i<n1)
    {
        ar[k] = L[i];
        k++, i++;
    }
    while(j<n2)
    {
        ar[k] = R[j];
        k++, j++;
    }
}

void majority(int ar[], int n)
{
    int count = 1;
    int i = 0;
    int x = ar[0];
    bool flag = false;
    for(i=1;i<n;i++)
    {
        if(x==ar[i])
        {
            count++;
            if(count>(n/2))
            {
                cout<<"1"<<"\n";
                flag = true;
                break;
            }
        }
        else
        {
            count = 1;
            x = ar[i];
        }
        
    }
    if(flag == false)
    cout<<"0\n";

}