#include <stdio.h>
#include "my_StringProg.h"
#include <string.h>
#define TXT 1024
#define WORD 30


int main(){
    char Word[WORD];
     //printf("word:\n");
    char a;
    int i=0;
    scanf("%c",&a);
    Word[i]=a;
    i++;
    while(a!=' '){
     scanf("%c",&a);
        Word[i]=a;
        i++;
    }
    char w[WORD];
    int k=0;
    for (int j = 0; j < i;j++)
    {
        if(Word[j]!='\n'&&Word[j]!='\t'&&Word[j]!=' '){
            w[k]=Word[j];
            k++;
        }
    }
    
    //printf("%s\n",w);
        char text[TXT];
    texts(text);
    G(text,w);
    
    Atb(text,w);
    isExist(w,text);


    return 0;
}