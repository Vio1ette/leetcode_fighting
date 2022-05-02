#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
* 这题，start，end的数据范围可达10^9，不可能开这么大的差分数组的
* 所以考虑用map来离散差分
* 
* 注意离散差分中增量的使用，用增量来快速得到某一个arr的值（单点查询）
* 不用增量：遍历arr，利用diff[i]和arr[i-1]求出arr[i]
* 用增量：arr[i] = 增量 + diff[i]，再更新增量 = arr[i];
* 
* 用增量的好处显而易见，arr[i] 不依赖于 arr[i-1]，避免了依次遍历来查询，总之：维护增量 + 遍历离散化差分数组
*/

class MyCalendar {
public:
    map<int, int> mp;

    MyCalendar() {}

    bool book(int start, int end) {
        mp[start]++;
        //注意这里是半开区间！[start,end)，所以不是用mp[end+1]--
        mp[end]--;

        // 维护增量，遍历离散化差分数组，因为原数组各值为0，增量其实就是原数组的值了
        int delta = 0;
        for (auto& [x, y] : mp) {
            delta += y;
            if (delta > 1) {
                mp[start]--;
                mp[end]++;
                return false;
            }
        }
        return true;
    }

};


/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

int main()
{
    MyCalendar* obj = new MyCalendar();
    bool param_1 = obj->book(10,20);
    bool param_2 = obj->book(20, 30);
    cout << endl;
	return 0;
}



