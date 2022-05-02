#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
* ���⣬start��end�����ݷ�Χ�ɴ�10^9�������ܿ���ô��Ĳ�������
* ���Կ�����map����ɢ���
* 
* ע����ɢ�����������ʹ�ã������������ٵõ�ĳһ��arr��ֵ�������ѯ��
* ��������������arr������diff[i]��arr[i-1]���arr[i]
* ��������arr[i] = ���� + diff[i]���ٸ������� = arr[i];
* 
* �������ĺô��Զ��׼���arr[i] �������� arr[i-1]�����������α�������ѯ����֮��ά������ + ������ɢ���������
*/

class MyCalendar {
public:
    map<int, int> mp;

    MyCalendar() {}

    bool book(int start, int end) {
        mp[start]++;
        //ע�������ǰ뿪���䣡[start,end)�����Բ�����mp[end+1]--
        mp[end]--;

        // ά��������������ɢ��������飬��Ϊԭ�����ֵΪ0��������ʵ����ԭ�����ֵ��
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



