#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int DG = -1000;
int GG = 1000;

void zamjena(int* a, int* b);
void uhrpi(int* V, int n, int i);
void heapSort(int* V, int n);
void bubbleSort(int* V, int n);
void ispisPolja(int* V, int n);

int main() {
    int n;
    time_t t1, t2;
    long int vrijemeIzvodenja;
    printf("Unesite broj elemenata polja: ");
    scanf_s("%d", &n);

    // Generiranje nasumičnih brojeva
    srand(time(NULL));

    int* V = (float*)malloc(n * sizeof(float));
    if (V == NULL) {
        printf("Greška pri alokaciji memorije.\n");
        return 1;
    }

    int* V2 = (float*)malloc(n * sizeof(float));
    if (V2 == NULL) {
        printf("Greška pri alokaciji memorije.\n");
        free(V);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        V[i] = DG + (float)rand() / RAND_MAX * (GG - DG);
    }

    // Kopiranje nasumično generiranog polja u drugo polje
    for (int i = 0; i < n; i++) {
        V2[i] = V[i];
    }

    //printf("Originalno polje:\n");
    //ispisPolja(V, n);

    t1 = clock();
    heapSort(V, n);
    t2 = clock();
    vrijemeIzvodenja = t2 - t1;

    //printf("Sortirano polje (heap sort): \n");
    //ispisPolja(V, n);
    printf("Vrijeme izvodenja heap sorta: %lims\n", vrijemeIzvodenja);


    t1 = clock();
    bubbleSort(V2, n);
    t2 = clock();
    vrijemeIzvodenja = t2 - t1;

    //printf("Sortirano polje (bubble sort):\n");
    //ispisPolja(V2, n);
    printf("Vrijeme izvodenja bubble sorta: %lims\n", vrijemeIzvodenja);

    free(V);
    free(V2);
    return 0;
}

void zamjena(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void uhrpi(int* V, int n, int i) {
    int najveci = i;
    int lijevi = 2 * i + 1;
    int desni = 2 * i + 2;

    if (lijevi < n && V[lijevi] > V[najveci])
        najveci = lijevi;

    if (desni < n && V[desni] > V[najveci])
        najveci = desni;

    if (najveci != i) {
        zamjena(&V[i], &V[najveci]);
        uhrpi(V, n, najveci);
    }
}

void heapSort(int* V, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        uhrpi(V, n, i);

    for (int i = n - 1; i > 0; i--) {
        zamjena(&V[0], &V[i]);
        uhrpi(V, i, 0);
    }
}

void bubbleSort(int* V, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (V[j] > V[j + 1])
                zamjena(&V[j], &V[j + 1]);
        }
    }
}

void ispisPolja(int* V, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", V[i]);
    printf("\n");
}
