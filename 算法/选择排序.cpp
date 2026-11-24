#include <iostream>
using namespace std;
int main()
{
    int a[10]={9,2,4,1,5,3,7,6,8,10};
    int i,j,max=0;
    for(i=0;i<10;i++)
    {
        max=0;
        for(j=0;j<10-i;j++)
        {
            if(a[j]>a[max])
            max=j;
        }
        int t=a[max];
        a[max]=a[j-1];
        a[j-1]=t;
    }
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}