#include <stdio.h>
#include<iostream>
#include <vector>
 
#define MAX 10
 
using namespace std;
 
int covered, odds[MAX], visited[MAX], weight[101];
int weightAll = 0;
vector<int> adj[MAX];
 
void addEdge(int u, int v) 
{ 
    adj[v].push_back(u);
    adj[u].push_back(v);
} 
 
int dfs(int v) {
    int grau = adj[v].size();
    weightAll += weight[v];
	visited[v] = 1;
	covered++;
	for (int u = 0; u < grau; u++)
		if (!visited[adj[v][u]])
			dfs(adj[v][u]);
	return covered;
}
 
bool eulerianPath() {
	covered = 0;
	int start = 0, vortex = 0, degreeOdd = 0;
	for (int i = 0; i < MAX; i++) {
        if (adj[i].size() % 2 != 0){
			degreeOdd++;
        }
		if (adj[i].size() > 0){
            vortex++;
            start = i;
        }
	}
 
    if(dfs(start) == vortex && degreeOdd == 0){
        return true;
    }else{
        return false;
    }
 
}
 
int	main() {
	int estradas, u, v, i;
 
    cin >> estradas;
 
		
        for (i = 0 ; i < estradas; i++) {
			cin >> u >> v;
            addEdge(u, v);
            cin >> weight[i];
		}
 
        cout << "Custos para percorrer o grafo: ";
        if(eulerianPath()){
            cout << weightAll;
        }else{
            cout << "nao";
        }
        cout << "\n\n";
 
	return 0;
} 