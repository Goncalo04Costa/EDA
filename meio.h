
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct meio
{
int codm;
char tipo[100];
float bateria;
float autonomia;
float preco;
char geocodigo[50];
int estado;
float espaco;
struct meio* seguinte;
} Meio;



void meiodisponivel(Meio *inicio); 
int alterarmeio(Meio* inicio, int cod, char tipo[100], float bateria, float autonomia, float preco, char geocodigo[50], int estado,int espaco);
void procurarMeio(Meio* inicio);
void listarMeiosPorAutonomia(Meio* inicio);
Meio* removerMeio(Meio* inicio, int cod);
void listarMeios(Meio * inicio);
 
Meio* lerMeios();
Meio* inserirMeio(Meio* inicio, int cod, char tipo[], float bateria, float autonomia, float preco, char geocodigo[], int estado,int espaco);
int guardarMeios(Meio* inicio);
int guardarMeiosembinario(Meio* inicio);
