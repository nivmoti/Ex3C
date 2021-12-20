#include <stdio.h>
#include "my_StringProg.h"
#include <string.h>
#define TXT 1024
#define WORD 30


int main(){
    char Word[WORD];
    scanf("%s",Word);
    int i=strlen(Word);
    char w[WORD];
    int k=0;
    for (int j = 0; j < i;j++)
    {
        if(Word[j]!='\n'&&Word[j]!='\t'&&Word[j]!=' '){
            w[k]=Word[j];
            k++;
        }
    }
    char text[TXT];
    texts(text);
    G(text,w);
    Atb(text,w);
    isExist(w,text);
    return 0;
}