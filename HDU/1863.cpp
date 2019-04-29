#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=105;

struct UnionFind{
	int ufset[MAXN];
	int size; //��ͨ�������� 
	
	int init(int N){ //NΪ�ڵ��� 
		size=N;
		for(int i=1;i<=N;i++){ //�ڵ��Ŵ�1��ʼ 
			ufset[i]=i;
		}
	}

	int find(int v){
		while(v!=ufset[v]) v=ufset[v];
		return v;
	}
	
	void join(int v,int u){
		int ra=find(v);
		int rb=find(u);
		if(ra==rb) return;
		ufset[ra]=rb;
		size--; 
	}
};

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

UnionFind uf;
Prim prim;
int N,M;
int u,v,w;

int main(){
	while(scanf("%d%d",&N,&M)==2 && N){
		uf.init(M);
		prim.init();
		for(int i=0;i<N;i++){
			scanf("%d%d%d",&u,&v,&w);
			prim.addEdge(u,v,w);
			prim.addEdge(v,u,w);
			uf.join(u,v);
		}
		if(uf.size!=1) printf("?\n");
		else {
			int ans=0;
			prim.prim(1);
			for(int i=0;i<prim.mst.size();i++){
				ans+=prim.mst[i].w;
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
