#include "LVP10.h"

Fracao::Fracao(){
	numera = 0;
	denomi = 0;            //contrutor para inicializar is itens que est�o na private para n�o pegar lixo de mem�ria
}

Fracao::~Fracao(){
	                          //destrutor vazio
}

Fracao::Fracao(int num_aux, int den_aux){
	this -> numera = num_aux;
	this -> denomi = den_aux; 
}

void Fracao::set_numera(int num_aux){
	numera = num_aux;
}

void Fracao::set_denomi(int den_aux){
	denomi = den_aux;
}

int Fracao::get_numera(){
	return numera;
}

int Fracao::get_denomi(){
	return denomi;
}

Fracao Fracao::mult(Fracao f1, Fracao f2){
	resnumera = f1.numera*f2.numera;                  //fun��o que calcula a nultiplica��o das fra��es
	resdenomi = f1.denomi*f2.denomi;
	
	Fracao solucao(resnumera, resdenomi);
	
	return solucao;
}

Fracao Fracao::divi(Fracao f1, Fracao f2){
	resnumera = f1.numera*f2.denomi;
	resdenomi = f1.denomi*f2.numera;              //fun��o que calcula a divi�o das fra��es
	
	Fracao solucao(resnumera, resdenomi);
	
	return solucao;
}

void Fracao::impri(){
	cout<<"\nO resultado em formado de fra��o � de: "<<resnumera<<"/"<<resdenomi<<endl;     //fun��o para imprimir o resultado em formato de fra��o
}

void Fracao::flutu(){
	float Pfloat = resnumera/resdenomi;
	
	cout<<"E o resultado em ponto flutuante � de: "<<fixed<<setprecision(4)<<Pfloat<<endl;       //fun��o para imprimir o resultado em forma decimal, que usa o set precision para imprimir uma quantidade de casas espec�ficas p�s virgula
}
