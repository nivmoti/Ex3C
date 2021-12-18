#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#include "my_StringProg.h"



void words(char Word[]){
    char a;
    int i=0;
    while (a!=' '&&a!='\t'&&a!='\n'&&i<30)
    {
      scanf("%c",&a);
        Word[i]=a;
        i++;
    }
      
}
void texts(char text[]){
    char a;
    int i=0;
    while (a!='~'&&i<1024)
    {
      scanf("%c",&a);
        text[i]=a;
        i++;
    }
      
}

int G(char te[],char wo[])
{
    int w=0;
    for (int i = 0; i < strlen(wo); i++)
    {
        if ((wo[i]>64)&&(wo[i]<91))
        {
            w=w+wo[i]-64;
        }
        if ((wo[i]>96)&&(wo[i]<123))
        {
            w=w+wo[i]-96;
        }
        
    }
    char ans[TXT]="";
    int temp=0;
    char bdik[TXT];
    int k=0;
    for (int i = 0; (i < strlen(te))||(te[i]!='~'); i++)
    {   
        int l=i;
       while (temp<w&&l<strlen(te))
       {
            if ((te[l]>64)&&(te[i]<91))
        {
            temp=temp+te[l]-64;
            
        }
        if ((te[l]>96)&&(te[l]<123))
        {
            temp=temp+te[l]-96;
        }
         bdik[k]=te[l];
            k++;
            l++;

       } 
       if(temp>=w){
        if (temp==w)
        {
           strcat(ans,bdik);
           ans[strlen(ans)]='~';
           k=0;
        }
        if (temp>w)
        {
            k=0;
        }
        }else{
            break;
       }
       }
       ans[strlen(ans)-1]='\n';
        printf("Gematria Sequences: %s",ans);
    
    return 0;

}

int Done(int is[],int size){
    
            for (int i = 0; i<size; i++)
            {
                if(is[i]==0){
                    return 0;
                }
            }
            return 1;
            
        }
        
    
int Atb(char te[],char wo[])
{
    char op[strlen(wo)];
    char ans[TXT]="";
    char opop[strlen(wo)];
    
    //int k=0;
    //int j=0;
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
    for (int i = 0; i < strlen(te); i++)
    {
        
        if(te[i]==op[0]){
            int l=i;
            int isCorr=1;
            if(l+1==strlen(te)&&strlen(wo)!=1)
                isCorr=0;
            while(isCorr==1&&l+1<strlen(te)){
                l++;
                int j = 0;
                while(j<strlen(op)){ 
                    if(te[l]==' '||te[l]=='\t'||te[l]=='\n'){
                        continue;
                    }
                    if(te[l]!=op[j]){
                        isCorr=0;
                        break;
                    }else{
                        j++;
                    }
                }
                if(j==strlen(op)){
                    char temp[l];
                    int h=0;
                    for (int m = i; m < l; m++)
                    {
                        temp[h]=te[m];
                        h++;
                    }
                    strcat(temp,"~");
                    strcat(ans,temp);
                }
                
            }
            
        }
        if(te[i]==opop[0]){
            int l=i;
            int isCorr=1;
             if(l+1==strlen(te)&&strlen(wo)!=1)
                isCorr=0;
            while(isCorr==1){
                l++;
                int j = 0;
                while(j<strlen(opop)){ 
                    if(te[l]==' '||te[l]=='\t'||te[l]=='\n'){
                        continue;
                    }
                    if(te[l]!=opop[j]){
                        isCorr=0;
                        break;
                    }else{
                        j++;
                    }
                }
                if(j==strlen(opop)){
                   char temp[l];
                    int h=0;
                    for (int m = i; m < l; m++)
                    {
                        temp[h]=te[m];
                        h++;
                    }
                    strcat(temp,"~");
                    strcat(ans,temp);
                }   
            }   
        }

    
       
    }
    ans[strlen(ans)-1]='\n'; 
    printf("Atbash Sequences: %s",ans);
    return 0;
        
    }
    

int isExist(char word[],char text[]){
    int isexist[strlen(word)];
    char an[TXT]="";
    char ans[strlen(text)];
    int k=0;
    for (int i = 0; i < strlen(word); i++)
    {
        isexist[i]=0;
    }
    for (int i = 0; i < strlen(text); i++)
    {
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
        
        if(isStart==1){
        int l=i;
        int booleanIs=1;
        int end=Done(isexist,sizeof(isexist));
        while (end==0&&booleanIs==1&&l<strlen(text))
        {
            booleanIs=0;
             if(text[l]==' '){
            ans[k]=text[l];
            k++; 
            booleanIs=1;
 
        }
        for (int j = 0; j < strlen(word); j++)
        {
            if(text[l]==word[j]&&isexist[j]==0){
                booleanIs=1;
                isexist[j]=1;
                ans[k]=text[l];
                k++;
                break;
            }
        }
        end=Done(isexist,sizeof(isexist));
        l++;
        }
        if(end==1){
            strcat(an,ans);
            strcat(an,"~");   
        }else{ if(l==strlen(text)){
            break;
        }else{
            k=0;
             for (int i = 0; i < strlen(word); i++)
    {
        isexist[i]=0;
    }
        }
        }
        }
    }
    an[strlen(an)-1]='\n';
    printf("Anagram Sequences: %s",an);
    return 0;

}
