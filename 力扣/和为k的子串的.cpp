#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>Map;
        Map[0]=1;
        int sum=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            if(Map.find(sum-k)!=Map.end())
            {
                res=res+Map[sum-k];
            }
            Map[sum]++;
        }
        return res;
    }
};
int main()
{
    Solution a;
    vector<int>num={1,2,3};
    int k=3;
    int res=a.subarraySum(num,k);
    cout<<res;
    return 0;
}