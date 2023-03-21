#ifndef Selec_H
#define Selec_H

//apenas cria��o da classe e prot�tipo das fun��es

class Selec {
	private:
		//parte privada
		string nome;
		int idad;
		string cpf;
		int pont;
		
	public:
		// parte publica
		Selec();
		~Selec();
		void setNome(string);
		void set_Idad(int);
		void set_CPF(string);
		void aprovado(int); //verificar se o candidato sera aprovado ou nao (para ser aprovado precisa ter tido um n�mero de pontos >= 6 e ter uma idade >=18)
		void contrato(); //metodo para impress�o de contrato com o Nome, CPF, e idade
		void resp_corr(int, int, int , int, int, int, int); //metodo para verificar se o usu�rio acertou a resposta 
		
		string getNome();
		int get_idad();
		string get_cpf();
		int pontuacao(); //metodo para retornar pontua��o
};
#endif

