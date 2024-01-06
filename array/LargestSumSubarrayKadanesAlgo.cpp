// KADENA ALGORITHM 
// IF SUM IS NEGATIVE THEN MAKE SUM 0 AND KEEP ADDING ARRAY TO GET THE MAX POSSIBLE VALUE WHILE CONTINUOUSLY UPDATING THE MAX VALUE

#include <iostream>
using namespace std;

int maxSubArraySum(int a[],int n)
{
    int max=0,sum=0;

    for (int i = 0; i < n; i++)
    {
        sum = sum + a[i];
        if(sum>max)
        {
            max=sum;
        }
        if(sum<0)
        {
            sum=0;
        }
    }
    
    return max;
}

int main()
{
    int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
    int n= sizeof(a)/sizeof(a[0]);

    int max_sum = maxSubArraySum(a,n);
    cout<<"Max contiguous sum is"<<max_sum;
    return 0;
}