#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

// ʱ�临�Ӷȣ�O(M+N)
// ˼·���������е��������Եó���
//  a.��һ���е�ĳ�����֣����ϵ����ֶ�����С
//  b.��һ���е�ĳ�����֣����ҵ����ֶ�������

// �������½ǵ�Ԫ�ؿ�ʼ����target�Ƚϣ���targetС�������ң���target��������ң������Ǽ�С������������



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


