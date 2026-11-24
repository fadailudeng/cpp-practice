#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int count=0;
        int i=0,j=0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)      // 只走 j > i，即上三角
                swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; i++) reverse(matrix[i].begin(), matrix[i].end());
}
};
