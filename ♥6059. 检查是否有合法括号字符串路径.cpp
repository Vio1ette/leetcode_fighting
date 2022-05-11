#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;


// 时间复杂度：因为是DFS，本质是穷举，最坏情况下，总共要遍历的最多的状态为 mn*100


class Solution4 {
public:
	bool res=false;
	bool hasValidPath(vector<vector<char>>& grid) {
		int row = grid.size();
		int col = grid[0].size();
		//stack<char> st;
		vector<vector<vector<int>>> visited(row, vector<vector<int>>(col, vector<int>(100)));
		dfs(grid, row, col, 0, 0,0,visited);
		return res;
	}
	void dfs(vector<vector<char>>& grid,int row, int col,  int i, int j,int cnt,  vector<vector<vector<int>>>& visited) {
		if (i >= row || j >= col) {  //超出范围
			return;
		}
		if (res)return; //已经找到一条路径了
		if (visited[i][j][cnt] != 0) { //已经访问过了，不重复访问 ，注意这里是对状态的检查，而不是单纯得是否访问过这个格子了
			return;
		}
		
		visited[i][j][cnt] = 1; //设置访问标记

		if (grid[i][j] == '(') { //cnt是左、右括号平衡数
			cnt++;
		}
		else cnt--;

		if (cnt < 0)return; //右括号的数目不能比左括号多，否则一定不平衡
		
		if (cnt > (row - 1 - i) + (col - 1 - j))  //cnt的数目如果太大，说明左括号太多，数目已经大于到终点的曼哈顿距离，则没有足够的右括号来平衡了
			return;

		if(i==row-1&&j==col-1){
			if(cnt==0) res = true;
			return;
		}
		dfs(grid, row, col, i + 1, j, cnt,visited);
		dfs(grid, row, col, i, j + 1, cnt,visited);

		//回溯，该怎么回溯呢？ 对于cnt，下一层递归对cnt的变动不会影响当前层，所以不需要回溯cnt的吧，但visited是需要回溯的吧
		// 注意这里visited中存储着状态，也就是说对于同一个格子，会有不同的状态，对于相同的状态，一定会得到相同的结果，所以visited[i][j][cnt]完全不需要回溯
		//visited[i][j][cnt] = 0; 
	}
};




int main(int argc, char* argv[])
{	
	return 0;
}


