#include "Veiculo.h"

Veiculo::Veiculo(){ //construtor default
	ano_fab = 0;
	n_chassi = 0;
	preco = 0.0;
}

Veiculo::Veiculo(unsigned ano_fab, unsigned n_chassi, float preco){
	set_ano_fab(ano_fab);
	set_n_chassi(n_chassi);
	set_preco(preco);
	
}

void Veiculo::set_ano_fab(unsigned ano_fab){
	this -> ano_fab = ano_fab;
}

void Veiculo::set_n_chassi(unsigned n_chassi){
	this -> n_chassi = n_chassi;
}

void Veiculo::set_preco(float preco){
	this -> preco = preco;
}

unsigned Veiculo::get_ano_fab(){
	return ano_fab;
}

unsigned Veiculo::get_n_chassi(){
	return n_chassi;
}

float Veiculo::get_preco(){
	return preco;
}
