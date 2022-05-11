#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

// 典型的中序遍历应用场景，注意两点细节
// 1. 特殊处理第一个元素
// 2. 一旦res变为false，递归结束的每处都要立即返回

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int pre = 0;
    bool res = true; //维护一个全局变量，监视中序遍历过程中是否违反了二叉搜索树的性质
    int flag = 0; 
    bool isValidBST(TreeNode* root) {
        midTraverse(root);
        return res;
    }
    void midTraverse(TreeNode* root) {
        if (!res)return; //每次递归完成之后，判断res是否为false，如果是，就立即返回
        if (root != nullptr) {
            midTraverse(root->left);
            if (!res)return; //每次递归完成之后，判断res是否为false，如果是，就立即返回
            if (!flag) { //对第一个元素的特殊处理
                pre = root->val;
                flag = 1;
            }
            else {
                res = root->val > pre;
                if (!res)return;
                pre = root->val;
            }
            midTraverse(root->right);
        }
    }
};
int main(int argc, char* argv[])
{	
	
	return 0;
}


