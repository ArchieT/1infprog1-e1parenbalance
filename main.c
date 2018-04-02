#include <stdio.h>
#include <stdlib.h>

char c;
typedef enum {
    paren, bracket
} what;
what *t;
unsigned short int d;
unsigned int n;
typedef enum {
    yes, no
} whether;
whether huh;

void do_getchar_until_newline() {
    do { c = (char) getchar(); } while (c != '\n');
}

int main() {
    scanf("%d", &n);
    c = (char) getchar(); /*gets that newline*/
    do {
        t = NULL;
        d = 0;
        while (1) {
            c = (char) getchar();
            what now = bracket;
            huh = yes;
            switch (c) {
                case '(':
                    now = paren;
                case '[':
                    now = now == paren ? paren : bracket;
                    t = realloc(t, (++d) * sizeof(what));
                    t[d - 1] = now;
                    goto koniecswitcha;
                case ')':
                    now = paren;
                case ']':
                    now = now == paren ? paren : bracket;
                    if (d == 0 || t[d - 1] != now) {
                        free(t);
                        do_getchar_until_newline();
                        huh = no;
                        goto koniecpetli;
                    }
                    t = realloc(t, (--d) * sizeof(what));
                    goto koniecswitcha;
                case '\n':
                default:
                    free(t);
                    huh = d == 0 ? yes : no;
                    goto koniecpetli;
            }
            koniecswitcha:
            continue;
        }
        koniecpetli:
        switch (huh) {
            case yes:
                printf("Yes");
                break;;
            case no:
                printf("No");
                break;;
        }
        putchar('\n');
    } while (--n > 0);
    return 0;
}