#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

#include <iostream>
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
class Stack {
public:
	int size;
	ListNode<T> *tail;

	// ������
	Stack<T>() : size(0), tail(nullptr) {}

	// �Ҹ���
	~Stack<T>() {
		ListNode<T> *t1 = tail, *t2;
		while (t1 != nullptr) {
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}

	// ��� �Լ�
	void push(T value) { // �� ���� �� ���� ����
		tail = new ListNode<T>(value, tail);
		size++;
	}

	T top() { // �� ���� ���� ��ȯ
		try {
			// ���� ó��: ������ ��� ����
			if (size == 0) throw UnderflowException();

			return tail->value;
		}
		catch (UnderflowException e) {
			cerr << "������ ��� �ִµ� top ������ �õ��߽��ϴ�." << endl;
			exit(1);
		}
	}

	void pop() { // �� ���� ���� ����
		try {
			// ���� ó��: ������ ��� ����
			if (size == 0) throw UnderflowException();

			ListNode<T> *temp = tail->next;
			delete tail;
			tail = temp;
			size--;
		}
		catch (UnderflowException e) {
			cerr << "������ ��� �ִµ� pop ������ �õ��߽��ϴ�." << endl;
			exit(2);
		}
	}
};

template<typename T>
ostream& operator <<(ostream &out, const Stack<T> &LL) { // ���ҵ��� �� �ٿ� ���ʴ�� ���
	ListNode<T> *temp = LL.tail;
	out << "top [";
	for (int i = 0; i < LL.size; i++) {
		out << temp->value;
		temp = temp->next;
		if (i < LL.size - 1) out << ", ";
	}
	out << "] bottom";
	return out;
}

char stack[100];
int stackk[100000];
int top = -1;
void push(char item) {
	top++;
	stack[top]=item;
}
/*
char pop() {
	return stack[top--];
}*/
void push(int item) {
	top++;
	stack[top] = item;
}
int pop() {
	return stack[top--];
}
void calculate(char letter) {
	switch (letter) {
	case '+': case '-':
		if (top == -1 || stack[top] == '(')
			push(letter);
		else {
			printf("%c",pop());
			calculate(letter);
		}
		break;
	case '*': case'/':
			if (top == -1 || stack[top] == '(' || stack[top] == '+' || stack[top] == '-')
				push(letter);
			else {
				printf("%c", pop());
				calculate(letter);
			}
			break;
	case '(':
		push(letter);
		break;
	case ')':
		while (true) {
			char temp = pop();
			if (temp == '(') break;
			else printf("%c", temp);
		}
		break;
	default:
		printf("%c", letter);
	}
}
void num1918() {
	string str;
	int num,i;
	cin>>str;
	for (i = 0; i < str.size();i++) {
		calculate(str[i]);
	}
	while (top != -1) {
		printf("%c", pop());
	}
}
void calcal(int num) {

}
void num1725() {
	int rep,num,max=0;
	scanf_s("%d", &rep);
	scanf_s("%d", &num);
	push(num);
	int pre;
	for (int i = 1; i < rep; i++) {
		scanf_s("%d", num);
		if (stack[top] < num)
			push(num);
		else {
			pre = pop();
			if (top == -1) {
				if(max>(pre*i)) max = pre * i;
			}
			else {
				//���ÿ����ٷξƷ�������׷������ǰŸ�
				if (max > pre*(i - top + 1)) max = pre * (i - top + 1);
				while (stack[top] >= num) {
					if(max>pre*(i-top+1)) max = pre * (i - top+1);
					pre = pop();
				}
			}
			push(num);
		}
	}

}/*
int main() {
	num1918();

	//������׷� ��Ƴ�
	//num1725(); 
}*/