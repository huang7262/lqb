/*

���⣺�ظ�ģʽ

    ��Ϊ drd �ĺ����ѣ������� atm �� drd ����ʱ�͸���һ�������ַ��� S ��atm Ҫ drd �������ҳ�һ������ַ��� T ��ʹ�� T �� S �����ٳ��������Σ�������˵�����ܾͲ��� T �С�

    �����ַ���ʵ����̫���ˣ�drd �����Ҳ������ʵ� T ������ drd ��������ҵ���� T �ĳ��ȡ�

�������ʽ��
һ�С�һ���ַ���������Ŀ��˵��S ��

�������ʽ��
һ�С�һ����������ʾ��� T �ĳ��ȡ�

���������롿
ababa

�����������
3

�����ݷ�Χ��
���� 30% �����ݣ�S���� <= 100
���� 60% �����ݣ�S���� <= 8000
���� 100% �����ݣ�S���� <= 500000

��ԴԼ����
��ֵ�ڴ����� < 256M
CPU����  < 1000ms


���ϸ�Ҫ���������Ҫ��������ش�ӡ���ƣ�����������...�� �Ķ������ݡ�

���д������ͬһ��Դ�ļ��У�����ͨ���󣬿����ύ��Դ�롣

ע��: main������Ҫ����0
ע��: ֻʹ��ANSI C/ANSI C++ ��׼����Ҫ���������ڱ��뻷�������ϵͳ�����⺯����
ע��: ���������ĺ���������ȷ����Դ�ļ��� #include <xxx>�� ����ͨ���������ö�ʡ�Գ���ͷ�ļ���

�ύʱ��ע��ѡ���������ı��������͡�

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