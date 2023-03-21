/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-10

>Descri��o do programa: Fa�a um programa que ir� realizar aritm�tica com fra��es
*/

#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

#include "LVP10.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");

	int num_aux = 0;
	int den_aux = 0;            //vari�veis auxiliares
	int escolha = 0;
	
	Fracao f1, f2, fr;         //cria��o dos objetos
	
	cout<<"--------------------------------------------------------\n"<<endl;
	cout<<"Escolha em qual das duas opera��es voc� deseja realizar:"<<endl;            //cria��o do menu do programa
	cout<<"\n1 - Multiplica��o de fra��es"<<endl;
	cout<<"\n2 - Divis�o de fra��es"<<endl;
	cout<<"\n--------------------------------------------------------"<<endl;
	cout<<"\nDigite aqui a op��o: ";
	cin>>escolha;
	
	switch (escolha){                //switch que ir� selecionar qual opera��o o usu�rio ir� seguir
		case 1:
			//aqui vai fazer a multiplica��o das fra��es
			cout<<"\nDigite a primeira fra��o" <<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f1.set_numera(num_aux);                          //processo para informar o numerador e denominador da primeira fra��o
			cout<<"Denominador: ";
			cin>>den_aux;
			f1.set_denomi(den_aux);
			
			cout<<"\nDigite a segunda fra��o"<<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f2.set_numera(num_aux);                         //processo para informar o numerador e denominador da primeira fra��o
			cout<<"Denominador: ";
			cin>>den_aux;
			f2.set_denomi(den_aux);
			
			fr.mult(f1,f2);     //chamda da fun��o de multiplica��o para o objeto fr
			fr.impri();         //chamada da fun��o que ir� retornar a solu��o em formato de fra��o
			fr.flutu();           //chamda da fun��o que ir� imprimir a solu��o em formato de ponto flutuante, ou em formato decimal 
			
			break;   //comando para finalizar o programa e impedir de seguir para o pr�ximo processo 
			
		case 2:
			//aqui vai fazer a divis�o das fra��es
			cout<<"\nDigite a primeira fra��o" <<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f1.set_numera(num_aux);
			cout<<"Denominador: ";                //processo para informar o numerador e denominador da primeira fra��o
			cin>>den_aux;
			f1.set_denomi(den_aux);
			
			cout<<"\nDigite a segunda fra��o"<<endl;
			cout<<"\nNumerador: ";
			cin>>num_aux;
			f2.set_numera(num_aux);                 //processo para informar o numerador e denominador da primeira fra��o
			cout<<"Denominador: ";
			cin>>den_aux;
			f2.set_denomi(den_aux);
			
			fr.divi(f1, f2);          //chamda da fun��o de divis�o para o objeto fr
			fr.impri();             //chamada da fun��o que ir� retornar a solu��o em formato de fra��o
			fr.flutu();            //chamda da fun��o que ir� imprimir a solu��o em formato de ponto flutuante, ou em formato decimal 
			
			break;      //comando para finalizar o programa e impedir de seguir para o pr�ximo processo 
	}
	return 0;
}
