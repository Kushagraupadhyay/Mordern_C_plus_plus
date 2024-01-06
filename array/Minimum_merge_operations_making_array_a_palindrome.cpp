//https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/

#include<iostream>
#include<vector>
using namespace std;
int minimum_merge_operations(vector<int> &arr)
{
    int n=arr.size(); //for 2 pointer method
    int ans=0;
    //for(int i=0,j=n-1;i<=j;)
    int i=0;
    int j=n-1;
    while (i<=j)    
    {
        if (arr[i]==arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i]>arr[j])
        {
            j--;
            arr[j]+=arr[j+1];
            ans++;
        }
        else 
        {
            i++;
            arr[i]+=arr[i-1];
            ans++;
        }             
    }
    
    return ans;
}
int main()
{
    vector<int> arr={1, 4, 5, 9, 1};
    cout<<"Hi"<<minimum_merge_operations(arr);
    return 0;
}