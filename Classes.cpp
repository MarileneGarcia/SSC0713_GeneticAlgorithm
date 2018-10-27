#include <iostream>
#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <time.h>

using namespace std;


class Candidato{ 
    //Parametros
    public:
    double educacao;
    double educacaoSexual;
    double saudePublica;
    double segurancaPublica;
    double porteArma;
    double estadoLaico;
    double estatutoFamilia;
    double legalizarAborto;
    double reformaTrabalhista;
    double reformaAgraria;
    double legalizarMaconha;
    double intervencaoMilitar;
    double escolaSemPartido;

    //Caracteristicas
        //Carater politico e economico
    double autoritario;
    double libertario;

    double direita;
    double centro;
    double esquerda;

        //Carater social
    double direitaSocial;
    double esquerdaSocial;
};

class EstadosEleitores{ 
    public:
    double classeA;
    double classeB;
    double classeC;
    double classesED;
    double popVotante;
    double religiosidade;
    //Determinantes IDH
    double rendaPerCapta;
    double escolaridade;
    //acho que pode ser um vetor com porcentagem de direita esquerda e talz
    double partidoMaisInf[3];
    //vamos fazer 1- primário, 2- sec e 3 - ter
    int setorMaisImport;
    double iGini;
    double taxaHomi;
    double porcIdosos;


};

