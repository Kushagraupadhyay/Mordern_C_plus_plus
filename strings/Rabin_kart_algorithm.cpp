#include<iostream>
#include<vector>
#include<math.h>
int oldHash;
int oldChar;
using namespace std;
int createHash_pattern(string str,int left,int right)
{
    int x=0;
    int prime=101;
    for (int i = left; i < right ; i++)
    {
        x+=str[i]*pow(prime,i);
    }
    oldChar=str[left];
    oldHash=x;
    return x;
}
int createHash_searchText(string str,int left,int right)
{
   int  prime=101;  //  you  can  choose any prime number for your hash function
   int  x=0;
   
   x=oldHash-oldChar; // for first occurance comparison
   x=x/prime;
   for (int i = left+1; i < right; i++)
   {
    //cout<<"x value "<<x<<endl;
     x+=str[i]*pow(prime,i);
   }
   oldHash=x;
   oldChar=str[left];
   //cout<<"pat  hash "<<x<<"  ";
   return  x; 
}

int robinKarp(string searchtext,string pattern)
{
   int st_size=searchtext.size();
   int pat_size=pattern.size();
   int pat_hash=createHash_pattern(pattern,0,0+pat_size,1);
   vector<int> searchtext_hash;
   oldHash=0; // generating hash for pattern would have updated these values to setting back to zero
   oldChar=0;
   searchtext.push_back(createHash_pattern(searchtext,0,0+pat_size));
   for (int i = 1; i < st_size-pat_size; i++)
   {
        
   }
   
    
    return 0;
   
}
int main()
{
    string searchtext="sadbutsadnotreallysad";
    string pattern="abe";
    cout<<"Index of first occurence of sad "<<robinKarp(searchtext,pattern);
}