#include <stdio.h>
#include <stdlib.h>

char* c;
typedef enum { paren , bracket } what;
what* t;
size_t d;
unsigned int n;

int main() {
    scanf("%d",&n);
    getchar(); /*gets that newline*/
    c = malloc(sizeof(char));
    do {
        t = NULL;
        d = 0;
        while(1) {
            *c = (char)getchar();
            switch (*c) {
                case '(':
                    if(t==NULL && d>0) goto koniecswitcha;
                    d+= sizeof(what);
                    t = realloc(t,d);
                    *(t+d) = paren;
                    goto koniecswitcha;
                case '[':
                    if(t==NULL && d>0) goto koniecswitcha;
                    d+= sizeof(what);
                    t = realloc(t,d);
                    *(t+d) = bracket;
                    goto koniecswitcha;
                case ')':
                    if(t==NULL) goto koniecswitcha;
                    if(*(t+d)==paren) {
                        d-= sizeof(what);
                        t = realloc(t,d);
                        if(t==NULL) goto koniecswitcha;
                    } else {
                        free(t);
                        goto koniecswitcha;
                    }
                    goto koniecswitcha;
                case ']':
                    if(t==NULL) goto koniecswitcha;
                    if(*(t+d)==bracket) {
                        d-= sizeof(what);
                        t = realloc(t,d);
                        if(t==NULL) goto koniecswitcha;
                    } else {
                        free(t);
                        goto koniecswitcha;
                    }
                    goto koniecswitcha;
                case '\n':
                default:
                    if(t==NULL) goto koniecpetli;
                    free(t);
                    goto koniecpetli;
            }
            koniecswitcha:
            continue;
        }
        koniecpetli:
        printf(d>0? "No" : "Yes");
        putchar('\n');
    } while (--n>0);
    free(c);
    return 0;
}