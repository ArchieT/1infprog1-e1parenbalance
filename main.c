#include <stdio.h>
#include <stdlib.h>

char* c;
typedef enum { paren , bracket } what;
struct stoth {
    what wha;
    unsigned int ile;
    struct stoth *poprz;
};
struct stoth *t;
struct stoth *tt;
unsigned int n;

int main() {
    scanf("%d",&n);
    getchar(); /*gets that newline*/
    c = malloc(sizeof(char));
    do {
        t = calloc(1,sizeof(struct stoth));
        (*t).wha = paren;
        (*t).ile = 0;
        (*t).poprz = NULL;
        tt = t;
        while(1) {
            *c = (char)getchar();
            switch (*c) {
                case '(':
                    if((*t).wha==paren) (*t).ile++;
                    else {
                        tt = t;
                        t = calloc(1,sizeof(struct stoth));
                        (*t).wha = paren;
                        (*t).ile = 1;
                        (*t).poprz = tt;
                    }
                    goto koniecswitcha;
                case '[':
                    if((*t).wha==bracket) (*t).ile++;
                    else {
                        tt = t;
                        t = calloc(1,sizeof(struct stoth));
                        (*t).wha = bracket;
                        (*t).ile = 1;
                        (*t).poprz = tt;
                    }
                    goto koniecswitcha;
                case ')':
                    while((*t).ile==0)
                        if((*t).poprz!=NULL) {
                            tt = t;
                            t=(*tt).poprz;
                            free(tt);
                        }
                        else goto koniecno; //return No, bo za duzo zamykajacych parenow
                    if((*t).wha==paren) (*t).ile--;
                    else goto koniecno; //return No, bo nie zgadzaja sie
                    goto koniecswitcha;
                case ']':
                    while((*t).ile==0)
                        if((*t).poprz!=NULL) {
                            tt = t;
                            t=(*tt).poprz;
                            free(tt);
                        }
                        else goto koniecno; //return No, bo za duzo zamykajacych bracketow
                    if((*t).wha==bracket) (*t).ile--;
                    else goto koniecno; //return No, bo nie zgadzaja sie
                    goto koniecswitcha;
                case '\n':
                default:
                    while((*t).ile==0)
                        if((*t).poprz!=NULL) {
                            tt = t;
                            t=(*tt).poprz;
                            free(tt);
                        }
                        else {
                            goto koniecyes;
                        } //return Yes, mamy pusto
                    goto koniecno; //return No, cos ciagle zostalo
            }
            koniecswitcha:
            continue;
        }
        koniecno:
        free(t);
        printf("No\n"); continue;
        koniecyes:
        free(t);
        printf("Yes\n");
    } while (--n>0);
    free(c);
    return 0;
}