#include "Livro.h"

Livro::Livro(int ID,string Titulo,string Autor,float Preco,int quantidade_aux) {
	this->ID = ID;
	this->Titulo = Titulo;
	this->Autor = Autor;
	this->Preco = Preco;
	set_Quantidade(quantidade_aux);
}

void Livro::set_Quantidade(int quantidade_aux){
  Quantidade = quantidade_aux;
}

int Livro::get_ID(){
  return ID;
}

string Livro::get_Titulo() {
	return Titulo;
}

string Livro::get_Autor() {
	return Autor;
}

float Livro::get_Preco() {
	return Preco;
}

int Livro::get_Quantidade() {
	return Quantidade;
}

//verifica se o livro esta¡ vazio
//true: se tiver vazio
//false: se nÃ£o tiver
bool Livro::isEmpty(){
  if(this->Preco == -1 && this->Quantidade == -1
    && this->ID == -1)
    return true;
  else
    return false;
}
