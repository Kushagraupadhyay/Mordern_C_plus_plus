// https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/ 
// this method creates another array so space complexity is also O(n) . 
#include<bits/stdc++.h>
using namespace std;

int firstMissingPos(vector<int>& arr)
{
    int n=arr.size();
    bool mark[n+1]={false};
    int i;
    for ( i=0;i<n;i++)
    {
        if(arr[i]>0 && arr[i]<=n)
        { 
            mark[arr[i]]= true;
        }
    }
    for( i=0;i<n;i++)
    {
        if(mark[i]== true)
        break;
    }

    return i;
}

int main()
{
   vector<int> arr = { 0, 10, 2, -10, -20 , 1};
   cout<<firstMissingPos(arr);
    return 0;
}