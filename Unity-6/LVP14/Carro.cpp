#include "Carro.h"

Carro::Carro(){//construtor default
	v_type = "";
	model = "";
}

Carro::Carro(unsigned ano_fab, unsigned n_chassi, float preco, string v_type, string model){
	set_ano_fab(ano_fab);
	set_n_chassi(n_chassi);
	set_preco(preco);
	
	this -> v_type = v_type;
	this -> model = model;		
}

void Carro::set_Vtype(string v_type){
	this -> v_type = v_type;
}

void Carro::set_model(string model){
	this -> model = model;
}

string Carro::get_Vtype(){
	return v_type;
}

string Carro::get_model(){
	return model;
}
