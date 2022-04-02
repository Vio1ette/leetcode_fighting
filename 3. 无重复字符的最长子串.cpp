#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

//˫ָ��+��ϣ��
//���ⲻ�ѣ���ϸ����Ҫע����
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int left = 0;
        int right = 0;
        int ret = 0;
        while (right < s.size())
        {
            if (mp.find(s[right]) != mp.end()) //�������ظ�
            {
                if (mp[s[right]] >= left) {  //@��������������ظ������㣬������left
                    ret = max(ret, right - left);
                    left = mp[s[right]] + 1;
                }
                mp[s[right]] = right;  //@�����ظ��ǲ����ڻ����������⣬����ǰ�ַ��Ĺ�ϣλ��һ��Ҫ���µ�
            }
            else
            {
                mp.insert({ s[right], right });
            }
            right++;
        }
        ret = max(ret, right - left);  //@������right��ĩβ��ҲҪ����һ��ret
        return ret;
    }
};

int main()
{

    Solution a;
    a.lengthOfLongestSubstring("aabaab!bb");

    return 0;
}