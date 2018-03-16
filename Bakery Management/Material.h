#pragma once

typedef struct
{
	char name[50];
	char supplier[50];
	int quantity;
	char date[10];
} Material;

Material createMaterial(char name[], char supplier[], int quantity, char date[]);
char* getName(Material* m);
char* getSupplier(Material* m);
int getQuantity(Material* m);
void changeQuantity(Material *m, int q);

void toString(Material m, char str[]);