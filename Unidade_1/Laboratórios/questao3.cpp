/*
>Discente: Breno Henrique Martins Silva
>Matr�cula: 120210882
>Per�odo: 21.1
>Curso: Engenharia El�trica
>Disciplina: T�cnicas de Programa��o
>Turma: 1
>Professor: Marcus Salerno
>Unidade 1: LVP-03

>Descri��o do programa: Escreva um programa que leia uma lista de pessoas. Cada pessoa possui um nome e 
uma idade (use uma struct para isso).  Use uma fun��o para fazer a leitura desses nomes. Em seguida, 
ordene essa lista em ordem crescente de idade. Use tamb�m uma fun��o para fazer isso. No final do 
programa, imprima a lista ordenada.
*/

#include <iostream>
#include <locale>

using namespace std;

struct Lista{          //cria��o da struct
    int idade;
    string nome;
};

void LerL(Lista[],int);              //prot�tipo da fun��o de ler listas
void ordena(Lista[], int);           // port�tipo da fun��o que ordena a lista

int main(){
    setlocale(LC_ALL,"Portuguese");

    int tam=0;
    int i =0;
    cout<<"Informa a quatidade de pessoas a serem cadastradas:"<<endl;     //pede para que o usu�rio informa o n�mero de pessoas que ser�o cadastradas
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
        cin>>pessoa[aux].nome;                         //fun��o que ir� ler a lista com os nomes e idade salvos
        cout<<"Informe a idade:";
        cin>>pessoa[aux].idade;
        aux++;
    }
}

void ordena(Lista pessoa[], int tam){
    int aux_troc = 0;
    int cont = 0;
    string N = "";                           // esta fun��o ir� ordenar a lista com as pessoas de menor idade para a manior

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