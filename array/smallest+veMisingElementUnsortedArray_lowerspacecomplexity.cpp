https://www.geeksforgeeks.org/find-the-smallest-positive-number-missing-from-an-unsorted-array/
#include <bits/stdc++.h>

using namespace std;

int findMissingPos(vector<int> &arr)
{
  int n=arr.size();
  int i;
  for(i=0;i<n;i++)
  {
    while(arr[i]>0 && arr[i]<=n && arr[i]!=arr[arr[i]-1])
    {
        swap(arr[i],arr[arr[i]-1]);
    }
  }

  for(i=0;i<n;i++)
  {
    if(arr[i]!= i+1)
    {
        break;
    }
  }
  return i+1;
}

int main()
{
    vector<int> arr ={ 0,10,2,-10,-20 } ;
    cout<<findMissingPos(arr);
    return 0;
}