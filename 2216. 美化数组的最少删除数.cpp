#include <bits/stdc++.h>
using namespace std;

//��ɾ����ģ���±�任
//index-cntΪ�±�����ֵ�����index-cntΪż�������жϣ�Ȼ�����ɾ����
class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size()-1; i++) {
            if ((i - cnt) % 2 == 0&&nums[i]==nums[i+1]) {
                cnt++;
            }
        }
        if (((nums.size() - 1 - cnt) % 2) == 0)cnt++;
        return cnt;
    }
    
};

int main()
{

    Solution a;
    return 0;
}