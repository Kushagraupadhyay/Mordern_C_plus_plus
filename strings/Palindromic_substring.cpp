//https://www.youtube.com/watch?v=XYQecbcd6_c&ab_channel=NeetCode
// added counter to the longest palindrome code 
#include<iostream>
#include<string>
using namespace std;
int longestPalindrome(string s)
{
    int left,right;
    int current_length,maxlenth=0;
    int lmax,rmax;
    int count=0;
    string result;
    for (int i = 0; i < s.length(); i++)
    {
        left=right=i;
        //for odd palindrome - approach - start from i and expand on both left and right end
        while (left>=0 && right<s.length() && s[left]==s[right])
        {
            count++;
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
            count++;
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
    
    return count;
}
int main()
{
    string s="abc";
    cout<<longestPalindrome(s);
}