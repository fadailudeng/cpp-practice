#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map> 
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    // int expect = 1;
    // for (int x : nums) {
    //     if (x == expect)      expect++;   // 这个数存在，往后要下一个
    //     else if (x > expect)  break;      // 比期望还大 → 中间断了，后面只会更大
    // }
    //return expect;
    for(int i=0;;)
    {
        if(nums[i]>=1)
        {
            break;
        }
        nums.erase(nums.begin());
    }
    int i=0;
    for(i;i<nums.size();i++)
    {
        if(nums[i]!=i+1)
        {
            break;
        }
        
    }
    return i+1;
    }
};



int main()
{
    Solution s;
    vector<int>nums={0,-1,3,1};
    int res=s.firstMissingPositive(nums);
    cout<<res<<endl;
}