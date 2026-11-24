#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int max_V=0,v;
       while(i!=j)
       {
        v=(j-i)*min(height[i],height[j]);
        max_V=max(max_V,v);
        if(height[i]>height[j])
        {
            j--;
        }
        else
        i++;
       }
        return max_V;
    }
    
};
int main()
{
    vector<int>height={1,8,6,2,5,4,8,3,7};
    Solution a;
    int max_V=a.maxArea(height);
    cout<<max_V<<endl;
    return 0;
}