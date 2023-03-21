#include "Concessionaria.h"

Concessionaria::Concessionaria(){
	
	ifstream arquivoCarro; //arquivo de leitura
	arquivoCarro.open("Carros.txt"); //abre arquivo
	
	string v_type, model;
	unsigned ano_fab, n_chassi;
	float preco;
	if(arquivoCarro.is_open()){
		while(arquivoCarro>>ano_fab){       //do jeito que o professor fez estava dando errado então coloquei da forma em que um monitor me aconselhou
			getline(arquivoCarro, v_type);
			
			if (arquivoCarro.eof())
				break;
				
			getline(arquivoCarro, model);
			arquivoCarro>>ano_fab;
			arquivoCarro>>n_chassi;            //chamada das variáveis que o arquivo ira receber 
			arquivoCarro>>preco;
			
			Carro car_aux(ano_fab, n_chassi, preco, v_type, model); //cria objeto com os dados do carro			
			estq_carro.push_back(car_aux); //insere o carro na lista
			arquivoCarro.ignore();
		}
		arquivoCarro.close();
	}
	else{
		cout<<"Nenhum carro disponível ou cadastrado no sistema!!!"<<endl;
	}
	
	ifstream arquivoCaminhao;
	arquivoCaminhao.open("Caminhoes.txt");
	
	string cam_type, modelo;
	unsigned n_eixo;
	int cubica_cap;
	float max_carg;
	if(arquivoCaminhao.is_open()){
		while(arquivoCaminhao>>ano_fab){
			getline(arquivoCaminhao, cam_type);
			
			if (arquivoCaminhao.eof())
				break;
				
			getline(arquivoCaminhao, modelo);
			arquivoCaminhao>>ano_fab;
			arquivoCaminhao>>n_chassi;
			arquivoCaminhao>>preco;
			arquivoCaminhao>>n_eixo;
			arquivoCaminhao>>cubica_cap;
			arquivoCaminhao>>max_carg;
			
			Caminhao cam_aux(ano_fab, n_chassi, preco, cam_type, modelo, n_eixo, cubica_cap, max_carg);
			estq_caminhao.push_back(cam_aux);
			arquivoCaminhao.ignore();			
		}
		arquivoCaminhao.close();
	}
	else{
		cout<<"Nenhum caminhão disponível ou cadastrado no sistema!!!"<<endl;
	}	
}

bool Concessionaria::add_carro(Carro carro_aux){
	for(int i = 0; i < estq_carro.size(); i++){
		if(estq_carro[i].get_n_chassi() == carro_aux.get_n_chassi())    //metodo adiciona carro
			return false;
	}
	estq_carro.push_back(carro_aux);
	return true;
}

bool Concessionaria::v_carro(unsigned n_chassi){
	for(int i = 0; i < estq_carro.size(); i++){
		if(estq_carro[i].get_n_chassi() == n_chassi){
			estq_carro.erase(estq_carro.begin() +i);     //metodo que vende carro
			return true;
		}
	}
	return false;
}

void Concessionaria::get_listCar(){
	for(int i = 0; i< estq_carro.size(); i++){
		cout<<"Ano de frabricação: "<<estq_carro[i].get_ano_fab()<<endl
			<<"Número do chassi: "<<estq_carro[i].get_n_chassi()<<endl
			<<"Preço: "<<estq_carro[i].get_preco()<<endl                    //metodo que imprime a lista de carros cadastrados
			<<"Tipo do veiculo: "<<estq_carro[i].get_Vtype()<<endl
			<<"Modelo: "<<estq_carro[i].get_model()<<endl
			<<"--------------------"<<endl<<endl;
	}
}

void Concessionaria::save_carro(){
	Carro carro_aux;
	
	ofstream arquivoCarro;
	arquivoCarro.open("Carros.txt");
		for(int i = 0; i< estq_carro.size(); i++){
			carro_aux = estq_carro[i];
			
			arquivoCarro<<carro_aux.get_ano_fab()<<endl;
			arquivoCarro<<carro_aux.get_n_chassi()<<endl;    // metodo que irá salvar os carros cadastrados no arquivo, tentei fazer no destrutor mas dava erro
			arquivoCarro<<carro_aux.get_preco()<<endl;
			arquivoCarro<<carro_aux.get_Vtype()<<endl;
			arquivoCarro<<carro_aux.get_model()<<endl;
		}
	arquivoCarro.close();
}

bool Concessionaria::add_caminhao(Caminhao caminhao_aux){
	for (int i = 0; i < estq_caminhao.size(); i++){
		if(estq_caminhao[i].get_n_chassi() == caminhao_aux.get_n_chassi())   //metodo que adciona caminhao
			return false;
	}
	estq_caminhao.push_back(caminhao_aux);
	return true;
}

bool Concessionaria::v_caminhao(unsigned n_chassi){
	for(int i = 0; i< estq_caminhao.size(); i++){
		if(estq_caminhao[i].get_n_chassi() == n_chassi){       //metodo que vende caminhao
			estq_caminhao.erase(estq_caminhao.begin() +i);
			return true;
		}
	}
	return false;
}

void Concessionaria::get_listCaminhao(){
	for(int i = 0; i < estq_caminhao.size(); i++){
		cout<<"Ano de frabricação: "<<estq_caminhao[i].get_ano_fab()<<endl
			<<"Número do chassi: "<<estq_caminhao[i].get_n_chassi()<<endl
			<<"Preço: "<<estq_caminhao[i].get_preco()<<endl
			<<"Tipo do caminhão: "<<estq_caminhao[i].get_cam_type()<<endl     //metodo para imprimir lista de caminhão
			<<"Modelo: "<<estq_caminhao[i].get_modelo()<<endl
			<<"Número de eixos: "<<estq_caminhao[i].get_n_eixo()<<endl
			<<"Capacidade Cúbica: "<<estq_caminhao[i].get_cubica_cap()<<endl
			<<"Carga Máxima: "<<estq_caminhao[i].get_max_carg()<<endl
			<<"---------------------"<<endl<<endl;
	}
}

void Concessionaria::save_caminhao(){
	Caminhao caminhao_aux;
	
	ofstream arquivoCaminhao;
	arquivoCaminhao.open("Caminhoes.txt");
		for(int i = 0; i < estq_caminhao.size(); i++){
			caminhao_aux = estq_caminhao[i];
			
			arquivoCaminhao<<caminhao_aux.get_ano_fab()<<endl;
			arquivoCaminhao<<caminhao_aux.get_n_chassi()<<endl;
			arquivoCaminhao<<caminhao_aux.get_preco()<<endl;
			arquivoCaminhao<<caminhao_aux.get_cam_type()<<endl;    //metodo que ira salvar os dados do caminhao no arquivo
			arquivoCaminhao<<caminhao_aux.get_modelo()<<endl;
			arquivoCaminhao<<caminhao_aux.get_n_eixo()<<endl;
			arquivoCaminhao<<caminhao_aux.get_cubica_cap()<<endl;
			arquivoCaminhao<<caminhao_aux.get_max_carg()<<endl;
		}
	arquivoCaminhao.close();
}

Concessionaria::~Concessionaria(){
	save_carro();
	save_caminhao();                      // destrutor chamando os metodos de salvamento para tirar do vector e salvar no arquivo quando o programa finalizar
}
