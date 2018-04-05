#include "Repo.h"
#include "UI.h"

int main() {

	testsMaterialRepo();

	MaterialRepo* repo = createRepo();
	MaterialRepo* repo2 = createRepo();
	OperationStack* operationStack = createStack();
	Controller* ctrl = createController(repo, repo2, operationStack);


	addMaterial(ctrl, "Drojdie", "Kaufland", 5, "13.03");
	addMaterial(ctrl, "Paine", "Dada", 50, "15.03");
	addMaterial(ctrl, "Nustiu", "Nup", 3, "5.1");
	addMaterial(ctrl, "Ciocolata", "Dada", 10, "5.5");
	addMaterial(ctrl, "Drojdie", "Buna", 7, "2.3");
	addMaterial(ctrl, "Drojdie", "Dada", 5, "1.2");
	addMaterial(ctrl, "Drojdie", "Dada", 12, "12.12");
	UI* ui = createUI(ctrl);
	startUI(ui);
	destroyUI(ui);

	return 0;
}