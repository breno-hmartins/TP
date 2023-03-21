#ifndef Novo.h
#define Novo_h

//criação da classe que irá herdar a classe mãe imóvel 

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
