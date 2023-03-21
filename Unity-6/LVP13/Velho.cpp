#include "Velho.h"

Velho::Velho(float desconto, string ruas, float preco) : Imovel(ruas, preco) {		//construtor inicializando as viraveis
	this -> desconto = desconto;
}

float Velho::f_desconto(){
	return preco*(desconto/100);       //função que ira calcular e retornar o desconto
}

float Velho::final(){
	return preco - f_desconto();        //função que aplica o desconto ao preço final
}

void Velho::impressao(){
	cout<<endl<<"Imovel velho com um desconto de R$"<<f_desconto()<<" , o preço final é R$"<<final()<<endl<<endl;    //função de impressão
}
