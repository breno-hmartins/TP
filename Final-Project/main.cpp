
//Declaração de Bibliotecas
#include <iostream>  //para tirar o std
#include <locale>  //para o portuques
#include <stdlib.h> //para limpar a tela 
#include <iomanip> //para o set precision()
#include <windows.h> //para dar um delay
#include <vector> //para declara vetor facilmente
#include <conio.h> //para getch()
#include <fstream> //para manipulação de arquivo 

using namespace std;// para poder usar usar o cout e cin

//Include de Classes
#include "Livro.cpp"
#include "Escolar.cpp"
#include "Literario.cpp"
#include "Estoque.cpp"
#include "Biblioteca.cpp"

//Função
	int  tela_inicial();
	bool tela_login();
	void tela_menu_admin();
	void tela_menu_usuario();

//Objetos
    Biblioteca library;
    Escolar school;
    Literario literary;

int main(){
	
	setlocale(LC_ALL,"portuguese");
	cout<<fixed<<setprecision(2);

	//variavel
	bool sair=false;
	
	while(sair==false){
	
		switch(tela_inicial()){
			case 1:
		
				if(tela_login()==true){
			
					tela_menu_admin();
			
				}
		
				break;
			case 2:
				
				cout<<"teste";
				tela_menu_usuario();
			
				break;
			case 3:
				
				sair=true;
		
				break;
			default:
				
				cout<<endl<<"Opção inexistente!!!"<<endl;
				system("pause");
					
				break;
		}
	
	}
	
		return 0;
		
}

//Tela inicial 
int tela_inicial(){
	
	//variaveis
	bool sair_inicial=false;
	int op;
	
	
	while(sair_inicial==false){
		system("CLS");
		cout<<"          BIBLIOTECA DA UFCG          "<<endl<<endl;
		
		cout<<"           (1)Administrador.          "<<endl;
		cout<<"           (2)Usuario.                "<<endl<<endl;
		
		cout<<"           (3)Finalizar.              "<<endl<<endl;
		
		cout<<"Opção: ";
		cin>>op;
		
		switch(op){
			case 1:
			
				sair_inicial=true;
				return 1;
			
				break;
			case 2:
			
				sair_inicial=true;
				return 2;
			
				break;
			case 3:
			
				cout<<endl<<"Finalizando!!!"<<endl;
				Sleep(1500);
				sair_inicial=true;
				return 3;
			
				break;
			default:
			
				cout<<endl<<"Opção inexistente!!!";
				system("pause");
				
			   	break;
		}
	}
	
	return 3;

}

//Tela de login
bool tela_login(){
	
	//variaveis
	bool sair_login=false;
	string usuario;
	string senha;
	int login;
	
	while(sair_login==false){
		system("CLS");
		cout<<"          BIBLIOTECA DA UFCG        "<<endl;
		cout<<"           (Tela de login)          "<<endl<<endl;
		
		cout<<"Usuário: ";
		cin>>usuario;
		cout<<"Senha: ";
		cin>>senha;
		
		cout<<endl<<"Sair(0)   Logar(1): ";
		cin>>login;
		
		switch(login){
			case 0:
			
				sair_login=true;
				
				break;
			case 1:
				
				if(usuario=="admin" && senha=="admin"){
					
					cout<<endl<<"Logando...";
					Sleep(1500);
				
					sair_login=true;
					return true;
		
				}
				else{
			
					cout<<endl<<"Usuário ou Senha incorreta!!!"<<endl;
					system("pause");
			
				}
				
				break;
			default:
			
				cout<<endl<<"Opção inexistente!!!"<<endl;
				system("pause");
				
				break;	
		}		
	}
	return false;
}

