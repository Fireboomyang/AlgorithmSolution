#include<cstdio>

struct Info{
	int ori;  //0 ����Ȧ�ڣ� 1 ����Ȧ�� 
	char str[12];
};

int n, m;
Info peo[100002];
int a, s;

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i<n; ++i) 
		scanf("%d%s", &peo[i].ori, peo[i].str);
		
	int ori;  //1 ��ʱ�룬 -1 ˳ʱ��
	int now=0;  //��ǰ�˵ı�� 
	for(int i=0; i<m; ++i){
		scanf("%d%d", &a, &s);
		 
		if(peo[now].ori==0) ori= a==0? -1: 1;
		else ori= a==0? 1: -1;
		
		now=(now+ori*s+n)%n;
	}
	
	printf("%s\n", peo[now].str);
	return 0;
}
