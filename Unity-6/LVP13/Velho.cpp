#include "Velho.h"

Velho::Velho(float desconto, string ruas, float preco) : Imovel(ruas, preco) {		//construtor inicializando as viraveis
	this -> desconto = desconto;
}

float Velho::f_desconto(){
	return preco*(desconto/100);       //fun��o que ira calcular e retornar o desconto
}

float Velho::final(){
	return preco - f_desconto();        //fun��o que aplica o desconto ao pre�o final
}

void Velho::impressao(){
	cout<<endl<<"Imovel velho com um desconto de R$"<<f_desconto()<<" , o pre�o final � R$"<<final()<<endl<<endl;    //fun��o de impress�o
}
