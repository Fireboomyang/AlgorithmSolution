#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define MAXN 505 //����������� 
using namespace std;

struct Edge{
    int v; //���� 
	int u; //��һ������ 
    int w; //Ȩֵ 
    Edge(int v,int u,int w):v(v),u(u),w(w){}
    bool operator < (const Edge &e) const {
        return w>e.w;
    }
};

vector<Edge> adj[MAXN]; //agj[v]����v�����ı� 
vector<Edge> mst; //��С������ 
priority_queue<Edge> pq; //���ȶ��У���ź��б� 
int vis[MAXN]; //���ʱ�־ 

void Prim(); //Prim�㷨��������С������ 
void visit(int v); //���÷��ʱ�־��������v���ڽ�㣨δ�����ʣ��ı߼������ȶ����� 

void Prim(){ 
    visit(1);
    while(!pq.empty()){
        Edge e=pq.top();
        pq.pop();
        if(vis[e.v] && vis[e.u]) continue;
        mst.push_back(e);
        if(!vis[e.v]) visit(e.v);
        if(!vis[e.u]) visit(e.u);
    }
}

void visit(int v){ 
    vis[v]=1;
    for(vector<Edge>::iterator i=adj[v].begin(); i!=adj[v].end();i++){
        if(!vis[(*i).u]){
            pq.push(*i);
        }
    }
}

int N;
int n,m;
int v,u,w;

int main(){
	scanf("%d",&N);
	while(N--){
		memset(vis,0,sizeof(vis));
		mst.clear();
		for(int i=0;i<MAXN;i++) adj[i].clear();
		while(!pq.empty()) pq.pop();

		scanf("%d%d",&n,&m);
		while(m--){
			scanf("%d%d%d",&v,&u,&w);
			adj[v].push_back(Edge(v,u,w));
			adj[u].push_back(Edge(u,v,w)); 
		}
		
		int mn=100; //��繩���豸��ѧУ����̾��� 
		for(int i=1;i<=n;i++){
			scanf("%d",&w); 
			if(mn>w) mn=w;
		}
		
		Prim();
	    int ans=0;
	    for(vector<Edge>::iterator i=mst.begin();i!=mst.end();i++){
	    	ans+=(*i).w;
		}
	    printf("%d\n",ans+mn);
	}
    return 0;
}

