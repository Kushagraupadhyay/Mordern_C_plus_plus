// https://www.geeksforgeeks.org/best-time-to-buy-and-sell-stock/
#include<iostream>
#include<vector>
using   namespace std;

int  max_profit(vector<int> prices,int n)
{
    int buy_price=prices[0];
    int sell_price,i;
    int ProfitSoFar=0;
    for(int i=1;i<n;i++)
    {
        if(prices[i]<buy_price)
        {
            buy_price=prices[i];
        }
        // checked profile for each instance and parallely updates the minimim stock price in one iteration
        else if(prices[i]-buy_price>ProfitSoFar)
        {
            ProfitSoFar=prices[i]-buy_price;
        }
    }
    
    return ProfitSoFar;
}

int  main()
{
    vector<int> prices={7,1,5,6,4};
    int profit=max_profit(prices,prices.size());
    cout<<profit<<endl;
    return 0;
}