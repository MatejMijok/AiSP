#include <stdio.h>
#include <stdlib.h>

typedef struct cvor {
    char x;
    struct cvor* left;
    struct cvor* right;
} Cvor;

Cvor* noviCvor(char data);
void noviUnos(Cvor** root, char data);
void preorder(Cvor* root);
void inorder(Cvor* root);
void postorder(Cvor* root);

int main() {
    Cvor* korijen = NULL;
    char ime[100];

    fgets(ime, 100, stdin);
    ime[strcspn(ime, "\n")] = 0;

    for (int i = 0; ime[i] != '\0'; i++)
        noviUnos(&korijen, ime[i]);

    printf("Preorder: ");
    preorder(korijen);

    printf("\nInorder: ");
    inorder(korijen);

    printf("\nPostorder: ");
    postorder(korijen);

    return 0;
}

Cvor* noviCvor(char upis) {
    Cvor* cvor = (Cvor*)malloc(sizeof(Cvor));
    cvor->x = upis;
    cvor->left = NULL;
    cvor->right = NULL;
    return cvor;
}

void noviUnos(Cvor** cvor, char upis) {
    if (*cvor == NULL) {
        *cvor = noviCvor(upis);
        return;
    }
    if (upis < (*cvor)->x)
        noviUnos(&(*cvor)->left, upis);
    else
        noviUnos(&(*cvor)->right, upis);
}

void preorder(Cvor* korijen) {
    if (korijen == NULL)
        return;
    printf("%c ", korijen->x);
    preorder(korijen->left);
    preorder(korijen->right);
}

void inorder(Cvor* korijen) {
    if (korijen == NULL)
        return;
    inorder(korijen->left);
    printf("%c ", korijen->x);
    inorder(korijen->right);
}

void postorder(Cvor* korijen) {
    if (korijen == NULL)
        return;
    postorder(korijen->left);
    postorder(korijen->right);
    printf("%c ", korijen->x);
}
