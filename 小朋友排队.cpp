/*
问题描述
　　n 个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。

　　每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是0。

　　如果某个小朋友第一次被要求交换，则他的不高兴程度增加1，如果第二次要求他交换，则他的不高兴程度增加2（即不高兴程度为3），依次类推。当要求某个小朋友第k次交换时，他的不高兴程度增加k。

　　请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。

　　如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。
输入格式
　　输入的第一行包含一个整数n，表示小朋友的个数。
　　第二行包含 n 个整数 H1 H2 … Hn，分别表示每个小朋友的身高。
输出格式
　　输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。
样例输入
3
3 2 1
样例输出
9
样例说明
　　首先交换身高为3和2的小朋友，再交换身高为3和1的小朋友，再交换身高为2和1的小朋友，每个小朋友的不高兴程度都是3，总和为9。
数据规模和约定
　　对于10%的数据， 1<=n<=10；
　　对于30%的数据， 1<=n<=1000；
　　对于50%的数据， 1<=n<=10000；
　　对于100%的数据，1<=n<=100000，0<=Hi<=1000000。
*/

#include <iostream>
using namespace std;

const int maxn = 100005;
const int N = 100000;
long long T[maxn];
void sort(long long *A, int x, int y);

int main()
{
	freopen("input.txt", "r", stdin);
	int n;
	long long child[maxn] = {0};
	cin >> n;
	for(int i = 0; i < n; i++){			//O(n)
		cin >> child[i];
		child[i] *= N;
	}

	sort(child, 0, n-1);
	
	long long cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += child[i]%N * (child[i]%N+1) / 2;
	}
	
	cout << cnt;
	return 0;
	
}

void sort(long long *A, int x, int y)
{
	if(x < y){
		int uh = 0;
		int m = x + (y-x)/2;
		int p = x, q = m+1, i = x;
		sort(A, x, m);
		sort(A, m+1, y);
		while(p <= m || q <= y){
			if(q > y || (p <= m && A[p]/N <= A[q]/N)){
				T[i++] = A[p++] + uh;
			}
			else{
				A[q] += m-p+1;
				uh++;
				T[i++] = A[q++];
			}
		}
		
		for(i = x; i <= y; i++){				
			A[i] = T[i];
		} 
	}
}