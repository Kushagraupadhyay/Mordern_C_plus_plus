#include<iostream>
#include<vector>
using namespace std;
vector<int> repeatedNumbers(const vector<int> &arr)
{
    int a,b;
    int n=arr.size();
    vector<int> marker(n,0);
    for(int i=0;i<n;i++)
    {
        if(marker[arr[i]-1]==0)
        {
            marker[arr[i]-1]=1;
        }
        else if(marker[arr[i]-1]==1)
        {
            a=arr[i];
        }
    }
    for(int i=0;i<n;i++)
    {
        if(marker[i]==0)
        {
            b=i+1;
            break;
        }
    }
    vector<int> result;
    cout<<a<<" "<<b<<endl;
    result.push_back(a);
    result.push_back(b);

    return result;
}
int main()
{
    const vector<int> arr={4, 3, 6, 2, 1, 1};
    repeatedNumbers(arr);

    return 0;
}