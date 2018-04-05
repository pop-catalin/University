#include "Controller.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Controller* createController(MaterialRepo* r, MaterialRepo* aux, OperationStack *undoS) {
	Controller* c = (Controller*)malloc(sizeof(Controller));
	c->repo = r;
	c->repo2 = aux;
	c->undoStack = undoS;

	return c;
}

void destroyController(Controller* c) {
	destroyRepo(c->repo);
	free(c);
}

int addMaterial(Controller* c, char* name, char* supplier, int quantity, char* date) {
	Material* m = createMaterial(name, supplier, quantity, date);
	Material* n = createMaterial("","",0,"");
	int res = add(c->repo, m);
	if (res == 1) {
		Operation* o = createOperation(m, n,"add");
		push(c->undoStack, o);
		destroyOperation(o);
	}

	//destroyMaterial(m);
	return res;
}

int deleteMaterial(Controller* c, char* name, char* supplier, int quantity, char* date) {
	Material* m = createMaterial(name, supplier, quantity, date);
	Material* n = createMaterial("","",0,"");
	int res = del(c->repo, m);
	if (res == 1) {
		Operation* o = createOperation(m, n, "delete");
		push(c->undoStack, o);
		destroyOperation(o);
		//destroyMaterial(m);
	}
	return res;
}

int updateMaterial(Controller* c, char* name1, char* supplier1, char* date1, char* name2, char* supplier2, int quantity2, char* date2) {
	Material* m = createMaterial(name1, supplier1, 0, date1);
	Material* n = createMaterial(name2, supplier2, quantity2, date2);
	int res = update(c->repo, m, n);
	if (res == 1){
		Operation* o = createOperation(m,n, "update");
		push(c->undoStack, o);
		destroyOperation(o);
		//destroyMaterial(m);
		//destroyMaterial(n);
	}
	
	return res;
}

MaterialRepo* sortShortSupply(Controller* c, char supplier[], int quantity) {
	MaterialRepo* res = createRepo();
	for (int i = 0; i < getLength(c->repo); i++) {
		Material* m = getMaterialOnPos(c->repo, i);
		if(strstr(getSupplier(m), supplier) != NULL && getQuantity(m) < quantity) {
			Material* n = createMaterial(m->name, m->supplier, m->quantity, m->date);
			add(res, n);
		}
	}
	Material *x = createMaterial("", "", 0, "");
	int i,j;
	for (i = 0; i < getLength(res) - 1; i++) {
		for (j = 0; j < getLength(res) - i - 1; j++) {
			if(res->materials[j]->quantity > res->materials[j + 1]->quantity) {
				x = res->materials[j];
				res->materials[j] = res->materials[j + 1];
				res->materials[j + 1] = x;
			}
		}
	}
	destroyMaterial(x);
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

/*void descending(Controller* c, char tofind[]) {
	int res = 0, i;
	Material m;
	for(i = 0; i < getLength(c->repo); ++i) {
		res = containstring(c->repo, getMaterialOnPos(c->repo, i), tofind);
		if (res == 1)
			add(c->repo2, getMaterialOnPos(c->repo, i));
	}
	for (i = 0; i < getLength(c->repo) -1 ; i++)
      for (int j = 0; j < getLength(c->repo) - i -1; j++) {
         if (strcmp(getMaterialOnPos(c->repo, j)->name, getMaterialOnPos(c->repo, j+1)->name) < 0) {
            m = getMaterialOnPos(c->repo, j);
            c->repo->materials[j]= getMaterialOnPos(c->repo, j + 1);
            c->repo->materials[j+1] = m;
         }
      }
}
*/


MaterialRepo* getRepo(Controller* c) {
	return c->repo;
}

MaterialRepo* getRepo2(Controller* c) {
	return c->repo2;
}

int undo(Controller* c) {
	if (isEmpty(c->undoStack))
		return 0;
	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0) {
		Material* material = getMaterial(operation);
		char name[50];
		char supplier[50];
		char date[10];
		int quantity = 0;
		strcpy(name, getName(material));
		strcpy(supplier, getSupplier(material));
		strcpy(date, getDate(material));
		deleteMaterial(c, name, supplier,quantity, date);
		pop(c->undoStack);
	}

	if (strcmp(getOperationType(operation), "delete") == 0) {
		Material* material = getMaterial(operation);
		char name[50];
		char supplier[50];
		char date[10];
		int quantity = getQuantity(material);
		strcpy(name, getName(material));
		strcpy(supplier, getSupplier(material));
		strcpy(date, getDate(material));
		addMaterial(c,name,supplier,quantity,date);
		pop(c->undoStack);
	}

	if (strcmp(getOperationType(operation), "update") == 0) {
		Material* material = getMaterial(operation);
		Material* material2 = getMaterial2(operation);
		char name1[50], supplier1[50], date1[50],name2[50], supplier2[50], date2[50];
		int quantity1 = getQuantity(material);
		int quantity2 = getQuantity(material2);
		strcpy(name1, getName(material));
		strcpy(supplier1, getSupplier(material));
		strcpy(date1, getDate(material));
		deleteMaterial(c,name1,supplier1,quantity1,date1);
		pop(c->undoStack);
		strcpy(name2, getName(material));
		strcpy(supplier2, getSupplier(material));
		strcpy(date2, getDate(material));
		addMaterial(c,name2,supplier2,quantity2,date2);
		pop(c->undoStack);
	}	

	destroyOperation(operation);

	return 1;
}

