#include <bits/stdc++.h>
#include <list>
#include <iostream>

using namespace std;


// ʱ�临�Ӷȣ���Ϊ��DFS����������٣������£��ܹ�Ҫ����������״̬Ϊ mn*100


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
		if (i >= row || j >= col) {  //������Χ
			return;
		}
		if (res)return; //�Ѿ��ҵ�һ��·����
		if (visited[i][j][cnt] != 0) { //�Ѿ����ʹ��ˣ����ظ����� ��ע�������Ƕ�״̬�ļ�飬�����ǵ������Ƿ���ʹ����������
			return;
		}
		
		visited[i][j][cnt] = 1; //���÷��ʱ��

		if (grid[i][j] == '(') { //cnt����������ƽ����
			cnt++;
		}
		else cnt--;

		if (cnt < 0)return; //�����ŵ���Ŀ���ܱ������Ŷ࣬����һ����ƽ��
		
		if (cnt > (row - 1 - i) + (col - 1 - j))  //cnt����Ŀ���̫��˵��������̫�࣬��Ŀ�Ѿ����ڵ��յ�������پ��룬��û���㹻����������ƽ����
			return;

		if(i==row-1&&j==col-1){
			if(cnt==0) res = true;
			return;
		}
		dfs(grid, row, col, i + 1, j, cnt,visited);
		dfs(grid, row, col, i, j + 1, cnt,visited);

		//���ݣ�����ô�����أ� ����cnt����һ��ݹ��cnt�ı䶯����Ӱ�쵱ǰ�㣬���Բ���Ҫ����cnt�İɣ���visited����Ҫ���ݵİ�
		// ע������visited�д洢��״̬��Ҳ����˵����ͬһ�����ӣ����в�ͬ��״̬��������ͬ��״̬��һ����õ���ͬ�Ľ��������visited[i][j][cnt]��ȫ����Ҫ����
		//visited[i][j][cnt] = 0; 
	}
};




int main(int argc, char* argv[])
{	
	return 0;
}