//Tela menu do Admin
void tela_menu_admin(){
	
	//variaveis
	bool sair_admin=false;
	int op_menu_admin;
	int opcao_livro_admin;
    int ID;
    string Titulo;
    string Autor;
    float Preco;
    int Quantidade;
    string Publico;
    string Genero;
    string Tipo;
    string Disciplina;
	
	while(sair_admin==false){
	
		system("CLS");
		cout<<"          BIBLIOTECA DA UFCG          "<<endl;
		cout<<"             (Menu Admin)             "<<endl<<endl;
		
		cout<<"        (1)Cadastrar Novo Livro.      "<<endl;
		cout<<"        (2)Pesquisar Livro.           "<<endl;
		cout<<"        (3)Editar um Livro.           "<<endl;
		cout<<"        (4)Excluir um Livro.          "<<endl;
		cout<<"        (5)Mostrar Estoque.           "<<endl<<endl;
		
		cout<<"        (6)Sair.                      "<<endl<<endl;
		
		cout<<"Opção: ";
		cin>>op_menu_admin;
		
		switch(op_menu_admin){
			
//CADASTRAR LIVRO
			case 1:
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (CADASTRAR)           "<<endl;
				cout<<"                  (Menu Admin)                      "<<endl<<endl;
				
				
				cout<<"                 (1)Livro Escolar.                  "<<endl;
				cout<<"                 (2)Livro Literario.                "<<endl<<endl;
				
				cout<<"Qual opção de livro ? ";
				cin>>opcao_livro_admin;
				cout<<endl;
				
				switch(opcao_livro_admin){
					
					//LIVRO ESCOLAR
					case 1:
						
						cout<<endl<<"Dados Do Livro:"<<endl;
						
	            		cout<<endl<<"Insira o ID do Livro: ";
            			cin>>ID;
            			
            			cout<<endl<<"Insira o Titulo do Livro: ";
            			cin.ignore();
            			getline(cin,Titulo);
            			
            			cout<<endl<<"Insira o Autor do Livro: ";
            			getline(cin,Autor);
            			
            			cout<<endl<<"Insira o Preco do Livro: ";
            			cin>>Preco;
            			
            			cout<<endl<<"Insira o Quantidade do Livro: ";
            			cin>>Quantidade;
            			
            			cout<<endl<<"Insira o Tipo do Livro: ";
            			cin.ignore();
            			getline(cin,Tipo);
            			
            			cout<<endl<<"Insira o Disciplina do Livro: ";
            			getline(cin,Disciplina);

            			school = Escolar(Tipo, Disciplina, ID, Titulo, Autor, Preco, Quantidade);

            			if (library.cadastra_livro(school) == true){
            				
            				cout<<endl<<"Livro ";
							cout<<library.dado_livrosE(ID).get_Titulo();
  	  	  	  	  	  	    cout<<endl<<"Cadastrado Com Sucesso!!"<<endl;
  	  	  	  	  	  	    
  	  	  	  	  	  	    system("pause");
  	  	  	  	  	  	    
						}
            			else{
            				
  	  	  	                cout<<endl<<"Cadastro não realizado"<<endl;
  	  	  	  	  	  	    system("pause");
  	  	  	  	  	  	    
							break;
						}
						
						break;
						
                   //Livro Literario
					case 2:
						
						 cout<<endl<<"Dados Do Livro:"<<endl;
						 
 	 	 	 	 	 	 cout<<endl<<"Insira o ID do Livro: ";
                         cin>>ID;
                         
                         cout<<endl<<"Insira o Titulo do Livro: ";
                         cin.ignore();
                         getline(cin,Titulo);
                         
                         cout<<endl<<"Insira o Autor do Livro: ";
                         getline(cin,Autor);
                         
               	   	     cout<<endl<<"Insira o Preco do Livro: ";
 	  	  	  	  	     cin>>Preco;
 	  	  	  	  	     
                         cout<<endl<<"Insira o Quantidade do Livro: ";
                         cin>>Quantidade;
                         
                         cout<<endl<<"Insira o Genero do Livro: ";
                         cin.ignore();
                         getline(cin,Publico);
                         
                         cout<<endl<<"Insira o Disciplina do Livro: ";
					     getline(cin,Genero);

                         literary = Literario(Publico, Genero, ID, Titulo, Autor, Preco, Quantidade);

 	 	 	 	    if(library.cadastra_livro(literary) == true){
           				
						cout<<endl<<"Livro ";
						cout<<library.dado_livrosL(ID).get_Titulo();
  	  	  	  	  	    cout<<endl<<"Cadastrado Com Sucesso!!"<<endl;
  	  	  	  	  	  	    
  	  	                system("pause");
					   
	 	 	        }
    			    else{
  	  	                    cout<<endl<<"Cadastro não realizado"<<endl;
  	  	  	  	  	  	    system("pause");
						    break;
					}
						
						break;
						
					default:
						
						cout<<endl<<"Opção inexistente!!!"<<endl;
						system("pause");
						
				}
				
				break;
			
//PESQUISA O LIVRO PELO ID
			case 2:
				
        		system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (Pesquisar)           "<<endl;
				cout<<"                  (Menu Admin)                      "<<endl<<endl;
				
				
				
				cout<<"                 (1)Livro Escolar.                  "<<endl;
				cout<<"                 (2)Livro Literario.                "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_admin;
				cout<<endl;
				
				switch(opcao_livro_admin){
					//LIVRO ESCOLAR
					case 1:
						cout<<"Qual o ID do livro: ";
						cin>>ID;
						if (library.dado_livrosE(ID).get_Titulo() == "")
							cout<<endl<<"Nenhum livro foi cadastrado"<<endl;
							
						else{
							cout<<endl<<"Livro: "<<library.dado_livrosE(ID).get_ID();
     						cout<<endl<<"Titulo: "<<library.dado_livrosE(ID).get_Titulo();
  							cout<<endl<<"Autor: "<<library.dado_livrosE(ID).get_Autor();
     						cout<<endl<<"Preco: "<<library.dado_livrosE(ID).get_Preco();
                    		cout<<endl<<"Quantidade: "<<library.dado_livrosE(ID).get_Quantidade();
                    		cout<<endl<<"Tipo: "<<library.dado_livrosE(ID).get_Tipo();
                   			cout<<endl<<"Disciplina: "<<library.dado_livrosE(ID).get_Disciplina()<<endl;
                   		}
                    			
						break;
					
                   //Livro Literario
					case 2:
						cout<<"Qual o ID do livro: ";
						cin>>ID;
	   	   	   				
							cout<<endl<<"Livro: "<<library.dado_livrosL(ID).get_ID();
                    		cout<<endl<<"Titulo: "<<library.dado_livrosL(ID).get_Titulo();
                    		cout<<endl<<"Autor: "<<library.dado_livrosL(ID).get_Autor();
                   			cout<<endl<<"Preco: "<<library.dado_livrosL(ID).get_Preco();
                   			cout<<endl<<"Quantidade: "<<library.dado_livrosL(ID).get_Quantidade();
                   			cout<<endl<<"Tipo: "<<library.dado_livrosL(ID).get_Publico();
                   			cout<<endl<<"Gênero: "<<library.dado_livrosL(ID).get_Genero()<<endl;
                   			
       						
						break;
				}
				
				system("pause");
				break;

//EDITA INFORMÇÕES DO LIVRO
			case 3:
				
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (EDITAR)             "<<endl;
				cout<<"                 (Menu Admin)                       "<<endl<<endl;


				
				cout<<"               (1)Livro Escolar.                    "<<endl;
				cout<<"               (2)Livro Literario.                  "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_admin;
				cout<<endl;
				switch(opcao_livro_admin){
					
					//LIVRO ESCOLAR
		          case 1:
		            if(library.get_estoqueE().size() == 0){
		            	
		                cout<<endl<<"Nenhum livro foi cadastrado";
		                
					}
		                
		            else{
		            	
		                cout<<endl<<"Insira o ID do Livro: ";
		                cin>>ID;
		                
		                cout<<endl<<"Insira o Titulo do Livro: ";
		                cin.ignore();
		                getline(cin,Titulo);
		                
		                cout<<endl<<"Insira o Autor do Livro: ";
		                getline(cin,Autor);
		                
		                cout<<endl<<"Insira o Preco do Livro: ";
		                cin>>Preco;
		                
		                cout<<endl<<"Insira o Quantidade do Livro: ";
		                cin>>Quantidade;
		                
		                cout<<endl<<"Insira o Tipo do Livro: ";
		                cin.ignore();
		                getline(cin,Tipo);
		                
		                cout<<endl<<"Insira o Disciplina do Livro: ";
		                getline(cin,Disciplina);
		
		                school = Escolar(Tipo, Disciplina, ID, Titulo, Autor, Preco, Quantidade);
		
		                if (library.edita_livro(school) == true){
		                	
		                  cout<<endl<<"Edição Realizada, "<<library.dado_livrosE(ID).get_Titulo()<<endl;
						  system("pause");
						  
		                }
		                
		                else{
		                  cout<<endl<<"Este livro não foi encontrado"<<endl;
		                  system("pause");
						}
						
		            }
		            break;
		        
					//LIVRO LITERARIO
		          case 2:
					
		            if(library.get_estoqueL().size() == 0)
		                cout<<endl<<"Nenhum livro foi cadastrado";
		                
		            else{
		            	
		                cout<<endl<<"Insira o ID do Livro: ";
		                cin>>ID;
		                
		                cout<<endl<<"Insira o Titulo do Livro: ";
		                cin.ignore();
		                getline(cin,Titulo);
		                
		                cout<<endl<<"Insira o Autor do Livro: ";
		                getline(cin,Autor);
		                
		                cout<<endl<<"Insira o Preco do Livro: ";
		                cin>>Preco;
		                
		                cout<<endl<<"Insira o Quantidade do Livro: ";
		                cin>>Quantidade;
		                
		                cout<<endl<<"Insira o Tipo do Livro: ";
		                cin.ignore();
		                getline(cin,Publico);
		                
		                cout<<endl<<"Insira o Disciplina do Livro: ";
		                getline(cin,Genero);
		
		                literary = Literario(Publico, Genero, ID, Titulo, Autor, Preco, Quantidade);
		
		                if (library.edita_livro(literary) == true){
		                  cout<<endl<<"Edição Realizada, "<<library.dado_livrosL(ID).get_Titulo();
		                }
		                
		                else{
		                	
		                  cout<<endl<<"Este livro não foi encontrado"<<endl;
						  system("pause");
						
						}
		            }
		            break;
		
		          default:
		            cout<<endl<<"Opção inválida"<<endl;
		            system("pause");
		            break;
		        }
		        system("cls");
		        break;

//EXCLUIR LIVRO			
			case 4:
						
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (EXCLUIR)             "<<endl;
				cout<<"                 (Menu Admin)                       "<<endl<<endl;

				
				
				cout<<"               (1)Livro Escolar.                    "<<endl;
				cout<<"               (2)Livro Literario.                  "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_admin;
				cout<<endl;
				switch(opcao_livro_admin){
					
					//LIVRO ESCOLAR
					case 1:
            				if(library.get_estoqueE().size() == 0){
            					
                				cout<<endl<<"Nenhum livro cadastrado";	
							
							}
							
            				else{
            					
								cout<<endl<<"Qual livro você quer remover? ";
								cin>>ID;
								
                			   if (library.remove_livro(opcao_livro_admin,ID) == true){
                			   	
	  	  	  	                    cout<<endl<<"Livro removido"<<endl;
	  	  	  	                    system("pause");
	  	  	  	                    
							   }
							   
                			   else{
                			   	
	  	  	  	                    cout<<endl<<"Este livro não foi encontrado"<<endl;
	  	  	  	                    system("pause");
	  	  	  	                    
							   }
							}
							
							break;
						
					//LIVRO Literario
					case 2:
            				if(library.get_estoqueL().size() == 0){
            					
                				cout<<endl<<"Nenhum livro cadastrado";
                				
							}
            				else{
								cout<<endl<<"Qual livro você quer remover? ";
								cin>>ID;
								
                			   if (library.remove_livro(opcao_livro_admin,ID) == true){
	  	  	  	                    cout<<endl<<"Livro removido"<<endl;
									system("pause");   
							   }
							   
                			   else{
	  	  	  	                    cout<<endl<<"Este livro não foi encontrado"<<endl;
	  	  	  	                    system("pause");
							   }
							}
							
							break;
							
					default:
						cout<<endl<<"Opção inexistente!!!"<<endl;
						system("pause");
						
						break;
				}
				
				break;
			
//ESTOQUE LIVRO	
			case 5:
				
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (ESTOQUE)             "<<endl;
				cout<<"                 (Menu Admin)                       "<<endl<<endl;


				
				cout<<"               (1)Livro Escolar.                    "<<endl;
				cout<<"               (2)Livro Literario.                  "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_admin;
				cout<<endl;
				switch(opcao_livro_admin){
					
					//LIVRO ESCOLAR
		          case 1:
		          	if (library.get_estoqueE().size() == 0)
		                cout<<endl<<"Estoque de Livros Escolares Vazio"<<endl;
		                
		            else{
		                for(unsigned i = 0; i<library.get_estoqueE().size(); i++){
		                    cout<<endl<<"Livro: "<<library.get_estoqueE()[i].get_ID();
		                    cout<<endl<<"Titulo: "<<library.get_estoqueE()[i].get_Titulo();
		                    cout<<endl<<"Autor: "<<library.get_estoqueE()[i].get_Autor();
		                    cout<<endl<<"Preco: "<<library.get_estoqueE()[i].get_Preco();
		                    cout<<endl<<"Quantidade: "<<library.get_estoqueE()[i].get_Quantidade();
		                    cout<<endl<<"Tipo: "<<library.get_estoqueE()[i].get_Tipo();
		                    cout<<endl<<"Disciplina: "<<library.get_estoqueE()[i].get_Disciplina()<<endl;
		                }
		            }
		            break;
		        
					//LIVRO LITERARIO
		          case 2:
		            if (library.get_estoqueL().size() == 0)
		                cout<<endl<<"Estoque de Livros Literários Vazio"<<endl;
		                
		            else{
		                for(unsigned i = 0; i<library.get_estoqueL().size(); i++){
		                    cout<<endl<<"Livro: "<<library.get_estoqueL()[i].get_ID();
		                    cout<<endl<<"Titulo: "<<library.get_estoqueL()[i].get_Titulo();
		                    cout<<endl<<"Autor: "<<library.get_estoqueL()[i].get_Autor();
		                    cout<<endl<<"Preco: "<<library.get_estoqueL()[i].get_Preco();
		                    cout<<endl<<"Quantidade: "<<library.get_estoqueL()[i].get_Quantidade();
		                    cout<<endl<<"Tipo: "<<library.get_estoqueL()[i].get_Publico();
		                    cout<<endl<<"Disciplina: "<<library.get_estoqueL()[i].get_Genero()<<endl;
		                }
		            }
		            break;
		
		           default:
		            cout<<endl<<"Opção inválida"<<endl;
		            break;
		        }
		        system("pause");
		        system("cls");
		        break;
		        
//SAIR
			case 6:				
				sair_admin=true;
				
				break;
			default:
			
				cout<<endl<<"Opção inexistente!!!"<<endl;
				system("pause");
			
				break;
		}
		
	}
}

