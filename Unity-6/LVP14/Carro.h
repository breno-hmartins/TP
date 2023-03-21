#ifndef CARRO_H
#define CARRO_H

class Carro : public Veiculo{
	private:
	// Private section
	string v_type;
	string model;
	
	public:
		// Public Declarations
		Carro();//construtor default
		Carro(unsigned, unsigned, float, string, string);
		
		void set_Vtype(string);
		void set_model(string);
		
		string get_Vtype();
		string get_model();		
};

#endif

