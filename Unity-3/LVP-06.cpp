/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 3: LVP-06

>Descrição do programa: Implemente um sistema de gerenciamento de banco de baterias (BMS). O BMS é composto de sensores, um concentrador e acessórios. Sua função
principal é, a partir do sensoriamento de variáveis importantes, comparar os dados recebidos com valores ideais de funcionamento. Em caso de valores não 
conformes com condições pré-definidas, o Controlador BMS detecta a disparidade e emite um aviso sobre tal condição, com o objetivo de garantir segurança. 
Utilizado principalmente em veículos elétricos, o programa controlador BMS coleta e testa os dados. Dessa forma, o programa deverá inicializar o valor dos 
atributos dos dados sensoriados através do construtor e demonstrar a utilização do método destrutor através de uma mensagem de sinalização da execução do método.
*/

#include <iostream>
#include <locale>

using namespace std;
//criação da classe Bateria
class Bateria{

	private:
		int ten_instantV;
		int temp_batC;
		int corr_batA;           //atributos privados que serão utilizados
		int niv_bat;
		int Vmax_corr;
	
	public:
		
		bateria();    // criação do protótipo do construtor
		
		~Bateria();   // criação do protótipo do destrutor
		
		void set_ten_instantV(int);
		void set_temp_batC(int);
		void set_corr_batA(int);
		void set_niv_bat(int);                //criação dos protóripos com o método set para atribuir as variáveis
		void set_Vmax_corr(int);
		void compara_carga(int, int);       //criação dos protótipos de void que irão fazer as análises
		void compara_temp(int);
		void compara_bat(int);
		
		int get_ten_instantV();        
		int get_temp_batC();
		int get_corr_batA();                //criação dos protótipos com o método get para retornar os valores atribuídos
		int get_niv_bat();
		int get_Vmax_corr();
		float pot(int, int);           //função para calcular a potência
};

Bateria::bateria(){
	ten_instantV = 0;
	temp_batC = 0;             //contrutor que iniciará os valores da seção private igualando igual a 0
	corr_batA = 0;             // para não obter lixo durante os processos
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
}                                                          //funções set para atribuir os valores das variáveis na parte private da class

void Bateria::set_niv_bat(int nivel_aux){
	niv_bat = nivel_aux;
}

void Bateria::set_Vmax_corr(int valor_aux){
	Vmax_corr = valor_aux;
}

void Bateria::compara_carga(int corrente_aux, int valor_aux){
	if (corrente_aux >= Vmax_corr)
		cout<<"Corrente anormal (estado de alerta)!"<<endl;            //função que irá realizar o teste de comparação de correntes da bateria
	else if (corrente_aux < Vmax_corr)
		cout<<"Corrente normal!"<<endl;
}

void Bateria::compara_temp(int temp_aux){
	if (temp_aux > 25)
		cout<<"Temperatura anormal (estado de alerta)!"<<endl;      //função que irá realizar o teste de temperatura da bateria
	else if (temp_aux <= 25)
		cout<<"Temperatura normal!"<<endl;
}

void Bateria::compara_bat(int nivel_aux){
	if (nivel_aux < 30)
		cout<<"Estado de carga anormal (estado de alerta)!"<<endl;       //função que irá realizar o teste do estado da carga atual da bateria
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
}                                             //funções de método get para retornar valores salvos na seção private da class

int Bateria::get_niv_bat(){
	return niv_bat;
}

int Bateria::get_Vmax_corr(){
	return Vmax_corr;                 
}

float Bateria::pot(int corrente_aux, int tensao_aux){
	return (corrente_aux*tensao_aux);                     //função que irá calcular a potência da bateria
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Bateria pilha;     //criação de um acesso a classe Bateria
	
	float tensao_aux;
	float temp_aux;
	int corrente_aux;        //criação das variáveis auxiliares
	int nivel_aux;
	int valor_aux;
	
	cout<<"Analisador de saúde de bateria"<<endl<<endl;   //mensagem informativa
	
	cout<<"Informe o valor da tensão instantânea da bateria: "<<endl;
	cin>>tensao_aux;	
	cout<<endl<<"Informe o valor da corrente que a bateria possui: "<<endl;
	cin>>corrente_aux;
	cout<<endl<<"Informe a temperatura que está a bateria: "<<endl;                         //atribuindo valores nas variáveis auxiliares
	cin>>temp_aux;
	cout<<endl<<"Informe o valor da corrente de sobrecarga: "<<endl;
	cin>>valor_aux;
	cout<<endl<<"Informe o nível de carga em que a bateria se encontra (em porcentagem): "<<endl;
	cin>>nivel_aux;
	
	pilha.set_ten_instantV(tensao_aux);
	pilha.set_temp_batC(temp_aux);	
	pilha.set_niv_bat(nivel_aux);                  //atribuindo os valores das variáveis dentro da class
	pilha.set_Vmax_corr(valor_aux);
	pilha.set_corr_batA(corrente_aux);

	
	cout<<"\n-------------------------------"<<endl;
	cout<<endl<<"A tensão da bateria é de: "<<pilha.get_ten_instantV()<<"V"<<endl;              //retorno da tensao da bateria em conjunto com chamada da função get para retornar o valor da tensao atribuida
	
	cout<<"A corrente da bateria é de: "<<pilha.get_corr_batA()<<"A, ";     //retorno do valor da corrente da bateria usando o metodo get e chamada da função de comparação das correntes
	pilha.compara_carga(corrente_aux, valor_aux);
	
	cout<<"A potência da bateria é de: "<<pilha.pot(corrente_aux, tensao_aux)<<"W"<<endl;  //chamando a função que retorna o valor da potencia atraves da formula inserida na função
	
	cout<<"Sensor de temperatura detectou uma temperatura de: "<<pilha.get_temp_batC()<<"°C, ";  //retorno do valor da temperatura da bateria atruida e chamada da função de análise de temperatura
	pilha.compara_temp(temp_aux);
	
	cout<<"A bateria se encontra com uma carga de: "<<pilha.get_niv_bat()<<"%, ";    // retorno do nível atual da bateria e chamada da função de análise do nível de bateria
	pilha.compara_bat(nivel_aux);	

	return 0;          // fim do programa
}
