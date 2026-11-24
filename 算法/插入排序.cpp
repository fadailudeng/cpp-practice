#include <iostream>
using namespace std;
int main()
{
    int a[10]={9,2,4,1,5,3,7,6,8,10};
    int i,j,max=0;
    for(i=1;i<10;i++)
    {
        for(j=i;j>=1;j--)
        {
            if(a[j]>a[j-1])//每次新加入的a[i]都要和前面的数进行比较排序
            {
                int t=a[j];
                a[j]=a[j-1];
                a[j-1]=t;
            }
        }
    }
    for(i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}