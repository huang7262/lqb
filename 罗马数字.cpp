#include <iostream>
#include <map>
#include <string> 
using namespace std;
int f(string str);
map<char,int> num;
	
int main()
{
	num['I'] = 1;
	num['V'] = 5;
	num['X'] = 10;
	num['L'] = 50;
	num['C'] = 100;
	num['D'] = 500;
	num['M'] = 1000;
	string str;
	cin >> str;
	cout << f(str);
	return 0;
}

int f(string str)
{
	if(str.size() ==0){
		return 0;
	}
	if(str.size() == 1){
		return num[str[0]];
	}
	string left, right;
	string::iterator max = str.begin();
	for(string::iterator i = str.begin(); i < str.end(); i++){
		max = (num[*max] >= num[*i])? max : i;
	}
	left = str.substr(0, max - str.begin());
	right = str.substr(max-str.begin()+1, str.end()-max-1);

	
	return num[*max] - f(left) + f(right);
}