//https://leetcode.com/problems/valid-palindrome/
#include<iostream>
#include<string>
#include<ctype.h>// for is alnum function
#include<cstring>//for is upper and is lower functions
#include<algorithm>// for reverse function
using namespace std;
bool isPalindrome(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!isalnum(str[i]))
        {
            str.erase(str.begin()+i);
            i--;
        }
        else if (isupper(str[i]))
        {
            str[i]=tolower(str[i]);
        }
        else if (str[i]==' ')
        {
            str.erase(str.begin()+i);
        }
        
    }
    string str2=str;
    reverse(str2.begin(),str2.end());
    cout<<"string- "<<str<<endl;
    cout<<"reversestring- "<<str2<<endl;
    if (str2==str)
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
   string str="A man, a plan, a canal: Panama";
   if(isPalindrome(str))
   {
     cout<<str<<" is a palindrome";
   }
   else
   {
    cout<<str<<" is not a palindrome";
   }  
}