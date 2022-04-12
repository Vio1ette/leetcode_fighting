#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//这题完完全全是我自己想出来的诶，值得表扬
//大体思路：
//想象一下雨水填满空隙后的场景：一个峰状的图
//1. 峰前
//第一次遍历：在峰左边，按顺序记录非递减的柱子（下标，高度），记为“峰前顶柱”，雨水不会超过它们的
//峰前，除此之外的地方，要么是雨水，要么是矮小柱子
//峰前，总共接的雨水 = “峰前顶柱”之间的空隙面积 - 它们之间的矮小柱子所占面积
//
//2.峰后
//将数组逆序，按同样的方式处理峰后（逆序后的峰前）

//时间复杂度：O(N)，N为 height 数组长度
class Solution {
public:
    int trap(vector<int> height) {
    
        int max_num = INT_MIN;
        int max_index = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= max_num) {
                max_num = height[i];
                max_index = i;
            }
        }

        queue<pair<int, int>> qe;
        qe.push({ 0,height[0] });
        int remain = 0;
        for (int i = 1; i <= max_index; i++) {
            if (height[i] >= qe.back().second) {
                qe.push({ i,height[i] });
            }
            else remain += height[i];
        }

        int area = 0;
        while (qe.size() > 1) {
            pair<int, int> temp = qe.front();
            qe.pop();
            area += (qe.front().first - temp.first - 1) * min(qe.front().second, temp.second);
        }
        if (max_index == height.size() - 1)return area - remain;

        //逆序
        reverse(height.begin(), height.end());

        max_index = height.size()-max_index-1;
        queue<pair<int, int>> qe1;
        qe1.push({ 0,height[0] });
        for (int i = 1; i <= max_index; i++) {
            if (height[i] >= qe1.back().second) {
                qe1.push({ i,height[i] });
            }
            else  remain += height[i];
        }

        while (qe1.size() > 1) {
            pair<int, int> temp = qe1.front();
            qe1.pop();
            area += (qe1.front().first - temp.first - 1) * min(qe1.front().second, temp.second);
        }
        return area - remain;
    }
};

int main()
{
    Solution a;
    a.trap({ 5,5,1,7,1,1,5,2,7,6});
	return 0;
}