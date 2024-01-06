// subsequence pick   dont pick method 1 - https://www.geeksforgeeks.org/print-subsequences-string/
// https://leetcode.com/problems/count-different-palindromic-subsequences/ 
// this solution runs out of memnory for large inputs, will  work
#include<iostream>
#include<string>
#include<algorithm>
#include<set>
using namespace std;
set<string> palindromeSet;
bool isPalindrome(string  subsequence)
{
    string strReverse = subsequence;
    reverse(strReverse.begin(),strReverse.end());
    if (strReverse==subsequence)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void subsequenceGenerator(string s,string subsequence)
{
    if (s.empty())
    {
        if (isPalindrome(subsequence)&& !subsequence.empty())
        {
            palindromeSet.insert(subsequence);
            //cout<<subsequence<<endl;
        }       
        return;
    }
    subsequenceGenerator(s.substr(1),subsequence+s[0]); // pick

    subsequenceGenerator(s.substr(1),subsequence); // dontpick
}

int countPalindromicSubsequences(string s)
{
    string subsequence= "";
    subsequenceGenerator(s,subsequence);
    return palindromeSet.size();
}

int main()
{
    string s="bccb";
    cout<<countPalindromicSubsequences(s);
    for(auto i:palindromeSet)
    {
        cout<<"-"<<i<<"-"<<endl;
    }
}