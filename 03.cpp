#include <stdio.h> 
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V;
	list<pair<int, int> > * adj;

public:

	Grafo(int V)
	{
		this->V = V;
		adj = new list<pair<int, int> >[V];
	}

    int verticeDesconexo(int index);

    bool impar(int index);
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
        adj[v2].push_back(make_pair(v1, custo));
	}

	int dijkstra(int orig, int dest)
	{
		int dist[V];
		int visitados[V];

		priority_queue < pair<int, int>,
		vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		dist[orig] = 0;


		pq.push(make_pair(dist[orig], orig));


		while(!pq.empty())
		{
			pair<int, int> p = pq.top();
			int u = p.second;
			pq.pop();

	
			if(visitados[u] == false)
			{

				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
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

int Grafo::verticeDesconexo(int index) 
{ 
    return adj[index].size();
} 

bool Grafo::impar(int index) 
{ 
    if(adj[index].size() % 2 == 0){
        return false;
    }
    return true;
} 

int criarNovasArestas(vector<int> impares, Grafo g){
    int caminho, menorCaminhoEntreImpares, menorU, menorV;

    if(impares.size() == 2){
        return g.dijkstra(impares[0], impares[1]);
    }else if(impares.size() < 2){
    	return 0;
	}else{
        menorCaminhoEntreImpares = INFINITO;
        for(int i = 0;  i < impares.size(); i++){
            for(int j = i+1;  j < impares.size(); j++){
                caminho = g.dijkstra(impares[i], impares[j]);
                if(caminho < menorCaminhoEntreImpares){
                    menorCaminhoEntreImpares = caminho;
                    menorU = i;
                    menorV = j;
                }
            }
        }
        impares.erase(impares.begin() + menorU - 1);
        impares.erase(impares.begin() + menorV - 2);
        return menorCaminhoEntreImpares + criarNovasArestas(impares, g);
    }
}

int main(int argc, char *argv[])
{
    int PesoArestasIniciais = 0;
    int u,v,weight;
    int CaminhosTuristicos, pontosTuristicos;
    vector<int> impares;

	
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
            cout << "IMPOSIVEL VISITAR TODOS OS CAMINHOS E PONTOS TURISTICOS, OS PONTOS TURISTICOS SAO DESCONEXOS! ";
			exit(0);
        }
        if(g.impar(i)){
            impares.push_back(i);
        }
    }
    cout << "Serao gastos ";
    if(impares.size() == 0){
        cout << PesoArestasIniciais;

    }
    else{
        cout << PesoArestasIniciais + criarNovasArestas(impares, g);
    }
    cout << "km para percorrer todas os caminhos";

	return 0;
}
