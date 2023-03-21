#include "LVP12.h"

bool Hospital::AddPatient(Paciente lista){	
	for(int i = 0; i < waitlist.size(); i++){
		if (waitlist[i].Nregister == lista.Nregister)  //fun��o que ir� analizar se ja existe um n�mero de registo igual, e ap�s isso ir� adcionar os dados do paciente no vector
			return false;
	}
	waitlist.push_back(lista);
	return true;
}

bool Hospital::AtenderP(){
	if (waitlist.size() > 0){
		atendidos.push_back(waitlist.front());  //fun��o que ira atender um paciente e mover� suas informa��es para uma lista de pacientes atendidos
		waitlist.erase(waitlist.begin());
		return true;
	}
	else
		return false;
}

bool Hospital::RemvPatient(unsigned Nregister){
	for(int i = 0; i < waitlist.size(); i++){
		if (waitlist[i].Nregister == Nregister){      //fun��o que ir� remover o paciente da lista de espera
			waitlist.erase(waitlist.begin())+i;
			return true;
		}
	}
	return false;
}

bool Hospital::PVlista(){
	if(waitlist.empty())
		return true;                     //fun��o que ir� analisar se a lista esta vazia ou n�o
	else
		return false;
}

void Hospital::PersonData(unsigned Nregister){
	for(int i = 0; i < waitlist.size(); i++){
		if (waitlist[i].Nregister == Nregister)                      //fun��o onde se pede um n�mero de registro e retorna os dados do paciente que esta com o mesmo n�mero registrado
			cout<<"\nNome: "<<waitlist[i].name<<endl<<"Doen�a: "<<waitlist[i].reason<<endl<<endl;		
	}
}

vector <Paciente> Hospital::NameList(){
	return waitlist;                         //fun��o de retorno do vector de todos os pacientes na lista de espera
}

vector <Paciente> Hospital::Patendidos(){
	return atendidos;                      //fun��o de retorno do vector de todos os pacientes ja atendidos
}
