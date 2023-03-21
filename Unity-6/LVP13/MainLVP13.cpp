/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 6: LVP-13

>Descrição do programa: Crie a classe Imóvel, que possui como atributos um endereço (nome e número da rua) e um preço. Esta classe não terá métodos, 
somente o construtor que irá inicializar os valores do seu atributo (endereço e preço) por parâmetros. 
*/

#include <iostream>
#include <locale>
#include <vector>

using namespace std;

#include "imovel.cpp"
#include "novo.cpp"
#include "velho.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	char aux; 
	float preco_aux = 0.0;       //criação das variáveis auxiliares
	string endereco_aux; 
	
	vector <Novo> novo;         //criação do vector tipo classe novo
	vector <Velho> velho;		//criação do vector tipo classe velho
	
	
	
	do{
		cout<<"---- Bem vindo a Imobiliária ----"<<endl
			<<"Informe qual obpção deseja usar:"<<endl
			<<"- 1: Adcionar um novo imovel."<<endl          //menu
			<<"- 2: Adcionar um imovel velho."<<endl
			<<"- 0: Para finalizar o programa."<<endl
			<<"\nInsira aqui sua escolha:";
		cin>>aux;
		
		switch(aux){
			
		case '0':{
			for(int i=0; i < novo.size(); i++){
				novo[i].impressao();
			}
			for(int j = 0; j < velho.size(); j++){      //metodo para imprimir a mensagem final com os resultados ao finalizar o programa
				velho[j].impressao();
			}
			
			system("pause");
			system("cls");
			break;
		}
		case '1':{
			
			float taxa_aux = 0.0;
			
			cout<<"\nInforme o preço do imóvel em reais: ";
			cin>>preco_aux;
			
			cout<<"\nInforme o a taxa adicional do imovel novo: ";
			cin>>taxa_aux;
			
			
			Novo imovel(taxa_aux, endereco_aux, preco_aux);             //atribuindo variaveis a classe objeto
			
			novo.push_back(imovel);          //arquivando os dados no vector
			
			system("pause");
			system("cls");			
			break;
		}
					
		case '2':{
			
			float taxa_aux = 0.0;
			
			cout<<"\nInforme o preço do imóvel em reais: ";
			cin>>preco_aux;
			
			cout<<"\nInforme o a taxa de desconto do imovel velho: ";
			cin>>taxa_aux;
			
			Velho imovel2(taxa_aux, endereco_aux, preco_aux);       //atribuindo variaveis a classe objeto
			
			velho.push_back(imovel2);           //arquivando os dados no vector
			
			system("pause");
			system("cls");	
			break;
		}
		
	}
	}while(aux != '0');
	return 0;              //fim do programa
}

