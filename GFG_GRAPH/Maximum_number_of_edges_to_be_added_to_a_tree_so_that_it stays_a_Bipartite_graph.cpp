//https://www.geeksforgeeks.org/maximum-number-edges-added-tree-stays-bipartite-graph/
#include<bits/stdc++.h>
using namespace std;
int c0,c1;
vector<bool>visited;
void dfs(vector<int>graph[],int node,int color){
	visited[node] = true;
	int ncolor;
	if(color == 0){
		ncolor = 1;
		c0++;
	}
	else{
		ncolor = 0;
		c1++;
	}
	for(int i = 0;i<graph[node].size();i++){
		if(!visited[graph[node][i]]){
			dfs(graph,graph[node][i],ncolor);
		}
	}
}
int main(){
	c0 = c1 = 0;
	int n,m;
	cin >> n >> m;
	vector<int>graph[n];
	visited = vector<bool>(n,false);
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(graph,0,0);
	int ans = c0*c1 - (n-1);
	cout<<ans<<endl;
}\