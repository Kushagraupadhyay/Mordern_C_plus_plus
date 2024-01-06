//https://www.youtube.com/watch?v=3ZDZ-N0EPV0&ab_channel=TusharRoy-CodingMadeSimple
//https://leetcode.com/problems/wildcard-matching/
//https://www.geeksforgeeks.org/wildcard-pattern-matching/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool isMatch(string s,string p)
{
    int i=0;
    string emptyString="";
    // first combine multiple *** to a single * as logically they are the same
    while (i < p.size()-1 && p!=emptyString) 
    {
        if (p[i]=='*' && p[i+1]=='*')
        {
            p.erase(i+1,1);
            //cout<<"removing "<<i+1<<" "<<p<<" "<<p.size()<<endl;
        }
        else
        {
          i++;
        }
    }
    //cout<<p<<endl;
    int rows=s.size()+1;
    int column=p.size()+1;
    //cout<<rows<<" "<<column<<endl;
    vector<vector<bool>> Table(rows,vector<bool>(column,false)); // initializing default value as false
    Table[0][0]= true; 
    if (p[0]=='*' && p!=emptyString)
    {
        Table[0][1]=true; // the only condition when * is true with NULL (0) is when the pattern starts with *  
    }   
      // first row and first column are reserves for null string computation, string com starts from index 1 
    for ( i = 1; i <=s.size(); i++)
    {
        for (int j = 1; j <= p.size(); j++)
        {
            // if both elements are equal or one is string is x(any value) and pattern is '?' then 
            // remove last digits both from string and pattern , while leaves us with a same string pattern combo of i-i and j-1
            if (s[i-1]==p[j-1] || p[j-1]=='?')
            {
                Table[i][j]=Table[i-1][j-1];
            }
            //for * we try one NULL combo and one where not null , the not null further breaks into null and not null and so on
            // as we cover both the left and right value
            else if (p[j-1]=='*')
            {
                Table[i][j]= Table[i-1][j] || Table[i][j-1];
            }
            else
            {
                Table[i][j]=false;
            }     
        }    
    }
    // // printing result matrix
    // for ( i = 0; i <=s.size(); i++)
    // {
    //     for (int j = 0; j <= p.size(); j++)
    //     {
    //         cout<<Table[i][j]<<" ";     
    //     }  
    //     cout<<endl;  
    // }
    
    return Table[s.size()][p.size()];

}
int main()
{
    // string s="baaabab";
    // string p="*****ba*****ab";
    // string s="XAYLMZ";
    // string p="X?Y*Z";
    string s="";
    string p="";
    cout<<isMatch(s,p);
}