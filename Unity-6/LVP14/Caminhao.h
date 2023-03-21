#ifndef CAMINHAO_H
#define CAMINHAO_H

class Caminhao : public Veiculo{
	private:
	// Private section
	string cam_type;
	string modelo;
	unsigned n_eixo;
	int cubica_cap;
	float max_carg;
	
	public:
		// Public Declarations
		Caminhao();//construtor default
		Caminhao(unsigned, unsigned, float, string, string, unsigned, int, float);
		
		void set_cam_type(string);
		void set_modelo(string);
		void set_n_eixo(unsigned);
		void set_cub_cap(int);
		void set_max_carg(float);
		
		string get_cam_type();
		string get_modelo();
		unsigned get_n_eixo();
		int get_cubica_cap();
		float get_max_carg();
};


#endif

