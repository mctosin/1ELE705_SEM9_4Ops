#pragma once
#ifndef MAIN_H
#define MAIN_H

typedef struct {
	const char* face; // define pointer face   
	const char* suit; // define pointer suit
	unsigned int face_number; // Define o número da face da carta
	unsigned int suit_number; // Define o número do naipe
	char* mode;
} Card; // end struct card    

typedef struct {
	double a;
	double b;
} Cart;

typedef struct {
	double r;
	double g;
} Pol;

typedef union {
	Cart	cart;
	Pol		pol;
} Cplx;

typedef struct {
	Cplx s;
	char* mode;
} CplxNum;

unsigned somacartesiana(Cart* x, Cart y);
unsigned cartesian2polar(Pol* w, Cart x);
unsigned multiplypolar(Pol* w, Pol p);
unsigned normalizeangle(Pol* w);

#endif // MAIN_H

// Descrição do Assignment

/*
Sua tarefa é ímplementar as funções acima prototipadas
Estas funções usam as structs, unions e typedefs definidos em
main.h. Estas definições permitem a manipulação de números 
complexos no sistema de coordenadas cartesiano (a+bj) ou no 
sistema polar (r*exp(jg)) (r=módulo, g=ângulo).

O objetivo é criar funções básicas para serem utilizadas na
construção de funções mais elaboradas, que permitirão lidar
com os problemas inerentes aos números complexos de maneira
transparente ao usuário.

Estas funções básicas, apesar de implementarem operações
matemáticas elementares, lidam com alguns problemas numéricos
importantes. Assim, os testes criados em test.cpp verificam
a implementação de cada uma destas quatro funções iniciais.
Os testes estão agrupados em tópicos referentes a cada uma
das funções a serem testadas, como pode ser visto no Test
Explorer.

A função somacartesiana recebe dois parâmetros do tipo Cart
e realiza a seguinte operação vetorial sobre estes:
x = x + y, 
onde dois números complexos (x, y) que estão na forma 
cartesiana, são somados.
Nesta versão, esta função sempre deve retornar zero.

A função cartesian2polar converte um número na forma 
cartesiana (x) em número na forma polar (w), onde x e w 
são os parâmetros de entrada e de saída da função, 
respectivamente.
Esta função converte vetores cartesianos nos quatro 
quadrantes. A função utiliza como unidade angular o radiano.
Na saída, o ângulo (g) estará entre -PI <= g < PI (rad).
A implementação de algumas das funções trigonométricas
tradicionais em math.h possuem problemas em diferentes
quadrantes e nos seus limites. Sua tarefa é pesquisar e 
encontrar a solução.
Nesta versão, esta função sempre deve retornar zero.

A função multiplypolar realiza a seguinte operação sobre
números na forma polar:
w = w * p
Como a função poderá ser utilizada para a divisão de dois 
números, esta testa para alguns problemas númericos comums.
Caso o módulo de qualquer um dos operadores for zero, então
o resultado retornado será o vetor polar (0,0), pois não há
definição de ângulo para vetor com comprimento zero.
Nas bibliotecas utilizadas existe a constante INFINITY, que
define um número o qual valores acima deste são considerados
números infinitos. Assim, caso algum dos módulos dos parâmetros
fornecidos para a função forem iguais ou maiores que INFINITY,
então a saída terá módulo INFINITY. O ângulo não é afetado.
Nas bibliotecas também é definido a constante _HUGE_ENUF. Caso
ambos os parâmetros de entrada forem maiores que _HUGE_ENUF,
então a função deve retornar INFINITY. O ângulo não é afetado.
Verifique como é definida a constante INFINITY e entenda o
porquê desta regra.
A função retorna zero normalmente e retorna 2 caso o módulo do 
resultado retornado seja INFINITY.

A função normalizeangle normaliza o ângulo de um número
complexo (w) na forma polar. O número entrado pode ter um ângulo
qualquer expresso em radianos, inclusive com valor negativo.
A função deve converter o ângulo entrado para o intervalo
positivo entre -PI <= g < PI (rad).
A norma do vetor não é processada, permanecendo inalterada.
Esta função sempre deve retornar zero.

*/
