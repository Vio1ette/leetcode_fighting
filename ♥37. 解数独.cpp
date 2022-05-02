#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//�����⣬�Ƚ��鷳������+״̬ѹ�������ݵ���״̬

/*
* Ϊɶ����?
* ״̬ѹ������Ϥ
* 
* getPossibileStatus�����С��С������������λ�õ����п���ֵ��״̬������ʵʱ��ȡ�ģ����Ըı�һ�����ӵ�״̬ʱ������Ҫ������������
* getNext()���ؿ�������С�ĸ���
* dfs()����״̬���
*/

class Solution {
public:

    //�����С��С������������λ�õ����п���ֵ��״̬��
    bitset<9> getPossibleStatus(int x, int y) {
        //ע�������cells[x/3][y/3]��һ��bitset�Ϳ��Ա�ʾһ������״̬��x/3��y/3������������תΪ������
        //����(6,6)->(2,2)��(6,7)->(2,2)����Ϊ���Ƕ�����ͬһ����
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    //���ؾ�����С�������ĸ�������
    vector<int> getNext(vector<vector<char>>& board) {
        int minCnt = 10;
        vector<int> res;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.')continue;
                int cur = getPossibleStatus(i, j).count();
                if (cur >= minCnt)continue;
                minCnt = cur;
                res = { i,j };
            }
        }
        return res;
    }

    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = fillFlag ? 1 : 0;
        cols[y][n] = fillFlag ? 1 : 0;
        cells[x / 3][y / 3][n] = fillFlag ? 1 : 0;
    }

    //��׼����
    bool dfs(vector<vector<char>>& board, int cnt) {
        if (cnt == 0)return true; //cnt��ʾʣ��δ��ո���

        auto next = getNext(board);
        //ÿ�ζ����¼���һ�¿��ܵ�ֵ������������ʱ���ÿ����������ӵ�״̬�仯����Ϊ�ڷ�������ʱ����ʵʱ������ǵ�״̬
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++) {
            if (!bits.test(n))continue;
            //�������ڲ���״̬�������߼�������1������״̬�ϣ��ǵ�0λ��1
            fillNum(next[0], next[1], n, true);
            //���������ظı�board
            board[next[0]][next[1]] = n + '1';

            //�ֽ��ߡ���������������������������
            if (dfs(board, cnt - 1))return true;
            //�ֽ��ߡ���������������������������

            //����
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
        //����cnt
        //��ʼ��״̬
        int cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    cnt++;
                    continue;
                }
                //״̬��ʼ��
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);

    }

private:
    //�С��С��Ź���
    vector<bitset<9>> rows;//9λ��ʾһ�����ӵ�״̬
    vector<bitset<9>> cols;
    // cells��¼��9������״̬��ÿ������9��bitset��ʾ9�����ӵ�״̬
    vector<vector<bitset<9>>> cells;

};

int main()
{

	return 0;
}