int redo(Controller* c) {
	if (isEmpty(c->undoStack))
		return 0;
	Operation* operation = pop(c->undoStack);

	if (strcmp(getOperationType(operation), "add") == 0) {
		Material* material = getMaterial(operation);
		char name[50];
		char supplier[50];
		char date[10];
		int quantity = 0;
		strcpy(name, getName(material));
		strcpy(supplier, getSupplier(material));
		strcpy(date, getDate(material));
		addMaterial(c, name, supplier,quantity, date);
	}

	if (strcmp(getOperationType(operation), "delete") == 0) {
		Material* material = getMaterial(operation);
		char name[50];
		char supplier[50];
		char date[10];
		int quantity = getQuantity(material);
		strcpy(name, getName(material));
		strcpy(supplier, getSupplier(material));
		strcpy(date, getDate(material));
		deleteMaterial(c,name,supplier,quantity,date);
	}

	if (strcmp(getOperationType(operation), "update") == 0) {
		Material* material = getMaterial(operation);
		Material* material2 = getMaterial2(operation);
		char name1[50], supplier1[50], date1[50],name2[50], supplier2[50], date2[50];
		int quantity1 = getQuantity(material);
		int quantity2 = getQuantity(material2);
		strcpy(name1, getName(material));
		strcpy(supplier1, getSupplier(material));
		strcpy(date1, getDate(material));
		deleteMaterial(c,name1,supplier1,quantity1,date1);
		pop(c->undoStack);
		strcpy(name2, getName(material));
		strcpy(supplier2, getSupplier(material));
		strcpy(date2, getDate(material));
		addMaterial(c,name2,supplier2,quantity2,date2);
		pop(c->undoStack);
	}	

	destroyOperation(operation);

	return 1;
}

MaterialRepo* listFromSupplier(Controller* c, char supplier[]) {
	MaterialRepo* res = createRepo();
	for (int i = 0; i < getLength(c->repo); i++) {
		Material* m = getMaterialOnPos(c->repo, i);
		if(strstr(getSupplier(m), supplier) != NULL) {
			Material* n = createMaterial(m->name, m->supplier, m->quantity, m->date);
			add(res, n);
		}
	}
	Material *x = createMaterial("", "", 0, "");
	int i,j;
	for (i = 0; i < getLength(res) - 1; i++) {
		for (j = 0; j < getLength(res) - i - 1; j++) {
			int day1 = 0, month1 = 0, day2 = 0, month2 = 0;
			sscanf(res->materials[j]->date, "%d.%d", &day1, &month1);
			sscanf(res->materials[j + 1]->date, "%d.%d", &day2, &month2);
			if(month1 > month2) {
				x = res->materials[j];
				res->materials[j] = res->materials[j + 1];
				res->materials[j + 1] = x;
			}
		}
	}
	return res;
}