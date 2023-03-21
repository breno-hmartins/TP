/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 1: LVP-01

>Descri��o do programa: Escreva um programa que crie uma estrutura chamada Ponto, contendo apenas 
a posi��o x e y (inteiros) do ponto. Declare 2 pontos, leia a posi��o (coordenadas x e y) de cada 
um e calcule a dist�ncia entre eles. Apresente no final a dist�ncia entre os dois pontos, com uma 
precis�o de duas casas decimais.
 */

#include <iostream>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

struct Ponto{
	int x,y;						// Cria��o da struct
};
float distancia (Ponto, Ponto);      // Prot�tipo da fun��o que calcula a dist�ncia entre os pontos

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Ponto ponto1,ponto2;
	float dist;
	
	cout<<"Informe o valor de x e y do primeiro ponto:"<<endl;
	cin>>ponto1.x;
	cin>>ponto1.y;												        //Pede para ser informado o valor de x e y dos pontos
	cout<<endl<<"Informe o valor de x e y do segundo ponto:"<<endl;
	cin>>ponto2.x;
	cin>>ponto2.y;
	
	cout<<setprecision(3);
	dist = distancia(ponto1, ponto2);                                // Retorna a distancia com o valor contando com duas casas decimais
	cout<<endl<<"O valort da dist�ncia � igual a "<<dist;             
	
	return 0;
}

float distancia(Ponto ponto1, Ponto ponto2){
	Ponto d;
	int s;
	float r;
	d.x = pow(ponto2.x - ponto1.x,2);
	d.y = pow(ponto2.y - ponto1.y,2);	     //fun��o que calcula a dist�ncia entre os dois pontos
	s = d.x + d.y;
	r = sqrt(s);
	return r;
}