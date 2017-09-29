/*问题描述
 * 　　在一条直线上有n堆石子，每堆有一定的数量，每次可以将两堆相邻的石子合并，合并后放在两堆的中间位置，合并的费用为两堆石子的总数。求把所有石子合并成一堆的最小花费。
 * 输入格式
 * 　　输入第一行包含一个整数n，表示石子的堆数。
 * 　　接下来一行，包含n个整数，按顺序给出每堆石子的大小 。
 * 输出格式
 * 　　输出一个整数，表示合并的最小花费。
 * 样例输入
 * 5
 * 1 2 3 4 5
 * 样例输出
 * 33
 * 数据规模和约定
 * 　　1<=n<=1000, 每堆石子至少1颗，最多10000颗。*/

#include <iostream>

using namespace std;

const int MAXN = 1000;

int main()
{
	int n;
	int dp[MAXN][MAXN] = {0};

	cin >> n;
	for(int i = 0; i != n; i++){
		cin >> dp[i][i];
	}

	for(int i = 0; i+1 != n; i++){
		for(int j = i+1; j != n; j++)
		dp[i][j] = dp[i][j-1] + dp[j][j];
	}
	
	for(int j = 2; j != n; j++){
		for(int i = 0; i+j != n; i++){
			int minAns;
			if(dp[i][i+j-1] <= dp[i+1][i+j])
				minAns = dp[i][i+j-1];
			else
				minAns = dp[i+1][i+j];
				
			for(int m = i+2; m < i+j; m++){
				if(dp[i][m-1] + dp[m][i+j] < minAns){
					minAns = dp[i][m-1] + dp[m][i+j];
				}
			}
			dp[i][i+j] += minAns;
		}
	}

	cout << dp[0][n-1] << endl;
	return 0;
}
