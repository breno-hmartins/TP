#include "Estoque.h"

//Metodo que armazena no vector
Estoque::Estoque(){
  ifstream arquivo_Livro_Escolar;
  arquivo_Livro_Escolar.open("Estoque_Livro_Escolar.txt");
	
  int ID,Quantidade;
  string Titulo, Autor, Publico, Genero, Disciplina, Tipo;
  float Preco;
    
  if(arquivo_Livro_Escolar.is_open()){
    while(!arquivo_Livro_Escolar.eof()){
    	
    	arquivo_Livro_Escolar.ignore(4);
		arquivo_Livro_Escolar>>ID;
		
		if (arquivo_Livro_Escolar.eof())
			break;
		
		arquivo_Livro_Escolar.ignore(9);
		getline(arquivo_Livro_Escolar,Titulo);
		arquivo_Livro_Escolar.ignore(7);
		getline(arquivo_Livro_Escolar,Autor);
		arquivo_Livro_Escolar.ignore(10);
		arquivo_Livro_Escolar>>Preco;
		arquivo_Livro_Escolar.ignore(3);
		arquivo_Livro_Escolar.ignore(12);
		arquivo_Livro_Escolar>>Quantidade;
		arquivo_Livro_Escolar.ignore(7);
		getline(arquivo_Livro_Escolar,Tipo);
		arquivo_Livro_Escolar.ignore(12);
		getline(arquivo_Livro_Escolar,Disciplina);
		
		Escolar school(Tipo, Disciplina, ID, Titulo, Autor, Preco, Quantidade);
		escolar.push_back(school);
		arquivo_Livro_Escolar.ignore();
		
    }
  	arquivo_Livro_Escolar.close();
  }

  else{
    cout<<endl<<"Não foi possível abrir a Lista de Livros Escolares!";
    getch();
  }

  //ler literario
  ifstream arquivo_Livro_Literario;
  arquivo_Livro_Literario.open("Estoque_Livro_Literario.txt");
  if(arquivo_Livro_Literario.is_open()){
    while(!arquivo_Livro_Literario.eof()){
        
        arquivo_Livro_Literario.ignore(4);
        arquivo_Livro_Literario>>ID;
		
		if (arquivo_Livro_Literario.eof())
			break;
		
		arquivo_Livro_Literario.ignore(9);
		getline(arquivo_Livro_Literario,Titulo);
		arquivo_Livro_Literario.ignore(7);
		getline(arquivo_Livro_Literario,Autor);
		arquivo_Livro_Literario.ignore(10);
		arquivo_Livro_Literario>>Preco;
		arquivo_Livro_Literario.ignore(3);
		arquivo_Livro_Literario.ignore(12);
		arquivo_Livro_Literario>>Quantidade;
		arquivo_Livro_Literario.ignore(10);
		getline(arquivo_Livro_Literario,Publico);
		arquivo_Livro_Literario.ignore(8);
		getline(arquivo_Livro_Literario,Genero);
		
		Literario literary(Publico, Genero, ID, Titulo, Autor, Preco, Quantidade);
		literario.push_back(literary);
		arquivo_Livro_Literario.ignore();
        
	}
   	arquivo_Livro_Literario.close();
  }
  
  else{
  	cout<<endl<<"Não foi possível abrir a Lista de Livros Literários!";
    getch();
  }
}

bool Estoque::set_Escolar(Escolar school) {
  bool existe;

  if (escolar.size() == 0){
    escolar.push_back(school);
    return true;
  }
    escolar.push_back(school);
    for(unsigned i = 0; i<escolar.size()-1;i++){
      if(escolar[i].get_ID() == escolar[escolar.size()-1].get_ID()){
        existe = true;
        break;
      }
    }
    if (existe == true){
    	escolar.erase(escolar.end());
      return false;
	}
    else
      return true;

}

bool Estoque::set_Literario(Literario literary) {
  bool existe;

  if (literario.size() == 0){
    literario.push_back(literary);
    return true;
  }
    literario.push_back(literary);
    for(unsigned i = 0; i<literario.size()-1; i++){
      if(literario[i].get_ID() == literario[literario.size()-1].get_ID()){
        existe = true;
        break;
      }
    }
    if (existe == true){
    	literario.erase(literario.end());
      return false;
	}
    else
      return true;
}

vector <Escolar> Estoque::get_Escolar(){
	Escolar escolaraux;
	for (unsigned i = 0; i<escolar.size();i++){
		for (unsigned j = 0; j<(escolar.size()-1);j++){
			if(escolar[j].get_ID() > escolar[j+1].get_ID()){
				escolaraux = escolar[j];
				escolar[j] = escolar[j+1];
				escolar[j+1] = escolaraux;
			}
		}
	}
  return escolar;
}

vector <Literario> Estoque::get_Literario(){
	Literario literarioaux;
	for (unsigned i = 0; i<literario.size();i++){
		for (unsigned j = 0; j<(literario.size()-1);j++){
			if(literario[j].get_ID() > literario[j+1].get_ID()){
				literarioaux = literario[j];
				literario[j] = literario[j+1];
				literario[j+1] = literarioaux;
			}
		}
	}
  return literario;
}

