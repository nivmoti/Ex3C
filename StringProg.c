#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#include "my_StringProg.h"


//gets word
// void words(char Word[]){
//     printf("word:\n");
//     char a;
//     int i=0;
//     scanf("%c",&a);
//     Word[i]=a;
//     while(a!=' '){
//      scanf("%c",&a);
//         Word[i]=a;
//         i++;
//     }
//    // printf("%s\n",Word); 
   
// }
//gets text
void texts(char text[]){
   // printf("text:\n");
    char a;
    int i=0;
    while (a!='~'&&i<1024)
    {
        scanf("%c",&a);
        if (a=='\n')
        {
            continue;
        }
      
        text[i]=a;
        i++;   
    } 
    
      
}
//A:
int G(char* te,char wo[])
{
    int w=0;
    for (int i = 0; i < strlen(wo); i++)
    {
        if ((wo[i]>64)&&(wo[i]<91))
        {
            w=w+(int)wo[i]-64;
        }
        if ((wo[i]>96)&&(wo[i]<123))
        {
            w=w+(int)wo[i]-96;
        }
        
    }
    char ans[TXT]="";
    int temp=0;
    int i=0;
    while (i<strlen(te))
    {
        for (int k = i; k < strlen(te); k++)
        {
            if(!(te[k]>64)&&(te[k]<91) && !(te[k]>96)&&(te[k]<123))
            {
                i++;
            }else{
                break;
            }
        }
        
        int j=i;
        temp=0;
        while (temp<w&& j < strlen(te))
        {
            if ((te[j]>64)&&(te[j]<91))
            {
                temp=temp+(int)te[j]-64;
            }
            if ((te[j]>96)&&(te[j]<123))
            {
                temp=temp+(int)te[j]-96;
            } 
            j++;
        }
        if(w==temp)
        {
            strncat(ans,te+i,j-i);
            strcat(ans,"~");
            temp=0;
               
        }
        if (temp>w)
        {
            temp=0;   
        }
        i++;
    }
    if(strlen(ans)==0){
        ans[0]='\n';
    }else{
        ans[strlen(ans)-1]='\n';
    }
    printf("Gematria Sequences: %s",ans);  
    return 0;
}

//B    
int Atb(char te[],char wo[])
{   
    char op[WORD];
    strcpy(op,wo);
    char ans[TXT]="";
    char opop[WORD];
    strcpy(opop,wo);
    for (int i = 0; i < strlen(wo); i++)
    {
        if ((wo[i]<=64+13)&&(wo[i]>64))
        {
            op[i]=91-(wo[i]-64);
        }
        if (((wo[i]>64+13)&&(wo[i]<91)))
        {
            op[i]=64+(91-wo[i]);
        }
        
        if ((wo[i]<=96+13)&&(wo[i]>96))
        {
            op[i]=123-(wo[i]-96);
        }
        if(wo[i]>96+13&&wo[i]<123){
            op[i]=96+123-wo[i];
        } 
    }
    

    for (int i = 0; i < strlen(op); i++)
    {
        opop[i]=op[strlen(op)-1-i];
    }
    // printf("length of wo:%ld\n",strlen(wo));
    // printf("length of op: %ld\n",strlen(op));
    // printf("length of opop: %ld\n",strlen(opop));
    for (int i = 0; i < strlen(te)-1; i++)
    {    
        if(te[i]==op[0])
        {   
           // printf("THIS IS OP");
            int l=i;
            int isCorr=1;
            if(l+1==strlen(te)&&strlen(wo)!=1)
                isCorr=0;
            l++;
            int j = 1;
            int k=1;
            while(j<strlen(op)&&isCorr==1&&l<strlen(te))
            { 
                //printf("check of op"); 
                if(te[l]==' '||te[l]=='\t'||te[l]=='\n')
                {
                    l++;
                    k++;
                    continue;
                }
                if(te[l]!=op[j]){
                    isCorr=0;
                    break;
                }else{
                        k++;
                        j++;
                        l++;
                    }
            }
            if(j==strlen(op)&&isCorr==1)
            {
                strncat(ans,te+i,k);
                strcat(ans,"~");
            }  
        }
        if(te[i]==opop[0])
        {
            //printf("THIS IS OPOP");
            int l=i;
            int isCorr=1;
            if(l+1==strlen(te)&&strlen(wo)!=1)
                isCorr=0;
            l++;
            int j = 1;
            int k=1;
           // int m=0;
            while(j<strlen(opop)&&isCorr==1&&l<strlen(te))
            {
                // m++;
                // if(m==10){
                //     printf("this is j %d\n",j);
                //     printf("this is l %d\n",l);
                //     printf("this is te length %ld\n",strlen(te));
                //     printf("this is opop len %ld\n",strlen(opop));
                //     printf("this is boolean::%d",isCorr);
                //     printf("this is the char: %c,\n",te[l]);
                //     break;
                // }
               // printf("check of opop"); 
                if(te[l]==' '||te[l]=='\t'||te[l]=='\n')
                {
                    k++;
                    l++;
                    continue;
                }
                if(te[l]!=opop[j])
                {
                    // printf("%c",te[l]);
                    // printf("\n");
                    // printf("%c\n",opop[j]);
                    // printf("%d",j);
                    isCorr=0;
                    break;
                }else{
                    k++;
                    j++;
                    l++;
                }
            }
            if(j==strlen(opop)&&isCorr==1)
            {
                strncat(ans,te+i,k);
                strcat(ans,"~");
            }      
        }
    }
     if(strlen(ans)==0){
        ans[0]='\n';
    }else{
        ans[strlen(ans)-1]='\n';
    }
    printf("Atbash Sequences: %s",ans);
    return 0;   
}
 //helper function for C:   
