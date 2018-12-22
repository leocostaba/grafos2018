	#include <stdio.h> 
	#include <limits.h> 
	#include <iostream>
	#include <vector>
	
	// Number of vertices  
	// in the graph 
	#define MAX 6

	using namespace std;
	
	// A utility function to find the  
	// vertex with minimum distance 
	// value, from the set of vertices 
	// not yet included in shortest 
	// path tree

	void weightEdges (int graph[MAX][MAX]){
		int weightAll = 0;
		for (int i = 0 ; i < MAX; i++) {
			for (int j = i ; j < MAX; j++) {
				weightAll += graph[i][j];
			}
		}
		cout << weightAll <<"\n";
	}

	int minDistance(int dist[],  
					bool sptSet[]) 
	{ 
		
		// Initialize min value 
		int min = INT_MAX, min_index; 
	
		for (int v = 0; v < MAX; v++) 
			if (sptSet[v] == false && 
					dist[v] <= min) 
				min = dist[v], min_index = v; 
	
		return min_index; 
	} 
	
	// Function to print shortest 
	// path from source to j 
	// using parent array 
	void printPath(int parent[], int j) 
	{ 
		
		// Base Case : If j is source 
		if (parent[j] == - 1) 
			return; 
	
		printPath(parent, parent[j]); 
	
		printf("%d ", j); 
	} 
	
	// A utility function to print  
	// the constructed distance 
	// array 
	int printSolution(int dist[], int n,  
						int parent[]) 
	{ 
		int src = 0; 
		printf("Vertex\t Distance\tPath"); 
		for (int i = 1; i < MAX; i++) 
		{ 
			printf("\n%d -> %d \t\t %d\t\t%d ", 
						src, i, dist[i], src); 
			printPath(parent, i); 
		} 
	} 
	
	// Funtion that implements Dijkstra's 
	// single source shortest path 
	// algorithm for a graph represented 
	// using adjacency matrix representation 
	void dijkstra(int graph[MAX][MAX], int src) 
	{ 
		
		// The output array. dist[i] 
		// will hold the shortest 
		// distance from src to i 
		int dist[MAX];  
	
		// sptSet[i] will true if vertex 
		// i is included / in shortest 
		// path tree or shortest distance  
		// from src to i is finalized 
		bool sptSet[MAX]; 
	
		// Parent array to store 
		// shortest path tree 
		int parent[MAX]; 
	
		// Initialize all distances as  
		// INFINITE and stpSet[] as false 
		for (int i = 0; i < MAX; i++) 
		{ 
			parent[0] = -1; 
			dist[i] = INT_MAX; 
			sptSet[i] = false; 
		} 
	
		// Distance of source vertex  
		// from itself is always 0 
		dist[src] = 0; 
	
		// Find shortest path 
		// for all vertices 
		for (int count = 0; count < MAX - 1; count++) 
		{ 
			// Pick the minimum distance 
			// vertex from the set of 
			// vertices not yet processed.  
			// u is always equal to src 
			// in first iteration. 
			int u = minDistance(dist, sptSet); 
	
			// Mark the picked vertex  
			// as processed 
			sptSet[u] = true; 
	
			// Update dist value of the  
			// adjacent vertices of the 
			// picked vertex. 
			for (int v = 0; v < MAX; v++) 
	
				// Update dist[v] only if is 
				// not in sptSet, there is 
				// an edge from u to v, and  
				// total weight of path from 
				// src to v through u is smaller 
				// than current value of 
				// dist[v] 
				if (!sptSet[v] && graph[u][v] && 
					dist[u] + graph[u][v] < dist[v]) 
				{ 
					parent[v] = u; 
					dist[v] = dist[u] + graph[u][v]; 
				}  
		} 
	
		// print the constructed 
		// distance array 
		printSolution(dist, MAX, parent); 
	} 
	
	// Driver Code 
	int main() 
	{ 
		int estradas, u, v, i;
		int weight, weightVortex, edgesVortex;
		vector<int> impares;

		int graph[MAX][MAX] = {
						{0, 0, 0, 0, 0, 0}, 
						{0, 0, 0, 0, 0, 0}, 
						{0, 0, 0, 0, 0, 0},  
						{0, 0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0, 0},  
						{0, 0, 0, 0, 0, 0}
						}; 
	
		cin >> estradas;
	
			
		for (i = 0 ; i < estradas; i++) {
			cin >> u >> v;
			cin >> weight;
			graph[v][u] = weight;
			graph[u][v] = weight;
		}

		for (int i = 0 ; i < MAX; i++) {
			edgesVortex = 0;
			weightVortex = 0;
			for (int j = 0 ; j < MAX; j++) {
				if(graph[i][j] != 0){
					weightVortex += graph[i][j];
					edgesVortex++;
				}
			}
			if(weightVortex == 0){
				cout << "IMPOSÍVEL VISITAR TODOS OS CAMINHOS E PONTOS TURISTICOS, OS PONTOS TURISTICOS SÃO DESCONEXOS! ";
				break;
			}else if(edgesVortex % 2 != 0){
				impares.push_back(i);
			}

			cout << impa	res.size();
		}

		//weightEdges(graph);
		//dijkstra(graph, 0); 
		return 0; 
	} 