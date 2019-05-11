#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

const int MAXN=105; //������
const int INF=0x3f3f3f3f;

struct Dijkstra { //��ⵥԴ����̾������⡣��������ͼ���ұߵ�ȨֵΪ����
	struct Edge {
		int u; //�ߵ�һ������
		int v; //�ߵ���һ������
		int w; //�ߵ�Ȩֵ
		Edge(int u,int v,int w):u(u),v(v),w(w) {}
		bool operator < (const Edge &e) const {
			return w>e.w;
		}
	};

	struct Dist { //Դ�㵱ǰ����u�ľ���w 
		int u;
		int w;
		Dist(int u,int w):u(u),w(w) {}
		bool operator < (const Dist &d) const {
			return w>d.w;
		}
	};

	vector<Edge> adj[MAXN];
	priority_queue<Dist> pq;
	int distTo[MAXN];
	bool vis[MAXN];

	void dijkstra(int s) {
		distTo[s]=0;
		pq.push(Dist(s,0));
		while(!pq.empty()) {
			int u=pq.top().u; pq.pop();
			if(vis[u]==true) continue;
			relax(u);
		}
	}

	void init() {
		for(int i=0; i<MAXN; i++) adj[i].clear();
		while(!pq.empty()) pq.pop();
		memset(distTo,INF,sizeof(distTo));
		memset(vis,0,sizeof(vis));
	}

	void addEdge(int u, int v, int w) {
		adj[u].push_back(Edge(u,v,w));
	}

	void relax(int u) {
		vis[u]=true;
		for(int i=0; i<adj[u].size(); i++) {
			int v=adj[u][i].v;
			if(distTo[v]>distTo[u]+adj[u][i].w) {
				distTo[v]=distTo[u]+adj[u][i].w;
				pq.push(Dist(v,distTo[v]));
			}
		}
	}

};

Dijkstra dijkstra;
int N, M;

int main() {
	while(scanf("%d%d",&N,&M)==2 && N) {
		dijkstra.init();
		int A,B,C;
		for(int i=0; i<M; i++) {
			scanf("%d%d%d",&A, &B, &C);
			dijkstra.addEdge(A,B,C);
			dijkstra.addEdge(B,A,C);
		}
		dijkstra.dijkstra(1);
		printf("%d\n",dijkstra.distTo[N]);
	}
	return 0;
}

