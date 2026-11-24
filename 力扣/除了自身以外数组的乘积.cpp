#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = (int)nums.size();

        // 第一趟：把合法的值 v 钉到下标 v-1 上
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // 第二趟：第一个没被钉对的位置，答案就是它该有的值
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) return i + 1;
        }
        return n + 1;
    }
};


int main()
{
    Solution s;
    vector<int>nums={1,2,3,4};
    vector<int>res;
    res=s.productExceptSelf(nums);
    for(auto &x:res)
    {
        cout<<x<<" ";
    }


}