#include "LVP10.h"

Fracao::Fracao(){
	numera = 0;
	denomi = 0;            //contrutor para inicializar is itens que estão na private para não pegar lixo de memória
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
	resnumera = f1.numera*f2.numera;                  //função que calcula a nultiplicação das frações
	resdenomi = f1.denomi*f2.denomi;
	
	Fracao solucao(resnumera, resdenomi);
	
	return solucao;
}

Fracao Fracao::divi(Fracao f1, Fracao f2){
	resnumera = f1.numera*f2.denomi;
	resdenomi = f1.denomi*f2.numera;              //função que calcula a divião das frações
	
	Fracao solucao(resnumera, resdenomi);
	
	return solucao;
}

void Fracao::impri(){
	cout<<"\nO resultado em formado de fração é de: "<<resnumera<<"/"<<resdenomi<<endl;     //função para imprimir o resultado em formato de fração
}

void Fracao::flutu(){
	float Pfloat = resnumera/resdenomi;
	
	cout<<"E o resultado em ponto flutuante é de: "<<fixed<<setprecision(4)<<Pfloat<<endl;       //função para imprimir o resultado em forma decimal, que usa o set precision para imprimir uma quantidade de casas específicas pós virgula
}
