#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int convertTime(string current, string correct) {
        int ret = 0;
        if (current > correct) {
            int temp = stoi(correct.substr(0, 2));
            temp += 24;
            char f1 = temp % 10 + '0';
            temp /= 10;
            char f0 = temp % 10 + '0';
            correct[1] = f1;
            correct[0] = f0;
        }

        int hour = stoi(correct.substr(0, 2)) - stoi(current.substr(0, 2));

        int minute = stoi(correct.substr(3, 2)) - stoi(current.substr(3, 2));

        int delta15 = minute / 15;

        minute -= delta15 * 15;
        

        int delta5 = minute / 5;
        minute -= delta5 * 5;

        int delta1 = minute;

        ret += hour + delta15 + delta5 + delta1;
        return ret;
    }
};

int main()
{

    Solution a;
    a.convertTime("02:30", "04:35");
    return 0;
}