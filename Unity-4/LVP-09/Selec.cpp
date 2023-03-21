#include "Selec_H.h"

Selec::Selec(){
	nome = " ";
	idad = 0;
	cpf = " ";              //inicizador das vari�veis
	pont = 0;
}

Selec::~Selec(){
	
}

void Selec::setNome(string nome_aux){
     nome = nome_aux;
}

void Selec::set_Idad(int idade_aux){
	idad = idade_aux;
}

void Selec::set_CPF(string cpf_aux){
	cpf = cpf_aux;
}

string Selec::getNome(){
	return nome;
}

string Selec::get_cpf(){
	return cpf;
}

int Selec::get_idad(){
	return idad;
}

void Selec::aprovado(int idade_aux){  //fun��o que vai analisar se o candidato foi aprovado ou n�o
	if (pont>=6 && idade_aux >= 18){
		cout<<"Parab�ns, voc� foi selecionado!\nSua pontua��o foi de: "<<pont<<"/7"<<endl;
		contrato();
	}
	else if(idade_aux < 18)
		cout<<"Voc� n�o � o padr�o que nossa empresa procura, at� logo!\nObrigado por nos dar uma chance de entrevista-lo"<<endl;
	else if (pont<6 && idade_aux >=18)
		cout<<"Voc� n�o � o padr�o que nossa empresa procura, at� logo!\nObrigado por nos dar uma chance de entrevista-lo\nSua pontua��o foi: "<<pont<<"/7"<<endl;
}

void Selec::contrato(){
	cout<<"Nome: "<<nome<<"     CPF: "<<cpf<<endl
		<<"Sal�rio de: R$ 2000,00 + bonifica��es"<<endl            //fun��o que ir� imprimir o contrato do candidato ap�s a avalia��o
		<<"Contratante: Marcus Salerno"<<endl;
}

void Selec::resp_corr(int q1, int q2, int q3, int q4, int q5, int q6, int q7){ //fun��o que analisa as respostas e soma a pontua��o do candidato
	if (q1 == 1)
		pont++;
	if (q2 == 1)
		pont++;
	if (q3==2)
		pont++;
	if (q4==1)
		pont++;
	if (q5==2)
		pont++;
	if (q6==1)
		pont++;
	if (q7==1)
		pont++;
}

int Selec::pontuacao(){
	return pont;          //fun��o que ir� retornar a pontua��o do candidato
}
