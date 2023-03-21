/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-08

>Descrição do programa: Crie uma classe chamada MegaSena que irá realizar um sorteio por meio da geração de números inteiros pseudo-aleatórios. Esta Classe
deverá prever também a realização de uma aposta e verificar o prêmio ganho. Para facilitar os testes do código, o intervalo de dezenas sorteadas foi 
reduzido de 60 para 20, sendo assim, devem ser sorteadas dezenas de 0 à 20. A porcentagem de divisão do prêmio para os ganhadores da quadra, quina e sena 
também foi modificada para um melhor entendimento do problema.
*/

#include <iostream>
#include <locale>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "LVP08.cpp"



int main(){
	setlocale(LC_ALL, "Portuguese");
	
	float bruto_aux;
	int *apo;
	int d = 0;
	
	
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"----------------------JOGUE NA MEGA SENA----------------------"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	
	cout<<"\nInsira o valor do prêmio: "<<endl;
	cin>>bruto_aux;	
	cout<<"\nEm quantas dezenas você quer apostar? ";
	cin>>d;
	
	MegaSena mega(bruto_aux, d);
	
	apo = new int [d];
	
	cout<<"\nDigite as dezenas de 0 a 20 da sua aposta separadas por espaço(não podem ser repetidas):"<<endl;
	
	for(int i; i < d; i++){
		cin>>apo[i];
	}
	
	mega.set_armazen(apo);
	mega.comprov();
	mega.sort();
	mega.p_resul();
	
	return 0;
}

