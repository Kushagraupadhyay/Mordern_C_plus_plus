//https://www.youtube.com/watch?v=JoF0Z7nVSrA&ab_channel=NeetCode
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// we ar4e using KMP algorithm here to find LPS and use LPS(longest prefix suffix) to find the needle 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
int strStr(string haystack,string needle)
{
    vector<int> lps(needle.length(),0); // default value in lps is 0
    int i=1; // lps[0] will always be 0 to that prefix and suffix are always one length less than string
    int prevLPS=0; // to store position of previous value of largest prefix that is also a suffix
    if (needle == "") // case when needle is empty string
    {
        return 0;
    }    
    while (i<needle.length())
    {
        if (needle[i]==needle[prevLPS])
        {
            lps[i]=prevLPS+1;
            prevLPS++;
            i++;
        }
        else if (prevLPS==0)
        {
            lps[i]=0;
            i++;
        }
        else
        {
            prevLPS=lps[prevLPS-1];
        }      
    }
    for(auto itr:lps) // printing LPS array
    {
        cout<<itr<<":";
    }
    cout<<endl; 
    i=0;
    int j=0;
    while (i<haystack.length())
    {
        if (haystack[i]==needle[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j==0)
            {
                i++;
            }
            else
            {
                j=lps[j-1];
            }
            
        }

        if (j==needle.length()) //when all elments in needle match with haystack that is the only occurance where j will equal needle's length
        {
            return i-needle.length();
        }   
        
    }   

    return -1;
}
int main()
{
    string haystack="sadbutsad";
    //string needle="sad";
    string needle="AAACAAAAAC";
    cout<<"Index of first occurence of sad "<<strStr(haystack,needle);
}