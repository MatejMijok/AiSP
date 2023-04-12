/*Zadatak 1. Potrebno je generirati slučajni Niz V od N elemenata. Nakon toga iz tog
niza formirati povezani popis. Mjeriti i usporediti vrijeme potrebno za kreiranje niza i
povezanog popisa. Nakon toga napraviti algoritam sekvencijalnog pretraživanja nad
nizom i nad povezanim popisom. Opet mjeriti vrijeme, što je brže?*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int DG = -1000;
int GG = 1000;

struct OE_ {
	float x;
	struct OE_* sljedeci;
}typedef OE; 

OE* kreirajListu(int);
float *kreirajPolje(int);
void oslobadanjeListe(OE**);
int sekvencijalnoPolje(int, float*, float);
int sekvencijalnoLista(OE*, float);

int main() {
	time_t t1, t2;
	OE* lista;
	int n;
	float trazeni;
	float* polje;

	srand((unsigned)time(NULL));
	
	printf("Unesite broj elemenata liste i polja: ");
	scanf_s("%d", &n);
	
	printf("Unesite element liste i polja koji zelite pronaci: ");
	scanf_s("%f", &trazeni);

	t1 = clock();
	lista = kreirajListu(n);
	t2 = clock();

	printf("Vrijeme potrebno za formiranje liste: %dms\n", (t2-t1));

	t1 = clock();
	polje = kreirajPolje(n);
	t2 = clock();

	printf("Vrijeme potrebno za formiranje polja: %dms\n", (t2-t1));

	t1 = clock();
	sekvencijalnoPolje(n, polje, trazeni);
	t2 = clock();

	printf("Vrijeme potrebno za pretrazivanje polja: %dms\n", (t2-t1));

	t1 = clock();
	sekvencijalnoLista(lista, trazeni);
	t2 = clock();

	printf("Vrijeme potrebno za pretrazivanje liste: %dms\n", (t2-t1));

	oslobadanjeListe(&lista);
	free(polje);
}

OE* kreirajListu(int n){
	OE* p = NULL, * pocetak = NULL;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			pocetak = (OE*)malloc(sizeof(OE));
			p = pocetak;
		}
		else {
			p->sljedeci = (OE*)malloc(sizeof(OE));
			p = p->sljedeci;
		}
		p->x = DG + (float)rand() / RAND_MAX * (GG - DG);
	}
	p->sljedeci = NULL;
	return pocetak;
}

float* kreirajPolje(int n) {
	float* polje = NULL;
	
	polje = (float*)calloc(n ,sizeof(float));
	if (polje == NULL) {
		printf("Polje se nije uspjesno kreiralo!\n");
		return -1;
	}

	for(int i = 0; i<n; i++){
		polje[i] = DG + (float)rand() / RAND_MAX * (GG - DG);
	}

	return polje;
}

void oslobadanjeListe(OE** lista) {
	OE *current = *lista;
	OE *sljedeci;

	while (current != NULL)
	{
		sljedeci = current->sljedeci;
		free(current);
		current = sljedeci;
	}

	*lista = NULL;
}

int sekvencijalnoPolje(int n, float* polje, float trazeni) {
	for (int i = 0; i < n; i++) {
		if (polje[i] == trazeni) {
			printf("Element pronaden na %d. poziciji!\n", i);
			return 0;
		}
	}
	return -1;
}

int sekvencijalnoLista(OE* lista, float trazeni) {
	OE* trenutni = lista;
	while (trenutni != NULL) {
		if (trenutni->x == trazeni) {
			printf("Element je pronaden!\n");
		}

		trenutni = trenutni->sljedeci;
	}
	return -1;
}
