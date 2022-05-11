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
		//我始终想判断，root的left或right为空时，我该怎么办，分了好几种情况，实际上，这不是我应该判断的事情，我没有充分理解递归
		pair<int, int> left = isAverage(root->left);
		pair<int, int> right = isAverage(root->right);
		count += left.first;
		count += right.first;
		sum += left.second;
		sum += right.second;
		if (sum / count == root->val)ans += 1;
		//我的原本思路是 <ans，平均值>，把自己搞得很狼狈，因为平均值不好算，ans和平均值都不是第一手信息，要进行抽象，抓住本质信息
		// count 和 sum 是好算的，依赖于子类的返回值，可以很轻松地算出来，然后再维护一个全局ans就行了
		return { count,sum };
	}
};	

class Solution {
public:
	int averageOfSubtree(TreeNode* root) {
		return  isAverage(root).first;
	}
	// first是满足条件的结点数，second是子树的平均值
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


