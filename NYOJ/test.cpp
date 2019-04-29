#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=505; //������ 

struct Edge{ 
    int u; //�ߵ�һ������
	int v; //�ߵ���һ������ 
    int w; //�ߵ�Ȩֵ 
    Edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const Edge &e) const {
        return w>e.w;
    }
};

struct Prim{ //Prim�㷨��������С���������������������ͼ 
	vector<Edge> adj[MAXN]; //agj[v]����v�����ı� 
	priority_queue<Edge> pq; //���ȶ��У���ź��б� 
	vector<Edge> mst; //��С������ 
	bool vis[MAXN]; //���ʱ�־
	
	void prim(int s){ //�����s��ʼ 
		visit(s); 
	    while(!pq.empty()){
	        Edge e=pq.top();
	        pq.pop();
	        if(vis[e.u] && vis[e.v]) continue;
	        mst.push_back(e);
	        if(!vis[e.u]) visit(e.u);
	        if(!vis[e.v]) visit(e.v);
	    }
	}
	
	void init(){ //��ʼ�� 
		for(int i=0;i<MAXN;i++) adj[i].clear();
		while(!pq.empty()) pq.pop();
		mst.clear();
		memset(vis,0,sizeof(vis));
	}
	
	void addEdge(int u,int v,int w){
		adj[u].push_back(Edge(u,v,w));
	}
	
	void visit(int u){ //���÷��ʱ�־��������v���ڽ�㣨δ�����ʣ��ı߼������ȶ�����
	    vis[u]=true;
	    for(vector<Edge>::iterator i=adj[u].begin(); i!=adj[u].end();i++)
	        if(!vis[(*i).v]) pq.push(*i);
	}
};

int N;
int n,m;
int u,v,w;

Prim prim;

int main(){
	scanf("%d",&N);
	while(N--){
		prim.init();

		scanf("%d%d",&n,&m);
		while(m--){
			scanf("%d%d%d",&u,&v,&w);
			prim.addEdge(u,v,w);
			prim.addEdge(v,u,w);
		}
		
		int mn=100; //��繩���豸��ѧУ����̾��� 
		for(int i=1;i<=n;i++){
			scanf("%d",&w); 
			if(mn>w) mn=w;
		}
		
		prim.prim(1);
	    int ans=0;
	    for(vector<Edge>::iterator i=prim.mst.begin();i!=prim.mst.end();i++){
	    	ans+=(*i).w;
		}
	    printf("%d\n",ans+mn);
	}
    return 0;
}
