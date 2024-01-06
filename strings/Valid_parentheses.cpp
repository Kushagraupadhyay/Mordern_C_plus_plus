//https://leetcode.com/problems/valid-parentheses/
//https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/
#include<iostream>
#include<string>
#include<map>
#include<stack>
using namespace std;
bool isValid(string s)
{
    map<string,string> bracket_map={{")","("},{"}","{"},{"]","["}};
    stack<char> bracket_stack;
    for (int i = 0; i < s.length(); i++)
    {
        if (bracket_stack.empty())
            bracket_stack.push(s[i]);        
        else if ( s[i]=='(' || s[i]=='{' || s[i]=='[' )
            bracket_stack.push(s[i]);
        else if ( (s[i]==')'&& bracket_stack.top()=='(') || (s[i]=='}'&& bracket_stack.top()=='{') || (s[i]==']'&& bracket_stack.top()=='[') )
            bracket_stack.pop();
        else if ( (s[i]==')'&& bracket_stack.top()!='(') || (s[i]=='}'&& bracket_stack.top()!='{') || (s[i]==']'&& bracket_stack.top()!='[') )
            return false;       
    }
    if (bracket_stack.empty())
        return true;
    else
        return false;    
}

int main()
{
    string s="()[]{}";
    if (isValid(s))
       cout<<"Bracket string is valid";
    else
       cout<<"Bracket  string is invalid";
    
}