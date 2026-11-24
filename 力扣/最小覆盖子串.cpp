#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.size() < t.size()) return "";

        unordered_map<char,int> mp;
        for (char c : t) mp[c]--;               

        int need = (int)t.size(), count = 0;
        int l = 0, minLen = (int)s.size() + 1;
        string str;

        for (int r = 0; r < (int)s.size(); r++) { 
            auto it = mp.find(s[r]);
            if (it != mp.end()) {
                it->second++;                      
                if (it->second <= 0) count++;      
            }
            while (count == need) {                
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    str = s.substr(l, r - l + 1);   
                }
                auto jt = mp.find(s[l]);
                if (jt != mp.end()) {
                    jt->second--;                   
                    if (jt->second < 0) count--;    
                }
                l++;
            }
        }
        return str;
    }
};

int main()
{
    string s="ADOBECODEBANC";
    string t="ABC";
    Solution str1;
    string res=str1.minWindow(s,t);
    cout<<res<<endl;
}