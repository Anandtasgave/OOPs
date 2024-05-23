#include<iostream>
using namespace std;

int main()
{
    int n,i,c=0,v;

    cin>>n;

    int a[n],b[n];
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }

    cin>>v;

    for(i=0;i<n;i++)
    {
        if(a[i]!=v)
        {
            b[i]=a[i];
        }
        else
        {
            continue;
        }
    }

	for(i=0;i<n;i++)
    {
        cout<<b[i];
    }
}
