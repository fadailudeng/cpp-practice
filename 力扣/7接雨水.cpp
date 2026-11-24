#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        /*int max_height=*max_element(height.begin(),height.end());
        int left=-1;
        int count=0,sum=0;
        for(int i=max_height;i>0;i--)
        {   count=0;
            left=-1;
            for(int j=0;j<height.size();j++)
            {
                if(height[j]>=i)
               if(left==-1)
               {
                left=j;
               }else{
                sum+=j-left-1;
                left=j;
               }
            }
        }
        return sum;*/
        //左右两指针，关注小的那一边，因为一边小大的那一边一定可以把水挡住一定可以存水，如果小的那一侧的当前值比目前最大值大
        //那也存不住水，只能比最大值小的时候才可以存水，存的水等于最大值减去当前值
        int l=0,r=height.size()-1;
        int lmax=0,rmax=0,res=0;
        while(l<r)
        {
           if(height[l]<height[r])
           {
            if(height[l]>=lmax)
            lmax=height[l];
            else
            res+=lmax-height[l];
            l++;
           }
           else{
            if(height[r]>=rmax)
                rmax=height[r];
            else
                res+=rmax-height[r];
            r--;
           }
        }
        return res;
    }
};
int main()
{
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    Solution a;
    int sum=a.trap(height);
    cout<<sum<<endl;
    return 0;
}