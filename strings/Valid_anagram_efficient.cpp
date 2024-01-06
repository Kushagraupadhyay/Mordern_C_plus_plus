// https://leetcode.com/problems/valid-anagram/
// using hashmap 
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool isAnagram(string s,string t)
{
   map<string,int> str1_map,str2_map;
   int i;
   if (s.length()!=t.length())
   {
      return false;
   }
   
   for ( i = 0; i < s.length(); i++)
   {
     str1_map[to_string(s[i])]++;
     str2_map[to_string(t[i])]++;
   }
   int n=str1_map.size();
   map<string,int>::iterator itr,itr2;
   for(itr=str1_map.begin(),itr2=str2_map.begin();itr!=str1_map.end(),itr2!=str2_map.end();itr++,itr2++)
   {
    //   cout<<"Key "<<itr->first<<" value "<<itr->second<<endl;
    //   cout<<"Key "<<itr2->first<<" value "<<itr2->second<<endl;
      if (itr->second!=itr2->second || itr->first!=itr2->first)
      {
        return false;
      }
            
   } 
   return true;
}
int main()
{
    string s="rat",t="car";
    if (isAnagram(s,t))
    
        cout<<s<<" and "<<t<<" are anagrams";
    else
        cout<<s<<" and "<<t<<" are not anagrams";
}