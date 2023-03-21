/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-10

>Descrição do programa: Faça um programa que irá realizar aritmética com frações
*/

#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

#include "LVP10.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");

	int num_aux = 0;
	int den_aux = 0;            //variáveis auxiliares
	int escolha = 0;
	
	Fracao f1, f2, fr;         //criação dos objetos
	
	cout<<"--------------------------------------------------------\n"<<endl;
	cout<<"Escolha em qual das duas operações você deseja realizar:"<<endl;            //criação do menu do programa
	cout<<"\n1 - Multiplicação de frações"<<endl;
	cout<<"\n2 - Divisão de frações"<<endl;
	cout<<"\n--------------------------------------------------------"<<endl;
	cout<<"\nDigite aqui a opção: ";
	cin>>escolha;
	
	switch (escolha){                //switch que irá selecionar qual operação o usuário irá seguir
		case 1:
			//aqui vai fazer a multiplicação das frações
			cout<<"\nDigite a primeira fração" <<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f1.set_numera(num_aux);                          //processo para informar o numerador e denominador da primeira fração
			cout<<"Denominador: ";
			cin>>den_aux;
			f1.set_denomi(den_aux);
			
			cout<<"\nDigite a segunda fração"<<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f2.set_numera(num_aux);                         //processo para informar o numerador e denominador da primeira fração
			cout<<"Denominador: ";
			cin>>den_aux;
			f2.set_denomi(den_aux);
			
			fr.mult(f1,f2);     //chamda da função de multiplicação para o objeto fr
			fr.impri();         //chamada da função que irá retornar a solução em formato de fração
			fr.flutu();           //chamda da função que irá imprimir a solução em formato de ponto flutuante, ou em formato decimal 
			
			break;   //comando para finalizar o programa e impedir de seguir para o próximo processo 
			
		case 2:
			//aqui vai fazer a divisão das frações
			cout<<"\nDigite a primeira fração" <<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f1.set_numera(num_aux);
			cout<<"Denominador: ";                //processo para informar o numerador e denominador da primeira fração
			cin>>den_aux;
			f1.set_denomi(den_aux);
			
			cout<<"\nDigite a segunda fração"<<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f2.set_numera(num_aux);                 //processo para informar o numerador e denominador da primeira fração
			cout<<"Denominador: ";
			cin>>den_aux;
			f2.set_denomi(den_aux);
			
			fr.divi(f1, f2);          //chamda da função de divisão para o objeto fr
			fr.impri();             //chamada da função que irá retornar a solução em formato de fração
			fr.flutu();            //chamda da função que irá imprimir a solução em formato de ponto flutuante, ou em formato decimal 
			
			break;      //comando para finalizar o programa e impedir de seguir para o próximo processo 
	}
	return 0;
}
