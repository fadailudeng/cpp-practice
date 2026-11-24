#include <iostream>
using namespace std;
#include <vector>
#include <deque>
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int left=0,right=1;
    deque<int>temp;
    temp.push_back(nums[0]);
    vector<int>res;
    int l=0,i=1;
    auto &it=temp;
    while(right<k)
    {
        while(!it.empty()&&nums[right]>=it.back())
        {
            temp.pop_back();
            if(temp.empty())
            break;
        }
        temp.push_back(nums[right++]);
    }
    res.push_back(*(it.begin()));
    while(right<nums.size())
    {
        if(nums[left]==*(it.begin()))
        {
            temp.pop_front();
        }
        left++;
        while(!it.empty()&&nums[right]>it.back())
        {
            temp.pop_back();
        }
        temp.push_back(nums[right++]);
        res.push_back(*(it.begin()));
    }
    return res;
    }
};
int main()
{
    Solution a;
    vector<int>num={-7,-8,7,5,7,1,6,0};
    vector<int>res;
    res=a.maxSlidingWindow(num,4);
    for(auto &x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}