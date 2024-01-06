#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void printarray(int arr[] ,int size)
{
    int i;
    for (i=0;i<size;i++)
    {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void reversearray(int arr[],int start, int end)
{
    if (start>=end)
    return ;

    int temp=arr[start];
    arr[start]=arr[end];
    arr[end]=temp;
    reversearray(arr,start+1,end-1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    printarray(arr,n);
    reversearray(arr,0,n-1);
    printarray(arr,n);
    return 0;
}