#ifndef Veho.h
#define Velho_h

//cria��o da classe que ir� herdar a classe m�e im�vel 

class Velho : public Imovel {
	private:
		float desconto;
	
	public:
		// Public Declarations
		Velho(float, string, float);
		float f_desconto();
		float final();
		void impressao();	
};


#endif

