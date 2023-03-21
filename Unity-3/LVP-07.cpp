/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 3: LVP-07

>Descri��o do programa: Crie uma classe chamada Ve�culo para calcular valor de um servi�o veicular. A classe deve armazenar atributos como: Pre�o do 
Litro, Capacidade M�xima em Litros do Tanque do Ve�culo, Consumo em km/L, Quantidade de litros no tanque, Quilometragem do ve�culo e o Total gasto.
*/

#include <iostream>
#include <locale>

using namespace std;

class Veiculo{
	
	private:
		float preco_L;
		int tanque_maxL;
		float consum;
		float quant_L_tanq;
		float quilom;
		float gasto_total;              //loop antes da classe
		
	public:
		Veiculo(float preco_aux, int tanque_aux, float con_aux, float litranq); //com parametros
		Veiculo(); //sem parametros
		
		~Veiculo();
		
		void set_preco_L(float);
		void set_tanque_maxL(int);
		void set_consum(float);
		void set_quant_L_tanq(float);
		void set_quilom(float);
		void custos(float);
		
		float get_preco_L();
		int get_tanque_maxL();
		float get_consum();
		float get_quent_L_tanq();
		float get_quilom();
		float abastecimento(float, float); //fun��o para calcular o valor total da compra
		float autonomia(); 
		bool PercorrerDistancia(); //falta fazer
		float Deslocamento();	//falta fazer
};

Veiculo::Veiculo(){   //inicializador sem parametros para n�o pegar lixo de mem�ria
	preco_L = 0;
	tanque_maxL = 0;
	consum = 0;
	quant_L_tanq = 0.10*tanque_maxL;
	quilom = 0;
}

Veiculo::Veiculo(float preco_aux, int tanq_aux, float con_aux, float litranq){ //inicializador com parametros para envolver os metodos set
	set_preco_L(preco_aux);
	set_tanque_maxL(tanq_aux);
	set_consum(con_aux);
	set_quant_L_tanq(litranq);
}

Veiculo::~Veiculo(){
	cout<<"\nObjeto destru�do!"<<endl;
}

void Veiculo::set_preco_L(float preco_aux){
	preco_L = preco_aux;
}

void Veiculo::set_tanque_maxL(int tanq_aux){
	tanque_maxL = tanq_aux;
}

void Veiculo::set_consum(float con_aux){
	consum = con_aux;
}

void Veiculo::set_quant_L_tanq(float litranq){
	quant_L_tanq = litranq;
}

void Veiculo::set_quilom(float quilometro){
	quilom = quilometro;
}

float Veiculo::get_preco_L(){
	return preco_L;
}

int Veiculo::get_tanque_maxL(){
	return tanque_maxL;
}

float Veiculo::get_consum(){
	return consum;
}

float Veiculo::get_quent_L_tanq(){
	return quant_L_tanq;
}

float Veiculo::get_quilom(){
	return quilom;
}

float Veiculo::abastecimento(float litranq, float preco_aux){
	float a;
	if (tanque_maxL > litranq+quant_L_tanq){
		a = (litranq*preco_aux)*1.025;                           //quant_L_tanq+=litranq
		custos(a);
		return a;
	}
	else{
		return 0;
	}	
	
}
void Veiculo::custos(float a){
	gasto_total+=a;
}

float Veiculo::autonomia(){
	return consum*quant_L_tanq;
}

//bool Veiculo::PercorrerDistancia(){
//	if (quant_L_tanq)
//}

int main(){
	setlocale(LC_ALL, "Portuguese");

	float preco_aux;
	int tanq_aux;
	float con_aux;
	float litranq;
	float quilometro;
	int x=0;
	

	cout<<"Auxiliar de planejamento de gastos para viagem de carro!!!\n"<<endl;
	
	cout<<"\nInforme o consumo de seu ve�culo:"<<endl;
	cin>>con_aux;
	
	cout<<"\nInsira a capacidade do tanque de seu ve�culo:"<<endl;
	cin>>tanq_aux;
	
	cout<<"\nInforme o pre�o do combust�vel, por litro, em sua regi�o:"<<endl;
	cin>>preco_aux;
	
	Veiculo monza(preco_aux, tanq_aux, con_aux, 0);

	do{
		cout<<"\nInsira a quantidade de litros que deseja colocar de combust�vel:"<<endl;
		cin>>litranq;		
	
		cout<<"\nInforme a quantidade de quilometros que deseja percorrer:"<<endl;
		cin>>quilometro;
		
		cout<<"Valor total da compra: "<<monza.abastecimento(litranq, preco_aux)<<" R$"<<endl;
		cout<<"Autonomia do veiculo: "<<monza.autonomia()<<"Km"<<endl;
		
	
		cout<<"\nDigite 1 - Para Continuar | 2 - Para Sair do Programa:"<<endl;
		cin>>x;
	}while(x == 1);
	
	//infelizmente n�o consegui finalizar, n�o esva conseguindo realizar a l�gica das fun��es que rotornam valores de forma correta
	
	return 0;
}

