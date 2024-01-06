//https://leetcode.com/problems/3sum/solutions/
// this code works for array that has no duplicates
#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<set>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    set<vector<int>> answer;
    vector<vector<int>> answer_in_2d_vector_form;
    unordered_set<int> s;
    int i,j,l,search_key,n=nums.size();
    for ( l = 1; l < n; l++)
    {
        s.insert(nums[l]);
    }
    
    for(i=0;i<n-2;i++) // fixing the first element
    {
        for(j=i+1;j<n;j++)
        {
            search_key=0-(nums[i]+nums[j]);
            if (s.find(search_key)==s.end()) // searaching in unordered set
            {
                continue;    // continue the loop is element not found
            }
            else
            {
                if (  nums[j]!=search_key && nums[i]!=search_key) //nums[i]!=nums[j] &&
                {
                    vector<int> insert_vector= {nums[i],nums[j],search_key};
                    sort(insert_vector.begin(),insert_vector.end());
                    answer.insert(insert_vector);    // inserting result in set to prevent duplicates                
                }     
            }
            
        }
    }
    int count = 0; // adding edge case for zero values
    for(i=0;i<n;i++)
    {
        if (nums[i]==0)
        {
            count++;
        }
        
    }
    if (count>=3)
    {
       vector<int> insert_vector= {0,0,0};
       sort(insert_vector.begin(),insert_vector.end());
       answer.insert(insert_vector);
    }
    

    for (auto& vec : answer) 
    {
        answer_in_2d_vector_form.push_back(vec);
    }       
    return answer_in_2d_vector_form;    
}
int main()
{
  vector<int> arr={-1,0,1,0};
  int sum=22;
  vector<vector<int>> result=threeSum(arr);
  for(auto& vec:result)
  {
    cout<<"[";
    for(auto& values:vec)
    {
        cout<<values<<",";
    }
    cout<<"]"<<endl;
  }
}