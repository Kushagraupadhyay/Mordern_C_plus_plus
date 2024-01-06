#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair getminmax(int arr[], int low , int high)
{
    struct Pair minmax, mml, mmr;
    int mid;

   if (low ==  high)
   {
      minmax.min=arr[low];
      minmax.max=arr[low];

      return minmax;
   }

   if (high == low+1)
   {
    if (arr[low]>arr[high])
    {
        minmax.min=arr[high];
        minmax.max=arr[low];
    }
    else {
       minmax.min=arr[low];
       minmax.max=arr[high];
    }
    return minmax;
   }

  mid=(high+low)/2;
  mml= getminmax(arr,low,mid);
  mmr= getminmax(arr,mid+1,high);
  if (mml.min<mmr.min)
  {
    minmax.min=mml.min;
  }
  else
  {
    minmax.min=mmr.min;
  }
  
  if (mml.max>mmr.max)
  {
    minmax.max=mml.max;
  }
  else
  {
    minmax.max=mmr.max;
  }
  
  return minmax;
}

int main()
{
    int arr[]={1000, 11, 445, 1, 330, 3000};
    int arrsize=6;
    struct Pair minmax = getminmax(arr,0,arrsize-1);
    cout << "Minimum element is " << minmax.min << endl;
    cout << "Maximum element is " << minmax.max;
    return 0;
}