#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = { 1, 2, 3, 6, 5, 4 };
   // rotate(arr.begin(),arr.begin()+3,arr.end());
    next_permutation(arr.begin(),arr.end()); //  https://www.geeksforgeeks.org/permutations-of-a-given-string-using-stl/ 
    for(auto i:arr)     // https://www.geeksforgeeks.org/range-based-loop-c/     info on iterator for vector
    {
        cout<<i<<" ";
    }
    return 0;
}