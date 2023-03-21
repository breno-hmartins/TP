/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 1: LVP-01

>Descrição do programa: Escreva um programa que crie uma estrutura chamada Ponto, contendo apenas 
a posição x e y (inteiros) do ponto. Declare 2 pontos, leia a posição (coordenadas x e y) de cada 
um e calcule a distância entre eles. Apresente no final a distância entre os dois pontos, com uma 
precisão de duas casas decimais.
 */

#include <iostream>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

struct Ponto{
	int x,y;						// Criação da struct
};
float distancia (Ponto, Ponto);      // Protótipo da função que calcula a distância entre os pontos

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
	cout<<endl<<"O valort da distância é igual a "<<dist;             
	
	return 0;
}

float distancia(Ponto ponto1, Ponto ponto2){
	Ponto d;
	int s;
	float r;
	d.x = pow(ponto2.x - ponto1.x,2);
	d.y = pow(ponto2.y - ponto1.y,2);	     //função que calcula a distância entre os dois pontos
	s = d.x + d.y;
	r = sqrt(s);
	return r;
}