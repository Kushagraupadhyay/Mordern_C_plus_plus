//https://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/
//combination using backtracking
#include<iostream>
#include<vector>
using namespace std;
vector<vector<int>> result; // declaring result vector as global
void generateCombinations(vector<int> &arr,vector<int> &data,int r,int n,int insert_index, int insert_element_index)
{
    if (insert_index==r)
    {
        result.push_back(data);  
        return;
    }
    if(insert_element_index>=n)
    {
      return;
    } 
    data[insert_index]=arr[insert_element_index];
    generateCombinations(arr,data,r,n,insert_index+1,insert_element_index+1);

    generateCombinations(arr,data,r,n,insert_index,insert_element_index+1);   
}
vector<vector<int>> combine(int n,int r)
{
    vector<int> arr;

        for(int i = 0; i < n; i++)
       {
          arr.push_back(i+1);
       }
       vector<int> data;
       for (int i = 0; i < r; i++)
       {
           data.push_back(0);
       }
       
       generateCombinations(arr,data,r,n,0,0);
    
    return result;
}
int main()
{   
    int n=1;
    int r=1;
    combine(n,r);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++)
            cout << result[i][j] << " ";
        cout << endl;
    }
}