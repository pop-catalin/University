#pragma once
#include "Repo.h"
#include "OperationStack.h"

typedef struct
{
	MaterialRepo* repo;
	MaterialRepo* repo2;
	OperationStack* undoStack;
} Controller;

Controller* createController(MaterialRepo* r, MaterialRepo* aux, OperationStack* undoS);
/* Adds a material to the repository.
c-> pointer to controller
name, supplier, quantity, date-> params of the material
returns 1 if the material was added, 0 otherwise*/
int addMaterial(Controller* c, char name[], char supplier[], int quantity, char date[]);

void destroyController(Controller* c);

/* deletes a material.
c-> pointer to the controller
name, supplier and date - params of the material to be deleted
returns 1 if the material was deleted, 0 otherwise*/
int deleteMaterial(Controller* c, char* name, char* supplier,int quantity, char* date);

/* updates a material.
c-> pointer to the controller
name, supplier and date - params of the material to be updated
returns 1 if the material was updated, 0 otherwise*/
int updateMaterial(Controller* c, char* name1, char* supplier1, char* date1, char* name2, char* supplier2, int quantity2, char* date2);

/*adds expired materials with the given string to the other repo
c-> pointer to controller
tofind - string to find*/
void checkMaterialDate(Controller* c, char tofind[]);

void descending(Controller*c, char tofind[]);

int compare_function(Material *a, Material *b);

MaterialRepo* sortShortSupply(Controller* c, char supplier[], int quantity);

MaterialRepo* getRepo(Controller* c);

MaterialRepo* getRepo2(Controller* c);

int undo(Controller* c);

int redo(Controller* c);

MaterialRepo* listFromSupplier(Controller* c, char supplier[]);