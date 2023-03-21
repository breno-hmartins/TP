#ifndef ESTOQUE_H
#define ESTOQUE_H

class Estoque{

  protected:
    vector <Escolar> escolar; //lista de livros didaticos
    vector <Literario> literario;//lista de livros paradidaticos

  public:
    //Construtor
    Estoque(); //Armazena dados do arquivo no Vector

    bool set_Escolar(Escolar);//recebe lista de livros didáticos
    bool set_Literario(Literario);//recebe lista de livros paradidaticos

    vector <Escolar> get_Escolar(); //retorna lista de livros didaticos
    vector <Literario> get_Literario();////retorna lista de livros paradidaticos

    bool edit_livroE(Escolar);//editar um livro escolar
    bool edit_livroL(Literario);//editar um livro literario
    bool remov_livroL(int);//remover livro literario
    bool remov_livroE(int);//remover livro escolar

    Escolar pesquisa_livroE(int);
    Literario pesquisa_livroL(int);
    Escolar pesquisa_livroE(string);
    Literario pesquisa_livroL(string);

    //Destrutor
    ~Estoque(); //Retira dados do vector e salva no arquivo
};
#endif
