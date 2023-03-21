#include "Literario.h"

Literario::Literario(string Publico,string Genero,int ID,string Titulo,string Autor,float Preco,int Quantidade)
          :Livro(ID,Titulo,Autor,Preco,Quantidade){
	this->Publico = Publico;
	this->Genero = Genero;
}

string Literario::get_Publico() {
	return Publico;
}

string Literario::get_Genero() {
	return Genero;
}
