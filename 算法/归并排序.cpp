#include <iostream>
using namespace std;

void merge(int *arr, int left, int mid, int right)
{
    int len = right - left + 1;
    int *temp = new int[len];  
    int i = 0;
    int l = left, r = mid + 1;
    while (l <= mid && r <= right) {
        if (arr[l] > arr[r])
            temp[i++] = arr[l++];
        else
            temp[i++] = arr[r++];
    }
    while (l <= mid) temp[i++] = arr[l++];
    while (r <= right) temp[i++] = arr[r++];
    for (int j = 0; j < len; j++)
        arr[left + j] = temp[j];
    delete[] temp;
}
void mergesort(int *arr, int left, int right)
{
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
}
int main()
{
    int a[10] = {9,2,4,1,5,3,7,6,8,10};
    mergesort(a, 0, 9);
    for(int i=0;i<10;i++)
        cout << a[i] << " ";
    return 0;
}