// mix and max element of an arrayy using brute force implementation
#include<iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair getminmax(int arr[],int n)
{
    struct Pair minmax;
    int i;
    if(n==1)
    {
        minmax.min=arr[0];
        minmax.max=arr[0];
    }

    if (arr[0]>arr[1])
    {
        minmax.min=arr[1];
        minmax.max=arr[0];
    }
    else
    {
        minmax.min=arr[0];
        minmax.max=arr[1];
    }

    for ( i = 0; i < n; i++)
    {
        if (arr[i]>minmax.max)
        {
            minmax.max=arr[i];
        }
        else if (arr[i]<minmax.min)
        {
            minmax.min=arr[i];
        }
    }

    return minmax;
}

int main()
{
    int arr[] = { 1000, 11, 445, 1, 330, 3000 };
    int arrsize=1;
    struct Pair minmax = getminmax(arr,arrsize);
    cout<<minmax.max<<endl<<minmax.min;

    return 0;
}