//Tela menu do Usuario
void tela_menu_usuario(){
	
	//variaveis
	bool sair_usuario=false;
	int op_menu_usuario,opcao_livro_usuario;
	string Titulo;
    string Nome = "";
	string CPF = "";
	float Preco_total;
	while(sair_usuario==false){
		
		system("CLS");
		cout<<"           BIBLIOTECA DA UFCG           "<<endl;
		cout<<"             (Menu Usuário)             "<<endl<<endl;
		
		cout<<"          (1)Estante de Livros.         "<<endl;
		cout<<"          (2)Pesquisar Livro.           "<<endl;
		cout<<"          (3)Comprar Livro.             "<<endl;
		cout<<"          (4)Mostrar Carrinho.          "<<endl;
		cout<<"          (5)Emitir Comprovante.        "<<endl;

		
		cout<<"          (6)Sair.                      "<<endl<<endl;
		
		cout<<"Opção: ";
		cin>>op_menu_usuario;

		switch(op_menu_usuario){
			
//MOSTRA A ESTANTE DE LIVRO 
			case 1:

        		system("CLS");
				cout<<"            BIBLIOTECA DA UFCG (ESTANTE)              "<<endl;
				cout<<"                  (Menu Usuário)                      "<<endl<<endl;
				
				
				
				cout<<"                 (1)Livro Escolar.                  "<<endl;
				cout<<"                 (2)Livro Literario.                "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_usuario;
				cout<<endl;
				
				switch(opcao_livro_usuario){
					
					//Livro Escolar
					case 1:
						if (library.get_estoqueE().size() == 0){
						
							cout<<endl<<"Estoque de Livros Escolares Vazio"<<endl;
						
						}
							
						else{
							
							for(unsigned i = 0; i<library.get_estoqueE().size(); i++){
								
								cout<<endl<<"Título: "<<library.get_estoqueE()[i].get_Titulo();
								cout<<endl<<"Autor: "<<library.get_estoqueE()[i].get_Autor()<<endl;								
							
							}
							
						}
						break;
					
					//Livro Literário
					case 2:
						if (library.get_estoqueL().size() == 0)
							cout<<endl<<"Estoque de Livros Literários Vazio"<<endl;
						else{
							for(unsigned i = 0; i<library.get_estoqueL().size(); i++){
								cout<<endl<<"Título: "<<library.get_estoqueL()[i].get_Titulo();
								cout<<endl<<"Autor: "<<library.get_estoqueL()[i].get_Autor()<<endl;
							}
						}
						break;
					
					default:
						cout<<endl<<"Opção inválida!"<<endl;
						break;
				}
				system("pause");
				break;
			
//PESQUISAR LIVRO
			case 2:
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (PESQUISAR)           "<<endl;
				cout<<"                  (Menu Usuário)                      "<<endl<<endl;
				
				
				
				cout<<"                 (1)Livro Escolar.                  "<<endl;
				cout<<"                 (2)Livro Literario.                "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_usuario;
				cout<<endl;
				
				switch(opcao_livro_usuario){
				
				//LIVRO ESCOLAR
					case 1:
						
						cout<<"Qual o Titulo do livro: ";
						cin.ignore();
						getline(cin,Titulo);
						
						if(library.dado_livrosE(Titulo).get_Titulo() == "")
							cout<<endl<<"Nenhum livro foi cadastrado"<<endl;
						else{
     						cout<<endl<<"Titulo: "<<library.dado_livrosE(Titulo).get_Titulo();
  							cout<<endl<<"Autor: "<<library.dado_livrosE(Titulo).get_Autor();
     						cout<<endl<<"Preco: "<<library.dado_livrosE(Titulo).get_Preco();
    	  	                cout<<endl<<"Quantidade: "<<library.dado_livrosE(Titulo).get_Quantidade();
    	  	                cout<<endl<<"Tipo: "<<library.dado_livrosE(Titulo).get_Tipo();
			                cout<<endl<<"Disciplina: "<<library.dado_livrosE(Titulo).get_Disciplina()<<endl;
                    	}
                    	
						break;
					
 	 	 	    //Livro Literario
					case 2:
						cout<<"Qual o Titulo do livro: ";
						cin.ignore();
						getline(cin,Titulo);
	   	   	   				
                    		cout<<endl<<"Titulo: "<<library.dado_livrosL(Titulo).get_Titulo();
                    		cout<<endl<<"Autor: "<<library.dado_livrosL(Titulo).get_Autor();
                   			cout<<endl<<"Preco: "<<library.dado_livrosL(Titulo).get_Preco();
                   			cout<<endl<<"Quantidade: "<<library.dado_livrosL(Titulo).get_Quantidade();
                   			cout<<endl<<"Tipo: "<<library.dado_livrosL(Titulo).get_Publico();
                   			cout<<endl<<"Gênero: "<<library.dado_livrosL(Titulo).get_Genero()<<endl;
                   			
                    			
						break;
						
					default:
						cout<<endl<<"Opção inválida!"<<endl;
						break;
				}
				system("pause");
				break;
			
//COMPRAR LIVRO
			case 3:
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (COMPRAR)           "<<endl;
				cout<<"                  (Menu Usuário)                      "<<endl<<endl;
				
				
				
				cout<<"                 (1)Livro Escolar.                  "<<endl;
				cout<<"                 (2)Livro Literario.                "<<endl<<endl;
				
				cout<<"Qual tipo de livro: ";
				cin>>opcao_livro_usuario;
				cout<<endl;
				
				switch(opcao_livro_usuario){
					
					//LIVRO ESCOLAR
					case 1:
						cout<<"Qual o Titulo do livro: ";
						cin.ignore();
						getline(cin,Titulo);
						
						if(library.get_estoqueE().size() == 0)
							cout<<endl<<"Nenhum livro cadastrado"<<endl;
							
						else{
							
							if(library.comprar_livro(opcao_livro_usuario,Titulo) == true)
								cout<<endl<<"Livro "<<Titulo<<" comprado"<<endl;
								
							else
								cout<<endl<<"Este livro não foi encontrado"<<endl;
						
						}
						break;
						
					//LIVRO LITERARIO
					case 2:
						if(library.get_estoqueL().size() == 0)
							cout<<endl<<"Nenhum livro cadastrado"<<endl;
							
						else{
							cout<<endl<<"Qual livro você deseja comprar? ";
							cin.ignore();
							getline(cin,Titulo);
							if (library.comprar_livro(opcao_livro_usuario,Titulo) == true)
								cout<<endl<<"Livro "<<Titulo<<" comprado"<<endl;
								
							else
								cout<<endl<<"Este livro não foi encontrado"<<endl;
						}
						break;
				}
				system("pause");	
				break;
			
//CARRINHO	
			case 4:
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (CARRINHO)            "<<endl;
				cout<<"                  (Menu Usuário)                      "<<endl<<endl;
				
				if (library.get_carrinhoE().size() == 0 && library.get_carrinhoL().size() == 0){

		            cout<<endl<<"Carrinho Vazio"<<endl;
		
		        }
		        else{
		            for(unsigned i = 0; i<library.get_carrinhoE().size(); i++){
		                cout<<endl<<"Titulo: "<<library.get_carrinhoE()[i].get_Titulo();
		                cout<<endl<<"Autor: "<<library.get_carrinhoE()[i].get_Autor();
		                cout<<endl<<"Preco: "<<library.get_carrinhoE()[i].get_Preco();
		                cout<<endl<<"Quantidade: "<<library.get_carrinhoE()[i].get_Quantidade()<<endl;
		            }
		
		            for(unsigned i = 0; i<library.get_carrinhoL().size(); i++){
		                cout<<endl<<"Titulo: "<<library.get_carrinhoL()[i].get_Titulo();
		                cout<<endl<<"Autor: "<<library.get_carrinhoL()[i].get_Autor();
		                cout<<endl<<"Preco: "<<library.get_carrinhoL()[i].get_Preco();
		                cout<<endl<<"Quantidade: "<<library.get_carrinhoL()[i].get_Quantidade()<<endl;
		            }
		        }
		  system("pause");
		  break;
			
//COMPROVANTE DA COMPRA
			case 5:
				Preco_total = 0.0;				
				system("CLS");
				cout<<"           BIBLIOTECA DA UFCG (COMPROVANTE)            "<<endl;
				cout<<"                  (Menu Usuário)                       "<<endl<<endl;
        
				cout<<endl<<"Comprovante"<<endl;
				 
				cout<<endl<<"Insira seu nome: ";
				cin.ignore();
				getline(cin,Nome);
				cout<<endl<<"Qual seu CPF: ";
				getline(cin,CPF);
				 
				cout<<endl<<"NOME: "<<Nome;
				cout<<endl<<"CPF: "<<CPF;
				
				if (library.get_carrinhoE().size() == 0 && library.get_carrinhoL().size() == 0){
					cout<<endl<<"Carrinho Vazio"<<endl;
        }
				else{
					for(unsigned i = 0; i<library.get_carrinhoE().size(); i++){
						
						cout<<endl<<"Titulo: "<<library.get_carrinhoE()[i].get_Titulo();
						cout<<endl<<"Autor: "<<library.get_carrinhoE()[i].get_Autor();
						cout<<endl<<"Preco: "<<library.get_carrinhoE()[i].get_Preco();
						cout<<endl<<"Quantidade: "<<library.get_carrinhoE()[i].get_Quantidade()<<endl;
						
						Preco_total += library.get_carrinhoE()[i].get_Preco();
						
					}
					for(unsigned i = 0; i<library.get_carrinhoL().size(); i++){
						
						cout<<endl<<"Titulo: "<<library.get_carrinhoL()[i].get_Titulo();
						cout<<endl<<"Autor: "<<library.get_carrinhoL()[i].get_Autor();
            			cout<<endl<<"Preco: "<<library.get_carrinhoL()[i].get_Preco();
            			cout<<endl<<"Quantidade: "<<library.get_carrinhoL()[i].get_Quantidade()<<endl;
            			
            			Preco_total += library.get_carrinhoL()[i].get_Preco();
					}
					cout<<endl<<"Preco Total: "<<Preco_total<<endl;
				}
				system("pause");
				break;
      case 6:
				sair_usuario=true;
				break;
			default:
				
				cout<<endl<<"Opção inexistente!!!"<<endl;
				system("pause");
				
				break;
		}
	}
}
