#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#define MAXSIZE 100001

char xx[4 * MAXSIZE] = {0};

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
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	
	int n;

	int i;
	scanf("%d", &n);
	char xx[4 * MAXSIZE] = {0};
	
	for(i = 0; i < n; i++){
		scanf("%s", xx);
		xtob(xx);
		btoo(xx);
		printf("%s\n", xx);	
	}
//	printf("time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC); 
	return 0;
}

void xtob(char *x)
{
	char t[4 * MAXSIZE] = {0};
	char *p = x;
	int i = 0;
	
	while(*p != 0){
		if(isdigit(*p)){
			t[i++] = xtb[*p - '0'][0];
			t[i++] = xtb[*p - '0'][1];
			t[i++] = xtb[*p - '0'][2];
			t[i++] = xtb[*p++ - '0'][3];
		}
		else{
			t[i++] = xtb[*p - 'A' + 10][0];
			t[i++] = xtb[*p - 'A' + 10][1];
			t[i++] = xtb[*p - 'A' + 10][2];
			t[i++] = xtb[*p++ - 'A' + 10][3];
		}
	} 
	
/*	while(*p != 0){
		if(isdigit(*p)){
			strcat(t, xtb[*p++ - '0']);
		}
		else{
			strcat(t, xtb[*p++ - 'A' + 10]);
		}
	}
*/
	strcpy(x, t);
	return;
}

void btoo(char *b)
{
	int i, j;
	char o[4 * MAXSIZE] = {0}; 
	int lenb = strlen(b) - 1;
	for(i = lenb, j = 0; i >= 0; j++){
		o[j] += b[i--];
		if(i >= 0){
			o[j] += 2 * (b[i--] - '0');
		}
		if(i >= 0){
			o[j] += 4 * (b[i--] - '0');
		}
	}
	int leno = strlen(o) - 1;
	if(o[leno] == '0'){
		o[leno] = 0;
	}
	strcpy(b, o);
	reverse(b);
	
}

void reverse(char * s)
{
	int i, j;
	int c;
	int len = strlen(s)-1;
	for(i = 0, j = len; i < j; i++, j--){
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
