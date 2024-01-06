//https://leetcode.com/problems/largest-number/
//https://www.geeksforgeeks.org/given-an-array-of-numbers-arrange-the-numbers-to-form-the-biggest-number/
// convert int to string and then compare both string s ans s2 in s1+s2>s2+s1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;
// // custom sort function to sort int based on first digit
// bool compare(int &lvalue,int &rvalue)
// {
//     string str1=to_string(lvalue);
//     string str2=to_string(rvalue);
//     int len1=str1.length();
//     int len2=str2.length();
//     int comparisonnumber1=lvalue/pow(10,len1-1); 
//     int comparisonnumber2=rvalue/pow(10,len2-1);
//     //cout<<"comp1-"<<comparisonnumber1<<" comp2 "<<comparisonnumber2<<" lvalue "<<lvalue<<" rvalue "<<rvalue<<" len1 "<<len1<<" Len2 "<<len2<<endl;
//     if (comparisonnumber1>comparisonnumber2)
//     {
//        return true;
//     }
//     else
//     {
//         return false;
//     }
// }
bool compare(string &str1,string &str2)
{
    string A=str1+str2;
    string B=str2+str1;
    return A>B;
}
string largestNumber(vector<int> &nums)
{
    vector<string> num_in_strform;
    string largest_number_string;
    int zero_test=*max_element(nums.begin(),nums.end());
    if(zero_test==0)
    {
        largest_number_string.push_back('0');
        return largest_number_string;
    }
    else
    {
          
      for (int i = 0; i < nums.size(); i++)
      {
          num_in_strform.push_back(to_string(nums[i]));
      }
      sort(num_in_strform.begin(),num_in_strform.end(),compare);
      for(auto it:num_in_strform)
      {
        largest_number_string+=it;
      }
      return largest_number_string;

    }    
}
int main()
{
    vector<int> arr={3,30,34,5,9};
    string str=largestNumber(arr);
    cout<<str;
}