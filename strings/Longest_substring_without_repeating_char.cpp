//https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Sliding window
//https://www.youtube.com/watch?v=wiGpQwVHdE0&ab_channel=NeetCode
// keep removing the string[left] element from set until the string [right] element is removed
//https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/3.%20Longest%20Substring%20Without%20Repeating%20Characters.cpp
#include<iostream>
#include<string>
#include<set>
using namespace std;
int length_of_longest_substring(string s)
{
    set<char> char_set;
    int left=0;
    int right=0;
    int max_subarray_length=0;
    int current_length=0;
    int n=s.length();
     while( left<n && right<n)
    {
        if (char_set.find(s[right])==char_set.end())
        {
            cout<<"Inserting "<<s[right]<<endl;
            char_set.insert(s[right]);
            current_length=right-left+1;
            max_subarray_length=max(max_subarray_length,current_length);
            right++;
        }
        else
        {
           cout<<"removing "<<*char_set.begin()<<endl;
           char_set.erase(s[left]); // because elements are in sorted order in set , we need to remove set[s[left]] and not set[0]
           //if we remove set 0 it will remove the wrong element
           left++;
        }       
        
    }
    
  return max_subarray_length;
}
int main()
{
    string s= "ynyo";
    cout<<length_of_longest_substring(s);
}