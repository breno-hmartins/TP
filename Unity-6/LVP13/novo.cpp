#include "Novo.h"

Novo::Novo(float adicional, string ruas, float preco) : Imovel(ruas, preco) {   //construtor inicializando as viraveis
	this -> adicional = adicional;
}

double Novo::f_adicional(){
	return preco*(adicional/100);    //fun��o que ira calcular e retornar o valor adicional
}

float Novo::final(){
	return preco + f_adicional();     //fun��o que aplica o valor adicional ao pre�o final
}

void Novo::impressao(){
	cout<<endl<<"Imovel novo com a taxa adicional � de R$"<<f_adicional()<<" , o pre�o final � R$"<<final()<<endl<<endl;   //fun��o de impress�o
}
