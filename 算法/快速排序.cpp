#include <iostream>
using namespace std;
void fastSort(int arr[],int left,int right)
{
    if(left>=right)
    return;
    int povit=arr[left];
    int l=left,r=right;
    while(l<r)
    { 
        while(l<r&&arr[r]>=povit)
            r--;
        arr[l]=arr[r];
        while(l<r&&arr[l]<=povit)
            l++;
        arr[r]=arr[l];
    } 
    arr[l]=povit;
    fastSort(arr,left,l-1);
    fastSort(arr,l+1,right);
}
int main()
{
    int a[11]={56,23,82,45,76,69,20,45,93,16,17};
    fastSort(a,0,10);
    for(auto&x:a)
    {
        cout<<x<<" ";
    }
    return 0;
}