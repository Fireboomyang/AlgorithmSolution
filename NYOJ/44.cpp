#include<stdio.h>
int main(){
	int N,n,d;
	scanf("%d",&N);
	while(N--){
		int prior,max;//prior�Ǵ�A1��A(n-1)������Ӵ���
		scanf("%d",&n);
		scanf("%d",&d);//�ȶ���һ���������prior��max��ʼ��
		prior=max=d;
		for(int i=1;i<n;i++){
			scanf("%d",&d);
			prior=d+prior>d?d+prior:d;
			max=max>prior?max:prior;
		}
		printf("%d\n",max);
	}
	return 0;
}

