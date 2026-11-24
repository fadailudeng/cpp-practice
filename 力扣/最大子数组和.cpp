#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int best = nums[0], cur = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            cur  = max(nums[i], cur + nums[i]);  
            best = max(best, cur);
    }
    return best;
}
};


int main()
{
    Solution s;
    vector<int>v={5,4,-1,7,8};
    int res=s.maxSubArray(v);
    cout<<res<<endl;

    
}