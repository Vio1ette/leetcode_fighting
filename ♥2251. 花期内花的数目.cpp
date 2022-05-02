#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

//�������

/*
* ��һ���㱾���Ĳ��˼·
* ������鰡���ÿ�����ڣ���Ҫһ�� 10^9 ���ȵ����� diff
* 
* ���£�
* �������ĸ��£���һ�α������л��Ļ��ڣ�ִ�в�������׼�ĸ��²��������� һ�仨�Ļ���Ϊ{1��6}��Ҫ diff[1]+1��diff[2]-1
* ������ò�֣��ͻ����6�θ��²������ò�ּ�С��2��
* 
* ���߲�ѯ����ѯʱ��Ҫһ��һ������������
* ���磬diff[1]=1��arr[0]=0����˵�� arr[1] = arr[0] + diff[1] = 5
* ��Ϊ diff[2]=0��arr[2] = arr[1] + diff[2] = 1;
* ...
* diff[7]=-1��arr[7] = arr[6] + diff[7] = 0;
* 
* ���⣺�������ܴ������ᳬʱ�ģ��編һ
  
  ��������С��10^9���ܲ���ֻά��Ҫ�õ���ֵ��

  ����ɢ����֡�

  ��map
  1. ����
  2. �м����ֵ����

  ��ѯ������飬���˱�������������һ������������ά��

  ������ɢ��������ϵ�ÿһ��ֵ

  �ȸ�������
  delta = delta + diff[i]

  �ټ���ֵ
  diff[i] = diff[i] + delta

*/

//���ز��
//class Solution {
//public:
//    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
//        vector<int> diff(1000000001, 0);
//        for (vector<int> x : flowers) {
//            diff[x[0]]++;
//            diff[x[1] + 1]--;
//        }
//
//        //���߲�ѯ
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
        //��ɢ�������
        for (auto& it : flowers) mp[it[0]]++, mp[it[1] + 1]--;
        for (auto x : persons) mp[x];

        //Ϊ��ѯ���˸���������ɢ��֣�����������ȡֵ
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



