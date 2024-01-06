//https://leetcode.com/problems/longest-palindromic-substring/
//https://www.youtube.com/watch?v=XYQecbcd6_c&ab_channel=NeetCode
#include<iostream>
#include<string>
using namespace std;
string longestPalindrome(string s)
{
    int left,right;
    int current_length,maxlenth=0;
    int lmax,rmax;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        left=right=i;
        //for odd palindrome - approach - start from i and expand on both left and right end
        while (left>=0 && right<s.length() && s[left]==s[right])
        {
            current_length=right-left+1;
            if (current_length>maxlenth)
            {
                lmax=left;
                rmax=right;
                maxlenth=current_length;
            }
            left--;
            right++;
        }
        // for even palindrome
        left=i;
        right=i+1;
        while(left>=0 && right<s.length() && s[left]==s[right])
        {
            current_length=right-left+1;
            if (current_length>maxlenth)
            {
                maxlenth=current_length;
                lmax=left;
                rmax=right;
            } 
            left--;
            right++;    
        }
        
    }

    for (int j = lmax; j <= rmax; j++)
    {
        result+=s[j];
    }
    
    return result;
}
int main()
{
    string s="cbbd";
    cout<<longestPalindrome(s);
}