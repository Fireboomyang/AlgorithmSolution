#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=30; //������ 

struct Edge{ 
    int u; //�ߵ�һ������
	int v; //�ߵ���һ������ 
    int w; //�ߵ�Ȩֵ 
    Edge(int u,int v,int w):u(u),v(v),w(w){}
    bool operator < (const Edge &e) const {
        return w>e.w;
    }
};

struct Prim{
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

Prim prim;

int n; //��ׯ��
int k; //��·��
char lab[5]; //��ׯ�ı�ǩ 

int main(){
	while(scanf("%d",&n)==1 && n!=0){
		prim.init();
		for(int i=0;i<n-1;i++){
			scanf("%s%d",lab,&k);
			int u,v,w;
			u=lab[0]-'A';
			for(int j=0;j<k;j++){
				scanf("%s%d",lab,&w);
				v=lab[0]-'A';
				prim.addEdge(u,v,w);
				prim.addEdge(v,u,w);
			}
		}
		
		prim.prim(0);
			
		int ans=0;
		for(int i=0;i<prim.mst.size();i++){
			ans+=prim.mst[i].w;
		}
		
		printf("%d\n",ans);
	}
	return 0;
} 
