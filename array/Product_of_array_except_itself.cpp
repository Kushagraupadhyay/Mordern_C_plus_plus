// Product of Array except itself
#include<iostream>
#include<vector>
using namespace std;
auto Product_except_self(vector<int> nums)
{
    vector<int> product;
    int all_multiple=1,i;
    int insert_value,count=0;
    for (i = 0; i < nums.size(); i++)
    {
        if(nums[i]!=0)
        {
            all_multiple*=nums[i];
        }
        else if(nums[i]==0)
        {
            count++;
        }
    }
    for(i=0;i<nums.size();i++)
    {
       // if multiple zeros in array
       if (count>1)
       {
        insert_value=0;
        product.push_back(insert_value);
       }
       // if only one zero
       if (count==1)
       {
          if(nums[i]!=0)
         {
          insert_value=0;
          product.push_back(insert_value);
         }
         else if(nums[i]==0)
         {
          insert_value=all_multiple;
          product.push_back(insert_value);
         }
          
       }
       // for no zeros in the array
       if(count==0)
       {
        insert_value=all_multiple/nums[i];
        product.push_back(insert_value);
       }
       
    }

    return product;   

}
int main()
{
    vector<int> nums = {10, 3, 5, 6, 2};
    auto answer = Product_except_self(nums);
    for (int i = 0; i < answer.size(); i++)
    {
        cout<<answer[i]<<" ";
    }
    
}