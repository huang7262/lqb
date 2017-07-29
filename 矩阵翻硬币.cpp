/*
问题描述
　　小明先把硬币摆成了一个 n 行 m 列的矩阵。

　　随后，小明对每一个硬币分别进行一次 Q 操作。

　　对第x行第y列的硬币进行 Q 操作的定义：将所有第 i*x 行，第 j*y 列的硬币进行翻转。

　　其中i和j为任意使操作可行的正整数，行号和列号都是从1开始。

　　当小明对所有硬币都进行了一次 Q 操作后，他发现了一个奇迹——所有硬币均为正面朝上。

　　小明想知道最开始有多少枚硬币是反面朝上的。于是，他向他的好朋友小M寻求帮助。

　　聪明的小M告诉小明，只需要对所有硬币再进行一次Q操作，即可恢复到最开始的状态。然而小明很懒，不愿意照做。于是小明希望你给出他更好的方法。帮他计算出答案。
输入格式
　　输入数据包含一行，两个正整数 n m，含义见题目描述。
输出格式
　　输出一个正整数，表示最开始有多少枚硬币是反面朝上的。
样例输入
2 3
样例输出
1
数据规模和约定
　　对于10%的数据，n、m <= 10^3；
　　对于20%的数据，n、m <= 10^7；
　　对于40%的数据，n、m <= 10^15；
　　对于10%的数据，n、m <= 10^1000（10的1000次方）。
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int maxn = 2005;

struct BigInteger{
	static const int WIDTH = 4;
	static const int BASE = 10000;
	vector<int> s;
	
	BigInteger operator = (const string& str){				//重载运算符
		s.clear();
		int x, len = (str.length() - 1) / WIDTH + 1;
		for(int i = 0; i < len; i++){
			int end = str.length() - i*WIDTH;
			int start = max(0, end - WIDTH);
			sscanf(str.substr(start, end-start).c_str(), "%d", &x);
			s.push_back(x);
		}
		return *this;
	}
	
	BigInteger operator * (const BigInteger& b) const{		//重载运算符 
		BigInteger ans;
		ans.s.clear();
		ans.s.resize(maxn);
		for(int i = 0; i < s.size(); i++){
			for(int j = 0, g = 0; j < b.s.size() || g; j++){
//				ans.s.push_back(0); 
				ans.s[i+j] += g;
				if(j < b.s.size()){
					ans.s[i+j] += b.s[j] * s[i];
				}
				g = ans.s[i+j] / BASE; 
				ans.s[i+j] %= BASE;
			}
		}
		while(ans.s.back() == 0 && ans.s.size() > 1){
			ans.s.pop_back();
		}
		return ans;
	}

	BigInteger operator + (const BigInteger& b) const{		//重载运算符
		BigInteger c;
		c.s.clear();
		for(int i = 0, g = 0; ; i++){
			if(g == 0 && i >= s.size() && i >= b.s.size())
				break;
			int x = g;
			if(i < s.size())
				x += s[i];
			if(i < b.s.size())
				x += b.s[i];
			c.s.push_back(x % BASE);
			g = x / BASE;
		}
		while(c.s.back() == 0 && c.s.size() > 1){
			c.s.pop_back();
		}
		return c;
	}

	BigInteger operator / (const int b) {				//重载运算符
		BigInteger ans;
		ans.s.clear();
		ans = *this;
		for(int i = s.size() - 1; i >= 0; i--){
			if(i>0){
				ans.s[i-1] += ans.s[i] % b * BASE;
			}
			ans.s[i] = ans.s[i] / b;
		}
		while(ans.s.back() == 0 && ans.s.size() > 1){
			ans.s.pop_back();
		}
		return ans;
	}
	
	bool operator < (const BigInteger& b) const{ 
		
		
		if(s.size() != b.s.size()){
			return s.size() < b.s.size();
		}
		for(int i = s.size() - 1; i >= 0; i--){
			if(s[i] != b.s[i])
				return s[i] < b.s[i];
		}
		return false;
	}
	
	bool operator <= (const BigInteger& b) const{			//重载运算符
		return !(b < *this);
	}

	BigInteger sqrt(){
		BigInteger begin, end, mid, one;
		begin = "0";
		end = *this;
		mid = (begin + end) / 2;
		one = "1";
		while(1){
			BigInteger mm;
			mm = mid*mid;
			if(mm <= *this && *this < (mid+one) * (mid+one)){
				return mid;
			}
			if((mm) < *this){
				begin = (mid + one);
			}else{
				end = mid;
			}
			mid = (begin + end) / 2;
		}
	}

	void printBig(){
		BigInteger text;
		text = *this;
		
		while(text.s.back() == 0 && text.s.size() > 1){
			text.s.pop_back();
		}
			printf("%d", text.s.back());
			text.s.pop_back();
		
		while(text.s.size()){
			printf("%04d", text.s.back());
			text.s.pop_back();
		}
		printf("\n");
		return;
	}
};
 
int main()
{
	char n[maxn], m[maxn];
	scanf("%s", n);
	scanf("%s", m);

	BigInteger N;
	BigInteger M;
	BigInteger ans;
	
	N = n;
	M = m;
	ans = N.sqrt() * M.sqrt();
//	ans = N.sqrt();
	ans.printBig();
	
	return 0; 
}