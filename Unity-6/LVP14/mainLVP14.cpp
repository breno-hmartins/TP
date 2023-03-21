/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 6: LVP-14

>Descrição do programa: O aluno deverá implementar um código em C++ que vise simular uma concessionária que venda caminhões e carros.
*/

#include <iostream>
#include <locale>
# include <vector>
# include <fstream>

using namespace std;

#include "Veiculo.cpp"
#include "Carro.cpp"
#include "Caminhao.cpp"
#include "Concessionaria.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	string senha = "123";
	string pwd;
	int escolha = 0;
	             
	Concessionaria test;
	
	
	cout<<"--------------------------"<<endl
		<<"Concessionária de Veículos"<<endl
		<<"--------------------------"<<endl<<endl;
	
	cout << "Insira a senha de login: ";
	cin >> pwd;

	while (true){
		if (pwd == senha)
			break;
			
		else {
			cout<<endl<<"Senha inválida, tente novamente: ";
			cin>>pwd;
		}
	}
	
	do{
		// menu de funcionário
		system("cls");
		
		cout<<"------------MENU------------"<<endl
			<<"- 1: Cadastrar Veículo."<<endl
			<<"- 2: Carros disponíveis."<<endl
			<<"- 3: Caminhões disponíveis."<<endl      //menu
			<<"- 4: Vender Veículo."<<endl
			<<"- 0: Sair da sessão."<<endl
			<<endl<<"Qual função deseja executar: ";
		cin>>escolha;
		
		switch(escolha){
			case 1:{
				system("cls");
				
				int esc_aux;
				unsigned ano_fab, n_chassi;
				float preco;
				//carro
				string v_type, model;
				 //caminhao
				string cam_type, modelo;
				unsigned n_eixo;
				int cubica_cap;
				float max_carg;
				
				cout<<"Qual o tipo de veículo que gostaria de cadastrar:"<<endl
					<<"- 1: Carro."<<endl
					<<"- 2: Caminhão."<<endl
					<<endl<<"Qual função deseja executar: ";
				cin>>esc_aux;
				
				if(esc_aux != 1 && esc_aux != 2){
					cout<<endl<<"Opção não encontrada ou não existente."<<endl<<"Você será redirecionado para o menu anterior!"<<endl<<endl;					
					
					system("pause");
					break;
				}
				else if(esc_aux == 1){
					system("cls");
					
					cout<<"Insira o Ano de Fabricação do carro: ";
					cin>>ano_fab;
					cout<<endl<<"Qual o número do chassi: ";
					cin>>n_chassi;					
					cout<<endl<<"Informe se o carro a ser cadastrado é Sedan, SUV, Picape, Crossover, Hatch, outros: ";  //cadastra o carro
					cin.ignore();
					getline(cin, v_type);
					cout<<endl<<"Informe o modelo do carro: ";
					getline(cin, model);
					cout<<endl<<"Qual o valor do carro a ser vendido: ";
					cin>>preco;
					
					Carro monza(ano_fab, n_chassi, preco, v_type, model);   //chamando no construtor para salvar
					
					if(test.add_carro(monza)){
						cout<<endl<<"Veiculo cadastrado com sucesso!"<<endl;    //chama metodo de adcionar para fazer o teste se ja existe algum carro com o mesmo numero de chassi
						system("pause");
					}						
					else{
						cout<<"Veiculo não cadastrado, tente novamente!"<<endl<<endl;
						system("pause");
					}
				}
				else if (esc_aux == 2){
					system("cls");
					
					cout<<"Insira o tipo de caminhão: ";
					cin.ignore();
					getline(cin, cam_type);
					
					cout<<endl<<"Insira o modelo: ";
					getline(cin, modelo);
					
					cout<<endl<<"Insira o Ano de Fabricação do Caminhão: ";
					cin>>ano_fab;
					
					cout<<endl<<"Qual o número do chassi: ";                      //cadastro do caminhao
					cin>>n_chassi;
					
					cout<<endl<<"Qual o valor do Caminhão a ser vendido: ";
					cin>>preco;
					
					cout<<endl<<"Qual a quatidade de eixos: ";
					cin>>n_eixo;
					
					cout<<endl<<"Insira a capacidade cúbica :";
					cin>>cubica_cap;
					
					if (n_eixo <= 1 && n_eixo >=7)
						max_carg = 0;
						
					else if(n_eixo == 2)
						max_carg = 5;
					
					else if(n_eixo == 3)          //atribuição da carga máxima em função do numeros de eixos
						max_carg = 11;
					
					else if(n_eixo == 5)
						max_carg = 25;
						
					else if (n_eixo == 6) 
						max_carg = 33;
						
					Caminhao pipa(ano_fab, n_chassi, preco, cam_type, modelo, n_eixo, cubica_cap, max_carg);    //chamando no construtor apra salvar
					
					if(test.add_caminhao(pipa)){
						cout<<endl<<"Veiculo cadastrado com sucesso!"<<endl;  ////chama metodo de adcionar para fazer o teste se ja existe algum caminhao com o mesmo numero de chassi
						system("pause");
					}						
					else{
						cout<<"Veiculo não cadastrado, tente novamente!"<<endl<<endl;
						system("pause");
					}
					
				}
				
				system ("cls");
				break;
			}
			case 2:{
				system ("cls");
				
				test.get_listCar();    //chamada da função que imprime a lista de carros
				system("pause");					
				
				break;
			}
			
			case 3:{
				system ("cls");
				
				test.get_listCaminhao();  //chamada da função que imprime a lista de caminhao
				
				system("pause");
				break;
			}
			
			case 4:{
				system ("cls");
				
				unsigned opc_aux = 0;
				
				cout<<"Dseja vender:"<<endl
					<<"- 1: Carro."<<endl
					<<"- 2: Caminhão."<<endl
					<<endl<<"Digite sua escolha: ";
				cin>>opc_aux;
				
				if(opc_aux != 1 && opc_aux != 2)
					cout<<endl<<"Opção não encontrada ou não existente."<<endl<<"Você será redirecionado para o menu anterior!"<<endl<<endl;
					
				else if(opc_aux == 1){
					system("cls");
					
					unsigned n_chassi = 0;
					
					cout<<"Qual o número de chassir do carro que deseja fazer a venda: ";
					cin>>n_chassi;
					
					if(test.v_carro(n_chassi)){                                      //chamada da função de venda de carro que realiza o teste para achar o veículo atravez d numero de chassi dele
						cout<<endl<<"Venda realizada com sucesso!!!"<<endl<<endl;
					}	
					else{
						cout<<endl<<"Infelimesnte não possivel realizar a venda do veículo, tente novamente!!"<<endl<<endl;
						}
					}
				else if(opc_aux == 2){
					system("cls");
					
					unsigned n_chassi = 0;
					
					cout<<"Qual o número de chassir do caminhão que deseja fazer a venda: ";    //chamada da função de venda de caminhão que realiza o teste para achar o veículo atravez d numero de chassi dele
					cin>>n_chassi;
					
					if(test.v_caminhao(n_chassi)){
						cout<<endl<<"Venda realizada com sucesso!!!"<<endl<<endl;
					}
					else{
						cout<<endl<<"Infelimesnte não possivel realizar a venda do veículo, tente novamente!!"<<endl<<endl;
						}
					}
				
				system("pause");
				break;
				
			}

		}


	}while(escolha != 0);
	
	system("cls");
	cout<<"Programa Finalizado com sucesso!!!"<<endl;      //fim do programa
	
	return 0;
}

