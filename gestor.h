#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct gestor
{
int codg;
int password;
int contacto;
char username[100];
struct gestor* seguinte;
} Gestor;


int guardarGestor(Gestor* inicio);
Gestor* lerGestor();
int existeGestor(Gestor* inicio, int cod);
Gestor* inserirGestor(Gestor* inicio, int codg,int password,int contacto, char username[]);
Gestor* removerGestor(Gestor* inicio, int cod);
int  alterargestor(Gestor *inicio, int cod, int pass, char novo_username[100], int nova_password);
void listarGestor(Gestor * inicio);
void contactarGestor(Gestor * inicio);
int guardarGestor(Gestor* inicio);
int guardarGestorembinario(Gestor* inicio);
