//https://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
int block;//made glbal for use by compare function
struct query_pair 
{
    int L,R;
};
bool compare(query_pair &q1,query_pair &q2)
{
    if (q1.L/block!=q2.L/block)
    {
        return q1.L/block<q2.L/block;
    }
    return q1.R<q2.R;    
}
int queryResult(vector<int> &arr,query_pair q[],int number_of_queries)
{
   block=(int)sqrt(arr.size()); // dividing the queries in block of root n size
   sort(q,q+number_of_queries,compare);
   int current_left=0;
   int current_right=0;
   int current_sum=0;
   for (int i = 0; i < number_of_queries; i++)
   {
     int current_query_left=q[i].L;
     int current_query_right=q[i].R;
    while (current_left<current_query_left)
    {
        current_sum-=arr[current_left]; // current right will be adding the values once again we traverse it from0 hence need to deduct those values from current sum
        current_left++;
    }
    while (current_left>current_query_left)
    {
        current_sum+=arr[current_left-1];
        current_left--;
    }
    while (current_right<=current_query_right)
    {
        current_sum+=arr[current_right];
        current_right++;
    }
    while (current_right>current_query_right+1)
    {
        current_sum-=arr[current_right-1];
        current_right--;
    }
       
    cout<<q[i].L<<" "<<q[i].R<<" sum "<<current_sum<<endl;
   }  

   return block;
}

int main()
{
    vector<int> arr={1, 1, 2, 1, 3, 4, 5, 2, 8};
    query_pair q[]={{4,5},{2, 4}, {1, 3},{0, 4}};//q[] to make array of queries
    int number_of_queries= sizeof(q)/sizeof(q[0]);
    cout<<queryResult(arr,q,number_of_queries);
}