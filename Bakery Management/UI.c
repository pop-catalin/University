#include "UI.h"
#include <stdio.h>

UI createUI(Controller* c) {
	UI ui;
	ui.ctrl = c;

	return ui;
}

void printMenu() {
	printf("1- Add a material\n");
	printf("2- List all materials\n");
	printf("3- Delete a material\n");
	printf("4- Update a material\n");
	printf("5- List expired items containing a string\n");
	printf("0- Exit\n");
}

int validCommand(int command) {
	if(command >= 0 && command <= 6)
		return 1;
	return 0;
}

int readNumber(const char* message) {
	char s[20];
	int res = 0;
	int flag = 0;
	int r = 0;

	while (flag == 0) {
		printf("%s",message);
		scanf("%s",s);

		r = sscanf(s, "%d", &res);
		flag = (r == 1);
		if(flag == 0)
			printf("Error reading number!\n");
	}
	return res;
}

int addMaterialUI(UI* ui) {
	char name[50], supplier[50], date[50];
	int quantity = 0;

	printf("Input a name: ");
	scanf("%49s", name);
	printf("Input a supplier: ");
	scanf("%49s", supplier);
	printf("Input a quantity: ");
	scanf("%d", &quantity);
	printf("Input an expiration date: ");
	scanf("%49s", date);

	return addMaterial(ui->ctrl, name, supplier, quantity, date);
}

void listAllMaterialsUI(UI* ui) {
	MaterialRepo* repo = getRepo(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no stored materials.";
		printf("%s\n",str);
	}

	for (int i = 0; i < getLength(repo); ++i) {
		char str[200];
		toString(getMaterialOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

int deleteMaterialUI(UI* ui) {
	char name[50], supplier[50], date[50];
	printf("Input the name of the material you want to delete: ");
	scanf("%49s", name);
	printf("Input the supplier: ");
	scanf("%49s", supplier);
	printf("Input the date: ");
	scanf("%49s", date);

	return deleteMaterial(ui->ctrl, name, supplier, date);
}

int updateMaterialUI(UI* ui) {
	char name1[50], name2[50], date1[50], date2[50], supplier1[50], supplier2[50];
	int quantity = 0;
	printf("Input the name of the material you want to update: ");
	scanf("%49s", name1);
	printf("Input the supplier: ");
	scanf("%49s", supplier1);
	printf("Input the date: ");
	scanf("%49s", date1);
	printf("Input the new name: ");
	scanf("%49s", name2);
	printf("Input the new supplier: ");
	scanf("%49s", supplier2);
	printf("Input the new quantity: ");
	scanf("%d", &quantity);
	printf("Input the new date: ");
	scanf("%49s", date2);

	return updateMaterial(ui->ctrl, name1, supplier1, date1, name2, supplier2, quantity, date2);
}

void listExpiredUI(UI *ui) {
	char tofind[50];
	printf("Input string to find: ");
	scanf("%49s", tofind);
	checkMaterialDate(ui->ctrl, tofind);
	MaterialRepo* repo = getRepo2(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no expired materials.";
		printf("%s\n",str);
	}

	for (int i = 0; i < length; ++i) {
		char str[200];
		toString(getMaterialOnPos(repo, i), str);
		printf("%s\n", str);
	}
	for (int i = 0; i < length; ++i)
		deleteMaterial(ui->ctrl, getMaterialOnPos(repo, i).name, getMaterialOnPos(repo, i).supplier, getMaterialOnPos(repo, i).date);
	
}

void listDescendingUI(UI *ui) {
	char tofind[50];
	printf("Input string to find: ");
	scanf("%49s", tofind);
	descending(ui->ctrl, tofind);
	MaterialRepo* repo = getRepo2(ui->ctrl);
	int length = getLength(repo);

	if (length == 0) {
		char* str = "There are no materials.";
		printf("%s\n",str);
	}

	for (int i = 0; i < length; ++i) {
		char str[200];
		toString(getMaterialOnPos(repo, i), str);
		printf("%s\n", str);
	}
}

void startUI(UI* ui) {
	while (1) {
		printMenu();
		int command = readNumber("Input command: ");
		while (validCommand(command) == 0) {
			printf("Please input a valid command!\n");
			command = readNumber("Input command: ");
		}
		if (command == 0)
			break;
		if (command == 1) {
			int res = addMaterialUI(ui);
			if(res == 1)
				printf("Material added.\n");
			else
				printf("Material could not be added\n");
		}
		if (command == 2)
			listAllMaterialsUI(ui);
		if (command == 3) {
			int res = deleteMaterialUI(ui);
			if (res == 1)
				printf("Material deleted.\n");
			else
				printf("Material was not deleted");
		}
		if (command == 4) {
			int res = updateMaterialUI(ui);
			if (res == 1)
				printf("Material updated\n");
			else
				printf("Material could not be updated\n");
		}
		if (command == 5)
			listExpiredUI(ui);

		if (command == 6)
			listDescendingUI(ui);
	}
}