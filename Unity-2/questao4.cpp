/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 2: LVP-04

>Descri��o do programa: Crie uma classe Empresa_Solar para calcular a quantidade de pain�is solares 
necess�rios para uma resid�ncia em fun��o do consumo mensal em kWh do im�vel. Al�m do n�mero de pain�is 
dever� ser determinado tamb�m a �rea m�nima que esses pain�is ocupam e a economia anual gerada pela 
ado��o do sistema com base no valor mensal gasto pelo im�vel, fornecido pelo usu�rio em reais.
*/

#include <iostream>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;
//cria��o da classe Empresa Solar
class Empresa_Solar{

	private:

		float pot_residencia;
		float valor_mensal;
		float pot_painel = 31.20;         //selecionando os itens privados
		int paineis;

	public:
		void set_potencia(float);
		void set_valor_mensal(float);
		void painel();                       //selecionando os itens e fun��es na parte p�blica da classe
		void calcula_paineis();

		int get_paineis();
		int calcula_area_minima();
		float economia();
};

void Empresa_Solar::set_potencia(float p){
	   pot_residencia = p;                        //esta fun��o ir� direcionar o valor informado pelo usu�rio at� o objeto de potencia
};

void Empresa_Solar::set_valor_mensal(float m){
	valor_mensal = m;                             //exerce a mersma fun��o que a de cima, mas diferente pois � para o valor mensal
};

void Empresa_Solar::painel(){
	pot_painel;                    // essa fun��o chama o pot_painel que possui o valor de uma constante
};

void Empresa_Solar::calcula_paineis(){
	paineis = ceil(pot_residencia/pot_painel);       //aqui � onde acontece o calculo de quantos paineis ser�o necess�rios
};

int Empresa_Solar::get_paineis(){
	return (paineis);                  //nesta parte, a fun��o retorna o n�mero de paineis para o usu�rio
};

int Empresa_Solar::calcula_area_minima(){
	return paineis *2;                      //a fun��o calcula a �rea m�nima que ser� utilizada pelos paineis
};

float Empresa_Solar::economia(){
	return (0.95*valor_mensal)*12;       //serve para calcular a quantidade de dinheiro que uma pessoa ir� econimizar anualmente com as placas instaladas
};

int main(){
	setlocale(LC_ALL,"Portuguese");

	Empresa_Solar energy;

	float p = 0,m = 0;      //definindo as vari�veis utilizadas no programa

	cout<<"--------------------------------------------------------------------\n\nO programa a seguir ir� "
		<<"calcular quantos pain�is ser�o necess�rios\nna sua casa, a �rea m�nima para instala��o, e a"          // apresneta��o do programa
		<<" economia anual que\nvoc� ter�!\n\n"
		<<"--------------------------------------------------------------------"<<endl;

	cout<<endl<<"Informe a pot�ncia mensal em kwh:"<<endl; 	//pede e armazena o valor da potencia mensal
	cin>>p;
	cout<<"Informe o gasto mensal em reais:"<<endl;      //pede e armazena o gasto mensal
	cin>>m;

	energy.set_potencia(p);     //chamada da fun��es com o par�metros de potencia
	energy.calcula_paineis();     //chamada da fun��o que calcula a quantidade de paineis
	cout<<"A quantidade de pain�is necess�rios � de "<<energy.get_paineis()<<endl;       //retorna o resultado do n�mero de paineis
	cout<<"\nA �rea m�nima para a instala��o � de "<<energy.calcula_area_minima()<<"m�"<<endl; //retorna o resultado da �rea m�nima
	energy.set_valor_mensal(m);  //chamada da fun��o com o parametro de valor mensal
	cout<<"\nE ter� uma economia anual de "<<fixed<< setprecision(2)<<energy.economia()<<"R$ por ano"<<endl;  //retorna a quatidade de dinheiro economizado
	//fim do programa
	
	return 0;
}