//https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/
#include<iostream>
#include<string>
#include<map>
using namespace std;
void printDuplicates(string str)
{
    map<char,int> duplicate_count_map;
    for (int i = 0; i < str.length(); i++)
    {
        duplicate_count_map[str[i]]++;        
    }
    for(auto map_iterator:duplicate_count_map)
    {
        if (map_iterator.second>1)
            cout<<map_iterator.first<<" count "<<map_iterator.second<<endl;
        else
            continue;
    }
}
int main()
{
    string str="test string";
    printDuplicates(str);
    }