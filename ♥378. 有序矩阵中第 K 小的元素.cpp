#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//��ָ Offer II 076. �����еĵ� k �������
//�����еĵ�K������֣���С���ѣ�����һ�£���K��Ҳ����˵����Ҫ���ģ����󶥶ѵ�top()�����ģ������󲻷�
//class Solution {
//public:
//	int findKthLargest(vector<int>& nums, int k) {
//		priority_queue<int, vector<int>, greater<int>> qe;
//		for (int i = 0; i < nums.size(); i++) {
//			if (qe.size() < k) {
//				qe.push(nums[i]);
//			}
//			else if (nums[i] > qe.top()) {
//				qe.pop();
//				qe.push(nums[i]);
//			}
//		}
//		return qe.top();
//	}
//};

// ��������е�kС��Ԫ�أ�˼��һ�£���KС����Ҫ��С�ģ����Բ�����С���ѣ�Ҫ�ô����
// ����ѿ���ά��ǰKС��Ԫ�أ���top()С����ѣ�������Ͳ��룻
// ��XXX�������뷨�����߼�������ǰ���ǣ���û���ظ�Ԫ�ء����������ظ�Ԫ�أ������ô˷���XXX��
// Ϊɶ���ظ�Ԫ�ؾͲ�������������ˣ�һ���İ�


class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int, vector<int>, less<int>> qe; //less<int> �����
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (qe.size() < k) {
					qe.push(matrix[i][j]);
				}
				else {
					if (matrix[i][j] < qe.top()) {
						qe.pop();
						qe.push(matrix[i][j]);
					}
				}
			}
		}
		return qe.top();
	}
};




int main(int argc, char* argv[])
{
	return 0;
}



