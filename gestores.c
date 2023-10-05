#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "gestor.h"

int guardarGestor(Gestor* inicio)
{FILE* fp;
 fp = fopen("gestores.txt","w");
 if (fp!=NULL)
 {
 Gestor* aux= inicio;
 while (aux != NULL)
 {
  fprintf(fp,"%d;%d;%d;%s\n", aux->codg,aux->password,aux->contacto, aux->username);
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
int guardarGestorembinario(Gestor* inicio)
{
    FILE* fp;
    fp = fopen("gestores.bin", "wb"); 
    if (fp != NULL)
    {
        Gestor* aux = inicio;
        while (aux != NULL)
        {
            fwrite(aux, sizeof(Gestor), 1, fp); 
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
 * @return Gestor* 
 */
Gestor* lerGestor()
{FILE* fp;
 int codg; 
 int password;
 int contacto;
char username[100];
Gestor* aux=NULL;
 fp = fopen("gestores.txt","r");
 if (fp!=NULL)
 {while (!feof(fp))
  { fscanf(fp,"%d;%d;%d;%[^\n]s\n", &codg,&password,&contacto, username);
    aux = inserirGestor(aux, codg, password,contacto, username);
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
int existeGestor(Gestor* inicio, int cod)
{while(inicio!=NULL)
  {if (inicio->codg == cod) return(1);
   inicio = inicio->seguinte;
  }
 return(0);
}
/**
 * @brief 
 * 
 * @param inicio 
 * @param cod_g 
 * @param password 
 * @param contacto 
 * @param username 
 * @return Gestor* 
 */
Gestor* inserirGestor(Gestor* inicio, int codg,int password,int contacto, char username[])
{
    if (!existeGestor(inicio, codg))
    {
        Gestor* novo = malloc(sizeof(struct gestor));
        if (novo != NULL)
        {
            novo->codg = codg;
            novo->password = password;
             novo->contacto = contacto;
            strcpy(novo->username, username);
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
void listarGestor(Gestor * inicio)
{while (inicio != NULL)
 {printf("%d;%d;%d;%s;\n",inicio->codg,inicio->password, 
		             inicio->contacto, inicio->username);
  inicio = inicio->seguinte;
 }
}

void contactarGestor(Gestor * inicio)
{while (inicio != NULL)
 {printf("%d;%s;\n",inicio->contacto, inicio->username);
  inicio = inicio->seguinte;
 }
}
/**
 * @brief 
 * 
 * @param inicio 
 * @param cod 
 * @return Gestor* 
 */
Gestor* removerGestor(Gestor* inicio, int cod) 
{
 Gestor *anterior=inicio, *atual=inicio, *aux;

 if (atual==NULL) return(NULL);
 else if (atual->codg == cod) 
 {aux = atual->seguinte;
  free(atual);
  return(aux);
 }
 else
 {while ((atual!=NULL)&&(atual->codg!=cod)) 
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
 * @param cod 
 * @param pass 
 * @param novousername 
 * @param novapassword 
 * @return int 
 */
int  alterargestor(Gestor *inicio, int cod, int pass, char novousername[100], int novapassword) 
{
    Gestor *atual = inicio;
    while (atual != NULL) {
        if (atual->codg == cod && atual->password == pass) 
        {
           
            strcpy(atual->username, novousername);
            atual->password = novapassword;
            
            printf("As informações do gestor foram atualizadas com sucesso!\n");
            return 1;
        }
        atual = atual->seguinte;
    }
       return 0;
}

