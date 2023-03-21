/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-08

>Descri��o do programa: Crie uma classe chamada MegaSena que ir� realizar um sorteio por meio da gera��o de n�meros inteiros pseudo-aleat�rios. Esta Classe
dever� prever tamb�m a realiza��o de uma aposta e verificar o pr�mio ganho. Para facilitar os testes do c�digo, o intervalo de dezenas sorteadas foi 
reduzido de 60 para 20, sendo assim, devem ser sorteadas dezenas de 0 � 20. A porcentagem de divis�o do pr�mio para os ganhadores da quadra, quina e sena 
tamb�m foi modificada para um melhor entendimento do problema.
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
	
	cout<<"\nInsira o valor do pr�mio: "<<endl;
	cin>>bruto_aux;	
	cout<<"\nEm quantas dezenas voc� quer apostar? ";
	cin>>d;
	
	MegaSena mega(bruto_aux, d);
	
	apo = new int [d];
	
	cout<<"\nDigite as dezenas de 0 a 20 da sua aposta separadas por espa�o(n�o podem ser repetidas):"<<endl;
	
	for(int i; i < d; i++){
		cin>>apo[i];
	}
	
	mega.set_armazen(apo);
	mega.comprov();
	mega.sort();
	mega.p_resul();
	
	return 0;
}

