#include<iostream>
#include<vector>
#include<set>
#include<bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> arr = {3,2,1,5,6,4};
  int k=2;
  sort(arr.begin(),arr.end());
  // // the below code removes duplicate instances
  // vector<int>::iterator itr;
  // for(auto itr=arr.begin();itr<arr.end();itr++)
  // {
  //   if(*(itr+1)==*itr)
  //   {
  //      arr.erase(itr);
  //   }
  // }
  // // the below instance uses above iterator to print the vector
  // for(auto itr=arr.begin();itr<arr.end();itr++)
  // {
  //   cout<<*itr<<endl;
  // }

  int Kth_largest = arr.size()-k; 
  cout<<arr[Kth_largest];

//   set<int> sset(arr.begin(),arr.end());
//   set<int>::iterator itr=sset.begin();
//   advance(itr,k-1);
//   cout<<"Kth smallest element"<<*itr;
}