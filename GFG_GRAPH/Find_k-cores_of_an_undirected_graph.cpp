// https://www.geeksforgeeks.org/find-k-cores-graph/
#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100010];
vector<bool>visited;
vector<int>deg;
void dfs(int node,int k){
//	cout<<"node is "<<node<<" and degree is "<<deg[node]<<endl;
	visited[node] = true;
	int dec = 0;
	if(deg[node] < k){
		deg[node] = 0;
		dec++;
	}
	for(int i = 0;i<graph[node].size();i++){
		if(deg[graph[node][i]] > 0)
			deg[graph[node][i]] -= dec;
		if(!visited[graph[node][i]]){
			dfs(graph[node][i],k);
		}
	}
//	cout<<"node is "<<node<<" and degree is "<<deg[node]<<endl;
}
void update_deg(int size,int k){
	for(int i = 0;i<size;i++){
		if(deg[i] != 0){
			int ndeg = 0;
			for(int j = 0;j<graph[i].size();j++){
				if(deg[graph[i][j]] >= k)
					ndeg++;
			}
			deg[i] = ndeg;
		}
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	visited = vector<bool>(n,false);
	for(int i = 0;i<m;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int k;cin >> k;
	deg = vector<int>(n,0);
	for(int i = 0;i<n;i++){
		deg[i] = graph[i].size();
	}
	for(int i = 0;i<n;i++)
		if(!visited[i])
			dfs(i,k);
	update_deg(n,k);
	for(int i = 0;i<n;i++){
		if(deg[i] >= k){
			cout<<i<<" and degree is "<<deg[i]<<endl;
			for(int j = 0;j<graph[i].size();j++){
				if(deg[graph[i][j]] >= k)
					cout<<graph[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
}