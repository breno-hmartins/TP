/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 3: LVP-06

>Descri��o do programa: Implemente um sistema de gerenciamento de banco de baterias (BMS). O BMS � composto de sensores, um concentrador e acess�rios. Sua fun��o
principal �, a partir do sensoriamento de vari�veis importantes, comparar os dados recebidos com valores ideais de funcionamento. Em caso de valores n�o 
conformes com condi��es pr�-definidas, o Controlador BMS detecta a disparidade e emite um aviso sobre tal condi��o, com o objetivo de garantir seguran�a. 
Utilizado principalmente em ve�culos el�tricos, o programa controlador BMS coleta e testa os dados. Dessa forma, o programa dever� inicializar o valor dos 
atributos dos dados sensoriados atrav�s do construtor e demonstrar a utiliza��o do m�todo destrutor atrav�s de uma mensagem de sinaliza��o da execu��o do m�todo.
*/

#include <iostream>
#include <locale>

using namespace std;
//cria��o da classe Bateria
class Bateria{

	private:
		int ten_instantV;
		int temp_batC;
		int corr_batA;           //atributos privados que ser�o utilizados
		int niv_bat;
		int Vmax_corr;
	
	public:
		
		bateria();    // cria��o do prot�tipo do construtor
		
		~Bateria();   // cria��o do prot�tipo do destrutor
		
		void set_ten_instantV(int);
		void set_temp_batC(int);
		void set_corr_batA(int);
		void set_niv_bat(int);                //cria��o dos prot�ripos com o m�todo set para atribuir as vari�veis
		void set_Vmax_corr(int);
		void compara_carga(int, int);       //cria��o dos prot�tipos de void que ir�o fazer as an�lises
		void compara_temp(int);
		void compara_bat(int);
		
		int get_ten_instantV();        
		int get_temp_batC();
		int get_corr_batA();                //cria��o dos prot�tipos com o m�todo get para retornar os valores atribu�dos
		int get_niv_bat();
		int get_Vmax_corr();
		float pot(int, int);           //fun��o para calcular a pot�ncia
};

Bateria::bateria(){
	ten_instantV = 0;
	temp_batC = 0;             //contrutor que iniciar� os valores da se��o private igualando igual a 0
	corr_batA = 0;             // para n�o obter lixo durante os processos
	niv_bat = 0;
	Vmax_corr = 0;
}

Bateria::~Bateria(){
	cout<<endl<<"TESTES REALIZADOS COM SUCESSO!!!"<<endl;         // destrutor para avisar que todos os testes foram realizados
}

void Bateria::set_ten_instantV(int tensao_aux){
	ten_instantV = tensao_aux;                     
}

void Bateria::set_temp_batC(int temp_aux){
	temp_batC = temp_aux;
}

void Bateria::set_corr_batA(int corrente_aux){
	corr_batA = corrente_aux;
}                                                          //fun��es set para atribuir os valores das vari�veis na parte private da class

void Bateria::set_niv_bat(int nivel_aux){
	niv_bat = nivel_aux;
}

void Bateria::set_Vmax_corr(int valor_aux){
	Vmax_corr = valor_aux;
}

void Bateria::compara_carga(int corrente_aux, int valor_aux){
	if (corrente_aux >= Vmax_corr)
		cout<<"Corrente anormal (estado de alerta)!"<<endl;            //fun��o que ir� realizar o teste de compara��o de correntes da bateria
	else if (corrente_aux < Vmax_corr)
		cout<<"Corrente normal!"<<endl;
}

void Bateria::compara_temp(int temp_aux){
	if (temp_aux > 25)
		cout<<"Temperatura anormal (estado de alerta)!"<<endl;      //fun��o que ir� realizar o teste de temperatura da bateria
	else if (temp_aux <= 25)
		cout<<"Temperatura normal!"<<endl;
}

void Bateria::compara_bat(int nivel_aux){
	if (nivel_aux < 30)
		cout<<"Estado de carga anormal (estado de alerta)!"<<endl;       //fun��o que ir� realizar o teste do estado da carga atual da bateria
	else if (nivel_aux >= 30)
		cout<<"Estado de carga normal!"<<endl;
}

int Bateria::get_ten_instantV(){
	return ten_instantV;
}

int Bateria::get_temp_batC(){
	return temp_batC;
}

int Bateria::get_corr_batA(){
	return corr_batA;
}                                             //fun��es de m�todo get para retornar valores salvos na se��o private da class

int Bateria::get_niv_bat(){
	return niv_bat;
}

int Bateria::get_Vmax_corr(){
	return Vmax_corr;                 
}

float Bateria::pot(int corrente_aux, int tensao_aux){
	return (corrente_aux*tensao_aux);                     //fun��o que ir� calcular a pot�ncia da bateria
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Bateria pilha;     //cria��o de um acesso a classe Bateria
	
	float tensao_aux;
	float temp_aux;
	int corrente_aux;        //cria��o das vari�veis auxiliares
	int nivel_aux;
	int valor_aux;
	
	cout<<"Analisador de sa�de de bateria"<<endl<<endl;   //mensagem informativa
	
	cout<<"Informe o valor da tens�o instant�nea da bateria: "<<endl;
	cin>>tensao_aux;	
	cout<<endl<<"Informe o valor da corrente que a bateria possui: "<<endl;
	cin>>corrente_aux;
	cout<<endl<<"Informe a temperatura que est� a bateria: "<<endl;                         //atribuindo valores nas vari�veis auxiliares
	cin>>temp_aux;
	cout<<endl<<"Informe o valor da corrente de sobrecarga: "<<endl;
	cin>>valor_aux;
	cout<<endl<<"Informe o n�vel de carga em que a bateria se encontra (em porcentagem): "<<endl;
	cin>>nivel_aux;
	
	pilha.set_ten_instantV(tensao_aux);
	pilha.set_temp_batC(temp_aux);	
	pilha.set_niv_bat(nivel_aux);                  //atribuindo os valores das vari�veis dentro da class
	pilha.set_Vmax_corr(valor_aux);
	pilha.set_corr_batA(corrente_aux);

	
	cout<<"\n-------------------------------"<<endl;
	cout<<endl<<"A tens�o da bateria � de: "<<pilha.get_ten_instantV()<<"V"<<endl;              //retorno da tensao da bateria em conjunto com chamada da fun��o get para retornar o valor da tensao atribuida
	
	cout<<"A corrente da bateria � de: "<<pilha.get_corr_batA()<<"A, ";     //retorno do valor da corrente da bateria usando o metodo get e chamada da fun��o de compara��o das correntes
	pilha.compara_carga(corrente_aux, valor_aux);
	
	cout<<"A pot�ncia da bateria � de: "<<pilha.pot(corrente_aux, tensao_aux)<<"W"<<endl;  //chamando a fun��o que retorna o valor da potencia atraves da formula inserida na fun��o
	
	cout<<"Sensor de temperatura detectou uma temperatura de: "<<pilha.get_temp_batC()<<"�C, ";  //retorno do valor da temperatura da bateria atruida e chamada da fun��o de an�lise de temperatura
	pilha.compara_temp(temp_aux);
	
	cout<<"A bateria se encontra com uma carga de: "<<pilha.get_niv_bat()<<"%, ";    // retorno do n�vel atual da bateria e chamada da fun��o de an�lise do n�vel de bateria
	pilha.compara_bat(nivel_aux);	

	return 0;          // fim do programa
}
