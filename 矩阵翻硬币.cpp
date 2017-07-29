/*
��������
����С���Ȱ�Ӳ�Ұڳ���һ�� n �� m �еľ���

�������С����ÿһ��Ӳ�ҷֱ����һ�� Q ������

�����Ե�x�е�y�е�Ӳ�ҽ��� Q �����Ķ��壺�����е� i*x �У��� j*y �е�Ӳ�ҽ��з�ת��

��������i��jΪ����ʹ�������е����������кź��кŶ��Ǵ�1��ʼ��

������С��������Ӳ�Ҷ�������һ�� Q ��������������һ���漣��������Ӳ�Ҿ�Ϊ���泯�ϡ�

����С����֪���ʼ�ж���öӲ���Ƿ��泯�ϵġ����ǣ��������ĺ�����СMѰ�������

����������СM����С����ֻ��Ҫ������Ӳ���ٽ���һ��Q���������ɻָ����ʼ��״̬��Ȼ��С����������Ը������������С��ϣ������������õķ���������������𰸡�
�����ʽ
�����������ݰ���һ�У����������� n m���������Ŀ������
�����ʽ
�������һ������������ʾ�ʼ�ж���öӲ���Ƿ��泯�ϵġ�
��������
2 3
�������
1
���ݹ�ģ��Լ��
��������10%�����ݣ�n��m <= 10^3��
��������20%�����ݣ�n��m <= 10^7��
��������40%�����ݣ�n��m <= 10^15��
��������10%�����ݣ�n��m <= 10^1000��10��1000�η�����
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
	
	BigInteger operator = (const string& str){				//���������
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
	
	BigInteger operator * (const BigInteger& b) const{		//��������� 
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

	BigInteger operator + (const BigInteger& b) const{		//���������
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

	BigInteger operator / (const int b) {				//���������
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
	
	bool operator <= (const BigInteger& b) const{			//���������
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