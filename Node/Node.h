#pragma once
#include <iostream>		//console window
#include <Windows.h>	//console color
#include <string>		//strings
#include <math.h>		//abs

//enum for better readability on options
enum _MENUOPTION {
	ADD,
	DEL,
	UPDATE,
	DISPLAY,
	EXIT
};

//Main Menu of Student Records
_MENUOPTION mainMenu();

class NODE {			//NODE struct // INFO on STUDENT

private:

	//student Records

	uint16_t  i_Age;
	uint16_t  i_Grade;
	uint16_t  i_ID;

	std::string s_name;

	//Next and Prev Nodes

	NODE* fLink = nullptr;
	NODE* bLink = nullptr;

public:

	//Constructor
	NODE(uint8_t age, uint8_t grade, uint16_t id, char* name) : i_Age(age), i_Grade(grade), i_ID(id), s_name(name) { }

	/* GETTERS */
	uint16_t	getID() const { return this->i_ID; }
	uint16_t	getAge() const { return this->i_Age; }
	uint16_t	getGrade() const { return this->i_Grade; }
	std::string	getName() const { return this->s_name; }

	/* SETTERS */
	void setID(uint16_t newId) { this->i_ID = newId; }
	void setAge(uint16_t newAge) { this->i_Age = newAge; }
	void setGrade(uint16_t newGrade) { this->i_Grade = newGrade; }
	void setName(const std::string& newName) { this->s_name = newName; }

	/* GETTERS FOR NEXT AND PREV NODE */
	NODE* getFLink() const { return this->fLink; }
	NODE* getBLink() const { return this->bLink; }

	/* SETTERS FOR NEXT AND PREV NODE */
	void setFLink(NODE* link) { fLink = link; }
	void setBLink(NODE* link) { bLink = link; }

	/* Functions to manipulate student records*/
	void AddRecord(NODE*& head, NODE*& tail);
	void updateRecord();
	void displayRecord();
	void deleteRecord(NODE*& head, NODE*& tail);


};