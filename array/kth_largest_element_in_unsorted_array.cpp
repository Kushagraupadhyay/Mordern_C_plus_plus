//https://www.geeksforgeeks.org/kth-smallest-largest-element-in-unsorted-array/
#include<iostream>
#include<vector>
#include<stdint.h>
using namespace std;

int findKthLargest(vector<int>& arr, int k)
{
    int largest,pos;
    int n=arr.size();
    int i;
    while(k>=2)
    {
     for(int j=0;j<k-1;j++)
    {
        largest=INT8_MIN;
        for(i=0;i<n;i++)
        {
            if(arr[i]>largest)
            {
                largest=arr[i];
                pos=i;
            }           
        }
        arr.erase(pos);
        k--;
    }
    }

    largest=INT8_MIN;
        for(i=0;i<n;i++)
        {
            if(arr[i]>largest)
            {
                largest=arr[i];
                pos=i;
            }           
        }
    return largest;
}

int main()
{
  vector<int> arr = {12, 3, 5, 7, 19};
  int k=4;
  cout<<findKthLargest(arr,k);
//   set<int> sset(arr.begin(),arr.end());
//   set<int>::iterator itr=sset.begin();
//   advance(itr,k-1);
//   cout<<"Kth smallest element"<<*itr;
  return 0;
}