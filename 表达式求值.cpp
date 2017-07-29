/*��������
��������һ��ֻ�����Ӽ��Գ������ŵĺϷ����ʽ������ʽ��ֵ�����г���ʾ������
�����ʽ
��������һ�У�����һ�����ʽ��
�����ʽ
�������������ʽ��ֵ��
��������
1-2+3*(4-5)
�������
-4
���ݹ�ģ��Լ��
�������ʽ���Ȳ�����100�����ʽ����Ϸ���������̶���int�ڽ��С�
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXSIZE 1000

typedef struct {
	int Date[MAXSIZE];
	int Top;   
}Stack;

void push(Stack* s, int n);
int pop(Stack* s);
void postfix(Stack* s);

int main()
{
	Stack pofix = { {0}, -1 };
	Stack calculate = {{0}, -1};

	postfix(&pofix);

	for(int i = 0; i <= pofix.Top; i++){
		if(isdigit(pofix.Date[i])){
			push(&calculate, pofix.Date[i++] - '0');
			while(isdigit(pofix.Date [i])){
				calculate.Date[calculate.Top] = calculate.Date[calculate.Top] * 10 + pofix.Date[i++] - '0';
			}
		}
		else if(pofix.Date[i] == '+'){
			push(&calculate, pop(&calculate) + pop(&calculate) );
		}
		else if(pofix.Date[i] == '-'){
			int op2 = pop(&calculate);
			push(&calculate, ( pop(&calculate)- op2 ) );
		}
		else if(pofix.Date[i] == '*'){
			push(&calculate, pop(&calculate) * pop(&calculate) );
		}
		else if(pofix.Date[i] == '/'){
			int op2 = pop(&calculate);
			push(&calculate, pop(&calculate) / op2);
		}
	}

	printf("%d", calculate.Date[0]);
	return 0;
}

void postfix(Stack* s)
{
	Stack sign = { { 0 }, -1 };
	int c;

	while ((c = getchar()) != EOF) {
		if (isdigit(c)) {
			push(s, c);
			while (isdigit(c = getchar())) {
				push(s, c); 
			}
			push(s, ' ');
		}
		if (c == '(') {
			push(&sign, c);
		}
		else if (c == '+' || c == '-') {
			if (sign.Top == -1 || sign.Date[sign.Top] == '(') {
				push(&sign, c);
			}
			else {
				push(s, pop(&sign));
				push(s, ' ');
				push(&sign, c);
			}
		}
		else if (c == '*' || c == '/') {
			if (sign.Top == -1){
				push(&sign, c);
			}
			else {
				if (sign.Date[sign.Top] == '*' || sign.Date[sign.Top] == '/') {
					push(s, pop(&sign));
					push(s, ' ');
					push(&sign, c);
				}
				else {
					push(&sign, c);
				}
			}
		}
		else if (c == ')') {
			while (sign.Date[sign.Top] != '(') {
				push(s, pop(&sign));
				push(s, ' ');
			}
			pop(&sign);
		}
	}
	while(sign.Top >= 0){
		push(s, pop(&sign));
		push(s, ' ');
	}
}

void push(Stack* s, int n)
{
	if (s->Top >= MAXSIZE - 1) {
		printf("stack full up.");
		return;
	}
	else {
		s->Date[++(s->Top)] = n;
		return;
	}
}

int pop(Stack* s)
{
	if (s->Top == -1) {
		printf("stack is empty");
		return 0;
	}
	else {
		return s->Date[(s->Top)--];
	}
}
