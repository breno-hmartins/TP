#ifndef LIVRO_H
#define LIVRO_H

class Livro{

  protected:
    int ID;
    string Titulo;
    string Autor;
    float Preco;
    int Quantidade;

  public:
    Livro(int = 0,string = "",string = "",float = 0.0,int = 0);
    int get_ID();
    string get_Titulo();
    string get_Autor();
    float get_Preco();
    void set_Quantidade(int);
    int get_Quantidade();
    bool isEmpty();

};
#endif
