#ifndef Selec_H
#define Selec_H

//apenas criação da classe e protótipo das funções

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
		void aprovado(int); //verificar se o candidato sera aprovado ou nao (para ser aprovado precisa ter tido um número de pontos >= 6 e ter uma idade >=18)
		void contrato(); //metodo para impressão de contrato com o Nome, CPF, e idade
		void resp_corr(int, int, int , int, int, int, int); //metodo para verificar se o usuário acertou a resposta 
		
		string getNome();
		int get_idad();
		string get_cpf();
		int pontuacao(); //metodo para retornar pontuação
};
#endif

