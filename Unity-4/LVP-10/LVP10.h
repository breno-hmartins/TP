#ifndef LVP10
#define LVP10

//apenas cria��o da classe e prot�tipo das fun��es

class Fracao{
	// se��o privada
	int numera;
	int denomi;
	float resnumera;
	float resdenomi;
	
	public:
		// declara��o p�blica
		Fracao();   //construtor
		~Fracao();   //destrutor
		Fracao mult(Fracao, Fracao);   //metodo para multiplicar dois numeros da fracao
		Fracao divi(Fracao, Fracao);   //metodo para dividir dois numeros da fracao
		void set_numera(int);
		void set_denomi(int);
		int get_numera();
		int get_denomi();
		void impri();   //fun��o para imprimir na forma a/b, onde a � o numerador e b � o denominador
		void flutu();  //fun��o Imprimir os n�meros Fracao em formato de ponto flutuante.
		Fracao(int, int);		
};

#endif

