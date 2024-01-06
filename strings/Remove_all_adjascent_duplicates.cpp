//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
#include<iostream>
#include<string>
using namespace std;
string removeDuplicate(string s)
{
    for (int i = 0; i < s.length()-1; )
    {
        if (s.length()==0)
            break;
        
        if (s[i]==s[i+1])
        {
            s.erase(i,2);
            cout<<i<<" "<<s<<endl;
            if (i>0)
                i--;
            else if (i==0)
                continue;           
        }
        else
          i++;
    }
    return s;
}
int main()
{
    string s="aaaaaaaa";
    cout<<removeDuplicate(s);
}