//https://www.geeksforgeeks.org/given-a-sorted-and-rotated-array-find-if-there-is-a-pair-with-a-given-sum/?ref=lbp
#include<iostream>
#include<vector>
using namespace std;
int find_rotation_index(vector<int> &nums , int l, int r)
{
    int mid=(l+r)/2;
    if(l>r)
    {
        return -1;
    }
    if(nums[mid]>nums[mid+1])
    {
        return mid;
    }
    else if(nums[l]>nums[mid]) //left side unsorted
    {
        return find_rotation_index(nums,l,mid);
    }
    else
    {
        return find_rotation_index(nums,mid+1,r);
    }
}
bool pair_search_in_sorted_rotated(vector<int> &nums,int pivot,int n,int x)
{
    int left = pivot+1;
    int right = pivot;
    while (left!=right) // keep moving left or right until they meet
    {
        if (nums[left]+nums[right]==x)
        {
            return true;
        }
        
        if (nums[left]+nums[right]>x)
        {
            right=(right-1+n)%n;
        }
        else
        {
            left=(left+1)%n;
        } 
    }
    return false;
}
int main()
{
    vector<int> arr={ 11, 15, 6, 8, 9, 10 };
    int pivot,n;
    n=arr.size();
    int pairSum=16;
    if(arr[0]<arr[n-1]) //checking if array is already sorted
    {
        pivot=n-1;
    }
    else
    {
       pivot= find_rotation_index(arr,0,arr.size()-1); // for rotated array
    }

    if (pair_search_in_sorted_rotated(arr,pivot,n,pairSum))
    {
        cout<<"Pair exists";
    }
    else
    {
        cout<<"Pair do not exist";
    }     
    return 0;
}