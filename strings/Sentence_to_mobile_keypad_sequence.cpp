//https://www.geeksforgeeks.org/convert-sentence-equivalent-mobile-numeric-keypad-sequence/
// use asci value of finding index of array with numbers 
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string printSequence(vector<string> &str,string &input)
{
    string result;
    //int position;
    int n=input.length();
    for (int i = 0; i < n; i++)
    {
        if (input[i]==' ')
            result+="0";
        else
        {
            int position = input[i] - 'A';
            result+=str[position];
        }
            
    }
    
    return result;

}
int main()
{
    vector<string> str={"2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999"};     
            // ascii value of any char - ascii value of A = position of that char in str
    string input="GEEKS FORGEEKS";
    cout<<printSequence(str,input);
}
