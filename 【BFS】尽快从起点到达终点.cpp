#include <bits/stdc++.h>
using namespace std;

//BFS经典题，细心一点，题不难，只是会有点麻烦

int BFS(vector<string>& mp,int row, int col, pair<int,int> start) {
	queue<pair<int, int>> qe;
	vector<vector<int>> move_{
		{0,-1},
		{0,1},
		{-1,0},
		{1,0}
	};
	vector<vector<int>> visited(row, vector<int>(col, 0));
	qe.push(start);
	int t = 0;
	int cur = 1;
	int next = 0;
	while (!qe.empty()) {
		//往下一层探索，秒数+1
		t++;
		while (cur--) {
			auto temp = qe.front();
			qe.pop();
			//怎么方便地表示上下左右的移动呢？
			for (int i = 0; i < 4; i++) {
				pair<int, int> point = { temp.first + move_[i][0],temp.second + move_[i][1] };
				if (point.first < 0 || point.first >= row || point.second < 0 || point.second >= col||visited[point.first][point.second]||mp[point.first][point.second]=='X')
					continue;
				if (mp[point.first][point.second] == 'E') {
					return t;
				}
				visited[point.first][point.second] = 1;
				qe.push(point);
				next++;
			}
		}
		cur = next;
		next = 0;
	}
	return -1;
}

int Key_BFS(vector<string>& mp, int row, int col, int key_num, pair<int, int> start) {
	queue<pair<int, int>> qe;
	vector<vector<int>> move_{
		{0,-1},
		{0,1},
		{-1,0},
		{1,0}
	};
	vector<vector<int>> visited(row, vector<int>(col, 0));
	qe.push(start);
	int t = 0;
	int cur = 1;
	int next = 0;
	while (!qe.empty()) {
		//往下一层探索，秒数+1
		t++;
		while (cur--) {
			auto temp = qe.front();
			qe.pop();
			//怎么方便地表示上下左右的移动呢？
			for (int i = 0; i < 4; i++) {
				pair<int, int> point = { temp.first + move_[i][0],temp.second + move_[i][1] };
				if (point.first < 0 || point.first >= row || point.second < 0 || point.second >= col || visited[point.first][point.second] || mp[point.first][point.second] == 'X')
					continue;
				if (mp[point.first][point.second] == 'K') {
					key_num--;
					if (key_num == 0) {
						return t + BFS(mp, row, col, point);
					}
				}
				visited[point.first][point.second] = 1;
				qe.push(point);
				next++;
			}
		}
		cur = next;
		next = 0;
	}
	return -1;
}


int main()
{	
	vector<string> mp{
		"OOOOO",
		"SKEOK",
		"OOOOO"
	};
	pair<int, int> start{-1,-1};
	int row = mp.size();
	int col = mp[0].size();
	int key_num = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (mp[i][j] == 'S') {
				start.first = i;
				start.second = j;
			}
			if (mp[i][j] == 'K') {
				key_num++;
			}
		}
	}

	int res = Key_BFS(mp, row, col, key_num, start);
	cout << ' ';
	return 0;
}



