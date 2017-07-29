#include <stdio.h>

int main()
{
	int n;
	int child[100];
	int i;
	int t;
	int count = 0; 
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &child[i]);
	}
	
	while(1){
		for(i = 0; i < n; i++){							// 检查小朋友的糖果数量是否都相等 
			if(child[0] != child[i]){
				break;
			}
		}
		if(i == n) break;								// 如果都相等，退出循环 
		
		for(i = 0; i < n; i++){							//如果糖果数量为奇数 
			if(child[i] % 2){	
				child[i]++;								//老师补发一颗糖果 
				count++;								//记录补发 
			}
		}
		
		t = child[0] / 2;
		for(i = 0; i < n - 1; i++){						//所有小朋友取出一半糖果给旁边 
			child[i] = child[i] / 2 + child[i+1] / 2;
		}
		child[n - 1] =  child[n - 1] / 2 + t;
		
	}
	
	printf("%d", count);
	return 0;
} 
