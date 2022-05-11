#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;


//2.

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2 {
public:
	int ans = 0;
	int averageOfSubtree(TreeNode* root) {
		isAverage(root);
		return ans;
	}
	pair<int, int> isAverage(TreeNode* root) {
		if (root == nullptr) {
			return { 0,0 };
		}
		int count = 1, sum = root->val;
		//��ʼ�����жϣ�root��left��rightΪ��ʱ���Ҹ���ô�죬���˺ü��������ʵ���ϣ��ⲻ����Ӧ���жϵ����飬��û�г�����ݹ�
		pair<int, int> left = isAverage(root->left);
		pair<int, int> right = isAverage(root->right);
		count += left.first;
		count += right.first;
		sum += left.second;
		sum += right.second;
		if (sum / count == root->val)ans += 1;
		//�ҵ�ԭ��˼·�� <ans��ƽ��ֵ>�����Լ���ú��Ǳ�����Ϊƽ��ֵ�����㣬ans��ƽ��ֵ�����ǵ�һ����Ϣ��Ҫ���г���ץס������Ϣ
		// count �� sum �Ǻ���ģ�����������ķ���ֵ�����Ժ����ɵ��������Ȼ����ά��һ��ȫ��ans������
		return { count,sum };
	}
};	

class Solution {
public:
	int averageOfSubtree(TreeNode* root) {
		return  isAverage(root).first;
	}
	// first�����������Ľ������second��������ƽ��ֵ
	pair<int, int> isAverage(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) {
			return { 1, root->val };
		}
		else if (root->left != nullptr && root->right == nullptr) {
			pair<int, int> cur = isAverage(root->left);
			return { cur.first + 1,(root->val + cur.second) / 2 };
		}
		else if (root->right != nullptr && root->left == nullptr) {
			pair<int, int> cur = isAverage(root->right);
			return { cur.first + 1, (root->val + cur.second) / 2 };
		}
		else {
			pair<int, int> cur1 = isAverage(root->left);
			pair<int, int> cur2 = isAverage(root->right);
			return { cur1.first + cur2.first + 1, (root->val + cur1.second + cur2.second) / 3 };
		}
	}

};






int main(int argc, char* argv[])
{	
	return 0;
}


