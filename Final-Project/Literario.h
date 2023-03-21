#ifndef LITERARIO_H
#define LITERARIO_H

class Literario : public Livro{

  protected:
    string Publico;//publico destinado (adulto, criança...)
    string Genero;//genero de cada livro (drama, terror, romance...)

  public:
    Literario(string = "",string = "",int = 0,string = "",string = "",float = 0.0,int = 0);
    string get_Publico();
    string get_Genero();
};

#endif
