/*
���⣺����6λ��

  ��һ��6λ�������������и�����������ʣ�

  �ֱ���2 3 4 5 6ȥ�������õ�����Ȼ��6λ�������ҳ˻��������������������6λ����ȫһ����ֻ���������ǵ�˳�����������˶��ѡ�

  ���������6λ����

  ����һ����������ͨ��������ύ�𰸣���Ҫ��д�κζ�������ݣ�����˵���Ե����֣�
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