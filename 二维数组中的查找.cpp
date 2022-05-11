#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

// 时间复杂度：O(M+N)
// 思路：由于行列递增，可以得出：
//  a.在一列中的某个数字，其上的数字都比它小
//  b.在一行中的某个数字，其右的数字都比它大

// 从最左下角的元素开始，与target比较，比target小就往上找，比target大就往右找，往上是减小，往右是增大



class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if (row == 0)return false;
        int col = matrix[0].size();
        int i = row - 1;
        int j = 0;
        while (i >= 0 && j < col) {
            if (matrix[i][j] == target) {
                return true;
            }
            else if (matrix[i][j] > target) {
                i--;
            }
            else j++;
        }
        return false;
    }
};


int main(int argc, char* argv[])
{	
	return 0;
}


