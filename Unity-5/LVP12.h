#ifndef LVP12
#define LVP12

//apenas cria��o da classe e prot�tipo das fun��es

class Hospital {
	// Privado
	vector <Paciente> waitlist; //cria��o do vector tipo struct
	vector <Paciente> atendidos; //cria��o do vector tipo struct
	
	public:
		// Publica
		bool AddPatient(Paciente); //adciona um paciente a lista de espera
		bool AtenderP(); //atender paciente da lista de espera
		bool RemvPatient(unsigned); // remover paciente da lista de espera
		bool PVlista(); //analisar se a lsita esta vazia
		void PersonData(unsigned); //imprimir as informa��es de um paciente espec�fico
		vector <Paciente> NameList(); //imprimir a lista de pacientes
		vector <Paciente> Patendidos(); //imprimi lista de paciente atendido		
};
#endif

