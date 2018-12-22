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
	int V; // n�mero de v�rtices

	// ponteiro para um array contendo as listas de adjac�ncias
	list<pair<int, int> > * adj;

public:

	// construtor
	Grafo(int V)
	{
		this->V = V; // atribui o n�mero de v�rtices

		/*
			cria as listas onde cada lista � uma lista de pairs
			onde cada pair � formado pelo v�rtice destino e o custo
		*/
		adj = new list<pair<int, int> >[V];
	}

    int verticeDesconexo(int index);

    bool impar(int index);

	// adiciona uma aresta ao grafo de v1 � v2
	void addAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
        adj[v2].push_back(make_pair(v1, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de dist�ncias
		int dist[V];

		/*
		   vetor de visitados serve para caso o v�rtice j� tenha sido
		   expandido (visitado), n�o expandir mais
		*/
		int visitados[V];

		// fila de prioridades de pair (distancia, v�rtice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		// inicia o vetor de dist�ncias e visitados
		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		// a dist�ncia de orig para orig � 0
		dist[orig] = 0;

		// insere na fila
		pq.push(make_pair(dist[orig], orig));

		// loop do algoritmo
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obt�m o v�rtice do pair
			pq.pop(); // remove da fila

			// verifica se o v�rtice n�o foi expandido
			if(visitados[u] == false)
			{
				// marca como visitado
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				// percorre os v�rtices "v" adjacentes de "u"
				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					// obt�m o v�rtice adjacente e o custo da aresta
					int v = it->first;
					int custo_aresta = it->second;

					// relaxamento (u, v)
					if(dist[v] > (dist[u] + custo_aresta))
					{
						// atualiza a dist�ncia de "v" e insere na fila
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		// retorna a dist�ncia m�nima at� o destino
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
        impares.erase(impares.begin()+menorU);
        impares.erase(impares.begin()+menorV);
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
            cout << "IMPOS�VEL VISITAR TODOS OS CAMINHOS E PONTOS TURISTICOS, OS PONTOS TURISTICOS S�O DESCONEXOS! ";
			exit(0);
        }
        if(g.impar(i)){
            impares.push_back(i);
        }
    }
    cout << "Ser�o gastos ";
    if(impares.size() == 0){
        cout << PesoArestasIniciais;

    }
    else{
        cout << PesoArestasIniciais + criarNovasArestas(impares, g);
    }
    cout << "km para percorrer todas os caminhos";

	return 0;
}
