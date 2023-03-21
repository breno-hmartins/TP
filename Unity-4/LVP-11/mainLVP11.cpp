/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-11

>Descri��o do programa: Programa que pede o hor�rio e atualiza ele com uma contagem de 3 segundos
*/

#include <iostream>
#include <locale>

using namespace std;

#include "LVP11.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int h_aux=0;
	int m_aux=0;         //cria��o das vari�veis auxiliares
	int s_aux=0;
	
	Relogio relogio;      //cria��o do objeto
	
	cout<<"Informe o seu hor�rio atual para que o programa avance conforme o tempo!!"<<endl;
	cout<<"\nDigite a hora: ";
	cin>>h_aux;
	cout<<"\nDigite os minutos: ";                     //processo para o usu�rio inserir os dados de hora, minutos e segundos
	cin>>m_aux;
	cout<<"\nDigite os segundos: ";
	cin>>s_aux;
	
	relogio.setHora(h_aux, m_aux, s_aux);          //chamada da fun��o sethora com os valores que o usuario informou
	
	relogio.avancHorario();
	relogio.avancHorario();           //contagem de 3 segundos no avan�o do tempo
	relogio.avancHorario();
	//impress�o da resposta final ap�s somar 3 segundos no tempo informado pelo usu�rio
	cout<<"\nAp�s o adiantamento o seu hor�rio ser� de "<<relogio.getHora()<<" horas "<<relogio.getMinuto()<<" minutos "<<relogio.getSegundos()<<" segundos!";
	
	return 0;
}

