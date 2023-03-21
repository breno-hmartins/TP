#include "Novo.h"

Novo::Novo(float adicional, string ruas, float preco) : Imovel(ruas, preco) {   //construtor inicializando as viraveis
	this -> adicional = adicional;
}

double Novo::f_adicional(){
	return preco*(adicional/100);    //função que ira calcular e retornar o valor adicional
}

float Novo::final(){
	return preco + f_adicional();     //função que aplica o valor adicional ao preço final
}

void Novo::impressao(){
	cout<<endl<<"Imovel novo com a taxa adicional é de R$"<<f_adicional()<<" , o preço final é R$"<<final()<<endl<<endl;   //função de impressão
}
