#include "Caminhao.h"

Caminhao::Caminhao(){ //construtor default
	cam_type = "";
	modelo = "";
	n_eixo = 0;
	cubica_cap = 0;
	max_carg = 0.0;
}

Caminhao::Caminhao(unsigned ano_fab, unsigned n_chassi, float preco, string cam_type, string modelo, unsigned n_eixo, int cubica_cap, float max_carg){
	set_ano_fab(ano_fab);
	set_n_chassi(n_chassi);
	set_preco(preco);
	
	set_cam_type(cam_type);
	set_modelo(modelo);
	set_n_eixo(n_eixo);
	set_cub_cap(cubica_cap);
	set_max_carg(max_carg);	
}

void Caminhao::set_cam_type(string cam_type){
	this -> cam_type = cam_type;
}

void Caminhao::set_modelo(string modelo){
	this -> modelo = modelo;
}

void Caminhao::set_n_eixo(unsigned n_eixo){
	this -> n_eixo = n_eixo;
}

void Caminhao::set_cub_cap(int cubica_cap){
	this -> cubica_cap = cubica_cap;
}

void Caminhao::set_max_carg(float max_carg){
	this -> max_carg = max_carg;
}

string Caminhao::get_cam_type(){
	return cam_type;
}

string Caminhao::get_modelo(){
	return modelo;
}

unsigned Caminhao::get_n_eixo(){
	return n_eixo;
}

int Caminhao::get_cubica_cap(){
	return cubica_cap;
}

float Caminhao::get_max_carg(){
	return max_carg;
}
