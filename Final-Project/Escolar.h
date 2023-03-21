#ifndef ESCOLAR_H
#define ESCOLAR_H

class Escolar: public Livro{

  protected:
    string Tipo;
    string Disciplina;

  public:
    Escolar(string = "",string = "",int = 0,string = "",string = "",float = 0.0,int = 0);
    string get_Tipo();
    string get_Disciplina();
};

#endif
