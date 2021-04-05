#pragma once
#ifndef MAIN_H
#define MAIN_H

typedef struct {
	const char* face; // define pointer face   
	const char* suit; // define pointer suit
	unsigned int face_number; // Define o n�mero da face da carta
	unsigned int suit_number; // Define o n�mero do naipe
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

// Descri��o do Assignment

/*
Sua tarefa � �mplementar as fun��es acima prototipadas
Estas fun��es usam as structs, unions e typedefs definidos em
main.h. Estas defini��es permitem a manipula��o de n�meros 
complexos no sistema de coordenadas cartesiano (a+bj) ou no 
sistema polar (r*exp(jg)) (r=m�dulo, g=�ngulo).

O objetivo � criar fun��es b�sicas para serem utilizadas na
constru��o de fun��es mais elaboradas, que permitir�o lidar
com os problemas inerentes aos n�meros complexos de maneira
transparente ao usu�rio.

Estas fun��es b�sicas, apesar de implementarem opera��es
matem�ticas elementares, lidam com alguns problemas num�ricos
importantes. Assim, os testes criados em test.cpp verificam
a implementa��o de cada uma destas quatro fun��es iniciais.
Os testes est�o agrupados em t�picos referentes a cada uma
das fun��es a serem testadas, como pode ser visto no Test
Explorer.

A fun��o somacartesiana recebe dois par�metros do tipo Cart
e realiza a seguinte opera��o vetorial sobre estes:
x = x + y, 
onde dois n�meros complexos (x, y) que est�o na forma 
cartesiana, s�o somados.
Nesta vers�o, esta fun��o sempre deve retornar zero.

A fun��o cartesian2polar converte um n�mero na forma 
cartesiana (x) em n�mero na forma polar (w), onde x e w 
s�o os par�metros de entrada e de sa�da da fun��o, 
respectivamente.
Esta fun��o converte vetores cartesianos nos quatro 
quadrantes. A fun��o utiliza como unidade angular o radiano.
Na sa�da, o �ngulo (g) estar� entre -PI <= g < PI (rad).
A implementa��o de algumas das fun��es trigonom�tricas
tradicionais em math.h possuem problemas em diferentes
quadrantes e nos seus limites. Sua tarefa � pesquisar e 
encontrar a solu��o.
Nesta vers�o, esta fun��o sempre deve retornar zero.

A fun��o multiplypolar realiza a seguinte opera��o sobre
n�meros na forma polar:
w = w * p
Como a fun��o poder� ser utilizada para a divis�o de dois 
n�meros, esta testa para alguns problemas n�mericos comums.
Caso o m�dulo de qualquer um dos operadores for zero, ent�o
o resultado retornado ser� o vetor polar (0,0), pois n�o h�
defini��o de �ngulo para vetor com comprimento zero.
Nas bibliotecas utilizadas existe a constante INFINITY, que
define um n�mero o qual valores acima deste s�o considerados
n�meros infinitos. Assim, caso algum dos m�dulos dos par�metros
fornecidos para a fun��o forem iguais ou maiores que INFINITY,
ent�o a sa�da ter� m�dulo INFINITY. O �ngulo n�o � afetado.
Nas bibliotecas tamb�m � definido a constante _HUGE_ENUF. Caso
ambos os par�metros de entrada forem maiores que _HUGE_ENUF,
ent�o a fun��o deve retornar INFINITY. O �ngulo n�o � afetado.
Verifique como � definida a constante INFINITY e entenda o
porqu� desta regra.
A fun��o retorna zero normalmente e retorna 2 caso o m�dulo do 
resultado retornado seja INFINITY.

A fun��o normalizeangle normaliza o �ngulo de um n�mero
complexo (w) na forma polar. O n�mero entrado pode ter um �ngulo
qualquer expresso em radianos, inclusive com valor negativo.
A fun��o deve converter o �ngulo entrado para o intervalo
positivo entre -PI <= g < PI (rad).
A norma do vetor n�o � processada, permanecendo inalterada.
Esta fun��o sempre deve retornar zero.

*/
