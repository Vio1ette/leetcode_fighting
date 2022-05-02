#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;



/*
* 大体思路：
* 要注意到，高度规模是小的，所以选择对高度进行遍历
* 得到[1,100]每个 高度下的宽度列表，将每个高度下的宽度列表按升序排序
* 
* 对于某个点[x,y]，遍历高度不小于它的高度，如果那些高度有列表，就对宽度列表进行二分查找，找出宽度不小于point宽度的数量（lower_bound左边界）
* 
* 时间复杂度：M*（100）* logN，M为点数，N为矩形个数 【不确定哈】
* 
* 也可用【树状数组】求解
* 
*/

//解法没问题，但会超时
//class Solution {
//public:
//    vector<int> countRectangles(vector<vector<int>> rectangles, vector<vector<int>> points) {
//        unordered_map<int, set<int>> mp;
//        for (vector<int> x : rectangles) {
//            mp[x[1]].insert(x[0]);
//        }
//        vector<int> res;
//        for (auto x : points) {
//            int temp = 0;
//            for (int h = 100; h >= 1; h--) {
//                if (h < x[1])break;
//                if (mp.find(h) != mp.end()) {
//                    auto it = mp[h].lower_bound(x[0]);
//                    temp += distance(it, mp[h].end());
//                }
//            }
//            res.push_back(temp);
//        }
//        return res;
//    }
//};


class Solution {
public:
    vector<int> countRectangles(vector<vector<int>> rectangles, vector<vector<int>> points) {
        vector<vector<int>> height(101);
        for (auto x : rectangles) {
            height[x[1]].push_back(x[0]);
        }
        for (int i = 1; i <= 100;i++) {
            if (height[i].size() >= 2) {
                sort(height[i].begin(), height[i].end());
            }
        }

        vector<int> res;

        for (auto x : points) {
            int temp = 0;
            for (int h = 100; h >= 1; h--) {
                if (h < x[1])break;
                int lower_bound_pos = 0;
                if (height[h].size() != 0) {
                    int left = 0;
                    int right = height[h].size();
                        while (left < right) {
                        int middle = left + (right - left) / 2;
                        if (height[h][middle] == x[0]) {
                            right = middle;
                        }
                        else if (height[h][middle] > x[0]) {
                            right = middle;
                        }
                        else if (height[h][middle] < x[0]) {
                            left = middle + 1;
                        }
                    }
                    lower_bound_pos = left;
                }
                temp += height[h].size() - lower_bound_pos;
            }
            res.push_back(temp);
        }
        return res;
    }
};


int main()
{
    Solution a;
    a.countRectangles({
        { 8,4 }, { 10,8 }, { 7,2 },{10,5},{4,7},{9,9},{5,2},{1,5}
        }, { {8,2},{10,8},{8,8},{1,3} });

	return 0;
}



