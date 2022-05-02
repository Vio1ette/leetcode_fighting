#include <bits/stdc++.h>
using namespace std;

//大概题面是这样，具体记不清了，感觉题面没看准，如果遇到必须要回退的情况，那path里会包含重复值，这种没有考虑

/*
*城市的编号是0，1，2，...
* 城市之间有连通性
* 从0出发，返回
* 1.能到达所有城市，最后回到0，字典序越小越好
* 2.能到达所有城市，但不能回到0，字典序越小越好
* 3.无法到达所有城市，返回-1
*/


/*
* 输入输出：
4 4
0 1
0 2
1 3
2 3
*/


//邻接表

//边表节点
//struct EdgeNodes
//{
//	int index;          //对应在顶点表中的下标
//	EdgeNodes* next;    
//};

//顶点表节点
//struct VertexNodes
//{
//	int val;   //顶点数据值
//	EdgeNodes* head;  //边表头指针
//};


//我思：求出所有路径，放入二维vector，然后再用sort对二维vector进行排序，就得到了按字典序升序的路径

vector<vector<int>> ret;

void dfs(vector<vector<int>>& mp, vector<int>& arr, vector<int>& visited,int remain) {
	if (remain == 0){
		if (mp[arr.back()][0]) {
			arr.push_back(0);
			ret.push_back(arr);
			arr.pop_back(); //回溯的时候的特殊情况，要单独pop_back一次
		}
		else ret.push_back(arr);
		return;
	}
	//走到哪儿了
	int cur = arr.back();

	for (int j = 0; j < mp.size(); j++) {
		if (cur == 0 && j == 0)continue;
		if (mp[cur][j] && !visited[j]) {
			visited[j] = 1;
			arr.push_back(j);
			dfs(mp, arr, visited, remain - 1);
			visited[j] = 0;
			arr.pop_back();
		}
	}
}


int main()
{
	int v, e;
	//cin >> v >> e;
	v = 4;
	e = 4;
	vector<vector<int>> mp{ 
		{0,0,0,1},
		{1,0,0,1},
		{1,0,0,1},
		{0,1,1,0}
	};

	//vector<VertexNodes> vertex;
	//for (int i = 0; i < vertex.size(); i++) {
		//vertex[i].val = i;
		//vertex[i].head = nullptr;
	//}


	//while (e--) {
	//	int i, j;
	//	while (cin >> i >> j) {

	//		mp[i][j] = 1;
	//		mp[j][i] = 1;
	//	}
	//}


	vector<int> visited(v);
	int remain = v-1;
	

	vector<int> path;
	path.push_back(0);
	visited[0] = 1;
	dfs(mp, path, visited, remain);
	
	//字典序
	sort(ret.begin(), ret.end());

	//遍历完所有城市，且最后回到0了
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i].size() == v + 1 && ret[i].back() == 0) {
			for (int x : ret[i]) {
				cout << x << ' ';
			}
			return 0;
		}
	}

	//遍历完所有城市，但无法回到0
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i].size() == v) {
			for (int x : ret[i]) {
				cout << x << ' ';
			}
			return 0;
		}
	}

	//无法遍历完所有城市
	cout << -1 << endl;


	return 0;
}



