#ifndef Novo.h
#define Novo_h

//cria��o da classe que ir� herdar a classe m�e im�vel 

class Novo : public Imovel{
	private:
		float adicional;
	
	public:
		// Public Declarations
		Novo(float, string, float);
		double f_adicional();
		float final();
		void impressao();
};
#endif
