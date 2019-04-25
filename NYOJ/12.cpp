#include<stdio.h>
#include<math.h>
#include<algorithm>
#define MAXN 10005
using namespace std;

struct Interval{
	double x1;
	double x2;
}interval[MAXN];

bool cmp(Interval a, Interval b){
	if(a.x1==b.x1)return a.x2>b.x2;
	return a.x1<b.x1;
}

int main(){
	int N;
	scanf("%d",&N);
	while(N--){
		int n,w,h;
		scanf("%d%d%d",&n,&w,&h);
		int x,r;
		int cnt=0;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&r);
			//ʵ�����õ���ˮ�� 
			if(2*r>=h){ 
				//������ˮ����ʵ�ʸ������䣨���ɶ��� 
				double l=sqrt(r*r-h*h/4.0);
				interval[cnt].x1=(x-l>=0?x-l:0);
				interval[cnt].x2=(x+l<=w?x+l:w);
				cnt++;
			}
		}
		sort(interval,interval+cnt,cmp);
		
		double xl=0,xr=0;//xl��xr����Ϊ�Ǹ���������Ҷ˵�
		int ans=0;
		int flag=0;
		int i,j;		
		for(i=0;i<cnt;i++){
			for(j=i;j<cnt;j++){
				if(interval[j].x1<=xl){//�ҵ�����Ҫ��ģ����Ҷ˵��������� 
					flag=1;
					xr=max(xr,interval[j].x2);
				}else break;
			}
			if(flag==0) break; 
			//�ҵ��� 
			ans++;
			if(xr==w) break;
			//��ʼ�� 
			flag=0;
			xl=xr;
			i=j-1;
		}
		if(flag==1)
			printf("%d\n",ans);
		else printf("0\n");
	}
	return 0;
}

