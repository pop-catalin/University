#pragma once
#include "Material.h"

typedef struct 
{
	Material* materials[100];
	int length;
} MaterialRepo;

MaterialRepo* createRepo();

void destroyRepo(MaterialRepo* v);

/*finds material with given name, supplier and date
v-> pointer to the repo
name, supplier and date-> params to search for
returns the position, -1 if not found
*/
Material* find(MaterialRepo* v, char name[], char supplier[], char date[]);

int getPos(MaterialRepo* v, Material* m);

/*adds a material to the repo, changes the quantity if the material is already added
v-> pointer to repo
m- material to be added
returns 1*/
int add(MaterialRepo* v, Material* m);

/*deletes a material from the repo
v-> pointer to repo
m- material to be added
returns 1 if the material was deleted, 0 otherwise
*/
int del(MaterialRepo* v, Material* m);

/*updates a material
v-> pointer to repo
m- material to be added
n- new material
returns 1 if the material was updated, 0 otherwise*/
int update(MaterialRepo* v, Material* m, Material* n);

/*checks if a material is expired
v-> pointer to repo
m-> material to be checked
returns 1 if material is expired, 0 otherwise*/
int date(MaterialRepo* v, Material* m);

/*checks is a material has a string in it
v-> pointer to repo
m-> material to be checked
tofind -> string to be found
returns 1 if string is empty or if it was found, 0 otherwise*/
int containstring(MaterialRepo* v, Material* m, char tofind[]);

int getLength(MaterialRepo* m);

/*returns the material on a certain position
v-> pointer to the repo
pos-> position of the returned material
returns the material or an empty one if position is not valid*/
Material* getMaterialOnPos(MaterialRepo* v, int pos);

void testsMaterialRepo();