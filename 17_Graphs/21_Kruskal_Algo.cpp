#include <bits/stdc++.h>
using namespace std;

void makeSet(vector<int> &parent, vector<int> &rank, int n){
	for(int i = 1; i <= n; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}

int findParent(int node, vector<int> &parent){
	if(parent[node] == node){
		return node;
	}
	
	return parent[node] = findParent(parent[node], parent);
}

void unionSet(int a, int b, vector<int> &parent, vector<int> &rank){
	int u = findParent(a, parent);
	int v = findParent(b, parent);
	
	if(rank[u] < rank[v]){
		parent[u] = v;
	}else if(rank[v] < rank[u]){
		parent[v] = u;
	}else{
		parent[v] = u;
		rank[u]++;
	}
}

bool cmp(vector<int>&a, vector<int> &b){
	return a[2] < b[2];
}

int kruskalMST(int n, vector<vector<int>> &edges)
{
	int ans = 0;
	vector<int> parent(n + 1, 0);
	vector<int> rank(n + 1, 0);
	
	makeSet(parent, rank, n);
	sort(edges.begin(), edges.end(), cmp);
	
	for(int i = 0; i < edges.size(); i++){
		int u = edges[i][0];
		int v = edges[i][1];
		int wt = edges[i][2];
		
		int a = findParent(u, parent);
		int b = findParent(v, parent);
		
		if(a != b){
			ans += wt;
			unionSet(a, b, parent, rank);
		}
	}
	
	return ans;
}
