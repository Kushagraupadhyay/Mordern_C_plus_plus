#include<iostream>

using namespace std;

void permute(string a,int l,int r)
{
    if(l==r)
    {
        cout<<a<<" ";
    }

    for (int i=l;i<=r;i++)
    {
        int temp=a[i];
        a[i]=a[l];
        a[l]=temp;

        permute(a,l+1,r);

    }
}

int main()
{
    string str ="123456";
    int n = str.size();
    permute(str,0,n-1);

    return 0;
}