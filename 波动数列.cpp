/*问题描述
　　观察这个数列：
　　1 3 0 2 -1 1 -2 ...

　　这个数列中后一项总是比前一项增加2或者减少3。

　　栋栋对这种数列很好奇，他想知道长度为 n 和为 s 而且后一项总是比前一项增加a或者减少b的整数数列可能有多少种呢？
输入格式
　　输入的第一行包含四个整数 n s a b，含义如前面说述。
输出格式
　　输出一行，包含一个整数，表示满足条件的方案数。由于这个数很大，请输出方案数除以100000007的余数。
样例输入
4 10 2 3
样例输出
2
样例说明
　　这两个数列分别是2 4 1 3和7 4 1 -2。
数据规模和约定
　　对于10%的数据，1<=n<=5，0<=s<=5，1<=a,b<=5；
　　对于30%的数据，1<=n<=30，0<=s<=30，1<=a,b<=30；
　　对于50%的数据，1<=n<=50，0<=s<=50，1<=a,b<=50；
　　对于70%的数据，1<=n<=100，0<=s<=500，1<=a, b<=50；
　　对于100%的数据，1<=n<=1000，-1,000,000,000<=s<=1,000,000,000，1<=a, b<=1,000,000。
*/

#include <iostream>
using namespace std;

const int MAXSIZE = 1100;
const long MOD = 100000007;

int dp[MAXSIZE*MAXSIZE] = {0};
long long n, s, a, b;
long long cnt = 0;

int main()
{
//	freopen("input.txt", "r", stdin);
	cin>>n>>s>>a>>b;
	
	dp[0]=1;
	for(int i = 1; i < n; i++){
		for(int j = i*(i+1)/2; j >= i; j--){
				dp[j]=(dp[j]+dp[j-i])%MOD;
		}
	}
	for(int j = 0; j <= n*(n-1)/2; j++){
		long long t = s - (j*a-(n*(n-1)/2-j)*b);
		if(t % n == 0)
			cnt=(cnt+dp[j])%MOD;
	}
	cout << cnt;
	return 0;
}