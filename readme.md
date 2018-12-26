# Algoritmo para o Carteiro Chinês

Algoritmo desenvolvido por: Leonardo Costa, Vínicius Brito e  Samuel Almeida para disciplina de Teoria dos Grafos ministrada pelo professor Roberto Parente na Universidade Federal da Bahia


## A ideia

O algoritmo foi desenvolvido em C++ e tem como objetivo ajudar um casal (Maria e João) que deseja conhecer Salvador e para isso João pediu uma orientação dos melhores pontos turístico de Salvador ao seu melhor amigo Leonardo,  que atenciosamente e prestativo lhe passou uma lista com 10 pontos turísticos e todas os caminhos turísticos que ligam um ponto a outro e desafiou o casal a passar por todos os caminhos. O casal quer aproveitar o máximo a sua viagem, então deseja visitar todos os caminhos turísticos de modo que visite todos os pontos turísticos e evite ao máximo repetir caminhos, caso faça isso precisa ser o menor tempo possível, e ao final do dia eles desejam retornar para o hotel em que estão hospedados. O algoritmo calcular quantos kilometros o casal precisou andar para catologar todos esses caminhos entre os pontos turisticos.

### Pré-requisitos

Compilador de C++ 11;

### Como rodar

Faça o clone do repositório para o seu computador e então:

```
g++ -std=c++11 03.cpp -o programa
./programa
```
ou então:
[LINK DO COMPILADOR ONLINE COM O CÓDIGO](https://ideone.com/kyB4fE)


Alguns Exemplos

## Casos de testes

```
8 13
2 6 70
6 7 70
5 7 60
2 7 120
0 2 50
2 3 70
0 3 50
3 5 60
0 1 50
1 3 50
1 5 50
1 4 70
4 5 70
```
```
SAÍDA: 1000
```
```
7 13
0 1 9
1 2 19
2 3 5
3 4 7
4 5 20
5 0 6
3 0 35
6 0 8
6 1 7
6 2 11
6 3 5
6 4 9
6 5 10
```
```
SAÍDA  182
```
```
6 6
3 0 2
0 2 2
1 5 2
4 1 2
0 5 2
2 3 2
0 4 2
```
```
SAÍDA   18
```
```
6 7
3 0 2
0 2 2
1 5 2
4 1 2
0 5 2
2 3 2
0 4 2
```
```
SAÍDA  14
```

## Autores

* **Leonardo Costa** 
* **Samuel Almeida**
* **Vínicius Brito**

## Direitos Autorais

Pode copiar, só dá os créditos e cuidado com o plágio hein?!

