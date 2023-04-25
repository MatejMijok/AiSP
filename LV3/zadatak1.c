#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX_SIZE 100

int binomniKoeficijent(int, int);
int binomniKoefStog(int, int);
void push(Stack* s, int x);
int pop(Stack* s);

typedef struct Stack {
    int top;
    int data[MAX_SIZE];
} Stack;

int main()
{
    time_t t1, t2;
    int n, m;
    int rjesenje = 0;
    printf("Unesite n: ");
    scanf_s("%d", &n);
    m = n / 2;
    t1 = clock();
    rjesenje = binomniKoeficijent(n, m);
    t2 = clock();
    printf("Vrijeme potrebno za rekurziju iznosi: %dms\n", t2-t1);

    t1 = clock();
    rjesenje = binomniKoefStog(n, m);
    t2 = clock();
    printf("Vrijeme potrebno za stog iznosi: %dms\n", t2 - t1);

    return 0;
}

int binomniKoeficijent(int n, int m) {
    if (m == 0 || m == n)
        return 1;
    return binomniKoeficijent(n - 1, m - 1) + binomniKoeficijent(n - 1, m);
}


void push(Stack* s, int x) {
    if (s->top == MAX_SIZE - 1) {
        printf("Error: stack overflow\n");
        exit(1);
    }
    s->data[++s->top] = x;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Error: stack underflow\n");
        exit(1);
    }
    return s->data[s->top--];
}

int binomniKoefStog(int n, int k)
{
    Stack s;
    s.top = -1;
    push(&s, n);
    push(&s, k);
    int rezultat = 0;
    while (s.top != -1) {
        k = pop(&s);
        n = pop(&s);
        if (k == 0 || k == n) {
            rezultat += 1;
        }
        else {
            push(&s, n - 1);
            push(&s, k - 1);
            push(&s, n - 1);
            push(&s, k);
        }
    }
    return rezultat;
}
