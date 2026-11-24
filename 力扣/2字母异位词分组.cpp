#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>
#include <algorithm>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>m;
        vector<vector<string>>res;
        vector<string>::iterator it=strs.begin();
        for(int i=0;i<strs.size();i++)
        {
            string key=strs[i];
            sort(key.begin(),key.end());
             m[key].push_back(strs[i]);
        }
        for(auto&pair:m)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};
int main()
{
    vector<string>strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");
    Solution a;
    vector<vector<string>> res=a.groupAnagrams(strs);
    for(auto&x:res)
    {
        for(auto&s:x)
        {
            cout<<s<<" ";
        }
        cout<<endl;
    }

    return 0;
}