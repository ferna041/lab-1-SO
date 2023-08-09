#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
/**********************************************************/



/*
    Función que calcula el tamaño de una sopa (asume que son cuadradas);
    parametros:
            1- FILE * sopa = puntero a la sopa deseada;
    Retorno:
            Int contador = tamaño de la sopa;
*/
int Tamano_Sopa(FILE * sopa){
    int contador =0;
    char letra;

    while(letra!='\n'){
        letra=fgetc(sopa);

        if(letra!=' ' && letra!='\n'){
            contador=contador+1;
        }
    }
    return contador;
};
/**********************************************************/


/*
    Función que mueve el archivo de una sopa en los directorios de acuerdo a su orientacion y tamaño;
    parametros:
            1- FILE * sopa = puntero a la sopa deseada;
            2- int Tamano_sopa = entero con el tamaño de la sopa (asume que es cuadrada);
            3- char orientacion = cadena de caracteres que indica la orientacion de la palabra buscada en la sopa;
    Retorno:
            La función no retorna nada, tipo void;
*/
void ordenar_sopa(FILE * sopa, int Tamano_Sopa, char orientacion[12]){

}
/**********************************************************/



int main(){

    /* ABRIR EL ARCHIVO*/
    FILE * x = fopen("viktor.txt","r");
    if (x==NULL){
        perror("error en la lectura");
        return 1;
    }

    int largo;
    char palabra_buscada[20];
    char orientacion[12];


    /* OBTENER LA ORIENTACION Y EL TAMAÑO DE LA SOPA*/
    fgets(orientacion,12,x);
    largo=Tamano_Sopa(x);

    /* PEDIR MEMORIA PARA LA MATRIZ DE LA SOPA */
    char** sopa;
    sopa=(char**)malloc(largo*sizeof(char*));
    for(int i=0;i<largo;i++){
        sopa[i]=(char*)malloc(largo*sizeof(char));
    }


    /* VOLVER AL INICIO DE LA SOPA SALTANDOSE LA ORIENTACION */
    fclose(x);
    x = fopen("viktor.txt","r");
    fgets(orientacion,12,x);



    /* RELLENAR LA MATRIZ CON LA SOPA */
    char letra;
    for(int i=0;i<largo;i++){
        for(int j=0;j<largo;j++){

            letra=fgetc(x);
            if(letra!=' ' && letra!='\n'){
                sopa[j][i]=letra;
                }
            else{
                j--;
                }
            }
        }



    /* RECORRER LA MATRIZ */
    for(int i=0;i<largo;i++){
            for(int j=0;j<largo;j++){
                    printf("%c",(sopa[j][i]));
                }
                printf("%c",'\n');
            }

    free(sopa);
    return 0;
}
