#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
class Biblioteca{   //funciona como controlador
  private:
    Estoque estoque;
    vector <Literario> carrinhoL;
    vector <Escolar> carrinhoE;

  public:
    //recebe apenas metodo
    Biblioteca();//chamar leitor de arquivos

    bool cadastra_livro(Escolar);//cadastra livros escolar
    bool cadastra_livro(Literario);//cadastra livros escolar
    bool edita_livro(Escolar);//editar um livro escolar
    bool edita_livro(Literario);//editar um livro escolar
    bool remove_livro(unsigned,int);//remover livro
    bool comprar_livro(unsigned,string);//compra livro

    Literario dado_livrosL(string);//retorna dados do livro escolhido
    Escolar dado_livrosE(string);//retorna dados do livro escolhido
    Literario dado_livrosL(int);//retorna dados do livro escolhido
    Escolar dado_livrosE(int);//retorna dados do livro escolhido
    
    void imprime_comprovante();//retorno o comprovante da compra ao finalizar o programa

    vector <Literario> get_carrinhoL();//exibe carrinho
    vector <Escolar> get_carrinhoE();//exibe carrinho
    vector <Literario> get_estoqueL();
    vector <Escolar> get_estoqueE();

};

#endif
