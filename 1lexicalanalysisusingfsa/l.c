#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int MAXLINE=10;
int main()
{
    char ch,word[30];
    char buffer[MAXLINE];
    char symbol[30][30],keyw[20][20]={"int","print","printf","float","main","char","long","double","if","else","for","while","void","do","switch","case","break"};
    int state=0,i,p=0,id,flag=0,k=0,m,wordlen,z;
   
    FILE *f,*fp,*fptr;
    f=fopen("c.c","r");
    
    while(1)
    {
        switch(state)
        {
            case 0:
                ch=fgetc(f);
                if(ch=='<')
                {
                    ch=fgetc(f);
                    if (ch=='=')
                        printf("<= - LE\n");
                    else if(ch=='>')
                        printf("<> - NE\n");
                    else 
                        {
                            printf("< - LT\n");
                            fseek(f,-1,SEEK_CUR);
                            state=0;
                        }
                }
                else if(ch=='>')
                {
                    ch=fgetc(f);
                    if (ch=='=')
                        printf(">= - GE\n");
                    else 
                        printf("> - GT\n");
                }
                else if(ch=='=')
                {
                    ch=fgetc(f);
                    if (ch=='=')
                        printf("== - EQ\n");          
                    else
                    {
                        printf("= - ASSIGN\n");
                        fseek(f,-1,SEEK_CUR);
                        state=0;
                    }                       
                }
                else if(isalpha(ch))
                    {   p=0;
                        word[p]=ch;
                        p++;
                        while(isalnum(ch=fgetc(f)))
                        {                        
                            word[p]=ch;p++;
                        }
                       
                        fseek(f,-1,SEEK_CUR);
                        word[p]='\0';
                        wordlen=p;
                        p=0;
                        for(i=0;i<14;i++)
                            if(strcmp(keyw[i],word)==0)
                            {
                                printf("%s - Keyword\n",word);
                                id=1;
                                break;
                            }
                        if(id==0)
                            {printf("%s - Identifier\n",word);
                                    fp=fopen("symboltable.txt","a");
                                    fputs(word,fp);
                                    fputs("\n",fp);
                                    fclose(fp);
                            }
                        state=0;
                        id=0;
                    }
                else if(ch=='+')
                {
                    ch=fgetc(f);
                    if (ch=='+')
                        printf("++ - INC\n");
                    else 
                        {
                            fseek(f,-1,SEEK_CUR);
                            printf("+ - PLU\n");
                        }
                }
                else if(ch=='-')
                {
                    ch=fgetc(f);
                    if (ch=='=')
                        printf("-= - DEC\n");
                    else 
                        printf("- - MIN\n");
                }
                else if(ch=='*')
                    printf("* - MUL\n");
                else if(ch=='/')
                    printf("/ - DIV\n");
                else if(ch=='%')
                    printf(" MOD\n");
                else if(isdigit(ch))
                    {
                        p=0;
                        word[p]=ch;
                        p++;
                        while(isdigit(ch=fgetc(f)))
                        {
                            word[p]=ch;
                            p++;
                        }
                        fseek(f,-1,SEEK_CUR);
                        word[p]='\0';
                        printf("%s - NUM\n",word);
                        p=0;
                    }
                else if(ch=='{')
                    printf("{ - Opening bracket\n");
                else if(ch=='}')
                    printf("} - Closing bracket\n");
            break;
            default: break;
                  
        }
        if(ch==EOF)
            break;
    }

    return 0;
}