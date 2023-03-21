/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 1: LVP-02

>Descrição do programa: Escreva um programa que converte certa temperatura de graus Celsius para 
Fahrenheit e vice-versa, utilizando union. Crie uma union com os atributos Celsius e Fahrenheit (float). 
Pergunte ao usuário qual das conversões ele deseja fazer (se é de Celsius-Fahrenheit ou 
Fahrenheit-Celsius), dependendo de sua resposta, insira o valor para a conversão e imprima o resultado 
convertido com aproximação de duas casas decimais.
*/

#include <iostream>
#include <locale>
#include <iomanip>

using namespace std;

union conversao{
    float celsius;              //definindo o union
    float firenheit;
};

int main(){
    setlocale(LC_ALL, "Portuguese");

    conversao conv;
    int escolha;                      

    cout<<"Conversão para Celsius ou Firenheit?"<<endl<<"Celsius = 1"<<endl
        <<"Firenheit = 2"<<endl<<endl<<"Informe aqui: ";                      // tabela de escolha para conversão
    cin>>escolha;                                                              

    if (escolha==1){
        float r=0;
        cout<<endl<<"Digite um valor para ser convertido:"<<endl;
        cin >> conv.celsius;                                              // converte para Celsius
        r =(conv.celsius * 1.8) + 32;
        cout<<fixed<<setprecision(2)<<"Temperatura em Celsius: "<<r;
    }
    else if (escolha ==2){
        float j=0;
        cout<<endl<<"Digite um valor para ser convertido:"<<endl;
        cin>>conv.firenheit;                                           //converte para Firenheit
        j=(conv.firenheit - 32) / 1.8;
        cout<<endl<<fixed<<setprecision(2)<<"Temperatura em Fahrenheit: "<<j;
    }
    return 0;
}