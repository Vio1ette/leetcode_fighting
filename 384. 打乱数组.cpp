#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;

//洗牌算法，对于有n个元素的数组来说，为了保证洗牌的公平性，应该要能够等概率的洗出n!种结果。

//每个数都有相等的概率被放到任意一个位置中，即每个位置中出现任意一个数的概率都是相同的

/*
* 开始数组中有五个元素；
* 在前五个数中随机选一个数与第五个数进行交换，每个数都有五分之一的概率被交换到最后一个位置；
* 在前四个数中随机选一个数与第四个数进行交换，每个数都有 4/5 * 1/4 = 1/5 的概率被交换到第四个位置；
* 在前三个数中随机选一个数与第三个数进行交换，每个数都有 4/5 * 3/4 * 1/3 = 1/5 的概率被交换到第三个位置；
*/

//看图说话：https://pic.leetcode-cn.com/1616380923-YvHlbL-53BF82B993210EA6F26B63EC7BDBFB04.png


class Solution {
public:
    Solution(vector<int>& nums) {
        arr = nums;
    }

    vector<int> reset() {
        return arr;
    }

    vector<int> shuffle() {
        vector<int> nums(arr);
        for (int i = 0; i < nums.size(); i++) {
            int index = i + rand() % (nums.size() - i);
            swap(nums, index, i);
        }
        return nums;
    }

    void swap(vector<int>& a, int i, int j) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }

    vector<int> arr;
};


int main(int argc, char* argv[])
{	

	cout << sizeof(a) << endl;
	return 0;
}


