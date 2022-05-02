#include <bits/stdc++.h>
using namespace std;

//�������������������ǲ����ˣ��о�����û��׼�������������Ҫ���˵��������path�������ظ�ֵ������û�п���

/*
*���еı����0��1��2��...
* ����֮������ͨ��
* ��0����������
* 1.�ܵ������г��У����ص�0���ֵ���ԽСԽ��
* 2.�ܵ������г��У������ܻص�0���ֵ���ԽСԽ��
* 3.�޷��������г��У�����-1
*/


/*
* ���������
4 4
0 1
0 2
1 3
2 3
*/


//�ڽӱ�

//�߱�ڵ�
//struct EdgeNodes
//{
//	int index;          //��Ӧ�ڶ�����е��±�
//	EdgeNodes* next;    
//};

//�����ڵ�
//struct VertexNodes
//{
//	int val;   //��������ֵ
//	EdgeNodes* head;  //�߱�ͷָ��
//};


//��˼���������·���������άvector��Ȼ������sort�Զ�άvector�������򣬾͵õ��˰��ֵ��������·��

vector<vector<int>> ret;

void dfs(vector<vector<int>>& mp, vector<int>& arr, vector<int>& visited,int remain) {
	if (remain == 0){
		if (mp[arr.back()][0]) {
			arr.push_back(0);
			ret.push_back(arr);
			arr.pop_back(); //���ݵ�ʱ������������Ҫ����pop_backһ��
		}
		else ret.push_back(arr);
		return;
	}
	//�ߵ��Ķ���
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
	
	//�ֵ���
	sort(ret.begin(), ret.end());

	//���������г��У������ص�0��
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i].size() == v + 1 && ret[i].back() == 0) {
			for (int x : ret[i]) {
				cout << x << ' ';
			}
			return 0;
		}
	}

	//���������г��У����޷��ص�0
	for (int i = 0; i < ret.size(); i++) {
		if (ret[i].size() == v) {
			for (int x : ret[i]) {
				cout << x << ' ';
			}
			return 0;
		}
	}

	//�޷����������г���
	cout << -1 << endl;


	return 0;
}



