#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int left=0,right=nums.size()-1,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i>0&&nums[i]==nums[i-1])
            {
                continue;
            }
            left=i+1,right=nums.size()-1;
            while(left<right)
            {
                sum=nums[left]+nums[right]+nums[i];
                if(sum>0)
                {
                    right--;
                }
                else if(sum<0)
                {
                    left++;
                }
                else 
                {
                    res.push_back({nums[i],nums[left],nums[right]});
                    while(left<right && nums[left]==nums[left+1]) left++;
                    while(left<right && nums[right]==nums[right-1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<int>num={-1,0,1,2,-1,-4};
    Solution a;
    vector<vector<int>> res=a.threeSum(num);
    for(auto&x:res)
    {
        for(auto&y:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}