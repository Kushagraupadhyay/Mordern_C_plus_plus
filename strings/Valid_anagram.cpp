//https://www.geeksforgeeks.org/check-whether-two-strings-are-anagram-of-each-other/
//https://leetcode.com/problems/valid-anagram/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool isAnagram(string s,string t)
{
   sort(s.begin(),s.end());
   sort(t.begin(),t.end());
   if (s==t)
   {
     return true;
   }
   else
   {
    return false;
   }  
}
int main()
{
    string s="anagram",t="nagaram";
    if (isAnagram(s,t))
    
        cout<<s<<" and "<<t<<" are anagrams";
    else
        cout<<s<<" and "<<t<<" are not anagrams";
       
}