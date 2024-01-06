// https://www.geeksforgeeks.org/next-permutation/ 
// use above link for login revision
//https://leetcode.com/problems/next-permutation/
#include<bits/stdc++.h>

using namespace std;

void nextPermutation(vector<int>& arr)
{
    int n= arr.size(),i,j;

    for ( i = n-2; i >= 0; i--)
    {
        if (arr[i]<arr[i+1])
        {
            break;       // i will stop at pivot, which breaks the inncreasing order from the right to left
        }
    }
    
    if(i<0)
    {
        reverse(arr.begin(),arr.end());
    }

    else
    {
        for( j=n-1;j>i;j--)
        {
            if(arr[j]>arr[i])
            {
                break;
            }
        }

        swap(arr[i],arr[j]);
        reverse(arr.begin()+i+1,arr.end());
    }
    
}

int main()
{
    vector<int> arr = { 1, 2, 3, 6, 5, 4 };
    nextPermutation(arr);

    int n= arr.size();
    
    for ( int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    // cout<<"Hi";
    // for (auto i : arr) {
    //     cout << i << " ";
    // }

    return 0;
}

