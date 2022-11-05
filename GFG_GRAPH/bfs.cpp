#include<bits/stdc++.h>
using namespace std;
vector<int>adj[50];
void bfs(int nodes){
	vector<int>visited(nodes,false);
	for(int i = 0;i<nodes;i++){
		if(!visited[i]){
			queue<int>q;
			q.push(i);
			visited[i] = true;
			while(!q.empty()){
				int node = q.front();
				cout<<"node is "<<node<<endl;
				q.pop();
				for(int i = 0;i < adj[node].size();i++){
					if(!visited[adj[node][i]]){
						visited[adj[node][i]] = true;
						q.push(adj[node][i]);
 					}
				}
			}
		}
	}
}
int main(){
	int nodes,edges;
	cin >> nodes >> edges;
	for(int i = 0;i<edges;i++){
	    int a,b;
	    cin >> a >> b;
	    adj[a].push_back(b);
	}
	bfs(nodes);
}