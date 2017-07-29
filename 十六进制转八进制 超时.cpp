#include <stdio.h>
#include <string.h>
#include <ctype.h> 
#define MAXSIZE 100001

void xtob(char *strnum);
void btoo(char *strnum);
void reverse(char * str);

	char xtb[16][5] = {
		"0000",
		"0001",
		"0010",
		"0011",
		"0100",
		"0101",
		"0110",
		"0111",
		"1000",
		"1001",
		"1010",
		"1011",
		"1100",
		"1101",
		"1110",
		"1111"
	};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int n;
	char xx[4 * MAXSIZE] = {0};
	int i;
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		scanf("%s", xx);
		xtob(xx);
		btoo(xx);
		printf("%s\n", xx);	
	}

	return 0;
}

void xtob(char *x)
{
	char t[4 * MAXSIZE] = {0};
	char *p = x;
	
	while(*p != 0){
		if(isdigit(*p)){
			strcat(t, xtb[*p++ - '0']);
		}
		else{
			strcat(t, xtb[*p++ - 'A' + 10]);
		}
	}

	strcpy(x, t);
	return;
}

void btoo(char *b)
{
	int i, j;
	char o[4 * MAXSIZE] = {0}; 
	for(i = strlen(b) - 1, j = 0; i >= 0; j++){
		o[j] += b[i--];
		if(i >= 0){
			o[j] += 2 * (b[i--] - '0');
		}
		if(i >= 0){
			o[j] += 4 * (b[i--] - '0');
		}
	}
	if(o[strlen(o)-1] == '0'){
		o[strlen(o)-1] = 0;
	}
	strcpy(b, o);
	reverse(b);
	
}

void reverse(char * s)
{
	int i, j;
	int c;
	
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}