#include <bits/stdc++.h>
#include <iostream>
using namespace std;


//剑指 Offer II 076. 数组中的第 k 大的数字
//数组中的第K大的数字，用小顶堆，想象一下，第K大，也就是说，不要最大的，而大顶堆的top()是最大的，与需求不符
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

// 有序矩阵中第k小的元素，思考一下，第K小，不要最小的，所以不能用小顶堆，要用大根堆
// 大根堆可以维护前K小个元素，比top()小就入堆，，否则就不入；
// 【XXX】错误想法：此逻辑成立的前提是：【没有重复元素】。此题有重复元素，不能用此法【XXX】
// 为啥有重复元素就不能用这个方法了？一样的啊


class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<int, vector<int>, less<int>> qe; //less<int> 大根堆
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



