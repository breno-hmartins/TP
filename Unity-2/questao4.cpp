/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 2: LVP-04

>Descrição do programa: Crie uma classe Empresa_Solar para calcular a quantidade de painéis solares 
necessários para uma residência em função do consumo mensal em kWh do imóvel. Além do número de painéis 
deverá ser determinado também a área mínima que esses painéis ocupam e a economia anual gerada pela 
adoção do sistema com base no valor mensal gasto pelo imóvel, fornecido pelo usuário em reais.
*/

#include <iostream>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;
//criação da classe Empresa Solar
class Empresa_Solar{

	private:

		float pot_residencia;
		float valor_mensal;
		float pot_painel = 31.20;         //selecionando os itens privados
		int paineis;

	public:
		void set_potencia(float);
		void set_valor_mensal(float);
		void painel();                       //selecionando os itens e funções na parte pública da classe
		void calcula_paineis();

		int get_paineis();
		int calcula_area_minima();
		float economia();
};

void Empresa_Solar::set_potencia(float p){
	   pot_residencia = p;                        //esta função irá direcionar o valor informado pelo usuário até o objeto de potencia
};

void Empresa_Solar::set_valor_mensal(float m){
	valor_mensal = m;                             //exerce a mersma função que a de cima, mas diferente pois é para o valor mensal
};

void Empresa_Solar::painel(){
	pot_painel;                    // essa função chama o pot_painel que possui o valor de uma constante
};

void Empresa_Solar::calcula_paineis(){
	paineis = ceil(pot_residencia/pot_painel);       //aqui é onde acontece o calculo de quantos paineis serão necessários
};

int Empresa_Solar::get_paineis(){
	return (paineis);                  //nesta parte, a função retorna o número de paineis para o usuário
};

int Empresa_Solar::calcula_area_minima(){
	return paineis *2;                      //a função calcula a área mínima que será utilizada pelos paineis
};

float Empresa_Solar::economia(){
	return (0.95*valor_mensal)*12;       //serve para calcular a quantidade de dinheiro que uma pessoa irá econimizar anualmente com as placas instaladas
};

int main(){
	setlocale(LC_ALL,"Portuguese");

	Empresa_Solar energy;

	float p = 0,m = 0;      //definindo as variáveis utilizadas no programa

	cout<<"--------------------------------------------------------------------\n\nO programa a seguir irá "
		<<"calcular quantos painéis serão necessários\nna sua casa, a área mínima para instalação, e a"          // apresnetação do programa
		<<" economia anual que\nvocê terá!\n\n"
		<<"--------------------------------------------------------------------"<<endl;

	cout<<endl<<"Informe a potência mensal em kwh:"<<endl; 	//pede e armazena o valor da potencia mensal
	cin>>p;
	cout<<"Informe o gasto mensal em reais:"<<endl;      //pede e armazena o gasto mensal
	cin>>m;

	energy.set_potencia(p);     //chamada da funções com o parámetros de potencia
	energy.calcula_paineis();     //chamada da função que calcula a quantidade de paineis
	cout<<"A quantidade de painéis necessários é de "<<energy.get_paineis()<<endl;       //retorna o resultado do número de paineis
	cout<<"\nA área mínima para a instalação é de "<<energy.calcula_area_minima()<<"m²"<<endl; //retorna o resultado da área mínima
	energy.set_valor_mensal(m);  //chamada da função com o parametro de valor mensal
	cout<<"\nE terá uma economia anual de "<<fixed<< setprecision(2)<<energy.economia()<<"R$ por ano"<<endl;  //retorna a quatidade de dinheiro economizado
	//fim do programa
	
	return 0;
}