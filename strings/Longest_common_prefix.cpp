//https://leetcode.com/problems/longest-common-prefix/
//
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string longestCommonPrefix(vector<string> &strs)
{
  int number_of_strings=strs.size();
  string common_prefix=strs[0];
  for (int i = 0; i < number_of_strings-1; i++)
  {
    int common_length = min(strs[i].length(),strs[i+1].length());
    int common_prefix_size = common_prefix.length();
    int common_length_including_prefix= min(common_prefix_size,common_length);
    int common_substring=0;
    if (common_prefix.length()==0) // is common prefix goes zero then no need to check further
        {
            break;
        }
    for (int j = 0; j < common_length_including_prefix; j++)
    {
        if (common_prefix[j] ==strs[i][j] && common_prefix[j] ==strs[i+1][j] )
        {
            common_substring++;
        }
        else if (common_prefix[j] != strs[i][j] || common_prefix[j] != strs[i+1][j] )
        {
            break;
        }     
    }
    if (common_substring==0)
    {
        string str="";
        return str;
    }
    else
    {
        common_prefix.erase(common_prefix.begin()+common_substring,common_prefix.end());
    }  
  }
  return common_prefix;
}
int main()
{
    vector<string> strs={"flower","flower","flower","flower"};
    cout<<longestCommonPrefix(strs);
}