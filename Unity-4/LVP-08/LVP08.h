#ifndef LVP08
#define LVP08

//apenas cria��o da classe e prot�tipo das fun��es
class MegaSena{
	private:
		float Premio_Bruto;
		int reul_sort[6];
		int *deze;
		int d;
		
	public:
		MegaSena(int, int);                             //inicializa os atributos de premio bruto, numeros de dezenas e o apontador;
		~MegaSena();                             //desalocar a memoria alocada no apontador da aposta
		void set_Premiao_Bruto(float);
		void set_armazen(int []);             //receber vetor por par�metro
		int comprov();                //metodo para a impress�o do comprovante de aposta
		int sort();       //metodo para realizar sorteio
		int p_resul();     //metodo para impressao dos resultados
		float aposta();      //calcular o pre�o da aposta
};
#endif

