/*

���⣺������ʽ

    ��4����ͬ�����֣���ɵ�һ���˷���ʽ�����ǵĳ˻���Ȼ����4��������ɡ�

    ���磺 

210 x 6 = 1260 
8 x 473 = 3784
27 x 81 = 2187 

    ������Ҫ��

    �������˷������ɵ���ʽ����ͬһ���������ô�������ϱ����г���3�������һ���ж���������Ҫ�����ʽ��

    ����д�����֣�ͨ��������ύ�𰸣���Ҫ��д�������ݣ����磺�г�������ʽ����

*/
#include <stdio.h>

int main()
{
	int a, b, c, d;
	int w, x, y, z;
	int n;
	int count = 0;
	int i;
	
	for(a = 0; a < 10; a++){
		
		for(b = 0; b < 10; b++){
			if(b == a)
				continue;
				
			for(c = 0; c < 10; c++){
				if(c == b || c == a)
					continue;
					
				for(d = 0; d < 10; d++){
					if(d == c || d == b || d == a)
						continue;
					i = 1;
					while(i < 3){
						if(i == 1 && a != 0 && c !=0){
							n = (10 * a + b) *(10 * c + d);
						}
						else if(i == 2 && a != 0 && b != 0){
							n = a * ( 100*b + 10*c + d );
						}
						else {
							i++;
							continue;
						}
						
						w = n / 1000;
						x = n % 1000 / 100;
						y = n % 100 / 10;
						z = n % 10;
						if(
							(w == a || w == b || w == c || w == d) &&
							(x == a || x == b || x == c || x == d) &&
							(y == a || y == b || y == c || y == d) &&
							(z == a || z == b || z == c || z == d) &&
							(w != x && w != y && w != z && x != y && x != z && y != z && n >= 1000)
						){
							count += i;
							if(i == 1){
								printf("%d%d %d%d 	%d\n", a ,b, c, d, n);
							}
							else{
								printf("%d %d%d%d 	%d\n", a ,b, c, d, n);
							}
						}
						i++;
					}
				}
			}
		}
	}
	printf("%d", count/2);
	return 0;
}