bool Estoque::edit_livroE(Escolar livroEscolarAux){
  for(unsigned i = 0; i< escolar.size(); i++){
    if(escolar[i].get_ID() == livroEscolarAux.get_ID()){
      escolar[i] = livroEscolarAux;//sobrescreve o livro escolar antigo pelo editado
      return true;
    }
  }
  return false;
}

bool Estoque::edit_livroL(Literario livroLiterarioAux){
  for(unsigned i = 0; i<literario.size(); i++){
    if(literario[i].get_ID() == livroLiterarioAux.get_ID()){
      literario[i] = livroLiterarioAux;//sobrescreve o livro escolar antigo pelo editado
      return true;
    }
  }
  return false;
}

bool Estoque::remov_livroL(int ID){
  for(unsigned int i = 0; i< literario.size(); i++){
    if(literario[i].get_ID() == ID){
      literario.erase(literario.begin()+i);
      return true;
    }
  }
  return false;
}

bool Estoque::remov_livroE(int ID){
  for(unsigned int i = 0; i< escolar.size(); i++){
    if(escolar[i].get_ID() == ID){
      escolar.erase(escolar.begin()+i);
      return true;
    }
  }
  return false;
}

Literario Estoque::pesquisa_livroL(int ID){
    for (unsigned i = 0; i<literario.size();i++){
      if(literario[i].get_ID() == ID)
        return literario[i];
    }
    Literario literarioVazio; //incia literario vazio
    return literarioVazio;
}

Literario Estoque::pesquisa_livroL(string titulo){
    for (unsigned i = 0; i<literario.size();i++){
      if(literario[i].get_Titulo() == titulo)
        return literario[i];
    }
    Literario literarioVazio; //incia literario vazio
    return literarioVazio;
}

Escolar Estoque::pesquisa_livroE(int ID){
    for (unsigned i = 0; i<escolar.size();i++){
      if(escolar[i].get_ID() == ID)
        return escolar[i];
    }
    Escolar escolarVazio; //incia escolar vazio
    return escolarVazio;
}

Escolar Estoque::pesquisa_livroE(string titulo){
    for (unsigned i = 0; i<escolar.size();i++){
      if(escolar[i].get_Titulo() == titulo)
        return escolar[i];
    }
    Escolar escolarVazio; //incia escolar vazio
    return escolarVazio;
}

Estoque::~Estoque(){
	
  ofstream arquivo_Livro_Escolar;
  arquivo_Livro_Escolar.open("Estoque_Livro_Escolar.txt");

  if (arquivo_Livro_Escolar.is_open()){
	  for(unsigned int i = 0; i<escolar.size(); i++){
		  arquivo_Livro_Escolar<<"ID: "<<escolar[i].get_ID()<<endl;
      	  arquivo_Livro_Escolar<<"TITULO: "<<escolar[i].get_Titulo()<<endl;
		  arquivo_Livro_Escolar<<"AUTOR: "<<escolar[i].get_Autor()<<endl;
		  arquivo_Livro_Escolar<<"PRECO: R$ "<<escolar[i].get_Preco()<<",00"<<endl;
		  arquivo_Livro_Escolar<<"QUANTIDADE: "<<escolar[i].get_Quantidade()<<endl;
		  arquivo_Livro_Escolar<<"TIPO: "<<escolar[i].get_Tipo()<<endl;
		  arquivo_Livro_Escolar<<"DISCIPLINA: "<<escolar[i].get_Disciplina()<<endl;
		  arquivo_Livro_Escolar<<endl;
		}
    
  arquivo_Livro_Escolar.close();
  }

  else{
    cout<<endl<<"Não foi possível gravar a Lista de Livros Escolares!";
    getch();
  }
  
  ofstream arquivo_Livro_Literario;
  arquivo_Livro_Literario.open("Estoque_Livro_Literario.txt");
  
  if(arquivo_Livro_Literario.is_open()){
    for(unsigned i = 0; i<literario.size(); i++){
        arquivo_Livro_Literario<<"ID: "<<literario[i].get_ID()<<endl;
        arquivo_Livro_Literario<<"TITULO: "<<literario[i].get_Titulo()<<endl;
        arquivo_Livro_Literario<<"AUTOR: "<<literario[i].get_Autor()<<endl;
        arquivo_Livro_Literario<<"PRECO: R$ "<<literario[i].get_Preco()<<",00"<<endl;
        arquivo_Livro_Literario<<"QUANTIDADE: "<<literario[i].get_Quantidade()<<endl;
        arquivo_Livro_Literario<<literario[i].get_Publico()<<endl;
        arquivo_Livro_Literario<<literario[i].get_Genero()<<endl;
        arquivo_Livro_Literario<<endl;
    }
    

  arquivo_Livro_Literario.close();
  }

  else{
    cout<<endl<<"Não foi possível gravar a Lista de Livros Literários!";
    getch();
  }
}
