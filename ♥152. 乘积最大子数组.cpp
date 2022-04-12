#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//˼·����̬�滮
// f[i]���� i ��β��������˻����ֵ
// ������ֻ����������0�ĵ�����£�f[i] = f[i-1] * nums[i]
// �����0��ǰ��˻�Ϊ0����ô�µ� f[i] = nums[i];
// �ٿ�������и��������
// �����ǰ nums[i] �Ǹ�������ζ��֮ǰ�����ֵ�����С����֮ǰ����Сֵ������
// ���Կ��ǲ�����ά��һ�����������˻�f[i]
// ͬʱҲά��һ����������С�˻�g[i]
// ��nums[i]Ϊ����ʱ��f[i]=max(g[i-1]*nums[i],nums[i]);
// ��Ϊf[i-1] * nums[i] <= g[i-1] * nums[i]�������� g[i-1] ���� f[i-1]

// ���� g[i] ��ά����ͬ��
// �� nums[i]>=0 ʱ��g[i] = min(g[i-1]*nums[i],nums[i]);
// �� nums[i] < 0 ʱ��g[i] =min(f[i-1]*nums[i],nums[i]);

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> f(nums.size());
        vector<int> g(nums.size());
        f[0] = nums[0];
        g[0] = nums[0];
        int res = INT_MIN;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                f[i] = max(f[i - 1] * nums[i], nums[i]);
                g[i] = min(g[i - 1] * nums[i], nums[i]);
            }
            else {
                f[i] = max(g[i - 1] * nums[i], nums[i]);
                g[i] = min(f[i - 1] * nums[i], nums[i]);
            }
            //ע��f[i]����i��β�����ֵ�������������������鲻һ����i��β
            //����ÿ�ζ�Ҫ����res
            res = max(res, f[i]);
        }
        res = max(res, f[0]);
        return res;
    }
};

int main()
{
    Solution a;
    a.maxProduct({-1});
	return 0;
}