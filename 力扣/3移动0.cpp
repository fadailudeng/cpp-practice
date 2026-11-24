#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0,count=0;
        for(i;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                int temp;
                temp=nums[j];
                nums[j]=nums[i];
                nums[i]=temp;
                j++;
                count++;
            }
        }
       for(i=count;i<nums.size();i++)
       {
        nums[i]=0;
       }
    }
};
int main()
{
    vector<int>num={0,1,0,3,12};
    Solution a;
    a.moveZeroes(num);
    return 0;
}