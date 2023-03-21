#include "LVP11.h"

void Relogio::setHora(int Hora, int Minuto, int Segundos){             
	this -> Hora = Hora;
	this -> Minuto = Minuto;
	this -> Segundos = Segundos;
}

int Relogio::getHora(){
	return Hora;
}

int Relogio::getMinuto(){
	return Minuto;
}

int Relogio::getSegundos(){
	return Segundos;
}

int Relogio::avancHorario(){           //função para realizar o adiantamento do tempo
	Segundos ++;
	
	if (Segundos > 59){
		Segundos = 0;
		Minuto++;
	}
	else if (Minuto > 59){
		Minuto = 0;
		Hora++;
	}
	else if (Hora > 23)
		Hora = 0;
}
