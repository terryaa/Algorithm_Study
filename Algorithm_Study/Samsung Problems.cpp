// Algorithm Study.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include<cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int n, m, i, j;

int pick(int nums, int **arr, int row, int col) {
	for (int x = row; i < n; i++)
		for (int y = col; j < m; j++) {
			if (arr[x][y] == 0) {
				nums++;
				arr[x][y] = 1;
				if (nums == 3) {
					//2���̷���������
					//�ִ밹���� ��
					arr[x][y] = 0;
					nums--;
					if (y + 1 < m)
						pick(nums, arr, x, y + 1);
					else {
						if (x + 1 < n)
							pick(nums, arr, x + 1, 0);
						else
							return 0;
					}
				}
				else {
					if (y + 1 < m)
						pick(nums, arr, x, y + 1);
					else {
						if (x + 1 < n)
							pick(nums, arr, x + 1, 0);
						else
							return 0;
					}

				}
			}
		}
};

int r, c, t;
int clean[2];
void printarr(int **arr) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}
int** expandgas(int i, int j, int **arr, int **expand) {
	int num = arr[i][j];
	int count = 0;
	//��
	if (j > 0) {
		if (arr[i][j - 1] != -1) {
			expand[i][j - 1] += num / 5;
			count++;
		}
	}
	//��
	if (i > 0) {
		if (arr[i - 1][j] != -1) {
			expand[i - 1][j] += num / 5;
			count++;
		}

	}
	//����
	if (j < c - 1) {
		expand[i][j + 1] += num / 5;
		count++;

	}
	//��
	if (i < r - 1) {
		if (arr[i + 1][j] != -1) {
			expand[i + 1][j] += num / 5;
			count++;
		}
	}
	arr[i][j] = num - (num / 5)*count;
	return expand;
}
int** clean_up(int** arr, int x) {
	for (int i = x - 1; i > 0; i--) {
		arr[i][0] = arr[i - 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		arr[0][i] = arr[0][i + 1];
	}
	for (int i = 0; i < x; i++) {
		arr[i][c - 1] = arr[i + 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		arr[x][i] = arr[x][i - 1];
	}
	arr[x][1] = 0;
	return arr;
}
int** clean_down(int **arr, int x) {
	for (int i = x + 1; i < r - 1; i++) {
		arr[i][0] = arr[i + 1][0];
	}
	for (int i = 0; i < c - 1; i++) {
		arr[r - 1][i] = arr[r - 1][i + 1];
	}
	for (int i = r - 1; i > x; i--) {
		arr[i][c - 1] = arr[i - 1][c - 1];
	}
	for (int i = c - 1; i > 1; i--) {
		arr[x][i] = arr[x][i - 1];
	}
	arr[x][1] = 0;
	return arr;
}


void num17144() {
	scanf_s("%d %d %d", &r, &c, &t);
	int **arr = new int*[r];
	int **expand = new int*[r];
	int head = 0;
	for (int i = 0; i < r; i++) {
		arr[i] = new int[c];
		expand[i] = new int[c];
		for (int j = 0; j < c; j++) {
			scanf_s("%d", &arr[i][j]);
			if (arr[i][j] == -1) {
				clean[head++] = i;
			}
			expand[i][j] = 0;
		}
	}
	for (int rep = 0; rep < t; rep++) {
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				if (arr[i][j] > 0) {
					expandgas(i, j, arr, expand);
				}
			}

		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++) {
				arr[i][j] += expand[i][j];
				expand[i][j] = 0;
			}
		arr = clean_up(arr, clean[0]);
		arr = clean_down(arr, clean[1]);
	}
	int ans = 0;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			ans += arr[i][j];
		}
	printf("%d", ans + 2);
}
void num14502() {
	scanf_s("%d %d", &n, &m);
	int **arr = new int*[n];
	for (i = 0; i < n; i++) {
		arr[i] = new int[m];
	}
	pick(0, arr, 0, 0);
}

