// Algo Study.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//
//C++ ����� ���ع���Ǯ��
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;



void num10950() {
	int num = 0;
	cin >> num;
	int **abs = new int*[num];
	for (int i = 0; i < num; i++) {
		abs[i] = new int[2];
		cin >> abs[i][0] >> abs[i][1];
		cout << (abs[i][0] + abs[i][1]) << '\n';
	}
}

int num10951() {
	int a, b;
	while (scanf_s("%d%d", &a, &b) != EOF)
		printf("%d\n", a + b);
	return 0;
}
int num10952() {
	int a = -1, b = -1;
	while (scanf_s("%d%d", &a, &b) != EOF && a != 0 && b != 0)
		printf("%d\n", a + b);
	return 0;
}

int num2675() {
	int num;
	scanf_s("%d", &num);
	while (num--) {
		int n;
		string str;
		cin >> n >> str;
		for (int i = 0; i < str.size(); i++)
			for (int j = 0; j < n; j++) {
				printf("%c", str[i]);
			}
		printf("\n");
	}
	return 0;
}
int num1100() {
	int var = 0, count = 0;
	string str;
	for (int i = 0; i < 8; i++) {
		cin >> str;
		for (int j = var % 2; j < 8; j += 2) {
			if (str[j] == 'F') {
				count++;
			}
		}
		var++;
	}
	printf("%d", count);
	return 0;
}

/*int main()
{

	//num10950();
	//num10951();
	//num10952();
	//num2675();
	//num1100();
} */
// ���α׷� ����: <Ctrl+F5> �Ǵ� [�����] > [��������� �ʰ� ����] �޴�
// ���α׷� �����: <F5> Ű �Ǵ� [�����] > [����� ����] �޴�

// ������ ���� ��: 
//   1. [�ַ�� Ž����] â�� ����Ͽ� ������ �߰�/�����մϴ�.
//   2. [�� Ž����] â�� ����Ͽ� �ҽ� ��� �����մϴ�.
//   3. [���] â�� ����Ͽ� ���� ��� �� ��Ÿ �޽����� Ȯ���մϴ�.
//   4. [���� ���] â�� ����Ͽ� ������ ���ϴ�.
//   5. [������Ʈ] > [�� �׸� �߰�]�� �̵��Ͽ� �� �ڵ� ������ ����ų�, [������Ʈ] > [���� �׸� �߰�]�� �̵��Ͽ� ���� �ڵ� ������ ������Ʈ�� �߰��մϴ�.
//   6. ���߿� �� ������Ʈ�� �ٽ� ������ [����] > [����] > [������Ʈ]�� �̵��ϰ� .sln ������ �����մϴ�.
