/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 5: LVP-12

>Descri��o do programa: Neste LVP voc� ir� implementar um sistema muito importante para o Hospital de CG: o sistema de controle da sala de espera dos 
pacientes.
*/

#include <iostream>
#include <locale>
#include <vector>
#include <cstdlib>

using namespace std;

//cria��o da struct

struct Paciente{
	string name;
	unsigned Nregister;
	string reason;
};

#include "LVP12.cpp"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	Paciente rgtr; //cria��o do objeto struct na main
	Hospital Hells_Pass; //cria��o do objeto da class na main
	int aux;  //cria��o da variavel que ir� realizar a escolha no switch case
	
	vector <Paciente> list;        //cria��o do vector do tipo struct na main
	
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
			<<"\nQual fun��o deseja: ";
		cin>> aux;
		
		system("cls");
		
		switch (aux){        //cria��o do switch que ira realuzar a fun��o de receber a escolha do usu�rio e realizar os procedimentos
			case 1:
				cout<<"--- ADI��O DE PACIENTE NA FILA ---"<<endl
					<<"-- Preencha os dados do paciente --"<<endl;
				
				cout<<"\n- Nome: ";
				cin.ignore();
				getline(cin, rgtr.name);  //registar o nome
				
				cout<<"- Doen�a: ";
				getline(cin, rgtr.reason);      //registrar qual a doen�a
				
				cout<<"- Registro: ";
				cin>>rgtr.Nregister;             //n�mero de registro
				
				if (Hells_Pass.AddPatient(rgtr))
					cout<<"\nPaciente cadastrado na fila com sucesso!\n"<<endl;         
				else                                                                  //condi��o que ir� chamar a fun��o e ir� fazer o retorno dependendo se for false ou true
					cout<<"\nJ� existe um paciente com o mesmo registro!\n"<<endl;
				
				system("pause");
				system("cls");				
				break;
				
			case 2:				
				cout<<"------------------------------------------"<<endl
					<<"---- Atendimento por orgem de chegada ----"<<endl
					<<"------------------------------------------"<<endl;
					
				if(Hells_Pass.AtenderP())                                              //chamada da fun��o em que ir� realizar o atendimento ao paciente
					cout<<"\n- sucesso: Paciente atendido com sucesso!\n"<<endl;
				else
					cout<<"\n- fila vazia: Nenhum paciente na fila de espera!\n"<<endl;
				
				system("pause");
				system("cls");
				break;
				
			case 3:
				cout<<"-----------------------------"<<endl
					<<"---- Remo��o de Paciente ----"<<endl
					<<"-----------------------------"<<endl;
					
				cout<<"\n- Informe o n�mero de registro do paciente: ";                
				cin>>rgtr.Nregister;                                         //pede o n�mero de registo afim de remover o paciente que o obtem, da lista de espera
				
				if(Hells_Pass.RemvPatient(rgtr.Nregister))
					cout<<"\nPaciente removido da fila com sucesso!\n"<<endl;          //e tamb�mr ealiza o teste para saber se possui ou n�o algum paciente na lista de espera
				else
					cout<<"\nERROR!!! Paciente n�o encontrado ou n�o foi registrado!!\n"<<endl;
				
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
						<<"Doen�a: "<<list[i].reason<<endl          //impress�o dos dados de todos os pacientes em ordem de chegada
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
					
				cout<<"Informe o n�mero de registro do Paciente: ";
				cin>>rgtr.Nregister;                                 //armazena o n�mero de registro
								
				if(Hells_Pass.PVlista())                                                          //realiza o teste para saber se a lista n�o esta vazia
					cout<<"\nERROR!!! Paciente n�o encontrado ou n�o foi registrado!!\n"<<endl;
				else
					Hells_Pass.PersonData(rgtr.Nregister);                    //retorna os dados do paciente que coincidir com o n�mero de registro
				
				system("pause");
				system("cls");
				break;
				
			case 6:
				cout<<"--------------------------------"<<endl
					<<"---- Pacientes j� Atendidos ----"<<endl
					<<"--------------------------------"<<endl;
				
				list = Hells_Pass.Patendidos();             //atribuindo o vector list a fun��o da classe que ira retornar a lsita de pciente ja atendidos
				
				if(list.empty())                   //realiza o teste para saber se a lista est� vazia e retorna uma mensagem 
					cout<<"\n- relat�rio vazio: N�o h� pacientes no relat�rio\n"<<endl;
				else{
					for(int i = 0; i < list.size(); i++){
						cout<<"\nRegistro: "<<list[i].Nregister<<endl          //impress�o dos dados de todos os paciente que ja foram atendidos
							<<"Nome: "<<list[i].name<<endl
							<<"Doen�a: "<<list[i].reason<<endl
							<<"\n------------------\n";
					}											
				}				
				system("pause");
				system("cls");
				break;
		}		
	}while(aux != 0);
	
	cout<<endl<<"-------------------------------------"<<endl
		<<"--VOC� FINALIZOU O HOSPITAL MANAGER--"<<endl
		<<"-------------------------------------\n"<<endl;
	return 0;             // fim do programa
}
