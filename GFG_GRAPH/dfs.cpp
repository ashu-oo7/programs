#include<bits/stdc++.h>
using namespace std;
vector<int>adj[50];
vector<int>visited;
int nodes;
void dfs(int node){
    cout<<"node is "<<node<<endl;
    visited[node] = true;
    for(int i = 0;i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
            dfs(adj[node][i]);
        }
    }
}
int main(){
	int edges;
	cin >> nodes >> edges;
	visited = vector<int>(nodes,false);
	for(int i = 0;i<edges;i++){
	    int a,b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	    adj[b].push_back(a);
	}
	for(int i = 0;i<nodes;i++)
	    if(!visited[i])
	        dfs(i);
}