//https://www.geeksforgeeks.org/trapping-rain-water/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int Rain_water_count(vector<int> height)
{
    int n=height.size(); 
    int Left_height_preprocessing[n] ;
    int Right_height_preprocessing[n];
    int i,maxx=0;
    for (i = 0; i < n ; i++)
    {
        if(height[i]>maxx)
        {
            maxx=height[i];
        }
        Left_height_preprocessing[i]=maxx;
    }
    maxx=0;
    for(i=n-1;i>=0;i--)
    {
        if(height[i]>maxx)
        {
            maxx=height[i];
        }
        Right_height_preprocessing[i]=maxx;
        //Right_height_preprocessing.insert(Right_height_preprocessing.begin(),maxx);
    }
    int trapper_water=0;
    for(i=1;i<n-1;i++)
    {
        trapper_water+=(min(Left_height_preprocessing[i],Right_height_preprocessing[i])-height[i]);
    }
    return trapper_water;
}
int main()
{
    vector<int> height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
    cout<<Rain_water_count(height);
    return 0;
}