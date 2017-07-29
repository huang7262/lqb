#include <iostream>
#include <cstdio>

using namespace std;

void ntoc(int n);

int main()
{
	for(int i = 1; i < 300; i++){
		ntoc(i);
		printf("\n");
	}
	return 0;
}

void ntoc(int n)
{
	if(n <= 0){
		return;
	}
	n--;
	
	ntoc(n / 26);
	
	printf("%c", (n %26) + 'A');

	return;
}