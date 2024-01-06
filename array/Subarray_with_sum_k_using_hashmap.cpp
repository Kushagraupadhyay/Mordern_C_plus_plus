//https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
//https://www.geeksforgeeks.org/number-subarrays-sum-exactly-equal-k/
// best solution in github link
// currentsum= k + (sum-K)
// so if sum-K exists in our map then we have found subarray
// add count of sum-k to total count on match - if count is 2 then add 2 for a single match og sum-k
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<map>
using namespace std;
int subarraySum(vector<int> &nums,int k)
{
   map<int,int> m_allsums; // all deafault value for key is 0
   // can also use unordered_map here with no further change required to existing code
   // for faster insertion an seach speeds
   int count=0,current_sum=0;
   for (int i = 0; i < nums.size(); i++)
    {
        current_sum+=nums[i];
        if (current_sum==k)
        {
            count++;
        }  
        count+=m_allsums[current_sum-k]; // is value does not exist then value for key will be 0
        m_allsums[current_sum]++;// all deafault values for all keys is 0 so incrementing that    
    }
    return count;
}
int main()
{
    vector<int> arr={10 , 2, -2, -20, 10};
    int k= -10;
    
    
    cout<<subarraySum(arr,k);
}