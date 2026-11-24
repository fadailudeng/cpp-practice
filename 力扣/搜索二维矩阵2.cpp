#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int i=0,j=m-1;
        while(j>=0&&i<n)
        {
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
       return false;
    }
};

int main()
{
    Solution s;
    vector<vector<int>>matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=5;
    bool res=s.searchMatrix(matrix,target);
    cout<<res<<endl;
}