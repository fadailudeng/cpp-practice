#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
       reverse(nums.begin(),nums.end());
       reverse(nums.begin(),nums.begin()+k);
       reverse(nums.begin()+k,nums.end());
    }
};
int main()
{
    vector<int>nums={1};
    Solution s;
    int k;
    cin>>k;
    s.rotate(nums,k);
    for(auto &x:nums)
    {
        cout<<x<<" ";
    }

}
