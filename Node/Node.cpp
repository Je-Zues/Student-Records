#include "Node.h"

void NODE::displayRecord() {
	/* sets console white and clears screen */
	system("color 7");
	system("cls");

	//user OPTION
	char option = NULL;

	/* IF HEAD is EMPTY THEN NO RECORDS*/
	if (this == nullptr) {
		std::cout << "DB is empty...\n";
		std::cout << "[M]enu\n";
		std::cout << "Option: ";

		/* WAIT FOR USER TO INPUT M FOR MAIN MENU */
		do {
			std::cin >> option;
		} while (option != 'M');
		return;
	}

	/* IF HEAD IS NOT EMPTY */
	NODE* node = this;	//start at head

	int rotations = 0;  //keep track of rotations to change color
	int listSize = 0;	//total amount of nodes

	do {
		system("cls");	//clears screen
		if (node == this)	//reached loop around
			listSize = abs(rotations);	//set size to how many rotations to do 1 loop

		if (listSize != 0 && abs(rotations) >= listSize)
			system("color b");	//set color to blue if weve rotated the full list
		else
			system("color 7");	//set color to white if we havent rotated full list


		/* PRINT STUDENT RECORD */
		std::cout << "------------------------\n";
		std::cout << "|Grade: " << node->getGrade() << "\t\t|\n";
		std::cout << "|NAME : " << node->getName() << "\t\t|\n";
		std::cout << "|AGE  : " << node->getAge() << "\t\t|\n";
		std::cout << "|ID   : " << node->getID() << "\t\t|\n";
		std::cout << "|[P]\t[E]\t[N]\t|\n";
		std::cout << "------------------------\n";
		std::cout << "Option: ";

		//Get user Option
		std::cin >> option;

		//P = Pevious, Go to previous node
		if (option == 'P') {
			if (node->getBLink() != nullptr)
				node = node->getBLink();
			rotations--;
		}
		//N = Next, Go to Next node
		else if (option == 'N') {
			if (node->getFLink() != nullptr)
				node = node->getFLink();
			rotations++;
		}
		/* while user hasnt chose to exit */
	} while (option != 'E');
}

void NODE::updateRecord() {
	/* sets console white and clears screen */
	system("color 7");
	system("cls");

	//user OPTION
	char option = NULL;

	/* IF HEAD is EMPTY THEN NO RECORDS*/
	if (this == nullptr) {
		std::cout << "DB is empty...\n";
		std::cout << "[M]enu\n";
		std::cout << "Option: ";
		/* WAIT FOR USER TO INPUT M FOR MAIN MENU */
		do {
			std::cin >> option;
		} while (option != 'M');
		return;
	}

	/* IF HEAD IS NOT EMPTY */
	NODE* node = this;	//start at head

	int rotations = 0;  //keep track of rotations to change color
	int listSize = 0;	//total amount of nodes

	//lambda to update a node 
	auto update = [&]() {

		//user choice
		uint16_t choice = 0;

		do {
			//clears screen
			system("cls");

			//shows current record and current option user is on
			std::cout << "--------UPDATING--------\n";
			std::cout << "------------------------\n";
			std::cout << (choice == 0 ? ">" : "|") << "Grade: " << node->getGrade() << "\t\t|\n";
			std::cout << (choice == 1 ? ">" : "|") << "NAME : " << node->getName() << "\t\t|\n";
			std::cout << (choice == 2 ? ">" : "|") << "AGE  : " << node->getAge() << "\t\t|\n";
			std::cout << (choice == 3 ? ">" : "|") << "ID   : " << node->getID() << "\t\t|\n";
			std::cout << "|[A] [E] [U] [B]\t|\n";
			std::cout << "------------------------\n";
			std::cout << "Option: ";

			//gets user option
			std::cin >> option;

			//A = higher item, go up the list 1
			if (option == 'A') {
				if (choice > 0) {
					choice--;
				}
			}

			//B = lower item, Go down the list 1
			if (option == 'B') {
				if (choice < 3) {
					choice++;
				}
			}

			//while user has not exitted or chosen to update that selection
		} while (option != 'E' && option != 'U');

		//if exitted then return
		if (option == 'E')
			return;

		//if updated option pressed, clear screen
		system("cls");

		switch (choice) {
			/* goes to item selected, ouputs to screen to enter new value of item to be updated */
		case 0: {
			uint16_t grade = 0;
			do {
				std::cout << "Enter New Grade: ";
				std::cin >> grade;
				if (grade == NULL || grade > 25)//error checking
					std::cout << "\nMust have valid Grade\n";
			} while (grade == NULL || grade > 25);
			node->setGrade(grade);
			break;

		}
		case 1: {
			std::string name = "";
			do {
				std::cout << "Enter New Name: ";
				std::cin >> name;
				if (name == "")//error checking
					std::cout << "\nMust have valid Name\n";
			} while (name == "");
			node->setName(name);
			break;

		}

		case 2: {
			uint16_t age = 0;
			do {
				std::cout << "Enter New Age: ";
				std::cin >> age;
				if (age == NULL || age > 100)//error checking
					std::cout << "\nMust have valid Age\n";
			} while (age == NULL || age > 100);
			node->setAge(age);
			break;

		}

		case 3: {
			uint16_t ID = 0;
			do {
				std::cout << "Enter New ID: ";
				std::cin >> ID;
				if (ID == NULL)//error checking
					std::cout << "\nMust have valid ID\n";
			} while (ID == NULL);
			node->setID(ID);
			break;

		}
		}

		//item is updated and returns
		return;
	};


	do {
		//CLEARS SCREEN
		system("cls");
		if (node == this)//reached loop around
			listSize = abs(rotations);	//set size to how many rotations to do 1 loop

		if (listSize != 0 && abs(rotations) >= listSize)
			system("color b");	//set color to blue if weve rotated the full list
		else
			system("color 7");	//set color to white if we havent rotated full list

		/* PRINT STUDENT RECORD */
		std::cout << "-------SELECTING_-------\n";
		std::cout << "------------------------\n";
		std::cout << "|Grade: " << node->getGrade() << "\t\t|\n";
		std::cout << "|NAME : " << node->getName() << "\t\t|\n";
		std::cout << "|AGE  : " << node->getAge() << "\t\t|\n";
		std::cout << "|ID   : " << node->getID() << "\t\t|\n";
		std::cout << "|[P] [E] [U] [N]\t|\n";
		std::cout << "------------------------\n";
		std::cout << "Option: ";

		//Get user Option
		std::cin >> option;

		//p = Previous node, goto previous node
		if (option == 'P') {
			if (node->getBLink() != nullptr)
				node = node->getBLink();
			rotations--;
		}

		//n = next node, goto next node
		else if (option == 'N') {
			if (node->getFLink() != nullptr)
				node = node->getFLink();
			rotations++;
		}

		//u = update node, update node
		else if (option == 'U') {
			update();
		}

		//while user does not exit
	} while (option != 'E');


}

