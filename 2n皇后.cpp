 /* 
��������

��������һ��n*n�����̣���������һЩλ�ò��ܷŻʺ�����Ҫ�������з���n���ڻʺ��n���׻ʺ�ʹ����������ڻʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϣ�����������׻ʺ󶼲���ͬһ�С�ͬһ�л�ͬһ���Խ����ϡ����ܹ��ж����ַŷ���nС�ڵ���8��

�����ʽ

��������ĵ�һ��Ϊһ������n����ʾ���̵Ĵ�С��

����������n�У�ÿ��n��0��1�����������һ������Ϊ1����ʾ��Ӧ��λ�ÿ��ԷŻʺ����һ������Ϊ0����ʾ��Ӧ��λ�ò����ԷŻʺ�

�����ʽ

�������һ����������ʾ�ܹ��ж����ַŷ���

��������

4

1 1 1 1

1 1 1 1

1 1 1 1

1 1 1 1

�������

2

��������

4

1 0 1 1

1 1 1 1

1 1 1 1

1 1 1 1

�������

0
*/
 
#include <stdio.h>
#include <math.h>

#define MAXSIZE 8

int bqueen[MAXSIZE];
int wqueen[MAXSIZE];
int board[MAXSIZE][MAXSIZE];

int n =4;
int count =0;

int blackqueen(int k);
int whitequeen(int k);

int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&board[i][j]);
		}
	}

	blackqueen(0);

	printf("%d\n",count);
	return 0;
}

int blackqueen(int k)
{
	int i, j;

	for(i =0; i < k - 1; i++)
	{
		if(bqueen[k - 1]==bqueen[i]||fabs(k - 1 - i)==fabs(bqueen[k - 1]-bqueen[i]))
			return 0;
	}

	if(k==n)
	{
		whitequeen(0);
		return 0;
	}

	for(j=0;j<n;j++)
	{
		if(board[k][j])
		{
			bqueen[k]=j;
			blackqueen(k+1);
		}
	}
}
int whitequeen(int k)
{
	int i, j;

	for(i =0; i < k - 1; i++)
	{
		if(wqueen[k - 1]==wqueen[i]||fabs(k - 1 - i)==fabs(wqueen[k - 1]-wqueen[i]))
			return 0;
	}

	if(k==n)
	{
		count++;
		return 0;
	}

	for(j=0;j<n;j++)
	{
		if(board[k][j]&&bqueen[k]!=j)
		{
		wqueen[k]=j;
		whitequeen(k+1);
		}
	}
}
