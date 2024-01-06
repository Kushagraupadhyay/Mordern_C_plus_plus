//https://www.youtube.com/watch?v=QM0klnvTQzk&ab_channel=Pepcoding
//https://leetcode.com/problems/subarray-sums-divisible-by-k/
// if we have a mod%k as 3 for ex and we find another mode%k=3 instance , if we subtract that from one another the reamaining subarray mod%k=0 hence divisible
//negative mod need to be converted to positive before addition in map
//     for ex - {2,-6, 3, 1,2,8,2,1}
//     k=7- n%k= 2,-4,-1, 0,2,3,5,6
//(((n%k)+k)%k)= 2, 3(1), 6 ,0,2,3(2),5,6   
// we have not 2 occurances of 3 , if we remove the first subarry, the remaining subarray will be divisible by7   
#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<map>
using namespace std;
int subarraySum(vector<int> &nums,int k)
{
  unordered_map<int,int> allsum_map;
  int count=0;
  int current_sum=0;
  for (int i = 0; i < nums.size(); i++)
  {
     current_sum+=nums[i];
     int mod= ((current_sum%k)+k)%k; // the +k)%k is to make negative mod to positive 
     if (mod==0)
     {
        count++;
     }
     allsum_map[mod]++;
     count+=(allsum_map[mod]-1); 
  }
  return count;
}
int main()
{
    vector<int> arr={4,5,0,-2,-3,1};
    int k= -10;    
    cout<<subarraySum(arr,k);
}