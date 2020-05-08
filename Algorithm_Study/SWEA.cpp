#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;



void sum() {

	int board[100][100];
	int sumcol[100];
	int sumrow[100];
	int sumcross[2];
	int rep;

	int max, cross_r, cross_l;
	freopen("C:\\input.txt", "r", stdin);



	for (int i = 0; i < 10; i++) {
		scanf("%d", &rep);
		for (int j = 0; j < 100; j++) {
			for (int k = 0; k < 100; k++){
				scanf("%d", &board[j][k]);
				}
		}

		max = 0;
		cross_r = 0; 
		cross_l = 99; 
		fill(sumcol, sumcol + 100, 0);
		fill(sumrow, sumrow + 100, 0);
		fill(sumcross, sumcross + 2, 0);
		for (int j = 0; j < 100; j++) {
			sumcross[0] += board[j][cross_r++];
			sumcross[1] += board[j][cross_l--];
			for (int k = 0; k < 100; k++) {
				sumrow[k] +=board[j][k];
				sumcol[k] += board[k][j];
			}
		}
		if (sumcross[0] > max) max = sumcross[0];
		if (sumcross[1] > max) max = sumcross[1];
		for(int k=0;k<100;k++){
			if (sumrow[k] > max) max = sumrow[k];
			if (sumcol[k] > max)max = sumcol[k];
		}
		printf("\#%d %d", rep,max);
	}

}
int N, pos=0;
bool visit[11][11];
void queen(int x, int y,int num) {
	bool copy[11][11];

	if (num == N) {
		pos++;
		return;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			copy[i][j] = visit[i][j];
		}
	}
	visit[x][y] = true;
	for (int i = 1; i <= N; i++) {
		visit[x][i] = true;
		visit[i][y] = true;
	}
	int crossl = y, crossr = y;
	for (int i = x; i <= N; i++) {
		if (crossl >= 1) { visit[i][crossl--] = true; }
		if (crossr <= N) { visit[i][crossr++] = true; }
	}
	crossl = y; crossr = y;
	for (int i = x; i > -1; i--) {
		if (crossl >= 1) { visit[i][crossl--] = true; }
		if (crossr <= N) { visit[i][crossr++] = true; }
	}
	for (int j = 1; j <= N; j++) {
		if (visit[x+1][j] == false && num < N) {
			queen(x+1, j, num + 1);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			visit[i][j] = copy[i][j];
		}
	}

}
void n_queen() {
	int rep;
	scanf("%d", &rep);
	
	for (int p = 0; p < rep; p++) {
		scanf("%d", &N);
		pos = 0;
		for (int i = 1; i <= N; i++) {
			queen(1, i, 1);
		}
		for (int i = 1; i <= N; i++) {
			fill(visit[i], visit[i] + N, false);
		}
		printf("\#%d %d\n", rep,pos);
	}

}

int dots[10];
int dots_in[20];
void num1245() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int nums;
		scanf("%d", &nums);
		for (int j = 0; j < nums; j++) {
			int num;
			scanf("%d", &num);
			dots_in[j] = num;
		}
		for (int j = nums; j < nums * 2; j++) {
			int num;
			scanf("%d", &num);
			dots_in[j] = num;
		}
		for (int j = 0; j < nums; j++) {
			int num = dots_in[j];
			dots[num - 1] = dots_in[j+nums];
		}
		
	}
}
int main() {
	//sum();
	num1245();
	//n_queen();
}