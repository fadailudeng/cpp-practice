#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <unordered_set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>m(nums.begin(),nums.end());
        int max_len=0;
        for(int x:m)
        {
            if(!m.count(x-1))
            {
                int cur=x;
                int len=1;
                while(m.count(cur+1))
                {
                    len++;
                    cur++;
                }
                max_len=max(max_len,len);
            }
        }
        return max_len;
    }
};
int main()
{
    vector<int>num;
    num.push_back(0);
    num.push_back(3);
    num.push_back(7);
    num.push_back(2);
    num.push_back(5);
    num.push_back(8);
    num.push_back(4);
    num.push_back(6);
    num.push_back(0);
    num.push_back(1);
    Solution a;
    int res=a.longestConsecutive(num);
    cout<<res<<endl;
    return 0;
}