int Done(int is[],int size){
            for (int i = 0; i<size; i++)
            {
                if(is[i]==0){
                   // printf("is[%d]=0",i);
                    return 0;
                }
            }
            return 1;
    }
//c:
int isExist(char word[],char text[]){
    int isexist[strlen(word)];
    char an[TXT]="";
    char ans[TXT]="";
    int k=0;
    for (int i = 0; i < strlen(text); i++)
    {
        for (int i = 0; i < strlen(word); i++)
        {
            isexist[i]=0;
        }
        int isStart=0;
        for (int j = 0; j < strlen(word); j++)
        {
            if(text[i]==word[j]){
                isStart=1;
                isexist[j]=1;
                ans[0]=text[i];
                k++;
                break;
            }
        } 
        //text[i] is in the word
        if(isStart==1)
        {
            //printf("this is i: %d\n",i);
            int l=i+1;
            int booleanIs=1;
            int end=Done(isexist,sizeof(isexist)/4);
             int wrongleter=1; 
            while (end==0&&booleanIs==1&&l<strlen(text))
            {
                booleanIs=0;
                if(text[l]==' ')
                {
                ans[k]=text[l];
                k++; 
                booleanIs=0;
                }else{
                wrongleter=1;
                for (int j = 0; j < strlen(word); j++)
                {
                    if(text[l]==word[j]){
                        wrongleter=0;
                        if(isexist[j]==0){
                        booleanIs=1;
                        isexist[j]=1;
                        ans[k]=text[l];
                        k++;
                        break;
                    }
                    }
                }
                }
                // printf("this is l: %d\n",l);
                //printf("the boolean is: %d\n",booleanIs);
                end=Done(isexist,sizeof(isexist)/4);
                l++;
        
            }
            //we find all the leters 
            if(end==1)
            {
                //printf("we pass all the leters\n");
                strcat(an,ans);
                strcat(an,"~"); 
            //we didnt find the leters  
            }else{ if(l==strlen(text)) 
                    {
                        //printf("l is end\n");
                        break;
                    }else{
                        //printf("wrong lete\n");
                        if(wrongleter==1){
                            i=l-1;

                        }
                        strcpy(ans,"");
                         k=0;
           
                        }
                 }
        }
    }
    //printf("the length is%ld\n",strlen(an));
    
    if(strlen(an)==0){
        an[0]='\0';
    }else{
        an[strlen(an)-1]='\0';
    }    printf("Anagram Sequences: %s",an);
    return 0;
}
