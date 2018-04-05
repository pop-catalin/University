#pragma once
#include "Material.h"
#include <string.h>

typedef struct {
	Material* material;
	Material* material2;
	char* operationType;
} Operation;

Operation* createOperation(Material* m, Material* n, char* operationType);
void destroyOperation(Operation* o);
Operation* copyOperation(Operation* o);
char* getOperationType(Operation* o);
Material* getMaterial(Operation* o);
Material* getMaterial2(Operation* o);

typedef struct {
	Operation* operations[100];
	int length;
} OperationStack;

OperationStack* createStack();
void destroyStack(OperationStack* s);
void push(OperationStack* s, Operation* o);
Operation* pop(OperationStack* s);
int isEmpty(OperationStack* s);
int isFull(OperationStack* s);