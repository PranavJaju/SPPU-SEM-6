#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Disjoint {
	vector<int>sizeSet;
	vector<int>parent;
	
	public:
		Disjoint(int n){
			sizeSet.resize(n+1);
			parent.resize(n+1);
			for(int i = 0;i<n+1;i++){
				parent[i] = i;
				sizeSet[i] = 1;
			}
		}
		int findPar(int x){
			if(parent[x]==x){
				return x;
			}
			return parent[x] = findPar(parent[x]);
		}
		
		void unionBySize(int u,int v){
			int uu = findPar(u);
			int uv = findPar(v);
			if(uu==uv) return;
			if(sizeSet[uu] < sizeSet[uv]){
				parent[uu] = uv;
				sizeSet[uv] += sizeSet[uu];
			}
			else{
				parent[uv] = uu;
				sizeSet[uu] += sizeSet[uv];
			}
			
		}
		friend class Graph;
};
class Graph {
private:
    int V;
    vector<vector<pair<int, int>>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, int weight) {
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // For undirected graph
    }

    int primMST() {
        vector<bool> inMST(V, false);
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>pq;

        int src = 0;
        pq.push({0, src});
        key[src] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for (auto& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                    pq.push({key[v], v});
                }
            }
        }

        int totalWeight = 0;
        for (int i = 1; i < V; ++i) {
            cout << "Edge: " << parent[i] << " - " << i << "    Weight: " << key[i] << endl;
            totalWeight += key[i];
        }
        return totalWeight;
    }
    
    int Kruskal(){
    	vector<pair<int,pair<int,int>>>edges;
    	for(int i = 0;i<V;i++){
    		for(auto it: adj[i]){
    			int adjNode = it.first;
    			int wt = it.second;
    			
    			edges.push_back({wt,{i,adjNode}});
			}
		}
		Disjoint ds(V);
		sort(edges.begin(),edges.end());
		int mstwt = 0;
		
		for(auto it:edges){
			int wt = it.first;
			int u = it.second.first;
			int v = it.second.second;
			
			if(ds.findPar(u)!=ds.findPar(v)){
				mstwt += wt;
                cout<<"\nedge"<<u<<"-->"<<v<<" wt: "<<wt;
				ds.unionBySize(u,v);
			}
		}
		
		
	
		return mstwt;
	}
    
};

int main() {
    int V;
    cin>>V;
    Graph g(V);
    int x,y,w;
    while(true){
    	cin>>x>>y>>w;
    	if(x==-1 || y==-1){
    		break;
		}
    	g.addEdge(x,y,w);
	}

    cout << "\nPrims : Total weight of MST: " << g.primMST() << endl;
    cout<<"\nKruskal's : Total weight of MST: "<<g.Kruskal() << endl;

    return 0;
}

