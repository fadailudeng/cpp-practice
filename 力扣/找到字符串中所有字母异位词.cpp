#include <iostream>
using namespace std;
#include <unordered_map>
#include <vector>
#include <string>
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       vector<int>count(26);
       vector<int>comper(26);
        vector<int>res;
        int p_size=p.size();
        int s_size=s.size();
        if(s_size<p_size)
        return res;
        for(int i=0;i<p_size;i++)
        {
            count[p[i]-'a']++;
            comper[s[i]-'a']++;
        }
        if(count==comper)
        {
            res.push_back(0);
        }
        for(int i=p_size;i<s_size;i++)
        {
            comper[s[i]-'a']++; 
            comper[s[i-p_size]-'a']--;
            if(count==comper)
            {
                res.push_back(i-p_size+1);
            }
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