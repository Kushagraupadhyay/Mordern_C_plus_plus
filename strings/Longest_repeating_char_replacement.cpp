// https://leetcode.com/problems/longest-repeating-character-replacement/
// https://www.youtube.com/watch?v=gqXU1UyA8pk&ab_channel=NeetCode
// insert in hashmap then check if window is valid before updating the result
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int characterReplacement(string s,int k)
{
    int left,right;
    int inser_char_count=0;
    int max_repeating_char_count_in_window =0;
    char current_max_repeating_char_in_window;
    int Longest_subarray = 0;
    unordered_map<char,int> char_count_map;
    for(left=0,right=0;right<s.length();)
    {
        char_count_map[s[right]]++; //insertion in hashmap
        cout<<"Inserting "<<s[right]<<" to window"<<"index "<<right;
        if (char_count_map.find(s[right])->second > max_repeating_char_count_in_window)
        {
            current_max_repeating_char_in_window=s[right]; // keeping track of max character
        }
        
        max_repeating_char_count_in_window=max(max_repeating_char_count_in_window,char_count_map.find(s[right])->second);
        cout<<"Max count "<<max_repeating_char_count_in_window<<endl;
        while ((right-left+1-max_repeating_char_count_in_window) > k) // make sure window is valid before updating the result
        {
            //char_count_map[s[left]]--;
            char_count_map.find(s[left])->second--;
            // decrementing max is not mandatory in this case , for explanation as to why watch the linked youtube video
            cout<<"Removing "<<s[left]<<" from window"<<"index "<<left<<endl; 
            left++;
        }
        Longest_subarray=max(Longest_subarray,right-left+1);
        right++;
    } 
        
   return Longest_subarray;
}
int main()
{
    string s="BAAA";
    int k=0;
    cout<<characterReplacement(s,k);
}
