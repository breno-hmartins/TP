#ifndef LVP10
#define LVP10

//apenas criação da classe e protótipo das funções

class Fracao{
	// seção privada
	int numera;
	int denomi;
	float resnumera;
	float resdenomi;
	
	public:
		// declaração pública
		Fracao();   //construtor
		~Fracao();   //destrutor
		Fracao mult(Fracao, Fracao);   //metodo para multiplicar dois numeros da fracao
		Fracao divi(Fracao, Fracao);   //metodo para dividir dois numeros da fracao
		void set_numera(int);
		void set_denomi(int);
		int get_numera();
		int get_denomi();
		void impri();   //função para imprimir na forma a/b, onde a é o numerador e b é o denominador
		void flutu();  //função Imprimir os números Fracao em formato de ponto flutuante.
		Fracao(int, int);		
};

#endif

