/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 3: LVP-07

>Descrição do programa: Crie uma classe chamada Veículo para calcular valor de um serviço veicular. A classe deve armazenar atributos como: Preço do 
Litro, Capacidade Máxima em Litros do Tanque do Veículo, Consumo em km/L, Quantidade de litros no tanque, Quilometragem do veículo e o Total gasto.
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
		float abastecimento(float, float); //função para calcular o valor total da compra
		float autonomia(); 
		bool PercorrerDistancia(); //falta fazer
		float Deslocamento();	//falta fazer
};

Veiculo::Veiculo(){   //inicializador sem parametros para não pegar lixo de memória
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
	cout<<"\nObjeto destruído!"<<endl;
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
	
	cout<<"\nInforme o consumo de seu veículo:"<<endl;
	cin>>con_aux;
	
	cout<<"\nInsira a capacidade do tanque de seu veículo:"<<endl;
	cin>>tanq_aux;
	
	cout<<"\nInforme o preço do combustível, por litro, em sua região:"<<endl;
	cin>>preco_aux;
	
	Veiculo monza(preco_aux, tanq_aux, con_aux, 0);

	do{
		cout<<"\nInsira a quantidade de litros que deseja colocar de combustível:"<<endl;
		cin>>litranq;		
	
		cout<<"\nInforme a quantidade de quilometros que deseja percorrer:"<<endl;
		cin>>quilometro;
		
		cout<<"Valor total da compra: "<<monza.abastecimento(litranq, preco_aux)<<" R$"<<endl;
		cout<<"Autonomia do veiculo: "<<monza.autonomia()<<"Km"<<endl;
		
	
		cout<<"\nDigite 1 - Para Continuar | 2 - Para Sair do Programa:"<<endl;
		cin>>x;
	}while(x == 1);
	
	//infelizmente não consegui finalizar, não esva conseguindo realizar a lógica das funções que rotornam valores de forma correta
	
	return 0;
}

