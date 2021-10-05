%{
    #include<stdio.h>
%}
letter [A-Za-z]
digit [0-9]
%%
"int"|"printf"|"float"|"main"|"char"|"long"|"double"|"if"|"else"|"for"|"while"|"void"|"do"|"switch"|"case"|"break" {printf("\n%s -- KEYWORD",yytext);}
"{"|"}"|"("|")"|"["|"]" {printf("\n%s -- PARANTHESIS",yytext);}
{digit}* {printf("\n%s -- NUM",yytext);}
{letter}({letter}|{digit})* {printf("\n%s -- IDENTIFER",yytext);}
"==" {printf("\n%s -- EQU",yytext);}
";" {printf("\n%s -- DELIM",yytext);}
\".*\" {printf("\n%s -- STRING",yytext);}
"<=" {printf("\n%s -- LE",yytext);}
"<>" {printf("\n%s -- NE",yytext);}
"<" {printf("\n%s -- LT",yytext);}
">=" {printf("\n%s -- GE",yytext);}
">" {printf("\n%s -- GT",yytext);}
"=" {printf("\n%s -- ASSIGN",yytext);}
"++" {printf("\n%s -- INC",yytext);}
"+" {printf("\n%s -- PLU",yytext);}
"-=" {printf("\n%s -- DEC",yytext);}
"-" {printf("\n%s -- MIN",yytext);}
"*" {printf("\n%s -- MUL",yytext);}
"/" {printf("\n%s -- DIV",yytext);}

%%
int main()
{
    FILE *fp;
    fp=fopen("var.c","r");
    yyin=fp;
    yylex();
    fclose(fp);
    return 0;
}