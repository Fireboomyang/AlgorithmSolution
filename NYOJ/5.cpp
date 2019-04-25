#include<stdio.h>
#include<string.h>
#define MAXN 1005

char A[MAXN],B[MAXN];
int f[MAXN];
int ans;

void getFail(char *P, int *f){
	int m=strlen(P);
	f[0]=f[1]=0;//���Ʊ߽��ֵ
	for(int i=1;i<m;i++){
		int j=f[i];
		while(j && P[i]!=P[j]) j=f[j];
		f[i+1]= P[i]==P[j]? j+1: 0;
	}
}
 
int find(char *T, char *P, int *f){
	int n=strlen(T),m=strlen(P);
	getFail(P,f);
	int j=0;//��ǰ����ţ���ʼΪ0�Ž�� 
	for(int i=0;i<n;i++){//�ı�����ǰָ�� 
		while(j && P[j]!=T[i]) j=f[j];//˳��ʧ����ߣ�ֱ������ƥ��
		if(P[j]==T[i])j++;
		if(j==m) ans++;
	}
}


int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		ans=0;
		scanf("%s%s",A,B);
		find(B,A,f);
		printf("%d\n",ans);
	}
	return 0;
}

