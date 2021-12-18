#include <stdio.h>
#include "my_StringProg.h"
#define TXT 1024
#define WORD 30


int main(){
    char text[TXT];
    char word[WORD];
    words(word);
    texts(text);
    G(text,word);
    Atb(text,word);
    isExist(word,text);

    
}