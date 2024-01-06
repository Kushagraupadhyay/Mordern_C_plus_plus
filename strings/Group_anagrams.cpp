//https://github.com/keineahnung2345/leetcode-cpp-practices/blob/master/49.%20Group%20Anagrams.cpp
//https://www.youtube.com/watch?v=vzdNOK2oB2E&t=354s&ab_channel=NeetCode
//https://leetcode.com/problems/group-anagrams/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>  
using namespace std;
vector<vector<string>> groupAnagram(vector<string> &strs)
{
    
    vector<vector<string>> result;
    unordered_map<string,vector<string>> String_hashmap;
    char key='a';
    for(auto eachString:strs)
    {
        vector<int> name(26,0); // vector if size 26 with 0 value
        for(auto eachCharacter:eachString)
        {
            name[eachCharacter-'a']++;
        }
        string HashKey="";
        for(int i=0;i<26;i++)
        {
            if(name[i]>0)
            {
                HashKey+=to_string(name[i]);
                HashKey+=('a'+i);            // eat   key - 1a1e1t   value : eat , tea 
            }
        } 
        String_hashmap[HashKey].push_back(eachString);             
    }
    int j=0;
    for(auto eachKey:String_hashmap)
    {
        result.push_back(eachKey.second);
    }

    return result;
}
int main()
{
    vector<string> strs= {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result=groupAnagram(strs); 
     for (auto& row : result) {
        for ( auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

}