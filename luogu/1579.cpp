#include<cstdio>
#include<math.h>
#define MAXN 10000000+10
#define MAXP 700000

int vis[MAXN];//��ǣ�1��������0��1����������ʼ��ȫ0
int prime[MAXP];//�������,��0��ʼ 

void sieve(int n){ //ɸ���� 
	int m=(int)sqrt(n+0.5);//���⸡����� 
	for(int i=2;i<=m;i++){
		if(vis[i]==0){
			for(int j=i*i;j<=n;j+=i){
				vis[j]=i;
			} 
		}
	}
}

int prime_table(int n){ //����1��n��������������������
	sieve(n);
	int c=0;
	for(int i=2;i<=n;i++){
		if(vis[i]==0){
			prime[c++]=i;
		}
	}
	return c;
} 

int n;
int main(){
	scanf("%d", &n);
	int m=prime_table(n);
	for(int i=0; i<m; ++i){
		for(int j=0; j<m; ++j){
			for(int k=m-1; k>=0; --k){
				if(prime[i]+prime[j]+prime[k]==n){
					printf("%d %d %d\n", prime[i], prime[j], prime[k]);
					return 0;
				}
			}
		}
	}
	return 0;
}
