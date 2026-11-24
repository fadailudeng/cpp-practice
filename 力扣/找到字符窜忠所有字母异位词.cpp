#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <string>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>map;
        vector<int>res;
        int count=0;
        for(char a:p)
        map[a]++;
        unordered_map<char,int>temp;
        int len=p.length();
        int left=0,right=0;
       while(right<s.length())
        {
            if(map.count(s[right]))
            {
                temp[s[right]]++;
                if(map[s[right]]==temp[s[right]])
                count++;
            }
            if(right-left+1==p.size()) 
            {
                if(count==map.size())
                res.push_back(left);
                if(map.count(s[left]))
                {
                    if(map[s[left]]==temp[s[left]])
                        count--;
                    temp[s[left]]--;
                }
                left++;
            }
            right++;
        } 
        return res;
    }
};
int main()
{

    Solution a;
    string s="cbaebabacd",p="abc";
    vector<int>res=a.findAnagrams(s,p);
    for(auto&x:res)
    {
        cout<<x<<" ";
    }
    return 0;
}