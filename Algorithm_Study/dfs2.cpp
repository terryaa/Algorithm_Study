#include <iostream>
#include <queue>

using namespace std;

int n, m, k, trash_size;
int map[101][101];
int check[101][101];
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };

void BFS(int i, int j)
{
	trash_size = 1;
	queue<pair<int, int> > Q;
	Q.push(make_pair(i, j));
	check[i][j] = 1;

	while (!Q.empty())
	{
		int y = Q.front().first;
		int x = Q.front().second;
		Q.pop();

		for (int k = 0; k < 4; k++)
		{
			int yy = y + dy[k];
			int xx = x + dx[k];
			if (yy >= 1 && yy <= n && xx >= 1 && xx <= m)
			{
				if (map[yy][xx] == 1 && check[yy][xx] == 0)
				{
					check[yy][xx] = 1;
					Q.push(make_pair(yy, xx));
					trash_size++;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	//���� ���� N(1 �� N �� 100)�� ���� ���� M(1 �� M �� 100) �׸��� ���Ĺ� �������� ���� K(1 �� K �� 10,000)

	int r, c;
	for (int i = 1; i <= k; i++)
	{//�������� ���� k����ŭ ��ǥ (r,c)�� �Է¹޾� map�� �����⸦ 1�� ǥ���Ѵ�.
		cin >> r >> c;
		map[r][c] = 1;
	}

	int max_size = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			//���� �湮���� ���� �����⸦ �߰��ϸ� BFSŽ�� �����Ѵ�.
			if (map[i][j] == 1 && check[i][j] == 0)
			{
				BFS(i, j);

				//BFSŽ���� ������, ���� trash_size�� ���������� �ִ� ������ ������ max_size�� ��
				if (trash_size > max_size)
					max_size = trash_size;
			}
		}
	}

	//���
	cout << max_size;
	return 0;
}
