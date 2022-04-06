#include <bits/stdc++.h>
using namespace std;


//时间复杂度：O(log(max_val/k))
class Solution {
public:
    int maximumCandies(vector<int> candies, long long k) {
        //这题十分经典，应该标个重点！

        //大体思路：二分查找右边界
        // left：小孩儿最少分到 0 个糖果
        // right：小孩儿最多分到 sum / k 个糖果

        long long sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }

        // 连每人一个都做不到，返回 0
        if (sum < k)return 0;

        //二分查找，右边界, target就是k，用堆数和它比较
        //二分右边界模板：
        // [left,right)
        long long  left = 0;
        long long  right = sum / k + 1; //注意这里的+1

        while (left < right) {
            int mid = left + (right - left) / 2;
            //判断当前的mid是否满足条件
            long long heap = 0;
            for (int x : candies) {
                heap += (x / mid);
            }
            if (heap >= k) {    //如果满足条件，则移动left，最终left是“右边界+1”
                left = mid + 1;
            }
            else if (heap < k) {//如果不满足，移动right，注意不能是mid-1（
                //考虑mid前一个就满足条件，那么当前的mid就是最终结果：“右边界+1”，所以right的移动不能-1）
                right = mid;
            }
        }


        //left的结果是“右边界+1”
        return left - 1;
    }
};

int main()
{

    Solution a;
    a.maximumCandies({ 5,6,4,10,10,1,1,2,2,2 }, 9);
    return 0;
}