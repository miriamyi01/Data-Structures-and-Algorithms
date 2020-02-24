//Reyes Mendoza Miriam Guadalupe
//Grupo 17 - IC (UNAM)
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

void conversion();
int prioridad(char op);
int pop(), vacia();
int op, tope, pila[50];
char original[50], polaca[50];

int main(){
    int o=162;
    tope=-1;
    printf("\nEscribe la expresi%cn: ",o);
    scanf("%s", original);
    conversion();
    printf("\nExpresi%cn polaca: %s\n",o,polaca);
    return 0;
}

void conversion(){
    int cont, arr=0;
    char siguiente;
    char op;
    for(cont=0; cont<strlen(original); cont++){
        op=original[cont];
        switch(op){
            case '(':
                push(op);
            break;
            case ')':
                while((siguiente= pop())!='('){
                    polaca[arr++]=siguiente;
                }
            break;
            case '+':
            case '-':
            case '*':
            case '/':
                while(prioridad(pila[tope])>=prioridad(op))
                    polaca[arr++]=pop();
                    push(op);
            break;
            default:
                polaca[arr++]=op;
        }
    }
    while(!vacia()){
        polaca[arr++]=pop();
    }
    polaca[arr] ='\0';
}

int prioridad(char op){
    switch(op){
        case '(':
            return 0;
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void push(int op){
    tope=tope + 1;
    pila[tope] = op;
}

int pop(){
    return(pila[tope--]);
}

int vacia(){
    if(tope!=-1){
        return 0;
    }
}
