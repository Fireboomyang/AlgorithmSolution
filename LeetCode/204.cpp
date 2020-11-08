const int MAXN=10000000+10;
int vis[MAXN];  //��ǣ�1��������0��1����������ʼ��ȫ0

class Solution {
public:
    
    void sieve(int n){
        int m=(int)sqrt(n+0.5); //���⸡����� 
        for(int i=2;i<=m;i++){
            if(vis[i]==0){
                for(int j=i*i;j<=n;j+=i){
                    vis[j]=i;
                } 
            }
        }
    }

    int countPrimes(int n) {
        sieve(n);
        int c=0;
        for(int i=2;i<n;i++){
            if(vis[i]==0){
                c++;
            }
        }
        return c;
    }
};
