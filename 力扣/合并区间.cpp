#include <iostream>
# include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};            // 防 nums[0] 越界
        sort(intervals.begin(), intervals.end());    // 按左端点排序
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); ++i) {
            if (res.back()[1] >= intervals[i][0]) {              // 与当前区间的右端重叠
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<vector<int>>intervals;
    intervals = {[1,3],[2,6],[8,10],[15,18]};
}