int A[21][21];
int N;
int Check(int x, int y, int i, int j) {

	//1���ű�
	int area[5] = {};
	int l;
	for (int p = 1; p < x + i; p++)
		for (int k = 1, end = y; k <= end;k++)
		{
			area[0] += A[p][k];
			if (p >= x) end--;
		}
	//2���ű�
	for (int p = 1; p <=x + j; p++)
		for (int k = y + 1; k <= N;) {
			area[1] += A[p][k];
			if (p >= x) k++;
		}
	//3���ű�
	for (int p = x + i; p <= N; p++)
		for (int k = 1; k < y - i + j; ) {
			area[2] += A[p][k];
			if (p <= x + i+j) k++;
		}
	//4���ű�
	for (int p = x + j+1; x <= N; x++)
		for (int k = y - i + j; k <= N; k++) {
			area[3] += A[p][k];
			if (p <= x + i + j) k--;
		}
	//5���ű�
	int s=y, e=y;
	bool turn1=false, turn2=false;
	for (int p = x; p <= x + i + j; p++) {
		for (int k = s; k <= e; k++)
			area[4] += A[p][k];
		if (s <= y - i)
			turn1 = true;
		if (turn1)
			s++;
		else
			s--;
		if (e >= y + j)
			turn2 = true;
		if (turn2)
			e--;
		else
			e++;
		
	}
	sort(area, area + 5);
	return area[4] - area[0];
}
void num17779() {
	int pop,best=INT_MAX;
	scanf_s("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			scanf_s("%d", &pop);
			A[i][j] = pop ;
		}
	for(int i=1;i<=N-1;i++)
		for (int j = 1; j <= N - 1; j++)
		{
			for(int x=1;x<=N;x++)
				for (int y = 2; y <= N-1; y++)
					if (x + i + j <= N && y + j <= N && y-i<y) {
						best=min(best,Check(x, y, i, j));
					}
		}
	printf("%d", best);
}



int check[20][20] = {};

//�������� �����ε�������
//�������ε��� 0ó��

void show(int board[][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf("%d ", board[i][j]);
		printf("\n");
	}
}
int(*push_right(int board[][20]))[20]{
	int nums;
	for (int i = 0; i < N; i++) {
		nums = N - 1;
		for (int j = N - 1; j > -1; j--) {
			//�����
			
			if (board[i][j] != 0) {
				if (j == 0) {
					int temp = board[i][j];
					board[i][j] = 0;
					board[i][nums] = temp;
				}
				else {
					for (int k = j - 1; k > -1; k--) {
						if (board[i][k] != 0) {
							if (board[i][j] == board[i][k]) {
								board[i][j] = 0;
								board[i][nums--] = board[i][k] * 2;
								board[i][k] = 0;
							}
							else {
								int temp = board[i][j];
								board[i][j] = 0;
								board[i][nums--] = temp;
							}
							j = k+1;
							break;
						}
					}
				}
			}
		}
	}
	return board;
}
int(*push_up(int board[][20]))[20]{
	int nums;
	for (int j = 0; j < N; j++) {
		nums = 0;
		for (int i = 0; i < N; i++) {
			if (board[i][j] != 0) {
				if (i==N-1) {
					int temp = board[i][j];
					board[i][j] = 0;
					board[nums][j] = temp;
				}
				else {
					for (int k = i + 1; k < N; k++) {
						if (board[k][j] != 0) {
							if (board[i][j] == board[k][j]) {
								board[i][j] = 0;
								board[nums++][j] = board[k][j] * 2;
								board[k][j] = 0;
							}
							else {
								int temp = board[i][j];
								board[i][j] = 0;
								board[nums++][j] = temp;
							}
							i = k - 1;
							break;
						}
					}
				}
			}
		}
	}
	return board;
}
int(*push_left(int board[][20]))[20]{
	int nums;
	for (int i = 0; i < N; i++) {
		nums = 0;
		for (int j = 0; j < N; j++) {
			if (board[i][j] != 0) {
				if (j == N - 1) {
					int temp = board[i][j];
					board[i][j] = 0;
					board[i][nums] = temp;
				}
				else {
					for (int k = j + 1; k < N; k++) {
						if (board[i][k] != 0) {
							if (board[i][j] == board[i][k]) {
								board[i][j] = 0;
								board[i][nums++] = board[i][k] * 2;
								board[i][k] = 0;
							}
							else {
								int temp = board[i][j];
								board[i][j] = 0;
								board[i][nums++] = temp;
							}
							j = k - 1;
							break;
						}

					}
				}
			}
		}
	}
	return board;
}
int (*push_down(int board[][20]))[20] {
	int nums;
	for (int j = 0; j < N;j++) {
		nums = N - 1;
		for (int i = N - 1; i > -1; i--) {
			if (board[i][j] != 0) {
				if (i == 0) {
					int temp = board[i][j];
					board[i][j] = 0;
					board[nums][j] = temp;
				}
				else {
					for (int k = i - 1; k > -1; k--) {
						if (board[k][j] != 0) {
							if (board[k][j] == board[i][j]) {
								board[i][j] = 0;
								board[nums--][j] = board[k][j] * 2;
								board[k][j] = 0;
							}
							else {
								int temp = board[i][j];
								board[i][j] = 0;
								board[nums--][j] = temp;
							}
							i = k + 1;
							break;
						}
					}
				}
			}
		}
	}
	return board;
}

