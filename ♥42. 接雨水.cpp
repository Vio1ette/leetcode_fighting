#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//��������ȫȫ�����Լ������������ֵ�ñ���
//����˼·��
//����һ����ˮ������϶��ĳ�����һ����״��ͼ
//1. ��ǰ
//��һ�α������ڷ���ߣ���˳���¼�ǵݼ������ӣ��±꣬�߶ȣ�����Ϊ����ǰ����������ˮ���ᳬ�����ǵ�
//��ǰ������֮��ĵط���Ҫô����ˮ��Ҫô�ǰ�С����
//��ǰ���ܹ��ӵ���ˮ = ����ǰ������֮��Ŀ�϶��� - ����֮��İ�С������ռ���
//
//2.���
//���������򣬰�ͬ���ķ�ʽ�����������ķ�ǰ��

//ʱ�临�Ӷȣ�O(N)��NΪ height ���鳤��
class Solution {
public:
    int trap(vector<int> height) {
    
        int max_num = INT_MIN;
        int max_index = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] >= max_num) {
                max_num = height[i];
                max_index = i;
            }
        }

        queue<pair<int, int>> qe;
        qe.push({ 0,height[0] });
        int remain = 0;
        for (int i = 1; i <= max_index; i++) {
            if (height[i] >= qe.back().second) {
                qe.push({ i,height[i] });
            }
            else remain += height[i];
        }

        int area = 0;
        while (qe.size() > 1) {
            pair<int, int> temp = qe.front();
            qe.pop();
            area += (qe.front().first - temp.first - 1) * min(qe.front().second, temp.second);
        }
        if (max_index == height.size() - 1)return area - remain;

        //����
        reverse(height.begin(), height.end());

        max_index = height.size()-max_index-1;
        queue<pair<int, int>> qe1;
        qe1.push({ 0,height[0] });
        for (int i = 1; i <= max_index; i++) {
            if (height[i] >= qe1.back().second) {
                qe1.push({ i,height[i] });
            }
            else  remain += height[i];
        }

        while (qe1.size() > 1) {
            pair<int, int> temp = qe1.front();
            qe1.pop();
            area += (qe1.front().first - temp.first - 1) * min(qe1.front().second, temp.second);
        }
        return area - remain;
    }
};

int main()
{
    Solution a;
    a.trap({ 5,5,1,7,1,1,5,2,7,6});
	return 0;
}