#include <iostream>
using namespace std;
#include <vector>
#include <map>
class Solution{
    public:
    vector<int> twosum(vector<int>&num,int target){
        map<int,int>m;
        map<int,int>::iterator pos=m.begin();
        vector<int>::iterator it=num.begin();
        for(int i=0;i<num.size();i++)
        {
            pos=m.find(target-num[i]);
            if(pos!=m.end())
            {
                return {i,pos->second};
            }
            m.insert(make_pair(num[i],i));
        }
        return {};
    }
};
int main()
{
    vector<int>num1;
    num1.push_back(3);
    num1.push_back(2);
    num1.push_back(4);
   // num1.push_back(15);
    Solution a;
    vector<int>res=a.twosum(num1,6);
    cout<<res[0]<<","<<res[1]<<endl;
    return 0;
}