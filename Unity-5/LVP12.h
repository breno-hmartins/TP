#ifndef LVP12
#define LVP12

//apenas criação da classe e protótipo das funções

class Hospital {
	// Privado
	vector <Paciente> waitlist; //criação do vector tipo struct
	vector <Paciente> atendidos; //criação do vector tipo struct
	
	public:
		// Publica
		bool AddPatient(Paciente); //adciona um paciente a lista de espera
		bool AtenderP(); //atender paciente da lista de espera
		bool RemvPatient(unsigned); // remover paciente da lista de espera
		bool PVlista(); //analisar se a lsita esta vazia
		void PersonData(unsigned); //imprimir as informações de um paciente específico
		vector <Paciente> NameList(); //imprimir a lista de pacientes
		vector <Paciente> Patendidos(); //imprimi lista de paciente atendido		
};
#endif

