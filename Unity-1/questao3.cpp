/*
>Discente: Breno Henrique Martins Silva
>Matrícula: 120210882
>Período: 21.1
>Curso: Engenharia Elétrica
>Disciplina: Técnicas de Programação
>Turma: 1
>Professor: Marcus Salerno
>Unidade 1: LVP-03

>Descrição do programa: Escreva um programa que leia uma lista de pessoas. Cada pessoa possui um nome e 
uma idade (use uma struct para isso).  Use uma função para fazer a leitura desses nomes. Em seguida, 
ordene essa lista em ordem crescente de idade. Use também uma função para fazer isso. No final do 
programa, imprima a lista ordenada.
*/

#include <iostream>
#include <locale>

using namespace std;

struct Lista{          //criação da struct
    int idade;
    string nome;
};

void LerL(Lista[],int);              //protótipo da função de ler listas
void ordena(Lista[], int);           // portótipo da função que ordena a lista

int main(){
    setlocale(LC_ALL,"Portuguese");

    int tam=0;
    int i =0;
    cout<<"Informa a quatidade de pessoas a serem cadastradas:"<<endl;     //pede para que o usuário informa o número de pessoas que serão cadastradas
    cin>>tam;
    Lista aux[tam];
    LerL(aux,tam);
    ordena(aux,tam);
    cout<<"Lista de forma ordenada:"<<endl;
    while (i < tam){          
        cout<<aux[i].nome<<" tem "<<aux[i].idade<<" anos de idade"<<endl;      //ira imprimir na tela a lista de forma crescente
        i++;
    }

    return 0;
}

void LerL(Lista pessoa[], int tamanho){
    int aux=0;
    while (aux < tamanho){
        cout<<"Informe o nome da pessoa:";
        cin>>pessoa[aux].nome;                         //função que irá ler a lista com os nomes e idade salvos
        cout<<"Informe a idade:";
        cin>>pessoa[aux].idade;
        aux++;
    }
}

void ordena(Lista pessoa[], int tam){
    int aux_troc = 0;
    int cont = 0;
    string N = "";                           // esta função irá ordenar a lista com as pessoas de menor idade para a manior

    for (int i = 0; i < tam -1; i++){
        while(cont<tam-1){
            if (pessoa[cont].idade > pessoa[cont+1].idade){
                aux_troc = pessoa[cont+1].idade;
                N = pessoa[cont+1].nome;

                pessoa[cont+1].idade = pessoa[cont].idade;
                pessoa[cont+1].nome = pessoa[cont].nome;

                pessoa[cont].idade = aux_troc;
                pessoa[cont].nome = N;
            }
            cont++;
        }
    }
}