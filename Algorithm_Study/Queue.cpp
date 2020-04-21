#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;
#include <cstdlib>
using namespace std;

class UnderflowException {};

template<typename T>
class ListNode {
public:
	T value;
	ListNode<T> *next; // ������ ���� nullptr

					   // ������
	ListNode<T>() : next(nullptr) {}
	ListNode<T>(T value1, ListNode<T> *next1) : value(value1), next(next1) {}
};

template<typename T>
class Queue {
public:
	int size;
	ListNode<T> *head, *tail;

	// ������
	Queue<T>() : size(0), head(nullptr), tail(nullptr) {}

	// �Ҹ���
	~Queue<T>() {
		ListNode<T> *t1 = head, *t2;
		while (t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	// ��� �Լ�
	void push(T value) { // �� �ڿ� �� ���� ����
		// ť�� ��� �־��� ���
		if (size == 0) head = tail = new ListNode<T>(value, nullptr);
		// �� ��
		else {
			tail->next = new ListNode<T>(value, nullptr);
			tail = tail->next;
		}
		size++;
	}

	T front() { // �� ���� ���� ��ȯ
		try {
			// ���� ó��: ť�� ��� ����
			if (size == 0) return -1;

			return head->value;
		}
		catch (UnderflowException e) {
			cerr << "ť�� ��� �ִµ� front ������ �õ��߽��ϴ�." << endl;
			exit(1);
		}
	}
	T back() {
		try {
			// ���� ó��: ť�� ��� ����
			if (size == 0) return -1;

			return tail->value;
		}
		catch (UnderflowException e) {
			cerr << "ť�� ��� �ִµ� front ������ �õ��߽��ϴ�." << endl;
			exit(1);
		}
	}

	T pop() { // �� ���� ���� ����
		try {
			// ���� ó��: ť�� ��� ����
			if (size == 0) return -1;

			ListNode<T> *temp = head;
			head = head->next;
			T value = temp->value;
			delete temp;
			if (head == nullptr) tail = nullptr; // ũ�Ⱑ 0�� ��
			size--;
			return value;
		}
		catch (UnderflowException e) {
			cerr << "ť�� ��� �ִµ� pop ������ �õ��߽��ϴ�." << endl;
			exit(2);
		}
	}
	T popBack() {
		try {
			// ���� ó��: ť�� ��� ����
			if (size == 0) return -1;

			ListNode<T> *temp = tail;
			head = head->next;
			T value = temp->value;
			delete temp;
			if (head == nullptr) tail = nullptr; // ũ�Ⱑ 0�� ��
			size--;
			return value;
		}
		catch (UnderflowException e) {
			cerr << "ť�� ��� �ִµ� pop ������ �õ��߽��ϴ�." << endl;
			exit(2);
		}
	}
	int empty() {
		if (size == 0)
			return 1;
		else
			return 0;
	}
};

template<typename T>
ostream& operator <<(ostream &out, const Queue<T> &LL) { // ���ҵ��� �� �ٿ� ���ʴ�� ���
	ListNode<T> *temp = LL.head;
	out << "front [";
	for (int i = 0; i < LL.size; i++) {
		out << temp->value;
		temp = temp->next;
		if (i < LL.size - 1) out << ", ";
	}
	out << "] rear";
	return out;
}
void num10845() {
	int rep, i, num;
	string cmd;
	Queue<int> q;
	scanf_s("%d", &rep);
	for (i = 0; i < rep; i++) {
		cin >> cmd;
		if (!cmd.compare("push")) {
			scanf_s("%d\n", &num);
			q.push(num);
		}
		else if (!cmd.compare("pop")) {
			printf("%d\n", q.pop());
		}
		else if (!cmd.compare("front")) {
			printf("%d\n", q.front());
		}
		else if (!cmd.compare("back")) {
			printf("%d\n", q.back());
		}
		else if (!cmd.compare("size")) {
			printf("%d\n", q.size);
		}
		else if (!cmd.compare("empty")) {
			printf("%d\n", q.empty());
		}
	}
}
void num1966() {

}
void num3078() {
	int n, m, i, j,ans=0;
	scanf_s("%d %d", &n, &m);
	string *names = new string[n];
	Queue<int> q[21];
	//int q[21][300000];
	int top[21] = {};
	for (i = 0; i < n; i++) {
		cin >> names[i];
		q[names[i].size()].push(i);
		//q[names[i].size()][top[i]++]=i;
	}
	
	for (i = 2; i < 21; i++) {
		while (!q[i].empty()) {
			ListNode<int> *temp = q[i].head->next;
			int num = q[i].head->value;
			while (temp!= nullptr) {
				if ((temp->value) - (num)  > m)
					break;
				temp = temp->next;
				ans++;
			}
			q[i].pop();
		}
	}
	
	cout << ans;

}
void num3078_2() {
	int n, m, i, j, ans = 0;
	scanf_s("%d %d", &n, &m);
	string str;
	int *str_len = new int[n];
	for (i = 0; i < n; i++) {
		cin >> str;
		str_len[i] = str.size();
	}
	for (i = 0; i < n-m; i++) {
		for (j = i+1; j <= i+m; j++) {
			if (str_len[i] == str_len[j])
				ans++;
		}
	}
	cout << ans;
}
/*
int main() {
	//num10845();
	//num1966();
	//num3078();
	num3078_2();
}
*/
