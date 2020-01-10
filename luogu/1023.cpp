#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=100000;

int expect_price; //Ԥ�ڼ۸� 
int expect_sales; //Ԥ��Ч�� 
int price[MAXN]; //�۸����� 
int sales[MAXN]; //�������� 
int decline; //������߼�֮��ĵ�λ�������� 
int cnt; //price��sales����ļ����� 

int main(){
	scanf("%d", &expect_price);
	int d1, d2;
	int pre_d1=0, pre_d2=0, k=0; 
	while(scanf("%d%d", &d1, &d2) && d1!=-1){
		if(pre_d1 && pre_d1+1!=d1){ //��������������֪�۸���δ֪�۸������ 
			k=(d2-pre_d2)/(d1-pre_d1); //��ֵ�����۸�ÿ�Ǹ�1Ԫ����������k
			while(++pre_d1<d1){
				pre_d2+=k;
				price[cnt]=pre_d1; sales[cnt]=pre_d2; ++cnt;
				if(pre_d1==expect_price) expect_sales=pre_d2; //��¼Ԥ������ 
			}
		} 
		if(d1==expect_price) expect_sales=d2;
		price[cnt]=d1; sales[cnt]=d2; ++cnt;
		pre_d1=d1; pre_d2=d2;
	}
	scanf("%d", &decline);
	
	//���������֪��߼۵������۸������
	int now_price=price[cnt-1]+1;
	int now_sales=sales[cnt-1]-decline;
	while(now_sales>0){
		if(now_price==expect_price) expect_sales=now_sales; 
		price[cnt]=now_price; sales[cnt]=now_sales; ++cnt;
		now_price+=1; now_sales-=decline;
	}
	
	double left=-MAXN, right=MAXN; //�������������Ҷ˵� 
	for(int i=0; i<cnt; ++i){
		if(expect_sales-sales[i]>0){
			left=max(left, ((price[i]-price[0])*sales[i]-(expect_price-price[0])*expect_sales)*1.0/(expect_sales-sales[i]));
		}
		else if(expect_sales-sales[i]<0){
			right=min(right, ((price[i]-price[0])*sales[i]-(expect_price-price[0])*expect_sales)*1.0/(expect_sales-sales[i])); 
		}
	}
	
	if(left>right) printf("NO SOLUTION\n");
	else{
		if(left>=0) printf("%d\n", (int)ceil(left));
		else if(right<=0) printf("%d\n", (int)floor(right));
		else printf("0\n");
	}
	return 0;
}