void NODE::AddRecord(NODE*& head, NODE*& tail) {

	system("cls");//clears screen

	do {/* Get name from user */
		std::cout << "Enter Name: ";
		std::cin >> this->s_name;
		if (s_name == "")//error checking
			std::cout << "\nMust have valid Name\n";
	} while (this->s_name == "");

	do {/* Get age from user */
		std::cout << "Enter Age: ";
		std::cin >> this->i_Age;
		if (this->i_Age == NULL || this->i_Age > 100)
			std::cout << "\nMust have valid Age\n";
	} while (this->i_Age == NULL || this->i_Age > 100);

	do {/* Get Grade from user */
		std::cout << "Enter Grade: ";
		std::cin >> this->i_Grade;
		if (this->i_Grade == NULL || this->i_Grade > 25)
			std::cout << "\nMust have valid Grade\n";
	} while (this->i_Grade == NULL || this->i_Grade > 25);


	//if DB is not empty
	if (tail != nullptr) {
		this->i_ID = tail->getID() + 1; //id = last node id + 1
		this->bLink = tail;				//set new node's tail to the current last node
		tail->setFLink(this);			//set current last node's head to new node
	}
	else
		this->i_ID = 1;					//if DB is empty then id = 1

	if (head == nullptr)				//if DB is empty then head = this new node
		head = this;
	else if (head->getFLink() == nullptr) {	//if DB only has 1 item
		head->setFLink(this);			//1st node's head = new node created
	}
	head->setBLink(this);				//sets 1st node's tail to new node
	this->setFLink(head);				//sets new nodes head to 1st item

	tail = this;						//updates tail


	/* Allow user to go back to main menu */
	char option;

	std::cout << "Successfully Added\n";
	std::cout << "[M]ENU\nOption: ";
	do {
		std::cin >> option;
	} while (option != 'M');

	//return to main menu
	return;

}

void NODE::deleteRecord(NODE*& head, NODE*& tail) {

	//clear console and set console to white
	system("cls");
	system("color 7");

	uint16_t i_DeleteID = 0;
	char option;

	//get ID from user to delete record

	std::cout << "Enter ID# to delete: ";

	do {
		std::cin >> i_DeleteID;
	} while (i_DeleteID == 0);

	//if DB is not empty
	if (head != nullptr) {

		NODE* temp = head;

		while (true) { //traverse nodes
			//if current node is node user wants to delete
			if (temp->getID() == i_DeleteID) {
				temp->getBLink()->setFLink(temp->getFLink()); //connect previous and next nodes together
				temp->getFLink()->setBLink(temp->getBLink());

				//if node to delete is the first node, move head to the next node
				if (head == temp) {
					//if only 1 node in list and deleting then head and tail = null
					if (head->getFLink() == head) {
						head = nullptr;
						tail = nullptr;
					}
					else { //else head = next node
						head = head->getFLink();
					}
				}

				//delete the node to prevent memory leaks

				delete temp;

				//output successfull and get user to enter M for main menu
				std::cout << "\nSuccessfully Deleted\n";

				std::cout << "[M]ENU\nOption: ";
				do {
					std::cin >> option;
				} while (option != 'M');

				//return 
				return;
				break;
			}

			//traverse the nodes looking for id
			temp = temp->getFLink();

			//if looked through all nodes and didn't find then break out 
			if (temp == head)
				break;
		}
	}

	//output couldnt find node and get user to Enter M for main menu
	std::cout << "\nRecord Not Found\n";

	std::cout << "[M]ENU\nOption: ";
	do {
		std::cin >> option;
	} while (option != 'M');

	return;
}



_MENUOPTION mainMenu() {
	//clear console and set color to white
	system("cls");
	system("color 7");

	/* list options user can select */
	std::cout << "Main Menu\n";
	std::cout << "[A]dd     Record\n";
	std::cout << "[R]emove  Record\n";
	std::cout << "[U]pdate  Record\n";
	std::cout << "[D]isplay Record\n";
	std::cout << "[E]xit\n";
	std::cout << "Option: ";

	//get choice
	char choice;

	do {
		std::cin >> choice;
	} while (choice == NULL);

	/* return user's choice */
	switch (choice) {
	case 'A': return ADD; break;
	case 'R': return DEL; break;
	case 'U': return UPDATE; break;
	case 'D': return DISPLAY; break;
	case 'E':
	default:
		return EXIT; break;

	}

}