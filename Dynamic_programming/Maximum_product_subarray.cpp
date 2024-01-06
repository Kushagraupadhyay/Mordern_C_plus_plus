//https://www.geeksforgeeks.org/maximum-product-subarray/
//https://www.youtube.com/watch?v=lXVy6YWFcRM&ab_channel=NeetCode
// keep track of min as well with max as min is one negative miltiple away for being max
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int max_product(vector<int>& nums)
{
    int min_prod=1,max_prod=1,temp,result,max_temp,min_temp;
    result=*max_element(nums.begin(),nums.end());
    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]==0)
        {
            min_prod=1;
            max_prod=1;
        }
        else
        {
            temp=max_prod*nums[i];
            //max_temp=max(max_prod*nums[i],min_prod*nums[i]);
            //max_prod=max(max_temp,nums[i]);
            max_prod=max(max(max_prod*nums[i],min_prod*nums[i]),nums[i]);
            // min_temp=min(temp,min_prod*nums[i]);
            // min_prod=min(min_temp,nums[i]);
            min_prod=min(min(temp,min_prod*nums[i]),nums[i]);
            result=max(result,max_prod);
        }
    }
    return result;
}
int main()
{
    vector<int> nums={6, -3, -10, 0, 2}; 
    cout<<max_product(nums);   
    return 0;
}