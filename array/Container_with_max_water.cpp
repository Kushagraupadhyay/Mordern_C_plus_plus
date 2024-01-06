#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int maxArea(vector<int> &height)
{
    int left_pointer=0;
    int right_pointer=height.size()-1;
    int max_area=-1;
    int area;
    while (left_pointer<right_pointer)
    {
        area=min(height[left_pointer],height[right_pointer])*abs(left_pointer-right_pointer);
        if (area>max_area)
        {
            max_area=area;
        }
        if (height[left_pointer]==height[right_pointer])
        {
            left_pointer++;
        }
        else
        {
            if (height[left_pointer]>height[right_pointer])
            {
                right_pointer--;
            }
            else
            {
                left_pointer++;
            }
            
        }
               
    }
    return max_area;
}
int main()
{
    vector<int> arr = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(arr);
}