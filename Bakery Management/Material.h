#pragma once

typedef struct
{
	char* name;
	char* supplier;
	int quantity;
	char* date;
} Material;

Material* createMaterial(char* name, char* supplier, int quantity, char* date);
void destroyMaterial(Material* m);
Material* copyMaterial(Material* m);
char* getName(Material* m);
char* getSupplier(Material* m);
int getQuantity(Material* m);
void changeQuantity(Material *m, int q);
char* getDate(Material* m);

void toString(Material* m, char str[]);