int start(int depth,int board[][20]) {
	int ans = 0;
	if (depth == 5) {
		int max = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (max < board[i][j]) max = board[i][j];
		return max;
	}
	push_left(board);
	ans=max(ans,start(depth + 1, board));
	push_right(board);
	ans=max(ans,start(depth + 1, board));
	push_up(board);
	ans=max(ans,start(depth + 1, board));
	push_down(board);
	ans=max(ans,start(depth + 1, board));
	return ans;
}
void num12100() {
	int board[20][20];
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &board[i][j]);
	//push_up(board);
	//push_right(board);
	push_left(board);
	//push_down(board);
	show(board);
	//int ans=start(0, board);
	//printf("%d", ans);
}


int team[21][21];
bool check2[21] = {};
int team1 = 0, team2 = 0;
int mini = INT_MAX;

void maketeam(int mem,int count) {
	check2[mem] = true;
	if (count == N / 2) {
		for(int i=1;i<=N;i++){
			for (int j = 1; j <= N; j++) {
				if (i != j&&check2[i]==true&&check2[j]==true) {
					team1 += team[i][j];
				}
				if (i != j && check2[i] == false && check2[j] == false) {
					team2 += team[i][j];
				}
			}
		}
		int sub = abs(team1 - team2);
		if ( sub< mini) {
			mini = sub;
		}
		team1 = 0; team2 = 0;
		return;
	}

	for (int i = mem+1; i <= N; i++) {
		count++;
		maketeam(i,count);
		check2[i] = false;
		count--;
	}
}

void num14889() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &team[i][j]);
		}
	}
	for (int i = 1; i <= N/2; i++) {
		maketeam(i,1);
		fill(check2, check2 + 21, false);
	}
	printf("%d", mini);

}

int cogs[4][8];

void clockwise(int num) {
	int temp = cogs[num][7];
	for (int i = 7; i >=1; i--) {
		cogs[num][i] = cogs[num][i-1];
	}
	cogs[num][0] = temp;

}
void counterwise(int num) {
	int temp = cogs[num][0];
	for (int i = 0; i <= 6; i++) {
		cogs[num][i] = cogs[num][i + 1];
	}
	cogs[num][7] = temp;
}
void turn(int num, int way,int point) {
	int prev = num - 1, next = num + 1;
	if (prev >-1 && point!=2 && cogs[num][6]!=cogs[prev][2]) {
		if (way == 1)
			turn(prev, -1, 1);
		else
			turn(prev, 1, 1);
	}
	if (next < 4 && point != 1&&cogs[num][2]!=cogs[next][6]) {
		if (way == 1)
			turn(next, -1, 2);
		else
			turn(next, 1, 2);
	}
	if (way == 1)
		clockwise(num);
	else
		counterwise(num);
}
void num14891() {
	string str;
	for (int i = 0; i < 4; i++) {
		cin >> str;
		cin.ignore(256, '\n');
		for (int j = 0; j < 8; j++) {
			cogs[i][j] = str[j]-'0';
		}
	}
	scanf("%d", &N);
	int a, b;
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		turn(a-1, b,0);
	}
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		if (cogs[i][0] == 1) {
			sum += pow(2, i);
		}
	}
	printf("%d", sum);
}

int flooor[50][50];
int M;
int a, b,dir;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
int four[4] = { 0,1,2,3 };
int dx2[4] = { 1,0,-1,0 };
int dy2[4] = { 0,-1,0,1 };
int cnt = 1;
bool go() {
	flooor[a][b] = 2;
	int nextx;
	int nexty;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			nextx = a + dx[dir];
			nexty = b + dy[dir];
			dir--;
			if (dir == -1)
				dir = 3;
			if (flooor[nextx][nexty] == 0) {
				cnt++;
				a = nextx;
				b = nexty;
				return false;
			}
			
		}
	a = a+dx2[dir];
	b = b+dy2[dir];
	if (flooor[a][b] == 1)
		return true;
	else {
		return false;
	}
}
void num14503() {
	
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &a, &b,&dir);
	for (int i = 0; i < N;i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d",&flooor[i][j]);
		}
	}
	while (true) {
		if (go())
			break;
	}
	printf("%d", cnt);

}

int main()
{
	//num14502();
	//num17144();
	//num17779();
	//��ǰ
	num12100();
	//num14889();
	//num14891();
	//num14503();

}




// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.


//to fix solution