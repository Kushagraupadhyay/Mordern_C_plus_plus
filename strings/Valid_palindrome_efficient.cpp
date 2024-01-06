//https://leetcode.com/problems/valid-palindrome/
#include<iostream>
#include<string>
#include<ctype.h>// for is alnum function
#include<cstring>//for is upper and is lower functions
#include<algorithm>// for reverse function
using namespace std;
bool isPalindrome(string str)
{
    int i;
    for ( i = 0; i < str.length(); i++)
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
    int n=str.length()/2;
    int start=0;
    int end=str.length()-1;
    bool flag=true;
    cout<<"String "<<str<<" "<<n<<endl;
    for ( i = 0; i < n; i++)
    {
        if (str[start]!=str[end])
        { 
            flag=false;
            break;
        }
        start++;
        end--;
    }
    return flag;
}
int main()
{
   string str="race a car";
   if(isPalindrome(str))
   {
     cout<<str<<" is a palindrome";
   }
   else
   {
    cout<<str<<" is not a palindrome";
   }  
}