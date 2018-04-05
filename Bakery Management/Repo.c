#include "Repo.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>

MaterialRepo* createRepo() {
	MaterialRepo* v = (MaterialRepo*)malloc(sizeof(MaterialRepo));
	v->length = 0;

	return v;
}

void destroyRepo(MaterialRepo* v) {
	for(int i = 0; i < v->length; i++)
		destroyMaterial(v->materials[i]);
	free(v);
}

Material* find(MaterialRepo* v, char* name, char* supplier, char* date) {
	for(int i = 0; i < v->length; ++i) {
		if(strcmp(v->materials[i]->name, name) == 0 && strcmp(v->materials[i]->supplier, supplier) == 0 && strcmp(v->materials[i]->date, date) == 0)
			return v->materials[i];
	}
	return NULL;
}

int getPos(MaterialRepo* v, Material* m) {
	for(int i = 0; i < v->length; i++) {
		if(strcmp(v->materials[i]->name, m->name) == 0 && strcmp(v->materials[i]->supplier, m->supplier) == 0 && strcmp(v->materials[i]->date, m->date) == 0)
			return i;
	}
	return -1;
}

int add(MaterialRepo* v, Material* m) {
	if (find(v, m->name, m->supplier, m->date) != NULL)
		changeQuantity(find(v, m->name, m->supplier, m->date), m->quantity);
	else {
		v->materials[v->length] = m;
		v->length++;
	}

	return 1;
}

int del(MaterialRepo* v, Material* m) {
	if (find(v, m->name, m->supplier, m->date) == NULL)
		return 0;
	for(int i = getPos(v, find(v, m->name, m->supplier, m->date)); i < v->length; ++i) {
		v->materials[i] = v->materials[i + 1];
	}
	v->length--;
	return 1;
}

int update(MaterialRepo* v, Material* m, Material* n) {
	if (find(v, m->name, m->supplier, m->date) == NULL)
		return 0;
	del(v, find(v, m->name, m->supplier, m->date));
	add(v, n);
	return 1;
}

int date(MaterialRepo* v, Material* m) {
	int day = 0, month = 0;
	sscanf(m->date, "%d.%d", &day, &month);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	if (tm.tm_mon + 1 > month || (tm.tm_mon + 1 == month && tm.tm_mday > day))
		return 1;
	return 0;
}

int containstring(MaterialRepo* v, Material* m, char tofind[]) {
	if (strcmp(tofind, " ") == 0)
		return 1;
	if(strstr(m->name, tofind) != 0)
		return 1;
	return 0;
}

int getLength(MaterialRepo* v) {
	return v->length;
}

Material* getMaterialOnPos(MaterialRepo* v, int pos) {
	if(pos < 0 || pos >= v->length)
		return NULL;
	return v->materials[pos];
}

void initMaterialRepoForTests(MaterialRepo* v) {
	Material* m = createMaterial("Mancare", "Dada", 5, "5.2");
	add(v, m);
}

void testAdd() {
	Material* m = createMaterial("Da", "Nu", 3, "12.3");
	MaterialRepo* v = createRepo();
	initMaterialRepoForTests(v);
	assert(getLength(v) == 1);

	assert(add(v, m) == 1);
	assert(getLength(v) == 2);

}

void testDel() {
	Material* m = createMaterial("Mancare", "Dada", 5, "5.2");
	MaterialRepo* v = createRepo();
	initMaterialRepoForTests(v);
	assert(del(v, m) == 1);
	assert(getLength(v) == 0);
}

void testUpdate() {
	Material* n = createMaterial("Da", "Nu", 3, "12.3");
	Material* m = createMaterial("Mancare", "Dada", 5, "5.2");
	MaterialRepo* v = createRepo();
	initMaterialRepoForTests(v);
	assert(update(v, m, n) == 1);
	assert(getLength(v) == 1);

}

void testDate() {
	Material* m = createMaterial("Mancare", "Dada", 5, "5.2");
	MaterialRepo* v = createRepo();
	initMaterialRepoForTests(v);
	assert(date(v, m) == 1);
}

void testsMaterialRepo() {
	testAdd();
	testDel();
	testUpdate();
	testDate();
}