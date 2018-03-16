#include "Material.h"
#include <string.h>
#include <stdio.h>

Material createMaterial(char name[], char supplier[], int quantity, char date[]) {
	Material m;
	strcpy(m.name, name);
	strcpy(m.supplier, supplier);
	m.quantity = quantity;
	strcpy(m.date, date);

	return m;
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

void toString(Material m, char str[]) {
	sprintf(str, "Material %s is supplied by %s in quantity %d and its expiration date is %s", m.name, m.supplier, m.quantity, m.date);
}