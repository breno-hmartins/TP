#ifndef Veho.h
#define Velho_h

//criação da classe que irá herdar a classe mãe imóvel 

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

