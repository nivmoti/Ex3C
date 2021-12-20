#include <stdio.h>
#include <string.h>
#define TXT 1024
#define WORD 30
#include "my_StringProg.h"


//gets word
void words(char Word[]){
    printf("word:\n");
    char a;
    scanf("%c",&a);
    int i=0;
    while ((a!=' ')&&(a!='\t')&&(a!='\n'))
    {   
        Word[i]=a;
        scanf("%c",&a);
        i++;
    }    
   
}
//gets text
void texts(char text[]){
    printf("text:\n");
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
    ans[strlen(ans)-1]='\n';
    printf("Gematria Sequences: %s",ans);  
    return 0;
}

//B    
int Atb(char te[],char wo[])
{
    char op[strlen(wo)];
    char ans[TXT]="";
    char opop[strlen(wo)];
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
    for (int i = 0; i < strlen(te)-1; i++)
    {    
        if(te[i]==op[0])
        {
            int l=i;
            int isCorr=1;
            if(l+1==strlen(te)&&strlen(wo)!=1)
                isCorr=0;
            l++;
            int j = 1;
            int k=1;
            while(j<strlen(op)&&isCorr==1&&l<strlen(te))
            {  
                if(te[l]==' '||te[l]=='\t'||te[l]=='\n')
                {
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
            int l=i;
            int isCorr=1;
            if(l+1==strlen(te)&&strlen(wo)!=1)
                isCorr=0;
            l++;
            int j = 1;
            int k=1;
            while(j<strlen(opop)-2&&isCorr==1&&l<strlen(te))
            {
                if(te[l]==' '||te[l]=='\t'||te[l]=='\n')
                {
                    k++;
                    continue;
                }
                if(te[l]!=opop[j])
                {
                    isCorr=0;
                    break;
                }else{
                    
                    
                    k++;
                    j++;
                    l++;
                }
            }
            if(j==strlen(opop)-2&&isCorr==1)
            {
                strncat(ans,te+i,k);
                strcat(ans,"~");
            }      
        }
    }
    ans[strlen(ans)-1]='\n'; 
    printf("Atbash Sequences: %s",ans);
    return 0;   
}
 //helper function for C:   
int Done(int is[],int size){
            for (int i = 0; i<size; i++)
            {
                if(is[i]==0){
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
            int l=i+1;
            int booleanIs=1;
            int end=Done(isexist,sizeof(isexist)/4);
            while (end==0&&booleanIs==1&&l<strlen(text))
            {
                booleanIs=0;
                if(text[l]==' ')
                {
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
                end=Done(isexist,sizeof(isexist)/4);
                l++;
        
            }
            //we find all the leters 
            if(end==1)
            {
                strcat(an,ans);
                strcat(an,"~"); 
            //we didnt find the leters  
            }else{ if(l==strlen(text)) 
                    {
                        break;
                    }else{
                        i=l-1;
                        strcpy(ans,"");
                         k=0;
           
                        }
                 }
        }
    }
    an[strlen(an)-1]='\n';
    printf("Anagram Sequences: %s",an);
    return 0;
}
