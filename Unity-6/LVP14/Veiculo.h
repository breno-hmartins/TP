#ifndef VEICULO_H
#define VEICULO_H

class Veiculo {
	private:
		// Private section
		unsigned ano_fab;
		unsigned n_chassi;
		float preco;
	
	public:
		// Public Declarations
		Veiculo(); //construtor default
		Veiculo(unsigned, unsigned, float);
		
		void set_ano_fab(unsigned);
		void set_n_chassi(unsigned);
		void set_preco(float);
		
		unsigned get_ano_fab();
		unsigned get_n_chassi();
		float get_preco();

};


#endif

