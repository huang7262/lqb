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
		for(i = 0; i < n; i++){							// ���С���ѵ��ǹ������Ƿ���� 
			if(child[0] != child[i]){
				break;
			}
		}
		if(i == n) break;								// �������ȣ��˳�ѭ�� 
		
		for(i = 0; i < n; i++){							//����ǹ�����Ϊ���� 
			if(child[i] % 2){	
				child[i]++;								//��ʦ����һ���ǹ� 
				count++;								//��¼���� 
			}
		}
		
		t = child[0] / 2;
		for(i = 0; i < n - 1; i++){						//����С����ȡ��һ���ǹ����Ա� 
			child[i] = child[i] / 2 + child[i+1] / 2;
		}
		child[n - 1] =  child[n - 1] / 2 + t;
		
	}
	
	printf("%d", count);
	return 0;
} 
