#include "Controller.h"
#include <string.h>
#include <stdlib.h>

Controller createController(MaterialRepo* r, MaterialRepo* aux) {
	Controller c;
	c.repo = r;
	c.repo2 = aux;

	return c;
}

int addMaterial(Controller* c, char name[], char supplier[], int quantity, char date[]) {
	Material m = createMaterial(name, supplier, quantity, date);
	int res = add(c->repo, m);
	return res;
}

int deleteMaterial(Controller* c, char name[], char supplier[], char date[]) {
	Material m = createMaterial(name, supplier, 0, date);
	int res = del(c->repo, m);
	return res;
}

int updateMaterial(Controller* c, char name1[], char supplier1[], char date1[], char name2[], char supplier2[], int quantity2, char date2[]) {
	Material m = createMaterial(name1, supplier1, 0, date1);
	Material n = createMaterial(name2, supplier2, quantity2, date2);
	int res = update(c->repo, m, n);
	return res;
}

void checkMaterialDate(Controller* c, char tofind[]) {
	int res = 0;
	for(int i = 0; i < getLength(c->repo); ++i){
		res = date(c->repo, getMaterialOnPos(c->repo, i)) && containstring(c->repo, getMaterialOnPos(c->repo, i), tofind);
		if (res == 1)
			add(c->repo2, getMaterialOnPos(c->repo, i));
	}
}

void descending(Controller* c, char tofind[]) {
	int res = 0, i;
	Material m;
	for(i = 0; i < getLength(c->repo); ++i) {
		res = containstring(c->repo, getMaterialOnPos(c->repo, i), tofind);
		if (res == 1)
			add(c->repo2, getMaterialOnPos(c->repo, i));
	}
	for (i = 0; i < getLength(c->repo) -1 ; i++)
      for (int j = 0; j < getLength(c->repo) - i -1; j++) {
         if (strcmp(getMaterialOnPos(c->repo, j).name, getMaterialOnPos(c->repo, j+1).name) < 0) {
            m = getMaterialOnPos(c->repo, j);
            c->repo->materials[j]= getMaterialOnPos(c->repo, j + 1);
            c->repo->materials[j+1] = m;
         }
      }
}


MaterialRepo* getRepo(Controller* c) {
	return c->repo;
}

MaterialRepo* getRepo2(Controller* c) {
	return c->repo2;
}