int main(){
    Candidato* candidatoTeste = new Candidato;
    srand( (unsigned)time(NULL) );
    
    //---- Inicializando os parametros do candidato ----- (acho que a evolução sera neles)
    candidatoTeste -> educacao = (((double)((rand()%101))/100));
    candidatoTeste -> educacaoSexual = (((double)((rand()%101))/100));
    candidatoTeste -> saudePublica = (((double)((rand()%101))/100));
    candidatoTeste -> segurancaPublica = (((double)((rand()%101))/100));
    candidatoTeste -> porteArma = (((double)((rand()%101))/100));
    candidatoTeste -> estadoLaico = (((double)((rand()%101))/100));
    candidatoTeste -> estatutoFamilia = (((double)((rand()%101))/100));
    candidatoTeste -> legalizarAborto = (((double)((rand()%101))/100));
    candidatoTeste -> reformaTrabalhista = (((double)((rand()%101))/100));
    candidatoTeste -> reformaAgraria = (((double)((rand()%101))/100));
    candidatoTeste -> legalizarMaconha = (((double)((rand()%101))/100));
    candidatoTeste -> intervencaoMilitar = (((double)((rand()%101))/100));
    candidatoTeste -> escolaSemPartido = (((double)((rand()%101))/100));

    //---- Carater politico e economico ----
        
        //---- Decobrir se um candidato é autoritario ou liberal ----
    double criteriosAutoritario = (candidatoTeste -> saudePublica + candidatoTeste -> segurancaPublica + candidatoTeste -> estatutoFamilia +
                                    + candidatoTeste -> reformaTrabalhista + candidatoTeste -> reformaAgraria + candidatoTeste -> intervencaoMilitar +
                                    + candidatoTeste -> escolaSemPartido);
    candidatoTeste -> autoritario = (criteriosAutoritario/7); // 7 é o numero de caracteristicas que o definem, normalizar entre 0 e 1
    printf("%lf \n", candidatoTeste -> autoritario);

    double criteriosLibertario = (candidatoTeste -> porteArma + candidatoTeste -> estadoLaico + candidatoTeste -> legalizarAborto + candidatoTeste -> legalizarMaconha);
    candidatoTeste -> libertario = (criteriosLibertario/4);
    printf("%lf \n", candidatoTeste -> libertario); // 4 é o numero de caracteristicas que definem, normalizar entre 0 e 1

    if(candidatoTeste -> autoritario > candidatoTeste -> libertario)
        printf("O candidato tem um viés político e economico autoritario\n");
    else 
        printf("O candidato tem um viés político e economico libertario\n");

        //---- Descobrir se um candidato é de direita, centro ou esquerda -----
    double criteriosDireita = (candidatoTeste -> estatutoFamilia + candidatoTeste -> reformaTrabalhista + candidatoTeste -> intervencaoMilitar + 
                                + candidatoTeste -> escolaSemPartido); 
    candidatoTeste -> direita = (criteriosDireita/4); // 4 é o numero de caracteristicas que o definem, normalizar entre 0 e 1
    printf("%lf \n", candidatoTeste -> direita); 
    
    double criteriosEsquerda = (candidatoTeste -> educacaoSexual + candidatoTeste -> saudePublica + candidatoTeste -> segurancaPublica + 
                                + candidatoTeste -> estadoLaico + candidatoTeste -> legalizarAborto + candidatoTeste -> reformaAgraria);
    candidatoTeste -> esquerda = (criteriosEsquerda /6);
    printf("%lf \n", candidatoTeste -> esquerda); // 6 é o numero de caracteristicas que o definem, normalizar entre 0 e 1

    if(candidatoTeste -> direita > 0.5 && candidatoTeste -> esquerda > 0.5){
        if(candidatoTeste -> direita > candidatoTeste -> esquerda)
            printf("O candidato tem um viés político e economico de direita\n");
        else
            printf("O candidato tem um viés político e economico de esquerda\n");
    }

    else if(candidatoTeste -> direita > 0.5 || candidatoTeste -> esquerda > 0.5){
        if(candidatoTeste -> direita > 0.5)
            printf("O candidato tem um viés político e economico de direita\n");
        else
            printf("O candidato tem um viés político e economico de esquerda\n");
    }
    else
        printf("O candidato tem um viés político e economico de centro\n");


    //---- Carater Social ----

    double criteriosDireitaSocial = (candidatoTeste -> segurancaPublica + candidatoTeste -> porteArma + candidatoTeste -> estatutoFamilia +
                                    + candidatoTeste -> reformaTrabalhista + candidatoTeste -> intervencaoMilitar + candidatoTeste -> escolaSemPartido);
    candidatoTeste -> direitaSocial = (criteriosDireitaSocial/6); // 6 é o numero de caracteristicas que o definem, normalizar entre 0 e 1
    printf("%lf\n",candidatoTeste -> direitaSocial);

    double criteriosEsquerdaSocial = (candidatoTeste -> educacao + candidatoTeste -> educacaoSexual + candidatoTeste -> saudePublica + candidatoTeste -> estadoLaico +
                                    + candidatoTeste -> legalizarAborto + candidatoTeste -> legalizarMaconha);
    candidatoTeste -> esquerdaSocial = (criteriosEsquerdaSocial/6); // 6 é o numero de caracteristicas que o definem, normalizar entre 0 e 1
    printf("%lf\n",candidatoTeste -> esquerdaSocial);

    if(candidatoTeste -> direitaSocial > candidatoTeste -> esquerdaSocial)
        printf("O candidato tem um viés social de direita\n");
    else 
        printf("O candidato tem um viés social de esquerda\n");



    // Setar os estados, acredito que quando formos setar os dados é bom que pegar os dados de um mesmo site
    
    //---- 1 Distrito Federal ----
    EstadosEleitores* DistritoFederal = new EstadosEleitores;

    DistritoFederal-> classeA = 0.0228;
    DistritoFederal-> classeB = 0.0252;
    DistritoFederal-> classeC = 0.1402;
    DistritoFederal-> classesED = 0.5048;
    DistritoFederal-> popVotante = 0.01395;
    DistritoFederal-> religiosidade = ;
    DistritoFederal-> rendaPerCapta = 2548;
    DistritoFederal-> escolaridade = ;
    DistritoFederal-> partidoMaisInf[] = {};
    DistritoFederal-> setorMaisImport = ;
    DistritoFederal-> iGini = 0.555;
    DistritoFederal-> taxaHomi = 18.2;
    DistritoFederal-> porcIdosos = 0.114;

    //---- 2 Sao Paulo ----
    EstadosEleitores* SaoPaulo = new EstadosEleitores;

    SaoPaulo-> classeA = 0.0054;
    SaoPaulo-> classeB = 0.0191;
    SaoPaulo-> classeC = 0.0805;
    SaoPaulo-> classesED = 0.5814;
    SaoPaulo-> popVotante = 0.22269;
    SaoPaulo-> religiosidade = ;
    SaoPaulo-> rendaPerCapta = 1712;
    SaoPaulo-> escolaridade = ;
    SaoPaulo-> partidoMaisInf[3] = ;
    SaoPaulo-> setorMaisImport = 3;
    SaoPaulo-> iGini = 0.46;
    SaoPaulo-> taxaHomi = 10.7;
    SaoPaulo-> porcIdosos = 0.153;

    //---- 3 Rio de Janeiro ----
    EstadosEleitores* RioDeJaneiro = new EstadosEleitores;

    RioDeJaneiro-> classeA = 0.0072;
    RioDeJaneiro-> classeB = 0.0186;
    RioDeJaneiro-> classeC = 0.0848;
    RioDeJaneiro-> classesED = 0.58;
    RioDeJaneiro-> popVotante = 0.08477;
    RioDeJaneiro-> religiosidade = ;
    RioDeJaneiro-> rendaPerCapta = 1445;
    RioDeJaneiro-> escolaridade = ;
    RioDeJaneiro-> partidoMaisInf[3] = ;
    RioDeJaneiro-> setorMaisImport = ;
    RioDeJaneiro-> iGini = 0.503;
    RioDeJaneiro-> taxaHomi = 40.4;
    RioDeJaneiro-> porcIdosos = 0.175;

    //---- 4 Santa Catarina -----
    EstadosEleitores* SantaCatarina = new EstadosEleitores;

    SantaCatarina-> classeA = 0.0036;
    SantaCatarina-> classeB = 0.0158;
    SantaCatarina-> classeC = 0.0766;
    SantaCatarina-> classesED = 0.6153;
    SantaCatarina-> popVotante = 0.3364;
    SantaCatarina-> religiosidade = ;
    SantaCatarina-> rendaPerCapta = 1597;
    SantaCatarina-> escolaridade = ;
    SantaCatarina-> partidoMaisInf[3] = ;
    SantaCatarina-> setorMaisImport = ;
    SantaCatarina-> iGini = 0.419;
    SantaCatarina-> taxaHomi = 16.5;
    SantaCatarina-> porcIdosos = 0.152;

    // ---- 5 Rio Grande do Sul ----
    EstadosEleitores* RioGrandeDoSul = new EstadosEleitores;

    RioGrandeDoSul-> classeA = 0.005;
    RioGrandeDoSul-> classeB = 0.0151;
    RioGrandeDoSul-> classeC = 0.095;
    RioGrandeDoSul-> classesED = 0.5928;
    RioGrandeDoSul-> popVotante = 0.05866;
    RioGrandeDoSul-> religiosidade = ;
    RioGrandeDoSul-> rendaPerCapta = 1635;
    RioGrandeDoSul-> escolaridade = ;
    RioGrandeDoSul-> partidoMaisInf[3] = ;
    RioGrandeDoSul-> setorMaisImport = ;
    RioGrandeDoSul-> iGini = 0.454;
    RioGrandeDoSul-> taxaHomi = 26.7;
    RioGrandeDoSul-> porcIdosos = 0.178;

    // ---- 6 Parana ----
    EstadosEleitores* Parana = new EstadosEleitores;

    Parana-> classeA = 0.0047;
    Parana-> classeB = 0.0169;
    Parana-> classeC = 0.0895;
    Parana-> classesED = 0.6013;
    Parana-> popVotante = 0.05456;
    Parana-> religiosidade = ;
    Parana-> rendaPerCapta = 1472;
    Parana-> escolaridade = ;
    Parana-> partidoMaisInf[3] = ;
    Parana-> setorMaisImport = ;
    Parana-> iGini = 0.465;
    Parana-> taxaHomi = 22.6;
    Parana-> porcIdosos = 0.146;

    // ---- 7 Mato Grosso ----
    EstadosEleitores* MatoGrosso = new EstadosEleitores;

    MatoGrosso-> classeA = 0.003;
    MatoGrosso-> classeB = 0.0138;
    MatoGrosso-> classeC = 0.0905;
    MatoGrosso-> classesED = 0.6001;
    MatoGrosso-> popVotante = 0.01541;
    MatoGrosso-> religiosidade = ;
    MatoGrosso-> rendaPerCapta = 1291;
    MatoGrosso-> escolaridade = ;
    MatoGrosso-> partidoMaisInf[3] = ;
    MatoGrosso-> setorMaisImport = ;
    MatoGrosso-> iGini = 0.445;
    MatoGrosso-> taxaHomi = 31.5;
    MatoGrosso-> porcIdosos = 0.114;

    // ---- 8 Mato Grosso do Sul ----
    EstadosEleitores* MatoGrossoDoSul = new EstadosEleitores;

    MatoGrossoDoSul-> classeA = 0.0054;
    MatoGrossoDoSul-> classeB = 0.0168;
    MatoGrossoDoSul-> classeC = 0.1064;
    MatoGrossoDoSul-> classesED = 0.6071;
    MatoGrossoDoSul-> popVotante = 0.01257;
    MatoGrossoDoSul-> religiosidade = ;
    MatoGrossoDoSul-> rendaPerCapta = 1291;
    MatoGrossoDoSul-> escolaridade = ;
    MatoGrossoDoSul-> partidoMaisInf[3] = ;
    MatoGrossoDoSul-> setorMaisImport = ;
    MatoGrossoDoSul-> iGini = 0.479;
    MatoGrossoDoSul-> taxaHomi = 20.8;
    MatoGrossoDoSul-> porcIdosos = 0.133;

    // ---- 9 Espirito Santo ----
    EstadosEleitores* EspiritoSanto = new EstadosEleitores;

    EspiritoSanto-> classeA = 0.0021;
    EspiritoSanto-> classeB = 0.0157;
    EspiritoSanto-> classeC = 0.0911;
    EspiritoSanto-> classesED = 0.5813;
    EspiritoSanto-> popVotante = 0.01851;
    EspiritoSanto-> religiosidade = ;
    EspiritoSanto-> rendaPerCapta = 1205;
    EspiritoSanto-> escolaridade = ;
    EspiritoSanto-> partidoMaisInf[3] = ;
    EspiritoSanto-> setorMaisImport = ;
    EspiritoSanto-> iGini = 0.471;
    EspiritoSanto-> taxaHomi = 37.4;
    EspiritoSanto-> porcIdosos = 0.148;

    // ---- 10 Goias ----
    EstadosEleitores* Goias = new EstadosEleitores;

    Goias-> classeA = 0.0025;
    Goias-> classeB = 0.0099;
    Goias-> classeC = 0.087;
    Goias-> classesED = 0.6119;
    Goias-> popVotante = 0.03053;
    Goias-> religiosidade = ;
    Goias-> rendaPerCapta = 1277;
    Goias-> escolaridade = ;
    Goias-> partidoMaisInf[3] = ;
    Goias-> setorMaisImport = ;
    Goias-> iGini = 0.436;
    Goias-> taxaHomi = 39.3;
    Goias-> porcIdosos = 0.124;

    // ---- 11 Minas Gerais ----
    EstadosEleitores* MinasGerais = new EstadosEleitores;

    MinasGerais-> classeA = 0.0039;
    MinasGerais-> classeB = 0.0136;
    MinasGerais-> classeC = 0.0912;
    MinasGerais-> classesED = 0.6032;
    MinasGerais-> popVotante = 0.10617;
    MinasGerais-> religiosidade = ;
    MinasGerais-> rendaPerCapta = 1224;
    MinasGerais-> escolaridade = ;
    MinasGerais-> partidoMaisInf[3] = ;
    MinasGerais-> setorMaisImport = ;
    MinasGerais-> iGini = 0.478;
    MinasGerais-> taxaHomi = 19.6;
    MinasGerais-> porcIdosos = 0.151;

    // ---- 12 Amazonas ----
    EstadosEleitores* Amazonas = new EstadosEleitores;

    Amazonas-> classeA = 0.0012;
    Amazonas-> classeB = 0.0078;
    Amazonas-> classeC = 0.0661;
    Amazonas-> classesED = 0.5377;
    Amazonas-> popVotante = 0.01550;
    Amazonas-> religiosidade = ;
    Amazonas-> rendaPerCapta = 850;
    Amazonas-> escolaridade = ;
    Amazonas-> partidoMaisInf[3] = ;
    Amazonas-> setorMaisImport = ;
    Amazonas-> iGini = 0.476;
    Amazonas-> taxaHomi = 31.3;
    Amazonas-> porcIdosos = 0.088;

    // ---- 13 Rondonia ----
    EstadosEleitores* Rondonia = new EstadosEleitores;

    Rondonia-> classeA = 0.0014;
    Rondonia-> classeB = 0.0088;
    Rondonia-> classeC = 0.092;
    Rondonia-> classesED = 0.5751;
    Rondonia-> popVotante = 0.0775;
    Rondonia-> religiosidade = ;
    Rondonia-> rendaPerCapta = 957;
    Rondonia-> escolaridade = ;
    Rondonia-> partidoMaisInf[3] = ;
    Rondonia-> setorMaisImport = ;
    Rondonia-> iGini = 0.452;
    Rondonia-> taxaHomi = 28.1;
    Rondonia-> porcIdosos = 0.102;

    // ---- 14 Roraima ----
    EstadosEleitores* Roraima = new EstadosEleitores;

    Roraima-> classeA = 0.0029;
    Roraima-> classeB = 0.0128;
    Roraima-> classeC = 0.0978;
    Roraima-> classesED = 0.5686;
    Roraima-> popVotante = 0.00216;
    Roraima-> religiosidade = ;
    Roraima-> rendaPerCapta = 1006;
    Roraima-> escolaridade = ;
    Roraima-> partidoMaisInf[3] = ;
    Roraima-> setorMaisImport = ;
    Roraima-> iGini = 0.5;
    Roraima-> taxaHomi = 44;
    Roraima-> porcIdosos = 0.08;

    // ---- 15 Tocantins ----
    EstadosEleitores* Tocantins = new EstadosEleitores;

    Tocantins-> classeA = 0.0033;
    Tocantins-> classeB = 0.0104;
    Tocantins-> classeC = 0.0754;
    Tocantins-> classesED = 0.5944;
    Tocantins-> popVotante = 0.00704;
    Tocantins-> religiosidade = ;
    Tocantins-> rendaPerCapta = 937;
    Tocantins-> escolaridade = ;
    Tocantins-> partidoMaisInf[3] = ;
    Tocantins-> setorMaisImport = ;
    Tocantins-> iGini = 0.504;
    Tocantins-> taxaHomi = 26.6;
    Tocantins-> porcIdosos = 0.13;

    // ---- 16 Amapa ----
    EstadosEleitores* Amapa = new EstadosEleitores;

    Amapa-> classeA = 0;
    Amapa-> classeB = 0.0076;
    Amapa-> classeC = 0.0881;
    Amapa-> classesED = 0.5396;
    Amapa-> popVotante = 0.00336;
    Amapa-> religiosidade = ;
    Amapa-> rendaPerCapta = 936;
    Amapa-> escolaridade = ;
    Amapa-> partidoMaisInf[3] = ;
    Amapa-> setorMaisImport = ;
    Amapa-> iGini = 0.457;
    Amapa-> taxaHomi = 53.9;
    Amapa-> porcIdosos = 0.08;


    // ---- 17 Sergipe ----
    EstadosEleitores* Sergipe = new EstadosEleitores;

    Sergipe-> classeA = 0.004;
    Sergipe-> classeB = 0.0063;
    Sergipe-> classeC = 0.0507;
    Sergipe-> classesED = 0.638;
    Sergipe-> popVotante = 0.01;
    Sergipe-> religiosidade = ;
    Sergipe-> rendaPerCapta = 836;
    Sergipe-> escolaridade = ;
    Sergipe-> partidoMaisInf[3] = ;
    Sergipe-> setorMaisImport = ;
    Sergipe-> iGini = 0.47;
    Sergipe-> taxaHomi = 55.7;
    Sergipe-> porcIdosos = 0.118;

    // ---- 18 Acre ----
    EstadosEleitores* Acre = new EstadosEleitores;

    Acre-> classeA = 0.003;
    Acre-> classeB = 0.0054;
    Acre-> classeC = 0.0678;
    Acre-> classesED = 0.5576;
    Acre-> popVotante = 0.00360;
    Acre-> religiosidade = ;
    Acre-> rendaPerCapta = 769;
    Acre-> escolaridade = ;
    Acre-> partidoMaisInf[3] = ;
    Acre-> setorMaisImport = ;
    Acre-> iGini = 0.5;
    Acre-> taxaHomi = 63.9;
    Acre-> porcIdosos = 0.088;

    // ---- 19 Pernambuco ----
    EstadosEleitores* Pernambuco = new EstadosEleitores;

    Pernambuco-> classeA = 0.0022;
    Pernambuco-> classeB = 0.0075;
    Pernambuco-> classeC = 0.0495;
    Pernambuco-> classesED = 0.6075;
    Pernambuco-> popVotante = 0.0462;
    Pernambuco-> religiosidade = ;
    Pernambuco-> rendaPerCapta = 852;
    Pernambuco-> escolaridade = ;
    Pernambuco-> partidoMaisInf[3] = ;
    Pernambuco-> setorMaisImport = ;
    Pernambuco-> iGini = 0.492;
    Pernambuco-> taxaHomi = 57.3;
    Pernambuco-> porcIdosos = 0.148;

    // ---- 20 Rio Grande do Norte ----
    EstadosEleitores* RioGrandeDoNorte = new EstadosEleitores;

    RioGrandeDoNorte-> classeA = 0.0012;
    RioGrandeDoNorte-> classeB = 0.0074;
    RioGrandeDoNorte-> classeC = 0.067;
    RioGrandeDoNorte-> classesED = 0.6088;
    RioGrandeDoNorte-> popVotante = 0.01660;
    RioGrandeDoNorte-> religiosidade = ;
    RioGrandeDoNorte-> rendaPerCapta = 845;
    RioGrandeDoNorte-> escolaridade = ;
    RioGrandeDoNorte-> partidoMaisInf[3] = ;
    RioGrandeDoNorte-> setorMaisImport = ;
    RioGrandeDoNorte-> iGini = 0.487;
    RioGrandeDoNorte-> taxaHomi = 68;
    RioGrandeDoNorte-> porcIdosos = 0.126;
    
    // ---- 21 Bahia ----
    EstadosEleitores* Bahia = new EstadosEleitores;

    Bahia-> classeA = 0.0017;
    Bahia-> classeB = 0.0056;
    Bahia-> classeC = 0.0496;
    Bahia-> classesED = 0.6415;
    Bahia-> popVotante = 0.07146;
    Bahia-> religiosidade = ;
    Bahia-> rendaPerCapta = 862;
    Bahia-> escolaridade = ;
    Bahia-> partidoMaisInf[3] = ;
    Bahia-> setorMaisImport = ;
    Bahia-> iGini = 0.481;
    Bahia-> taxaHomi = 45.1;
    Bahia-> porcIdosos = 0.134;

    // ---- 22 Para ----
    EstadosEleitores* Para = new EstadosEleitores;

    Para-> classeA = 0.0011;
    Para-> classeB = 0.0044;
    Para-> classeC = 0.049;
    Para-> classesED = 0.5969;
    Para-> popVotante = 0.03614;
    Para-> religiosidade = ;
    Para-> rendaPerCapta = 715;
    Para-> escolaridade = ;
    Para-> partidoMaisInf[3] = ;
    Para-> setorMaisImport = ;
    Para-> iGini = 0.459;
    Para-> taxaHomi = 53.4;
    Para-> porcIdosos = 0.106;

    // ---- 23 Ceara ----
    EstadosEleitores* Ceara = new EstadosEleitores;

    Ceara-> classeA = 0.0012;
    Ceara-> classeB = 0.047;
    Ceara-> classeC = 0.0403;
    Ceara-> classesED = 0.6271;
    Ceara-> popVotante = 0.04406;
    Ceara-> religiosidade = ;
    Ceara-> rendaPerCapta = 824;
    Ceara-> escolaridade = ;
    Ceara-> partidoMaisInf[3] = ;
    Ceara-> setorMaisImport = ;
    Ceara-> iGini = 0.453;
    Ceara-> taxaHomi = 59.1;
    Ceara-> porcIdosos = 0.149;

    // ---- 24 Paraiba ----
    EstadosEleitores* Paraiba = new EstadosEleitores;

    Paraiba-> classeA = 0.0019;
    Paraiba-> classeB = 0.0089;
    Paraiba-> classeC = 0.0627;
    Paraiba-> classesED = 0.6295;
    Paraiba-> popVotante = 0.02014;
    Paraiba-> religiosidade = ;
    Paraiba-> rendaPerCapta = 928;
    Paraiba-> escolaridade = ;
    Paraiba-> partidoMaisInf[3] = ;
    Paraiba-> setorMaisImport = ;
    Paraiba-> iGini = 0.51;
    Paraiba-> taxaHomi = 31.9;
    Paraiba-> porcIdosos = 0.135;

    // ---- 25 Alagoas ----
    EstadosEleitores* Alagoas = new EstadosEleitores;

    Alagoas-> classeA = 0.0004;
    Alagoas-> classeB = 0.0031;
    Alagoas-> classeC = 0.0444;
    Alagoas-> classesED = 0.6034;
    Alagoas-> popVotante = 0.01367;
    Alagoas-> religiosidade = ;
    Alagoas-> rendaPerCapta = 658;
    Alagoas-> escolaridade = ;
    Alagoas-> partidoMaisInf[3] = ;
    Alagoas-> setorMaisImport = ;
    Alagoas-> iGini = 0.438;
    Alagoas-> taxaHomi = 56.9;
    Alagoas-> porcIdosos = 0.128;

    // ---- 26 Piaui ----
    EstadosEleitores* Piaui = new EstadosEleitores;

    Piaui-> classeA = 0.0025;
    Piaui-> classeB = 0.0031;
    Piaui-> classeC = 0.0468;
    Piaui-> classesED = 0.6446;
    Piaui-> popVotante = 0.0167;
    Piaui-> religiosidade = ;
    Piaui-> rendaPerCapta = 715;
    Piaui-> escolaridade = ;
    Piaui-> partidoMaisInf[3] = ;
    Piaui-> setorMaisImport = ;
    Piaui-> iGini = 0.505;
    Piaui-> taxaHomi = 20.2;
    Piaui-> porcIdosos = 0.121;

    // ---- 27 Maranhao ----
    EstadosEleitores* Maranhao = new EstadosEleitores;

    Maranhao-> classeA = 0.002;
    Maranhao-> classeB = 0.059;
    Maranhao-> classeC = 0.0364;
    Maranhao-> classesED = 0.6083;
    Maranhao-> popVotante = 0.03208;
    Maranhao-> religiosidade = ;
    Maranhao-> rendaPerCapta = 597;
    Maranhao-> escolaridade = ;
    Maranhao-> partidoMaisInf[3] = ;
    Maranhao-> setorMaisImport = ;
    Maranhao-> iGini = 0.506;
    Maranhao-> taxaHomi = 29.4;
    Maranhao-> porcIdosos = 0.113;

    return 0;
}


//Taxa de homicío Brail 30.8