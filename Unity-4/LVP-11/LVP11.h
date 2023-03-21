#ifndef LVP11
#define LVP11

//apenas criação da classe e protótipo das funções

class Relogio {
	// seção privada
	int Hora;
	int Minuto;
	int Segundos;
	
	public:
		// Public Declarations
		int getHora();
		int getMinuto();
		int getSegundos();		
		int avancHorario();
		void setHora(int, int, int);
};
#endif

