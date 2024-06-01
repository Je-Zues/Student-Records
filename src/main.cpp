#include "Node.h"

int main() {

	_MENUOPTION option;

	NODE* head = nullptr; //sets head and tail null since DB is empty
	NODE* tail = nullptr;

	do {
		option = mainMenu(); //get option from user

		switch (option) {
			case ADD: {//makes a new node and adds to records
				NODE* node = new NODE(0, 0, 0, (char*)""); 
				node->AddRecord(head,tail); 
			
				break; 
			}
			case DISPLAY: { //displays current records
				head->displayRecord();
				break;
			}
			case DEL: { //deletes a record
				head->deleteRecord(head,tail);
				break;
			}
			case UPDATE: { //updates a record
				head->updateRecord();
			}
		
		}

		//while user does not select to exit
	} while (option != EXIT);


}

