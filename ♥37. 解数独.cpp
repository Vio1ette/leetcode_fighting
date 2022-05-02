#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


//困难题，比较麻烦，回溯+状态压缩，回溯的是状态

/*
* 为啥不会?
* 状态压缩不熟悉
* 
* getPossibileStatus根据行、列、宫，返回这个位置的所有可能值（状态），是实时获取的，所以改变一个格子的状态时，不需要考虑其他格子
* getNext()返回可能数最小的格子
* dfs()进行状态穷举
*/

class Solution {
public:

    //根据行、列、宫，返回这个位置的所有可能值（状态）
    bitset<9> getPossibleStatus(int x, int y) {
        //注意这里的cells[x/3][y/3]，一个bitset就可以表示一个宫的状态，x/3，y/3，将格子坐标转为宫坐标
        //例如(6,6)->(2,2)，(6,7)->(2,2)，因为它们都属于同一个宫
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }

    //返回具有最小可能数的格子坐标
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

    //标准回溯
    bool dfs(vector<vector<char>>& board, int cnt) {
        if (cnt == 0)return true; //cnt表示剩余未填空个数

        auto next = getNext(board);
        //每次都重新计算一下可能的值，所以填数的时候不用考虑其他格子的状态变化，因为在访问它们时，会实时获得它们的状态
        auto bits = getPossibleStatus(next[0], next[1]);
        for (int n = 0; n < bits.size(); n++) {
            if (!bits.test(n))continue;
            //现在是在操作状态，例如逻辑上是填1，但是状态上，是第0位置1
            fillNum(next[0], next[1], n, true);
            //现在真正地改变board
            board[next[0]][next[1]] = n + '1';

            //分界线——————————————
            if (dfs(board, cnt - 1))return true;
            //分界线——————————————

            //回溯
            board[next[0]][next[1]] = '.';
            fillNum(next[0], next[1], n, false);
        }
        return false;

    }

    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
        //计算cnt
        //初始化状态
        int cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') {
                    cnt++;
                    continue;
                }
                //状态初始化
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);

    }

private:
    //行、列、九宫格
    vector<bitset<9>> rows;//9位表示一个格子的状态
    vector<bitset<9>> cols;
    // cells记录着9个宫的状态，每个宫有9个bitset表示9个格子的状态
    vector<vector<bitset<9>>> cells;

};

int main()
{

	return 0;
}



