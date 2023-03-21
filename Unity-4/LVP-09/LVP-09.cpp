/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-9

>Descri��o do programa:Fa�a um programa em C++, com separa��o de arquivos, para realizar o processo de sele��o de um usu�rio que deseja ser um colaborador 
em uma empresa de programa��o. Esta sele��o dever� ser feita por uma s�rie de perguntas (7 perguntas).
*/

#include <iostream>
#include <locale>
#include <string.h>

using namespace std;

#include "Selec.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Selec seles;
	
	string nome_aux = " ";
	string cpf_aux = " ";                                    //cria��o das vari�veis auxiliares
	int idade_aux = 0;
	int q1=0, q2=0, q3=0, q4=0, q5=0, q6=0, q7=0;

	cout<<"##### Bem vindo a Sele��o de funcin�rios da empresa TP! ######\n"<<endl;
	cout<<"Vamos come�ar com o seu cadastro no nosso banco de dados:\n"<<endl;
	
	cout<<"Insira o nome: "<<endl;
	getline(cin, nome_aux);
	seles.setNome(nome_aux);	
	cout<<"Insira sua idade: "<<endl;
	cin>>idade_aux;
	cin.ignore();                                                               //cadastro do candidadto
	seles.set_Idad(idade_aux);	
	cout<<"Insira o CPF (contendo ou n�o caracteres especiais): "<<endl;
	getline(cin, cpf_aux);
	seles.set_CPF(cpf_aux);
	
	cout<<"\n#Cadastro realizado!#\n";
	cout<<endl<<"Agora vamos iniciar uma prova de C++ como processo seletivo, boa sorte!\n\n\n"<<endl;
	
	cout<<"Digite o numero 1 para falso e 2 para verdadeiro:\n"<<endl;
	
	cout<<"1.  A estrutura Union pode atribuir e armazenar mais de um valor a um atributo por execu��o: "<<endl;
	cin>>q1;
	cout<<"2.  Ao determinarmos o comando 'cout<<fixed<<setprecision(2)<<endl' estamos arredondando um valor de float para inteiro"<<endl;
	cin>>q2;
	cout<<"3.  Se quisermos calcular fun��es matematicas, como uma raiz quadrada ou um numero exponencial, por exemplo, utilizamos a biblioteca cmath"<<endl;
	cin>>q3;
	cout<<"4.   Usando a biblioteca ctime podemos gerar um numero aleatorio a partir da fun��o srand(time(0))"<<endl;
	cin>>q4;
	cout<<"5.   Podemos utilizar estruturas como classes, struct e union em programa��o orientada a objeto"<<endl;                   //realiza��o do questionario
	cin>>q5;
	cout<<"6.   Os comandos system('pause') e system('cls') pertencem a biblioteca locale"<<endl;
	cin>>q6;
	cout<<"7.   O construtor e o destrutor s�o utilizados para destruir e inicializar objetos, respectivamente"<<endl;
	cin>>q7;
	
	seles.resp_corr(q1, q2, q3, q4, q5, q6, q7);       //chamada da fun��o apra analisar as respostas do candidato com as do gabarito
	
	seles.aprovado(idade_aux);	//chamada da fun��o para analisar se o candidato sera aprovado ou n
		
	return 0;
}

