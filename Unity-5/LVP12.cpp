#include "LVP12.h"

bool Hospital::AddPatient(Paciente lista){	
	for(int i = 0; i < waitlist.size(); i++){
		if (waitlist[i].Nregister == lista.Nregister)  //função que irá analizar se ja existe um número de registo igual, e após isso irá adcionar os dados do paciente no vector
			return false;
	}
	waitlist.push_back(lista);
	return true;
}

bool Hospital::AtenderP(){
	if (waitlist.size() > 0){
		atendidos.push_back(waitlist.front());  //função que ira atender um paciente e moverá suas informações para uma lista de pacientes atendidos
		waitlist.erase(waitlist.begin());
		return true;
	}
	else
		return false;
}

bool Hospital::RemvPatient(unsigned Nregister){
	for(int i = 0; i < waitlist.size(); i++){
		if (waitlist[i].Nregister == Nregister){      //função que irá remover o paciente da lista de espera
			waitlist.erase(waitlist.begin())+i;
			return true;
		}
	}
	return false;
}

bool Hospital::PVlista(){
	if(waitlist.empty())
		return true;                     //função que irá analisar se a lista esta vazia ou não
	else
		return false;
}

void Hospital::PersonData(unsigned Nregister){
	for(int i = 0; i < waitlist.size(); i++){
		if (waitlist[i].Nregister == Nregister)                      //função onde se pede um número de registro e retorna os dados do paciente que esta com o mesmo número registrado
			cout<<"\nNome: "<<waitlist[i].name<<endl<<"Doença: "<<waitlist[i].reason<<endl<<endl;		
	}
}

vector <Paciente> Hospital::NameList(){
	return waitlist;                         //função de retorno do vector de todos os pacientes na lista de espera
}

vector <Paciente> Hospital::Patendidos(){
	return atendidos;                      //função de retorno do vector de todos os pacientes ja atendidos
}
