#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//差分数组

/*
* 想一下你本来的差分思路
* 差分数组啊，得看最大花期，需要一个 10^9 长度的数组 diff
* 
* 更新：
* 差分数组的更新：第一次遍历所有花的花期，执行差分数组标准的更新操作：例如 一朵花的花期为{1，6}，要 diff[1]+1，diff[2]-1
* 如果不用差分，就会造成6次更新操作，用差分减小到2次
* 
* 离线查询，查询时需要一个一个遍历来递推
* 比如，diff[1]=1，arr[0]=0，就说明 arr[1] = arr[0] + diff[1] = 5
* 因为 diff[2]=0，arr[2] = arr[1] + diff[2] = 1;
* ...
* diff[7]=-1，arr[7] = arr[6] + diff[7] = 0;
* 
* 问题：差分数组很大！这样会超时的，如法一
  
  差分数组大小：10^9，能不能只维护要用到的值？

  【离散化差分】

  用map
  1. 有序
  2. 中间插入值方便

  查询差分数组，除了遍历，还可以用一个【增量】来维护

  对于离散差分数组上的每一个值

  先更新增量
  delta = delta + diff[i]

  再计算值
  diff[i] = diff[i] + delta

*/

//朴素差分
//class Solution {
//public:
//    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
//        vector<int> diff(1000000001, 0);
//        for (vector<int> x : flowers) {
//            diff[x[0]]++;
//            diff[x[1] + 1]--;
//        }
//
//        //离线查询
//        vector<int> arr(10000000001, 0);
//        for (int i = 1; i < 1000000001; i++) {
//            arr[i] = arr[i - 1] + diff[i];
//        }
//
//        vector<int> res;
//        for (int i = 0; i < persons.size(); i++) {
//            res.push_back(arr[persons[i]]);
//        }
//        return res;
//    }
//};


class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> mp;
        //离散差分数组
        for (auto& it : flowers) mp[it[0]]++, mp[it[1] + 1]--;
        for (auto x : persons) mp[x];

        //为查询打了个表，对于离散差分，采用增量获取值
        int tot = 0;
        for (auto& [x, y] : mp)
            y = (tot += y);

        for (auto& x : persons)
            x = mp[x];
        return persons;
    }
};


int main()
{
    //vector<vector<int>> flower{ {1,6},{3,7},{9,12},{4,13} };
    vector<vector<int>> flower{ {1,6},{3,7} };

    vector<int> person{6};
    Solution a;
    a.fullBloomFlowers(flower, person);
	return 0;
}



