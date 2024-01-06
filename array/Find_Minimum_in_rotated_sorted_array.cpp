#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int partition_function(vector<int> &nums,int l,int r)
{
    int mid=(l+r)/2;

    if(l>r)
    {
        return -1;
    }
    else 
    if (nums[mid]>nums[mid+1])
    {
        return mid;
    }
    
    else if(nums[l]<nums[mid])  // for sorted left partition
    {
      return partition_function(nums,mid+1,r);
    }
    else //if(nums[l]>nums[mid])
    {
      return  partition_function(nums,l,mid);
    }
}
int find_Minimum(vector<int>& nums)
{   
    int n=nums.size();
    if(nums[0]<nums[n-1])
    {
        return nums[0];
    }
    else if (n==1)
    {
        return nums[0];
    }
    
    else if(n>=2)
    {
      
      int partition_point=partition_function(nums,0,n-1);
      return nums[partition_point+1];
    }
    
}
int main()
{
    //vector<int> arr={4,5,6,7,0,1,2};
    vector<int> arr={2,3,4,5,1};
    cout<<find_Minimum(arr);
    return  0;
}