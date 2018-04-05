#include "OperationStack.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Operation* createOperation(Material* m, Material* n, char* operationType) {
	Operation* o = (Operation*)malloc(sizeof(Operation));
	o->material = copyMaterial(m);
	o->material2 = copyMaterial(n);

	if (operationType != NULL)
	{
		o->operationType = (char*)malloc(sizeof(char) * (strlen(operationType) + 1));
		strcpy(o->operationType, operationType);
	}
	else
		o->operationType = NULL;

	return o;
}

void destroyOperation(Operation* o) {
	if (o == NULL)
		return;

	destroyMaterial(o->material);
	destroyMaterial(o->material2);
	free(o->operationType);
	free(o);
}

Operation* copyOperation(Operation* o) {
	if (o == NULL)
		return NULL;
	Operation* x = createOperation(o->material, o->material2, o->operationType);
	return x;
}

char* getOperationType(Operation* o) {
	return o->operationType;
}

Material* getMaterial(Operation* o) {
	return o->material;
}

Material* getMaterial2(Operation* o) {
	return o->material2;
}

OperationStack* createStack() {
	OperationStack* s = (OperationStack*)malloc(sizeof(OperationStack));
	s->length = 0;

	return s;
}

void destroyStack(OperationStack* s) {
	if (s == NULL)
		return;
	for (int i = 0; i < s->length; i++)
		destroyOperation(s->operations[i]);
	free(s);
}

void push(OperationStack* s, Operation* o) {
	if (isFull(s))
		return;

	s->operations[s->length++] = copyOperation(o);
}

Operation* pop(OperationStack* s) {
	if (isEmpty(s))
		return NULL;
	s->length--;
	return s->operations[s->length];
}

int isEmpty(OperationStack* s)
{
	return (s->length == 0);
}

int isFull(OperationStack* s)
{
	return s->length == 100;
}