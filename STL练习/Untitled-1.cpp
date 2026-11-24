#include <iostream>
using namespace std;
template <class T>
void Sort(T a[],int len)
{
    T k,min,t;
    for(int i=0;i<len;i++)
    {
        min=i;
        for(int j=i+1;j<len;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
    }
}
void text01()
{
    int a[]={10,9,8,7,6,5,4,3,2,1};
    int num=sizeof(a)/sizeof(a[0]);
    Sort(a,num);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
}
void text02()
{
    char a[]="qwertyuiop";
    int num=sizeof(a)/sizeof(a[0]);
    Sort(a,num);
    for(int i=0;i<10;i++)
    {
        cout<<a[i]<<" ";
    }
}
int main()
{
    //text01();
    text02();
    return 0;
}