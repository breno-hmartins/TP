#include "Selec_H.h"

Selec::Selec(){
	nome = " ";
	idad = 0;
	cpf = " ";              //inicizador das variáveis
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

void Selec::aprovado(int idade_aux){  //função que vai analisar se o candidato foi aprovado ou não
	if (pont>=6 && idade_aux >= 18){
		cout<<"Parabéns, você foi selecionado!\nSua pontuação foi de: "<<pont<<"/7"<<endl;
		contrato();
	}
	else if(idade_aux < 18)
		cout<<"Você não é o padrão que nossa empresa procura, até logo!\nObrigado por nos dar uma chance de entrevista-lo"<<endl;
	else if (pont<6 && idade_aux >=18)
		cout<<"Você não é o padrão que nossa empresa procura, até logo!\nObrigado por nos dar uma chance de entrevista-lo\nSua pontuação foi: "<<pont<<"/7"<<endl;
}

void Selec::contrato(){
	cout<<"Nome: "<<nome<<"     CPF: "<<cpf<<endl
		<<"Salário de: R$ 2000,00 + bonificações"<<endl            //função que irá imprimir o contrato do candidato após a avaliação
		<<"Contratante: Marcus Salerno"<<endl;
}

void Selec::resp_corr(int q1, int q2, int q3, int q4, int q5, int q6, int q7){ //função que analisa as respostas e soma a pontuação do candidato
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
	return pont;          //função que irá retornar a pontuação do candidato
}
