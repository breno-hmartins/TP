#ifndef LVP11
#define LVP11

//apenas cria��o da classe e prot�tipo das fun��es

class Relogio {
	// se��o privada
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

