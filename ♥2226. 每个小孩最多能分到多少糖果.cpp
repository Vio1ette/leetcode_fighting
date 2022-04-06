#include <bits/stdc++.h>
using namespace std;


//ʱ�临�Ӷȣ�O(log(max_val/k))
class Solution {
public:
    int maximumCandies(vector<int> candies, long long k) {
        //����ʮ�־��䣬Ӧ�ñ���ص㣡

        //����˼·�����ֲ����ұ߽�
        // left��С�������ٷֵ� 0 ���ǹ�
        // right��С�������ֵ� sum / k ���ǹ�

        long long sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum += candies[i];
        }

        // ��ÿ��һ���������������� 0
        if (sum < k)return 0;

        //���ֲ��ң��ұ߽�, target����k���ö��������Ƚ�
        //�����ұ߽�ģ�壺
        // [left,right)
        long long  left = 0;
        long long  right = sum / k + 1; //ע�������+1

        while (left < right) {
            int mid = left + (right - left) / 2;
            //�жϵ�ǰ��mid�Ƿ���������
            long long heap = 0;
            for (int x : candies) {
                heap += (x / mid);
            }
            if (heap >= k) {    //����������������ƶ�left������left�ǡ��ұ߽�+1��
                left = mid + 1;
            }
            else if (heap < k) {//��������㣬�ƶ�right��ע�ⲻ����mid-1��
                //����midǰһ����������������ô��ǰ��mid�������ս�������ұ߽�+1��������right���ƶ�����-1��
                right = mid;
            }
        }


        //left�Ľ���ǡ��ұ߽�+1��
        return left - 1;
    }
};

int main()
{

    Solution a;
    a.maximumCandies({ 5,6,4,10,10,1,1,2,2,2 }, 9);
    return 0;
}