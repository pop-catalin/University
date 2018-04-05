#include "Material.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Material* createMaterial(char* name, char* supplier, int quantity, char* date) {
	Material* m = (Material*)malloc(sizeof(Material));
	m->name = (char*)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(m->name, name);
	m->supplier = (char*)malloc(sizeof(char) * (strlen(supplier) + 1));
	strcpy(m->supplier, supplier);
	m->quantity = quantity;
	m->date = (char*)malloc(sizeof(char) * (strlen(date) + 1));
	strcpy(m->date, date);

	return m;
}

void destroyMaterial(Material* m) {
	free(m->name);
	free(m->supplier);
	free(m->date);

	free(m);
}

Material* copyMaterial(Material* m) {
	if (m == NULL)
		return NULL;

	Material* x = createMaterial(getName(m), getSupplier(m), getQuantity(m), getDate(m));
	return x;
}

char* getName(Material* m) {
	return m->name;
}

char* getSupplier(Material* m) {
	return m->supplier;
}

int getQuantity(Material* m) {
	return m->quantity;
}

void changeQuantity(Material *m, int q) {
	m->quantity += q;
}

char* getDate(Material* m) {
	return m->date;
}

void toString(Material* m, char str[]) {
	sprintf(str, "Material %s is supplied by %s in quantity %d and its expiration date is %s", m->name, m->supplier, m->quantity, m->date);
}