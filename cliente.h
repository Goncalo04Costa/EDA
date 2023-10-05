#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cliente 
{
int codc; 
char nome[100];
int NIF; 
float saldo; 
char morada[250];
char geocodigoc[250]; 
struct cliente* seguinte; 
} Cliente;


int guardarCliente(Cliente* inicio);
Cliente* lerCliente();
int existeCliente(Cliente* inicio, int cod);
Cliente* inserirCliente(Cliente* inicio, int codc, char nome[], int NIF, float saldo, char morada[], char geocodigoc[]);
void listarClientes(Cliente * inicio);
Cliente* removerCliente(Cliente* inicio, int cod);
int alterarcliente(Cliente *inicio, int codc, int nif, char nova_morada[250]);
Cliente* carregarsaldo(Cliente *inicio, int cod,  float valor);
int guardarClientebinario(Cliente* inicio);

