#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 8000

void reverse(char *);

int main()
{
	int n;
	char str[MAXSIZE];
	int count = 0;
	int i, j, k, mid;
	int t;
	int smid = 0;
	scanf("%d", &n);
	scanf("%s", str);
	
	mid = n / 2;
	for(i = 0; i < mid; i++){
		if(str[i] == str[n-1-i]){
			continue;
		}
		for(j = n-1-i; j > i; j--){
			if(str[j] == str[i]){
				t = str[j];
				for(k = j ;k < n-1-i; k++){
					str[k] = str[k+1];
					count++;
				}
				str[n-i-1] = t;
				break;
			}
		}
		if(j == i){
			if(n % 2 == 1 && smid == 0){
				smid == 1;
				reverse(str);
				i--;
			}
			else{
				printf("Impossible");
				return 0;
			}
		}
	}
	printf("%d", count);
	return 0;
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