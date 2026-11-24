#include <iostream>
using namespace std;
#include <unordered_map>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    unordered_map<char,int>pop;
    int left=0,max_len=0;
    for(int right=0;right<s.length();right++)
    {
        if(pop.count(s[right])&&pop[s[right]]>=left)
        {
            left=pop[s[right]]+1;
        }
        pop[s[right]]=right;
        max_len=max(max_len,right-left+1);
    }
    return max_len;
}
};
int main()
{
    Solution a;
    int len=a.lengthOfLongestSubstring("abcabcbb");
    cout<<len<<endl;
    return 0;
}