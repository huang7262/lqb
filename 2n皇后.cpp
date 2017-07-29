 /* 
问题描述

　　给定一个n*n的棋盘，棋盘中有一些位置不能放皇后。现在要向棋盘中放入n个黑皇后和n个白皇后，使任意的两个黑皇后都不在同一行、同一列或同一条对角线上，任意的两个白皇后都不在同一行、同一列或同一条对角线上。问总共有多少种放法？n小于等于8。

输入格式

　　输入的第一行为一个整数n，表示棋盘的大小。

　　接下来n行，每行n个0或1的整数，如果一个整数为1，表示对应的位置可以放皇后，如果一个整数为0，表示对应的位置不可以放皇后。

输出格式

　　输出一个整数，表示总共有多少种放法。

样例输入

4

1 1 1 1

1 1 1 1

1 1 1 1

1 1 1 1

样例输出

2

样例输入

4

1 0 1 1

1 1 1 1

1 1 1 1

1 1 1 1

样例输出

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
