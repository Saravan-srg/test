#include<bits/stdc++.h>
using namespace std;

//directed graph
class Graph{
	int V; //no of vertices

	list<int> *adj;
	
	public:
		Graph(int N){
			V = N;
			adj = new list<int>[N];
		}
		
		void AddEdge(int v, int w){
			adj[v].push_back(w);//adding w to v's list
		}
		
		void BFS(int s){
			//mark all the verticess as not visited
			bool *visited = new bool[V];
			for(int i=0; i<V; i++)
				visited[i] = false;
			
			list<int>  Q;// Queue as linked list
			
			visited[s] = true;
			Q.push_back(s);
			
			list<int>::iterator i;
			
			while(!Q.empty()){
				s = Q.front();
				printf("%d ", s);
				Q.pop_front();
				
				for(i=adj[s].begin(); i!=adj[s].end(); i++)
				{
					if(!visited[*i])
					{
						Q.push_back(*i);
						visited[*i] = true; 
					}
				}
			}	
		}	
};


int main(){
	Graph G(4);
	G.AddEdge(0, 1);
	G.AddEdge(0, 2);
	G.AddEdge(1, 2);
	G.AddEdge(2, 0);
	G.AddEdge(2, 3);
	G.AddEdge(3, 3);
	
	G.BFS(2);//BFS on vertex 2
	
	return 0;
}

//working properly
