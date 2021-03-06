/*
标题：网络寻路

    X 国的一个网络使用若干条线路连接若干个节点。节点间的通信是双向的。某重要数据包，为了安全起见，必须恰好被转发两次到达目的地。该包可能在任意一个节点产生，我们需要知道该网络中一共有多少种不同的转发路径。

    源地址和目标地址可以相同，但中间节点必须不同。

    如图1所示的网络。

    1 -> 2 -> 3 -> 1  是允许的
    
    1 -> 2 -> 1-> 2 或者 1->2->3->2 都是非法的。

    输入数据的第一行为两个整数N M，分别表示节点个数和连接线路的条数(1<=N<=10000; 0<=M<=100000)。
    接下去有M行，每行为两个整数 u 和 v，表示节点u 和 v 联通(1<=u,v<=N , u!=v)。

    输入数据保证任意两点最多只有一条边连接，并且没有自己连自己的边，即不存在重边和自环。


    输出一个整数，表示满足要求的路径条数。

例如：
用户输入：
3 3
1 2
2 3
1 3
则程序应该输出：
6


再例如：
用户输入：
4 4
1 2
2 3
3 1
1 4
则程序应该输出：
10



资源约定：
峰值内存消耗 < 64M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型(千万不要混淆c和cpp)。

*/

#include <iostream>
#include <vector>
using namespace std;

const int MAXSIZE = 10005;

vector<int> graph[MAXSIZE];

int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	long long cnt = 0;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i1 = 1; i1 <= n; i1++){
		for(int j = 0; j < graph[i1].size(); j++){
			int i2 = graph[i1][j];
			for(int k = 0; k < graph[i2].size(); k++){
				int i3 = graph[i2][k];
				if(i3 == i1){
					continue;
				}
				for(int l = 0; l < graph[i3].size(); l++){
					int i4 = graph[i3][l];
					if(i4 == i2){
						continue;
					}
					cnt++;
				}
			}
		}
	}

	cout << cnt++;
	
	return 0;
}