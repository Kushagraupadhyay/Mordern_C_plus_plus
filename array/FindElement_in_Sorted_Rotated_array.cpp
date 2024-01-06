// relies on login - if we divide a sorted rotated array into 2 parts, if one mart is unsorted that the other part have to be sorted
#include<bits/stdc++.h>

using namespace std;

int findElementIndex(vector<int> &arr,int key,int left,int right)
{
    if (left>right)
    {
        return -1;
    }

    int mid = (left+right)/2;
    if(arr[mid]==key)
    {
        return mid;
    }
    
    if(arr[left]<arr[mid]) // if first half is sorted
    {
          if(key>=arr[left] && key<arr[mid])
          {
            return findElementIndex(arr,key,left,mid-1); // cehck the key in sorted first half
          }
          else
          {
            return findElementIndex(arr,key,mid+1,right);
          }
    }
    else // when first half of array is unsorted 
    {
        if(key<=arr[right] && key>arr[mid])     
        {
            return findElementIndex(arr,key,mid+1,right);      // then we can check the other sorted half 
        }
        else 
        {
            return findElementIndex(arr,key,left,mid-1);
        }

    }

} 

int main()
{
     vector<int> arr ={ 5, 6, 7, 8, 9, 10, 1, 2, 3};
     int key=3;
    // cout<<"Enter element to be searched";
    // cin>>key;
     int n = arr.size();
     int i = findElementIndex(arr,key,0,n-1);
     cout<<"position "<<i;
    return 0;
}