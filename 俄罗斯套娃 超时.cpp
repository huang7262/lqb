/*
标题：套娃

    作为 drd 送的生日礼物，atm 最近得到了一个俄罗斯娃娃。他对这个俄罗斯娃娃的构造很感兴趣。

    俄罗斯娃娃是一层一层套起来的。假设：一个大小为 x 的俄罗斯娃娃里面可能会放任意多个大小小于 x 的俄罗斯娃娃（而市场上的套娃一般大娃里只能放一个小娃）。

    drd 告诉 atm ，这个俄罗斯娃娃是由 n 个小娃娃组成的，它们的大小各不相同。    我们把这些小娃娃的大小从小到大依次记为 1 到 n 。

    如果 atm 想观赏大小为 k 的小娃娃，他会先看这个小娃娃是否已经在桌子上了。    如果已经在桌子上，那么他就可以观赏了。否则他就打开桌子上某一个俄罗斯娃娃，将它套住的所有的小娃娃拿出来，摆在桌子上。
    一开始桌子上只有 drd 送的大小为 n 的娃娃。注意，他只会将其中所有小娃娃拿出来，如果小娃娃里面还套着另外的小娃娃，他是不会将这些更里层的这些小娃娃拿出来的。
    而且 atm 天生具有最优化的强迫症。他会最小化他所需要打开的娃娃的数目。

    atm 是一个怪人。有时候他只想知道观看大小为 x 的娃娃时需要打开多少个娃娃（但并不去打开）；有时候听 drd 说某个娃娃特别漂亮，于是他会打开看。现在请你输出他每次需要打开多少个娃娃。

【输入格式】
第一行两个数 n m ，表示娃娃的数目以及 atm 想看的娃娃的数目。
接下来 n - 1 行，每行两个数 u v，表示大小为 u 的娃娃里面套着一个大小为 v 的娃娃。保证 u > v 。
接下来 m 行，每行形如：
  P x ：表示 atm 一定要看到大小为 x 的娃娃；
  Q x ：表示 atm 只想知道为了看大小为 x 的娃娃，他需要打开多少个娃娃，但实际上并不打开他们。

【输出格式】
输出 m 行。对应输入中P操作或Q操作需要打开（或假想打开）多少个俄罗斯娃娃。

【样例输入】
5 5
5 3
5 4
3 2
3 1
Q 1
Q 4
P 2
Q 1
Q 4

【样例输出】
2
1
2
0
0

【数据范围】
对于 30% 的数据：n, m <= 1000
对于 100% 的数据：n, m <= 100000


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
#include <cstring>
#include <vector>
using namespace std;

const int maxn = 100005;

struct tree {
	int parent;
	vector<int> child;
	
	tree(){
		parent = 0;
		child.clear();
	}
};

tree a[maxn];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	int u, v;
	char cmd;
	int x;


	memset(a, 0, sizeof(a));
	cin >> n >> m;
	for(int i = 0; i < n-1; i++){			//O(n)
		cin >> u >> v;
		a[u].child.push_back(v);
		a[v].parent = u;
	}
	
	for(int i = 0; i < m; i++){
		cin >> cmd >> x;
		int cnt = 0;
		if(cmd == 'P'){
			while(a[x].parent){
				x = a[x].parent;
				vector<int>::iterator i;
				for(i = a[x].child.begin(); i < a[x].child.end(); i++){
					a[*i].parent = 0;
					a[a[x].parent].child.push_back(*i);
				}
				a[x].child.clear();
				cnt++;
			}
		}
		else{
			int t1 = a[x].parent;
			while(t1){
				t1 = a[t1].parent;
				cnt++;
			}
		}
		cout << cnt <<'\n';
	}
	
} 