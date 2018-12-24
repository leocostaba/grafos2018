#include <bits/stdc++.h>
#include <stdio.h> 
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <set>

#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; 
	list<pair<int, int> > * adj;

public:

	Grafo(int V){
		this->V = V;
		adj = new list<pair<int, int> >[V];
	}

    int verticeDesconexo(int index);

    bool impar(int index);
	
	int criarNovasArestas(vector<int> *impares);

	void addAresta(int v1, int v2, int custo){
		adj[v1].push_back(make_pair(v2, custo));
        adj[v2].push_back(make_pair(v1, custo));
	}

	int dijkstra(int orig, int dest){
		int dist[V];
		int visitados[V];

		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < V; i++){
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		dist[orig] = 0;

		pq.push(make_pair(dist[orig], orig));


		while(!pq.empty()){
			pair<int, int> p = pq.top();
			int u = p.second; 
			pq.pop(); 
			if(visitados[u] == false){
				visitados[u] = true;
				list<pair<int, int> >::iterator it;
				for(it = adj[u].begin(); it != adj[u].end(); it++){
					int v = it->first;
					int custo_aresta = it->second;
					if(dist[v] > (dist[u] + custo_aresta))
					{
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}
		return dist[dest];
	}
};

int Grafo::verticeDesconexo(int index) { 
    return adj[index].size();
} 

bool Grafo::impar(int index){ 
    if(adj[index].size() % 2 == 0){
        return false;
    }
    return true;
} 

int Grafo::criarNovasArestas(vector<int> *impares){
    int caminho, menorCaminhoEntreImpares=0, menorU, menorV;
	priority_queue<pair<int, pair<int,int> > >PQ;
    if(impares->size() == 2){
        return dijkstra((*impares)[0], (*impares)[1]);
    }else{
        for(int i = 0;  i < impares->size(); i++){
            for(int j = i+1;  j < impares->size(); j++){
                caminho = dijkstra((*impares)[i], (*impares)[j]);
				PQ.push(make_pair(caminho, make_pair(i,j)));
        }
    }
	set<int>S;
	while (!PQ.empty()) {
		auto i = PQ.top();
		PQ.pop();
		if (S.find(i.second.first) == S.end() && S.find(i.second.first) == S.end()) {
			menorCaminhoEntreImpares+=i.first;
			cout << i.first <<"   " <<i.second.first << i.second.second << endl;
			S.insert(i.second.first);
			S.insert(i.second.second);
		}
	}
    return menorCaminhoEntreImpares;
    }
}


int main(int argc, char *argv[]){
    int PesoArestasIniciais = 0;
    int u,v,weight;
    int CaminhosTuristicos, pontosTuristicos;
    vector<int> *impares = new vector<int>();

	
    cin >> pontosTuristicos;
    Grafo g(pontosTuristicos);
    
    cin >> CaminhosTuristicos;
    for (int i = 0 ; i < CaminhosTuristicos; i++) {
        cin >> u >> v >> weight;
        g.addAresta(u, v, weight);
        PesoArestasIniciais +=  weight;
	}

    for(int i = 0; i < pontosTuristicos; i++){
        if(g.verticeDesconexo(i) == 0){
            cout << "IMPOSIVEL VISITAR TODOS OS CAMINHOS E PONTOS TURISTICOS, OS PONTOS TURISTICOS S�O DESCONEXOS! ";
			exit(0);
        }
        if(g.impar(i)){
            impares->push_back(i);
        }
    }
    cout << "Serao gastos ";
    if(impares->size() == 0){
        cout << PesoArestasIniciais;

    }
    else{
        cout << PesoArestasIniciais + g.criarNovasArestas(impares);
    }
    cout << "km para percorrer todas os caminhos";

	return 0;
}
