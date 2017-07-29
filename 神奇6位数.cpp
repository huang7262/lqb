/*
标题：神奇6位数

  有一个6位的正整数，它有个很神奇的性质：

  分别用2 3 4 5 6去乘它，得到的仍然是6位数，并且乘积中所包含的数字与这个6位数完全一样！只不过是它们的顺序重新排列了而已。

  请计算出这个6位数。

  这是一个整数，请通过浏览器提交答案，不要填写任何多余的内容（比如说明性的文字）
*/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(int* a, int* b);

int main()
{
	int b[6];
	int t[6];
	for(b[0] = 1; b[0] < 10; b[0]++){
		for(b[1] = 0; b[1] < 10; b[1]++){
			for(b[2] = 0; b[2] < 10; b[2]++){
				for(b[3] = 0; b[3] < 10; b[3]++){
					for(b[4] = 0; b[4] < 10; b[4]++){
						for(b[5] = 0; b[5] < 10; b[5]++){
							int i;
							for(i = 2; i <= 6; i++){
								for(int j = 5; j >= 0; j--){
									t[j] = b[j] * i;
								}
								for(int j = 5; j >= 0; j--){
									t[j-1] += t[j] / 10;
									t[j] %= 10;
								}
								if(!cmp(t, b)){
									break;
								}
							}
							if(i > 6){
								for(int i = 0; i < 6; i++){
									cout << b[i];
								}
								return 0;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}

bool cmp(int* a, int* b)
{
	int s[6];
	int t[6];
	memcpy(s, a, sizeof(s));
	memcpy(t, b, sizeof(t));
	sort(s, s+6);
	sort(t, t+6);
	for(int i = 0; i < 6; i++){
		if(s[i] != t[i]){
			return 0;
		}
	}
	return 1;
}