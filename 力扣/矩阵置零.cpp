#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m,n;
        m=matrix.size();
        n=matrix[0].size();
        bool m1=false,n1=false;
         for(int j=0;j<n;j++)
        {
            if(matrix[0][j]==0)
            {
                m1=true;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                n1=true;
            }
        }
       

       for(int i=1;i<m;i++)
       {
        for(int j=1;j<n;j++)
        {
            if(matrix[i][j]==0)
            {
                matrix[0][j]=0;
                matrix[i][0]=0;
            }
        }
       }
       for(int i=1;i<m;i++)
       {
        for(int j=1;j<n;j++)
        {
            if(matrix[0][j]==0||matrix[i][0]==0)
            {
                matrix[i][j]=0;
            }
        }
       }
       if(m1)
       {
        fill(matrix[0].begin(),matrix[0].end(),0);
       }
       if(n1)
       {
        for(int i=0;i<m;i++)
        {
            matrix[i][0]=0;
        }
       }
    }
};



int main()
{
    Solution s;
    vector<vector<int>>matrix = ;
}