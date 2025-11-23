#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <cstring>
using namespace std;
void LEITURA (string *musicas,int *codigos, int *musicaslidas, float *duracoes);
void GERARLISTA (string *musicas, int *codigos, int *musicaslidas, float *duracoes, int *qtd, int *playlistcodigos, string *playlistmusicas, float *playlistduracoes);
void EXIBIRLISTA (int *playlistcodigos, string *playlistmusicas, float *playlistduracoes,int *qtd);
void GRAVARLISTA (int *playlistcodigos, string *playlistmusicas, float *playlistduracoes, int *qtd);
int main()
{
    setlocale(LC_ALL,"portuguese");

    //Declarações
    string *musicas = new string [20];
    int *codigos = new int [20];
    int *musicaslidas = new int(0);
    float *duracoes = new float [20];
    int *qtd = new int (0);
    int *op = new int(-1);




    //Lendo as musicas do arquivo music.txt
    cout << "Lendo músicas do arquivo music.txt..." << endl;
    LEITURA (musicas,codigos,musicaslidas,duracoes);
    cout << "Digite a quantidade de músicas que deseja incluir na sua playlist : (max. 20) : " << endl;
    cin >> *qtd;
    //



    ///**DECLARAÇÕES DA NOVA PLAYSLIST
    int *playlistcodigos = new int [*qtd];
    string *playlistmusicas = new string [*qtd];
    float *playlistduracoes = new float [*qtd];
    bool *acesso = new bool (false);
    ///*
    do  ///**MENU DE OPÇÕES**///
    {
        cout << "Selecione uma opção abaixo : " << endl;
        cout << "0 - Sair " << endl;
        cout << "1 - Gerar lista"  << endl;
        cout << "2- Exibir lista" << endl;
        cout << "3 - Gravar playlist" << endl;
        cin >> *op;


        ///Switch case das opções**//
        switch (*op)
        {
        case 0 :
            cout << "Encerrando o programa..." << endl;
            return 0 ;
            break;
        case 1 :
            GERARLISTA (musicas,codigos,musicaslidas,duracoes,qtd,playlistcodigos,playlistmusicas,playlistduracoes);
            (*acesso) = true;
            break;
        case 2 :
            if (*acesso)
            {
                EXIBIRLISTA (playlistcodigos,playlistmusicas,playlistduracoes,qtd);

            }
            else
            {
                cout << "Erro ! Você precisa gerar a lista antes de acessar as demais opções 0" << endl;
            };
            break;

            break;
        case 3:
            if (*acesso)
            {
                GRAVARLISTA (playlistcodigos, playlistmusicas, playlistduracoes,qtd);

            }
            else
            {
                cout << "Erro ! Você precisa gerar a lista antes de acessar as demais opções 0" << endl;
            }
            break;

        }
    }
    while (*op != 0);

    delete [] musicas;
    delete[] codigos;
    delete musicaslidas;
    delete [] duracoes;
    delete qtd;
    delete op;

    musicas = nullptr;
    codigos = nullptr;
    musicaslidas = nullptr;
    duracoes = nullptr;
    qtd = nullptr;
    op = nullptr;

    return 0;



}
void LEITURA (string *musicas,int *codigos, int *musicaslidas, float *duracoes)
{
    ifstream *ler = new ifstream ();
    (*ler).open("music.txt");

    //Caso não consiga abrir o arquivo :
    if (!(*ler).is_open())
    {
        cout << "Erro ! Não foi possivel abrir o arquivo music txt...." << endl;
        return;
    }

    //Declarações
    string *linha = new string ();
    int *qtd = new int (0);
    size_t *primeirocorte = new size_t ();
    string *codigodamusica = new string ();
    size_t *segundocorte = new size_t ();
    string *nomedamusica = new string();
    string *duracaodamusica = new string ();






    cout << "Músicas lidas : " << endl;
    while (getline(*ler,*linha))
    {
        if((*linha).empty())
        {
            continue;
        }
        //Lógica para extrair o código do arquivo

        *primeirocorte = (*linha).find(';');
        *codigodamusica = (*linha).substr(0,(*primeirocorte));

        //Lógica para extrair o nome da música

        *segundocorte = (*linha).find(';',(*primeirocorte) + 1);
        *nomedamusica = (*linha).substr(*primeirocorte+1, *segundocorte - (*primeirocorte + 1));

        //Lógica para extrair a duração da música

        *duracaodamusica = (*linha).substr (*segundocorte + 1);


        ///**ADICIONANDO NOS VETORES : ///*

        *codigos = atoi((*codigodamusica).c_str());
        *musicas = *nomedamusica;
        *duracoes = atof((*duracaodamusica).c_str());
        cout << *codigos << " " << *musicas << " " ;
        cout << fixed << (setprecision(2)) << *duracoes << endl;
        codigos ++;
        musicas ++;
        duracoes ++;
        (*musicaslidas)++ ;




    }
    codigos -= (*musicaslidas);
    musicas -= (*musicaslidas);
    duracoes -= (*musicaslidas);
    delete codigodamusica;
    delete nomedamusica;
    delete duracaodamusica;
    codigodamusica = nullptr;
    nomedamusica = nullptr;
    duracaodamusica = nullptr;


}
void GERARLISTA (string *musicas, int *codigos, int *musicaslidas, float *duracoes,int *qtd, int *playlistcodigos, string *playlistmusicas, float *playlistduracoes)
{
    int *numeroaleatorio = new int ();
    int *i = new int ();
    int *j = new int ();
    int *numerosjagerados = new int[20];
    bool *repetido = new bool (false);
    int *aux = numerosjagerados;


    for (*i=0; *i < *qtd ; (*i)++)
    {
        do
        {
            numerosjagerados = aux;
            *repetido = false;
            *numeroaleatorio = rand () % (*musicaslidas);
            for (*j=0; *j<*i; (*j)++)
            {
                if (*numeroaleatorio == *numerosjagerados)
                {
                    (*repetido) = true;
                    break;
                }
                numerosjagerados++;
            }


        }
        while (*repetido);
        numerosjagerados = aux +(*i);
        *numerosjagerados = *numeroaleatorio;



        musicas += *numeroaleatorio;
        codigos +=*numeroaleatorio;
        duracoes += *numeroaleatorio;

        *playlistmusicas = *musicas;
        *playlistcodigos = *codigos;
        *playlistduracoes = *duracoes;

        musicas -=*numeroaleatorio;
        codigos -= *numeroaleatorio;
        duracoes -= *numeroaleatorio;

        playlistmusicas ++;
        playlistcodigos ++ ;
        playlistduracoes ++;



    }
    playlistmusicas -= (*i);
    playlistcodigos -= (*i) ;
    playlistduracoes -= (*i);
    numerosjagerados -=(*i);

    delete[] aux;
    delete numeroaleatorio;
    delete i;
    delete j;
    delete repetido;


    aux = nullptr;
    numeroaleatorio = nullptr;
    numerosjagerados = nullptr;
    i = nullptr;
    j = nullptr;
    repetido = nullptr;
    cout << "Números gerados com sucesso ! " << endl;
    system("pause");









}
void EXIBIRLISTA (int *playlistcodigos, string *playlistmusicas, float *playlistduracoes, int *qtd)
{
    int *i = new int (0);
    for (*i = 0 ; *i < *qtd; (*i)++)
    {
        cout << *playlistcodigos << "." << *playlistmusicas << " : " << *playlistduracoes << endl;
        playlistcodigos ++;
        playlistmusicas ++;
        playlistduracoes ++;
    }
    delete i;
    i = nullptr;
    system("pause");
}
void GRAVARLISTA (int *playlistcodigos, string *playlistmusicas, float *playlistduracoes, int *qtd)
{
    ofstream *gerarlista = new ofstream ();
    (*gerarlista).open("playlist.txt");
    int *i = new int (0);
    for (*i=0; (*i) < (*qtd); (*i)++)
    {
        (*gerarlista) << *playlistcodigos << " " << *playlistmusicas << " " << *playlistduracoes << endl;
        playlistcodigos ++ ;
        playlistmusicas ++;
        playlistduracoes ++;

    }
    playlistcodigos -= (*i);
    playlistmusicas -= (*i);
    playlistduracoes -= (*i);
    (*gerarlista).close();
    delete gerarlista;
    gerarlista = nullptr;
    cout << "Lista gravada com sucesso ! " << endl;
    system("pause");
}
