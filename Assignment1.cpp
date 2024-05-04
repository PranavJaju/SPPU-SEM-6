//Implement depth first search (DFS) algorithm and breadth first search
//(BFS) algorithm. Use an application for undirected graph and develop a 
//recursive algorithm for searching all the vertices of a graph or tree data 
//structure. Also print the levels as it traverses for both algorithms

#include <bits/stdc++.h>
using namespace std;
class Graph{
	vector<vector<int>>adj;
	int n;
	public:
		Graph(int n){
			adj.resize(n);
			this->n = n;
		}
		void add_edge(){
			while(true){
				int x,y;
				cout<<"\nEnter node 1 : ";
				cin>>x;
				cout<<"\nEnter node 2 : ";
				cin>>y;
				
				if(x == -1 || y==-1){
					break;
				}
				if(x>=n || x<0 || y>=n || y<0){
					cout<<"\n!!! Invalid node ---> vertices are in the range (0,"<<n-1<<")";
				}
					adj[x].push_back(y);
					adj[y].push_back(x);
			}
		}
		void bfs(queue<int> & q,vector<int> & vis){
			if(q.empty()){
				return;
			}
			int top = q.front();
			q.pop();
			cout<<top<<" ";
			for(auto it: adj[top]){
				if(!vis[it]){
					q.push(it);
					vis[it] = 1;
				}
			}
			
			bfs(q,vis);
		}
		void dfs(int v,vector<int> & vis){
			vis[v] = 1;
			cout<<v<<" ";
			for(auto it: adj[v]){
				if(!vis[it]){
					dfs(it,vis);
				}
			}
			return;
		}
};

int main(){
	int n,ch;
	cout<<"Enter the number of nodes : ";
	cin>>n;
	Graph g(n);
	
	while(true){
		cout<<"\nMain Menu : \n1. Add edges\n2. BFS traversal\n3. DFS traversal\n4. Quit";
		cin>>ch;
		switch(ch){
			case 1:
				{
					cout<<"\nvertices are in the range (0,"<<n-1<<") and to stop enter -1 -1 ";
					g.add_edge();
					break;
				}
			case 2:	{
				cout<<"\nEnter the starting node (0,"<<n-1<<") : ";
				int start;
				vector<int>v(n,0);
				cin>>start;
				cout<<"\nFollowing is the BFS traversal:  ";
				queue<int>q;
				q.push(start);
				v[start] = 1;
				g.bfs(q,v);
				break;
			}
			case 3:{
				cout<<"\nEnter the starting node (0,"<<n-1<<") : ";
				int start;
				vector<int>v(n,0);
				cin>>start;
				cout<<"\nFollowing is the BFS traversal:  ";
				g.dfs(start,v);
				break;
			}
			case 4:{
				return 0;
				break;
			}
			default:{
				cout<<"\nInvalid Choice";
				break;
			}
		}
	} 
	return 0;
}
