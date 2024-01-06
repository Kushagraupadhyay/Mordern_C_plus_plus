#include<bits/stdc++.h>

using namespace std;

void allpermutations(string str)
{
    int len= str.length();
    sort(str.begin(),str.end());
    bool isfinished = false ;
    while (!isfinished)
    {
        int i,j;
        for (i=len-2;i>=0;i--)
        {
            if (str[i]<str[i+1])
            {
                break;
            }
        }

        if(i<0)
        {
            isfinished = true;
        }

        else
        {
            for(j=len-1;j>=0;j--)
            {
               if(str[j]>str[i])
               {
                break;
               }
            }
            swap(str[i],str[j]);
            reverse(str.begin()+i+1,str.end());
        }

       cout<<str<<" "<<endl;
    }
}

int main()
{
   string str = "ACBC";
   allpermutations(str);

    return 0;
}