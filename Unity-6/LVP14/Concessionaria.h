#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H

class Concessionaria {
	private:
	// Private section
	vector <Carro> estq_carro;
	vector <Caminhao> estq_caminhao;
	public:
		// Public Declarations
		Concessionaria();
		~Concessionaria();
		
		bool add_carro(Carro);
		bool v_carro(unsigned);
		void get_listCar();
		void save_carro();
		
		bool add_caminhao(Caminhao);
		bool v_caminhao(unsigned);
		void get_listCaminhao();
		void save_caminhao();
};


#endif

