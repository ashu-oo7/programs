//https://www.geeksforgeeks.org/path-rectangle-containing-circles/
//complexity = m*n*k
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>visited;
int radius,size;
bool solve(int i,int j,int m,int n,int X[],int Y[]){
	if(i > m || j > n)return false;
	if(visited[i][j] >= 0)return visited[i][j];
	if(i == m && j == n)return true;
	else{
			for(int p = 0;p<size;p++){
				int x = i-X[p],y = j-Y[p]; 
				int dist = x*x + y*y;
				if(dist <= (radius*radius))return false;
			}
			visited[i][j]  = solve(i+1,j,m,n,X,Y)||solve(i,j+1,m,n,X,Y);
			return visited[i][j];
	}
}
int main(){
	int m,n,k,r;
	cin >> m >> n >> k >> r;
	radius = r;size = k;
	visited = vector<vector<int>>(m,vector<int>(n,-1));
	int X[k],Y[k];
	for(int &i:X)
		cin >> i;
	for(int &j:Y)
		cin >> j;
	bool res = solve(0,0,m-1,n-1,X,Y);
	cout<<res<<endl;
}