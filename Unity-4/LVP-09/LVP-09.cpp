/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-9

>Descrição do programa:Faça um programa em C++, com separação de arquivos, para realizar o processo de seleção de um usuário que deseja ser um colaborador 
em uma empresa de programação. Esta seleção deverá ser feita por uma série de perguntas (7 perguntas).
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
	string cpf_aux = " ";                                    //criação das variáveis auxiliares
	int idade_aux = 0;
	int q1=0, q2=0, q3=0, q4=0, q5=0, q6=0, q7=0;

	cout<<"##### Bem vindo a Seleção de funcinários da empresa TP! ######\n"<<endl;
	cout<<"Vamos começar com o seu cadastro no nosso banco de dados:\n"<<endl;
	
	cout<<"Insira o nome: "<<endl;
	getline(cin, nome_aux);
	seles.setNome(nome_aux);	
	cout<<"Insira sua idade: "<<endl;
	cin>>idade_aux;
	cin.ignore();                                                               //cadastro do candidadto
	seles.set_Idad(idade_aux);	
	cout<<"Insira o CPF (contendo ou não caracteres especiais): "<<endl;
	getline(cin, cpf_aux);
	seles.set_CPF(cpf_aux);
	
	cout<<"\n#Cadastro realizado!#\n";
	cout<<endl<<"Agora vamos iniciar uma prova de C++ como processo seletivo, boa sorte!\n\n\n"<<endl;
	
	cout<<"Digite o numero 1 para falso e 2 para verdadeiro:\n"<<endl;
	
	cout<<"1.  A estrutura Union pode atribuir e armazenar mais de um valor a um atributo por execução: "<<endl;
	cin>>q1;
	cout<<"2.  Ao determinarmos o comando 'cout<<fixed<<setprecision(2)<<endl' estamos arredondando um valor de float para inteiro"<<endl;
	cin>>q2;
	cout<<"3.  Se quisermos calcular funções matematicas, como uma raiz quadrada ou um numero exponencial, por exemplo, utilizamos a biblioteca cmath"<<endl;
	cin>>q3;
	cout<<"4.   Usando a biblioteca ctime podemos gerar um numero aleatorio a partir da função srand(time(0))"<<endl;
	cin>>q4;
	cout<<"5.   Podemos utilizar estruturas como classes, struct e union em programação orientada a objeto"<<endl;                   //realização do questionario
	cin>>q5;
	cout<<"6.   Os comandos system('pause') e system('cls') pertencem a biblioteca locale"<<endl;
	cin>>q6;
	cout<<"7.   O construtor e o destrutor são utilizados para destruir e inicializar objetos, respectivamente"<<endl;
	cin>>q7;
	
	seles.resp_corr(q1, q2, q3, q4, q5, q6, q7);       //chamada da função apra analisar as respostas do candidato com as do gabarito
	
	seles.aprovado(idade_aux);	//chamada da função para analisar se o candidato sera aprovado ou n
		
	return 0;
}

