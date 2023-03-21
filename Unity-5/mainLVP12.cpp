/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 5: LVP-12

>Descrição do programa: Neste LVP você irá implementar um sistema muito importante para o Hospital de CG: o sistema de controle da sala de espera dos 
pacientes.
*/

#include <iostream>
#include <locale>
#include <vector>
#include <cstdlib>

using namespace std;

//criação da struct

struct Paciente{
	string name;
	unsigned Nregister;
	string reason;
};

#include "LVP12.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Paciente rgtr; //criação do objeto struct na main
	Hospital Hells_Pass; //criação do objeto da class na main
	int aux;  //criação da variavel que irá realizar a escolha no switch case
	
	vector <Paciente> list;        //criação do vector do tipo struct na main
	
	do{
		cout<<"--------------------------"<<endl
			<<"     HOSPITAL DE CG"<<endl
			<<"   - Sala de espera - "<<endl
			<<"--------------------------"<<endl;
		
		cout<<"Digite: "<<endl
			<<"\n1 - Adicionar novo paciente."
			<<"\n2 - Atender paciente."                            //menu
			<<"\n3 - Remover paciente da fila."
			<<"\n4 - Exibir fila de atendimento."
			<<"\n5 - Exibir dados de um paciente."
			<<"\n6 - Exibir lista de pacientes atendidos."
			<< endl << "\n0 - Sair do sistema."<<endl;
			
		cout<<"_______________________"	
			<<"\nQual função deseja: ";
		cin>> aux;
		
		system("cls");
		
		switch (aux){        //criação do switch que ira realuzar a função de receber a escolha do usuário e realizar os procedimentos
			case 1:
				cout<<"--- ADIÇÃO DE PACIENTE NA FILA ---"<<endl
					<<"-- Preencha os dados do paciente --"<<endl;
				
				cout<<"\n- Nome: ";
				cin.ignore();
				getline(cin, rgtr.name);  //registar o nome
				
				cout<<"- Doença: ";
				getline(cin, rgtr.reason);      //registrar qual a doença
				
				cout<<"- Registro: ";
				cin>>rgtr.Nregister;             //número de registro
				
				if (Hells_Pass.AddPatient(rgtr))
					cout<<"\nPaciente cadastrado na fila com sucesso!\n"<<endl;         
				else                                                                  //condição que irá chamar a função e irá fazer o retorno dependendo se for false ou true
					cout<<"\nJá existe um paciente com o mesmo registro!\n"<<endl;
				
				system("pause");
				system("cls");				
				break;
				
			case 2:				
				cout<<"------------------------------------------"<<endl
					<<"---- Atendimento por orgem de chegada ----"<<endl
					<<"------------------------------------------"<<endl;
					
				if(Hells_Pass.AtenderP())                                              //chamada da função em que irá realizar o atendimento ao paciente
					cout<<"\n- sucesso: Paciente atendido com sucesso!\n"<<endl;
				else
					cout<<"\n- fila vazia: Nenhum paciente na fila de espera!\n"<<endl;
				
				system("pause");
				system("cls");
				break;
				
			case 3:
				cout<<"-----------------------------"<<endl
					<<"---- Remoção de Paciente ----"<<endl
					<<"-----------------------------"<<endl;
					
				cout<<"\n- Informe o número de registro do paciente: ";                
				cin>>rgtr.Nregister;                                         //pede o número de registo afim de remover o paciente que o obtem, da lista de espera
				
				if(Hells_Pass.RemvPatient(rgtr.Nregister))
					cout<<"\nPaciente removido da fila com sucesso!\n"<<endl;          //e tambémr ealiza o teste para saber se possui ou não algum paciente na lista de espera
				else
					cout<<"\nERROR!!! Paciente não encontrado ou não foi registrado!!\n"<<endl;
				
				system("pause");
				system("cls");
				break;
				
			case 4:
				cout<<"-----------------------------"<<endl
					<<"---- Fila de Atendimento ----"<<endl
					<<"-----------------------------"<<endl;			
				
				list = Hells_Pass.NameList();        //atribuindo a vector list a classe afim de retornar a fila de atendimento
				
				for(int i = 0; i < list.size(); i++){
					cout<<"\nNome: "<<list[i].name<<endl                  
						<<"Doença: "<<list[i].reason<<endl          //impressão dos dados de todos os pacientes em ordem de chegada
						<<"Registro: "<<list[i].Nregister<<endl
						<<"\n------------------\n";
				}
				
				system("pause");
				system("cls");
				break;
				
			case 5:
				cout<<"---------------------------"<<endl
					<<"---- Dados de Paciente ----"<<endl
					<<"---------------------------"<<endl;
					
				cout<<"Informe o número de registro do Paciente: ";
				cin>>rgtr.Nregister;                                 //armazena o número de registro
								
				if(Hells_Pass.PVlista())                                                          //realiza o teste para saber se a lista não esta vazia
					cout<<"\nERROR!!! Paciente não encontrado ou não foi registrado!!\n"<<endl;
				else
					Hells_Pass.PersonData(rgtr.Nregister);                    //retorna os dados do paciente que coincidir com o número de registro
				
				system("pause");
				system("cls");
				break;
				
			case 6:
				cout<<"--------------------------------"<<endl
					<<"---- Pacientes já Atendidos ----"<<endl
					<<"--------------------------------"<<endl;
				
				list = Hells_Pass.Patendidos();             //atribuindo o vector list a função da classe que ira retornar a lsita de pciente ja atendidos
				
				if(list.empty())                   //realiza o teste para saber se a lista está vazia e retorna uma mensagem 
					cout<<"\n- relatório vazio: Não há pacientes no relatório\n"<<endl;
				else{
					for(int i = 0; i < list.size(); i++){
						cout<<"\nRegistro: "<<list[i].Nregister<<endl          //impressão dos dados de todos os paciente que ja foram atendidos
							<<"Nome: "<<list[i].name<<endl
							<<"Doença: "<<list[i].reason<<endl
							<<"\n------------------\n";
					}											
				}				
				system("pause");
				system("cls");
				break;
		}		
	}while(aux != 0);
	
	cout<<endl<<"-------------------------------------"<<endl
		<<"--VOCÊ FINALIZOU O HOSPITAL MANAGER--"<<endl
		<<"-------------------------------------\n"<<endl;
	return 0;             // fim do programa
}
