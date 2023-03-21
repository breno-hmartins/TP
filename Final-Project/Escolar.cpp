#include "Escolar.h"

Escolar::Escolar(string Tipo,string Disciplina,int ID,string Titulo,string Autor,float Preco,int Quantidade)
        :Livro(ID,Titulo,Autor,Preco,Quantidade){
	this->Tipo = Tipo;
	this->Disciplina = Disciplina;
}

string Escolar::get_Tipo() {
	return Tipo;
}

string Escolar::get_Disciplina() {
	return Disciplina;
}
