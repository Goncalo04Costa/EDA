#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "cliente.h"

/**
 * @brief 
 * 
 * @param inicio 
 * @return int 
 */
int guardarCliente(Cliente* inicio)
{FILE* fp;
 fp = fopen("clientes.txt","w");
 if (fp!=NULL)
 {
 Cliente* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%s;%d;%f;%s;%s\n", aux->codc,aux->nome, aux->NIF, 
	                      aux->saldo, aux->morada, aux->geocodigoc);
  aux = aux->seguinte;
 }
 fclose(fp);
 return(1);
 }
 else return(0);
}






/**
 * @brief 
 * 
 * @param inicio 
 * @return int 
 */
int guardarClientebinario(Cliente* inicio)
{
    FILE* fp;
    fp = fopen("clientes.bin", "wb"); 
    if (fp != NULL)
    {
        Cliente* aux = inicio;
        while (aux != NULL)
        {
            fwrite(aux, sizeof(Cliente), 1, fp); 
            aux = aux->seguinte;
        }
        fclose(fp);
        return (1);
    }
    else 
        return (0);
}





/**
 * @brief 
 * 
 * @return Cliente* 
 */
Cliente* lerCliente()
{FILE* fp;
int codc; 
char nome[100];
int NIF; 
float saldo; 
char morada[250];
char geocodigoc[250]; 
 Cliente* aux= NULL;
 fp = fopen("clientes.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%[^\n]s;%d;%f;%[^\n]s;%[^\n]s\n", &codc, nome, &NIF, &saldo, morada, geocodigoc);
    aux = inserirCliente(aux, codc, nome, NIF, saldo, morada, geocodigoc);
  }
 fclose(fp);
 }
 return(aux);
}




/**
 * @brief 
 * 
 * @param inicio 
 * @param cod 
 * @return int 
 */
int existeCliente(Cliente* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codc == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}
/**
 * @brief 
 * 
 * @param inicio 
 * @param codc 
 * @param nome 
 * @param NIF 
 * @param saldo 
 * @param morada 
 * @return Cliente* 
 */
Cliente* inserirCliente(Cliente* inicio, int codc, char nome[], int NIF, float saldo, char morada[], char geocodigoc[])
{
    if (!existeCliente(inicio, codc))
    {
        Cliente* novo = malloc(sizeof(struct cliente));
        if (novo != NULL)
        {
            novo->codc = codc;
            strcpy(novo->nome, nome);
            novo->NIF = NIF;
            novo->saldo = saldo;
            strcpy(novo->morada, morada);
             strcpy(novo->geocodigoc, geocodigoc);
            novo->seguinte = inicio;
            inicio = novo; 
        }
    }
    return inicio; 
}
/**
 * @brief 
 * 
 * @param inicio 
 */
void listarClientes(Cliente * inicio)
{while (inicio != NULL)
 {printf("%d;%s;%d;%.2f;%s;%s\n\n",inicio->codc,inicio->nome, 
		             inicio->NIF, inicio->saldo, inicio->morada,inicio->geocodigoc);
  inicio = inicio->seguinte;
 }
}


/**
 * @brief 
 * 
 * @param inicio 
 * @param cod 
 * @return Cliente* 
 */
Cliente* removerCliente(Cliente* inicio, int cod) 
{
 Cliente *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->codc == cod)
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codc!=cod)) 
  {anterior = atual;
   atual = atual->seguinte;
  }
  if (atual==NULL) return(inicio);
  else
  {anterior->seguinte = atual->seguinte;
   free(atual);
   return(inicio);
  }
 }
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param cod_c 
 * @param nif 
 * @param nova_morada 
 * @return int 
 */
int alterarcliente(Cliente *inicio, int codc, int nif, char nova_morada[250]) 
{
    Cliente * atual = inicio;
    while (atual != NULL) 
    {
        if (atual->codc == codc && atual->NIF == nif) {
            
            strcpy(atual->morada, nova_morada);
            
            return 1;
        }
        atual = atual->seguinte;
    }
    
    return 0;
}

/**
 * @brief 
 * 
 * @param inicio 
 * @param cod 
 * @param valor 
 * @return Cliente* 
 */
Cliente* carregarsaldo(Cliente *inicio, int cod, float valor) 
{
    Cliente *cliente = inicio;
    while (cliente != NULL) 
    {
        if (cliente->codc == cod ) 
        {
            cliente->saldo += valor;
            printf("Saldo atualizado com sucesso!\n Novo saldo: %.2f\n", cliente->saldo);
            return cliente;
        }
        cliente = cliente->seguinte;
    }
    printf("Cliente não encontrado.\n");
    return NULL;
}

