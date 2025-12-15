#include <iostream>
#include <iomanip>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct OPCOES
{
    string *opcao  = new string ();
    int *vetor1 = new int [20];
    int *vetor2 = new int [20];
    int *num = new int();

};
void LENDOARQUIVO (ifstream *ler,OPCOES *p);
void REMOVER (int *numero, OPCOES *p,int *tamvet, int *vet);
int main()
{
    setlocale (LC_ALL, "portuguese");
    cout << "Abrindo arquivo texto Entrada.txt..." << endl;


    ///**lendo o arquivo
    ifstream *ler = new ifstream ("Entrada.txt");
    //criando *p para struct
    OPCOES *p = new OPCOES;

    LENDOARQUIVO (ler,p);
    (*ler).close();
    ///

}
void LENDOARQUIVO (ifstream *ler,OPCOES *p)
{
    string *linha = new string();
    string *vetor = new string ();
    int *numero = new int();
    int *tamvet1 = new int ();
    int *tamvet2 = new int ();
    while (getline(*ler,*linha))
    {
        //Subtraindo a opção
        size_t *pos1 = new size_t;
        *pos1 = linha ->find(" ", 0);
        if (*pos1 != string::npos)
        {
            *p->opcao = (*linha).substr(0,*pos1);


            //Subtraindo o vetor
            size_t *pos2 = new size_t;
            *pos2 = linha->find(" ",*pos1 + 1);
            if (*pos2 != string::npos)
            {
                *vetor = (*linha).substr(*pos1+1,*pos2 - *pos1 - 1);
            }


            ///Opção adicionar numero no vetor
            if (*p->opcao == "adiciona" )
            {
                //subtraindo o numero------------//
                string *pos3 = new string();
                *pos3 = (*linha).substr(*pos2+1);
                *numero = atoi (pos3->c_str());
                //------------------------------//

                if (*vetor == "V1")
                {
                    *(p->vetor1 + *tamvet1)= *numero;
                    (*tamvet1)++;
                    cout << "O número " << *numero << " foi adicionado no vetor 1 " << endl;
                }
                else if (*vetor == "V2")
                {
                    *(p->vetor2 + *tamvet2)= *numero;
                    (*tamvet2)++;
                    cout << "O número " << *numero << " foi adicionado no vetor 2 " << endl;
                }
                delete pos3;

            }

            ///Opção remover elemento do vetor
            else if(*p->opcao == "remove")
            {
                //subtraindo o numero------//
                string *pos3 = new string();
                *pos3 = (*linha).substr(*pos2+1);
                *numero = atoi (pos3->c_str());
                //---------------------------//

                if (*vetor == "V1")
                {
                    REMOVER(numero,p,tamvet1,p->vetor1);

                }
                else if (*vetor == "V2")
                {
                    REMOVER (numero,p,tamvet2,p->vetor2);
                }
                delete pos3;
            }

            ///Opção mostra
            else if (*p->opcao == "Mostra")
            {
                if (*vetor == "V1")
                {
                    int *i = new int ();
                    cout << "Mostrando elementos do vetor 1 : " << endl;
                    for (*i=0; *i<*tamvet1; (*i)++)
                    {
                        cout << *(p->vetor1 + *i) << ";";

                    }
                    cout << endl;
                    delete i;
                }
                else if (*vetor == "V2")
                {
                    int *i = new int ();
                    cout << "Mostrando elementos do vetor 2 : " << endl;
                    for (*i=0; *i<*tamvet2; (*i)++)
                    {
                        cout << *(p->vetor2 + *i) << ";";

                    }
                    cout << endl;
                    delete i;
                }
            }

            ///Opção QTD
            else if (*p->opcao == "Qtd")
            {
                if (*vetor == "V1")
                {
                    cout << "Quantidade de elementos do Vetor 1 " << *tamvet1 << endl;

                }
                else if (*vetor == "V2")
                {
                    cout << "Quantidade de elementos do Vetor 2 : " << *tamvet2 << endl;
                }
            }

delete pos2;
        }
delete pos1;

    }

        delete linha;
        delete vetor;
        delete numero;
        delete tamvet1;
        delete tamvet2;
}
void REMOVER (int *numero, OPCOES *p,int *tamvet, int *vet)
{
    int *i = new int ();
    bool *achado = new bool (false);
    int *j = new int ();
    for (*i=0; *i<*tamvet; (*i)++)
    {
        if (*numero == *(vet+*i))
        {
            *achado = true;
            for (*j = *i; *j < *tamvet - 1; (*j)++)
            {

                *(vet + *j) = *(vet + *j + 1);
            }


            (*tamvet)--;
            break;
        }

    }
    if (!(*achado))
    {
        cout << "Número " << *numero << " não consta no vetor " << endl;
    }
    else if (*achado)
    {
        cout << "Número " << *numero << " removido com sucesso " << endl;

    }
    delete i;
    delete j;
    delete achado;

}
