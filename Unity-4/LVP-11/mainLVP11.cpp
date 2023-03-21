/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 4: LVP-11

>Descrição do programa: Programa que pede o horário e atualiza ele com uma contagem de 3 segundos
*/

#include <iostream>
#include <locale>

using namespace std;

#include "LVP11.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int h_aux=0;
	int m_aux=0;         //criação das variáveis auxiliares
	int s_aux=0;
	
	Relogio relogio;      //criação do objeto
	
	cout<<"Informe o seu horário atual para que o programa avance conforme o tempo!!"<<endl;
	cout<<"\nDigite a hora: ";
	cin>>h_aux;
	cout<<"\nDigite os minutos: ";                     //processo para o usuário inserir os dados de hora, minutos e segundos
	cin>>m_aux;
	cout<<"\nDigite os segundos: ";
	cin>>s_aux;
	
	relogio.setHora(h_aux, m_aux, s_aux);          //chamada da função sethora com os valores que o usuario informou
	
	relogio.avancHorario();
	relogio.avancHorario();           //contagem de 3 segundos no avanço do tempo
	relogio.avancHorario();
	//impressão da resposta final após somar 3 segundos no tempo informado pelo usuário
	cout<<"\nApós o adiantamento o seu horário será de "<<relogio.getHora()<<" horas "<<relogio.getMinuto()<<" minutos "<<relogio.getSegundos()<<" segundos!";
	
	return 0;
}

