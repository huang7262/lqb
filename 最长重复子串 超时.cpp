/*

标题：重复模式

    作为 drd 的好朋友，技术男 atm 在 drd 生日时送给他一个超长字符串 S 。atm 要 drd 在其中找出一个最长的字符串 T ，使得 T 在 S 中至少出现了两次，而他想说的秘密就藏在 T 中。

    由于字符串实在是太长了，drd 总是找不到合适的 T 。于是 drd 请你帮他找到这个 T 的长度。

【输入格式】
一行。一个字符串，即题目中说的S 。

【输出格式】
一行。一个整数，表示最长的 T 的长度。

【样例输入】
ababa

【样例输出】
3

「数据范围」
对于 30% 的数据，S长度 <= 100
对于 60% 的数据，S长度 <= 8000
对于 100% 的数据，S长度 <= 500000

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <ctime>
using namespace std;

bool strcmp_s(char* a, char* b);

const int maxn = 500005;

int main()
{
	freopen("input.txt", "r", stdin);
	vector<char*> post;
	char s[maxn];
	int max = 0;
	cin >> s;
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		post.push_back(s+i);
	}
//	cout << n;
//cout << "time:" << (double)clock() / CLOCKS_PER_SEC << '\n'; 

	sort(post.begin(), post.end(), strcmp_s);
	
//cout << "time:" << (double)clock() / CLOCKS_PER_SEC << '\n';

	for(int i = 0; i+1 < n; i++){
		int cnt = 0;
		char* p = post[i];
		char* q = post[i+1];
		while(*p++ == *q++){
		}
		cnt = p-1 - post[i];
//	strcmp(post[i], post[i+1]);
		max = (max > cnt) ? max : cnt; 
	}
	
//cout << "time:" << (double)clock() / CLOCKS_PER_SEC << '\n'; 

	cout << max;
	return 0;
}

bool strcmp_s(char* a, char* b)
{
	if(strcmp(a, b) <= 0){
		return true;
	}
	return false;
}