#include "Biblioteca.h"

//Construtor Para chamar as outras classes
Biblioteca::Biblioteca() {
    //
}

//Metodo Cadastrar Um Livro
bool Biblioteca::cadastra_livro(Escolar escolar) {
    if(estoque.set_Escolar(escolar) == true)
        return true;
    return false;
}

bool Biblioteca::cadastra_livro(Literario literario) {
    if(estoque.set_Literario(literario) == true)
        return true;
    return false;
}

//Metodo Para Edita Um Livro
bool Biblioteca::edita_livro(Escolar livroEscolaraux) {
    if(estoque.edit_livroE(livroEscolaraux) == true)
        return true;
    return false;
  }
bool Biblioteca::edita_livro(Literario livroLiterarioaux){
    if(estoque.edit_livroL(livroLiterarioaux) == true)
        return true;
    return false;
    }

//Metodo Para Remover Um Livro
bool Biblioteca::remove_livro(unsigned opc,int ID){
  if(opc == 1){
    if(estoque.remov_livroE(ID == true))
        return true;
    return false;
  }

  else{
    if(estoque.remov_livroL(ID == true))
        return true;
    return false;
  }
}

//Metodo para Comprar o Livro Literario
bool Biblioteca::comprar_livro(unsigned opc, string Titulo) {
  //var
  int nova_qtd;

  if (opc == 2){
  	Literario literarioaux;
  	
  	if (estoque.pesquisa_livroL(Titulo).get_Titulo() != "")
    	literarioaux = estoque.pesquisa_livroL(Titulo);
    
    else
    	return false;
	
    //usa o isEmpty() herdado publicamente de Livro
    if(literarioaux.isEmpty()){
      return false;
    }

    else{
      nova_qtd = literarioaux.get_Quantidade() - 1;
      literarioaux.set_Quantidade(nova_qtd);
      estoque.edit_livroL(literarioaux);

      if(nova_qtd == 0){
        estoque.remov_livroL(literarioaux.get_ID());
      }

      nova_qtd = 1;
      literarioaux.set_Quantidade(nova_qtd);
      carrinhoL.push_back(literarioaux);
      return true;
    }
  }

  else{
  	Escolar escolaraux;
  	
  	if (estoque.pesquisa_livroE(Titulo).get_Titulo() != "")
    	escolaraux = estoque.pesquisa_livroE(Titulo);
    
    else
    	return false;

    //usa o isEmpty() herdado publicamente de Livro
    if(escolaraux.isEmpty()){
      return false;
    }

    else{

      nova_qtd = escolaraux.get_Quantidade() - 1;
      escolaraux.set_Quantidade(nova_qtd);
      estoque.edit_livroE(escolaraux);

      if(nova_qtd == 0){
        estoque.remov_livroE(escolaraux.get_ID());
      }

      nova_qtd = 1;
      escolaraux.set_Quantidade(nova_qtd);
      carrinhoE.push_back(escolaraux);
      return true;
    }
  }
}

Literario Biblioteca::dado_livrosL(string Titulo) {
    return estoque.pesquisa_livroL(Titulo);
}

Escolar Biblioteca::dado_livrosE(string Titulo) {
    return estoque.pesquisa_livroE(Titulo);
}

Literario Biblioteca::dado_livrosL(int ID) {
    return estoque.pesquisa_livroL(ID);
}

Escolar Biblioteca::dado_livrosE(int ID) {
    return estoque.pesquisa_livroE(ID);
}

vector <Literario> Biblioteca::get_carrinhoL() {
  return carrinhoL;
}

vector <Escolar> Biblioteca::get_carrinhoE() {
  return carrinhoE;
}

vector <Literario> Biblioteca::get_estoqueL(){
    return estoque.get_Literario();
}

vector <Escolar> Biblioteca::get_estoqueE(){
    return estoque.get_Escolar();
}
