#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

// ���͵��������Ӧ�ó�����ע������ϸ��
// 1. ���⴦���һ��Ԫ��
// 2. һ��res��Ϊfalse���ݹ������ÿ����Ҫ��������

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
    bool res = true; //ά��һ��ȫ�ֱ�����������������������Ƿ�Υ���˶���������������
    int flag = 0; 
    bool isValidBST(TreeNode* root) {
        midTraverse(root);
        return res;
    }
    void midTraverse(TreeNode* root) {
        if (!res)return; //ÿ�εݹ����֮���ж�res�Ƿ�Ϊfalse������ǣ�����������
        if (root != nullptr) {
            midTraverse(root->left);
            if (!res)return; //ÿ�εݹ����֮���ж�res�Ƿ�Ϊfalse������ǣ�����������
            if (!flag) { //�Ե�һ��Ԫ�ص����⴦��
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


