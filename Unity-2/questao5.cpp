/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 2: LVP-05

>Descrição do programa: Crie uma struct chamada CorpoCeleste. A estrutura deve conter um atributo nome 
do tipo string e os atributos raioPlaneta, massa do tipo double. Crie uma classe chamada 
Sistema_Interestelar que deverá conter dois atributos do tipo CorpoCeleste; um atributo para armazenar a 
distância entre os dois Corpos Celestes do tipo double; um atributo para armazenar o nome; e um atributo 
constante do tipo const double para armazenar a constante gravitacional universal (6.67e-11 = 6.67*10-11).
*/

#include <iostream>
#include <locale>
#include <cmath>
#include <iomanip>

using namespace std;

//criação da struct
struct CorpoCeleste{
    string nome;
    double raioPlaneta;
    double massa;
};

//criação do sistema
class Sistema_Interestelar{
				//classes da parte privada
             const double constGravitacional = 6.67e-11;
              string nome;
              CorpoCeleste Corpo1;
              CorpoCeleste Corpo2;
              double distanciaCorposCelestes;
      
	  	//classes da parte pública
    public:

        void setPlanetas(CorpoCeleste, CorpoCeleste);
        void setDistanciaCorposCelestes(double);
        double forcaGravitacional();
        float velocidadeEmOrbita();
        float velocidadeDeEscape();
        float campoGravitacional();

};
//sistema para igualar 
void Sistema_Interestelar::setPlanetas(CorpoCeleste cp1, CorpoCeleste cp2){
    Corpo1 = cp1;
    Corpo2 = cp2;
};
//indicando o d para informar a distancia entre as estrelas no main
void Sistema_Interestelar::setDistanciaCorposCelestes(double d){
    distanciaCorposCelestes = d;
};
//metodo da classe que irá calcular a força gravitaconal
double Sistema_Interestelar::forcaGravitacional(){
    return constGravitacional*(Corpo1.massa*Corpo2.massa)/pow(distanciaCorposCelestes,2);
};
//metodo da classe que irá calcular a velocidade em orbita
float Sistema_Interestelar::velocidadeEmOrbita(){
    double M = 0;
     double v = 0;
    
    if (Corpo1.massa>Corpo2.massa){
        M=Corpo1.massa;
    }
    else if (Corpo2.massa>Corpo1.massa){
        M=Corpo2.massa;
    }
    v= (sqrt((constGravitacional* M) / distanciaCorposCelestes) / 1000);
    return v;
};
//metodo da classe que irá calcular a velocidade de escape
float Sistema_Interestelar::velocidadeDeEscape(){
    double Ma = 0;
    double r = 0;
    double vi = 0;
    if (Corpo1.massa>Corpo2.massa){
        Ma=Corpo1.massa;
        r=Corpo1.raioPlaneta;
    }
    else if (Corpo2.massa>Corpo1.massa){
        Ma=Corpo2.massa;
        r=Corpo2.raioPlaneta;
    }
    vi = (sqrt((2*Ma*constGravitacional)/ r) / 1000);
    
    return vi;
};
//metodo da classe que irá calcular o campo gravitacional
float Sistema_Interestelar::campoGravitacional(){
    double Mb = 0;
    double ra = 0;
    if (Corpo1.massa>Corpo2.massa){
        Mb=Corpo1.massa;
        ra=Corpo1.raioPlaneta;
    }
    else if (Corpo2.massa>Corpo1.massa){
        Mb=Corpo2.massa;
        ra=Corpo2.raioPlaneta;
    }
    
    return constGravitacional*(Mb/pow(ra,2));
};

int main (){
	setlocale(LC_ALL,"Portuguese");
	
	Sistema_Interestelar System;
	//defidindo as variaveis
	CorpoCeleste cp1, cp2;
	double d;
	
	cout<<"----------------------Análises entre Estrelas----------------------"<<endl;
	//primeira parte que irá pedir as informaçãos da primeira estrela
	cout<<"Informe o nome da estrela:"<<endl;
	cin>>cp1.nome;
	cout<<"Informe a massa:"<<endl;
	cin>>cp1.massa;
	cout<<"Informe o raio da estrela:"<<endl;
	cin>>cp1.raioPlaneta;
	//segunda parte que irá pedir as informações da segunda estrala
	cout<<"Informe o nome da estrela:"<<endl;
	cin>>cp2.nome;
	cout<<"Informe a massa:"<<endl;
	cin>>cp2.massa;
	cout<<"Informe o raio da estrela:"<<endl;
	cin>>cp2.raioPlaneta;
	//informando a distancia entre as estrelas
    cout<<"Distancia entre os planetas:"<<endl;
    cin>>d;
    //chamada dos metodos de classes
    System.setPlanetas(cp1,cp2);
    System.setDistanciaCorposCelestes(d);
    //imprime o valor da força gravitacional
    cout<<"A força gravitacional é: "<<scientific<<setprecision(2)<<System.forcaGravitacional()<<" N"<<endl;
    //imprime o campo gravitacional
    cout<<"O campo gravitacional do maior corpo celeste é: "<<scientific<<setprecision(2)<<System.campoGravitacional()<<" m/s²"<<endl;
	//imprime a velocidade de escape
	cout<<"A velocidade de escape do maior corpo é: "<<scientific<<setprecision(2)<<System.velocidadeDeEscape()<<" km/s"<<endl;
	//imprime a velocidade em orbita
	cout<<"A velocidade em orbita do menor corpo em relação ao maior é: "<<scientific<<setprecision(2)<<System.velocidadeEmOrbita()<<" km/s"<<endl;
	
	return 0;
}