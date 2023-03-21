#include "LVP08.h"

MegaSena::MegaSena(int bruto_aux, int d){
	this -> Premio_Bruto = bruto_aux;
	this -> d = d;
	deze = new int [d];
}

MegaSena::~MegaSena(){
	delete []deze;
}

void MegaSena::set_Premiao_Bruto(float bruto_aux){
	Premio_Bruto = bruto_aux;
}

void MegaSena::set_armazen(int apo[]){
	for(int i=0; i < d; i++){
		deze[i] = apo[i];
	}
}

int MegaSena::sort(){
	int aux;
	srand(time(NULL));
    for (int i = 0; i < 6; i++)
    {
        do{
			aux = rand() % 21;				
        }
        while(aux == reul_sort[0] || aux == reul_sort[1] || aux == reul_sort[2] || aux == reul_sort[3] || aux == reul_sort[4] || aux == reul_sort[5]);
        reul_sort[i] = aux;
    };
    return 0;
}

int MegaSena::p_resul(){
	int correct = 0;
	int score = 0;
	
	cout<<"Os números sorteados foram: ";
	
	while(score < 6){
		cout << reul_sort[score]<<" ";
		score++;
	}
	
	for (int i = 0; i < d; i++){
		for(int j=0; j < 6; j++){
			if(deze[i]==reul_sort[j])
				correct++;
		}
	}
	
	cout<<"\nVocê acertou: "<<correct<<endl;
	if(correct == 4)
		cout<<"Parabéns!! Você acertou na quadra, o valor do seu prêmio é de R$"<< Premio_Bruto*0.2<<endl;
	else if(correct == 5)
		cout<<"Parabéns!! Você acertou na quina, o valor do seu prêmio é de R$"<< Premio_Bruto*0.3<<endl;
	else if(correct == 6)
		cout<<"Parabéns!! Você acertou na sena, o valor do seu prêmio é de R$"<< Premio_Bruto*0.5<<endl;
	else
		cout<<"Infelizmente você não acertou a pontuação mínima para ter direito ao prêmio."<<endl;
}

float MegaSena::aposta(){
	float pagar;
	if (d == 6){
		pagar = 4.5;
		return pagar;
	}	
	else if(d==7){
		pagar = 31.50;
		return pagar;
	}
	else if(d==8){
		pagar = 126.00;
		return pagar;
	}
	else if(d==9){
		pagar = 378.00;
		return pagar;
	}
	else if(d==10){
		pagar = 945.00;
		return pagar;
	}
	else if(d==11){
		pagar = 2079.00;
		return pagar;
	}
	else if(d==12){
		pagar = 4158.00;
		return pagar;
	}
	else if(d==13){
		pagar = 7722.00;
		return pagar;
	}
	else if(d==14){
		pagar = 13513.50;
		return pagar;
	}
	else if(d==15){
		pagar = 22522.50;
		return pagar;
	}
}

int MegaSena::comprov(){
	cout<<endl<<"Seus número escolhidos foram os: ";
	for(int i=0; i < d; i++)
		cout<<deze[i]<<" ";
	
	cout<<endl<<"Com o total a pagar de R$"<<aposta()<<endl;
}
