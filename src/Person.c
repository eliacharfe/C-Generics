#include "Person.h"

void fillPersons(Person persons[])
{   // initiate all persons
	for (int i = 0; i < ARR_SIZE; i++) {  // empty char arrays on names
		memset(persons[i].m_name, ' ', 15);
		persons[i].m_name[15] = '\0';
	}

	fillPerson(&persons[0], 302278338, '2');
	fillPerson(&persons[1], 204455676, '5');
	fillPerson(&persons[2], 391116872, '1');
	fillPerson(&persons[3], 436489555, '7');
	fillPerson(&persons[4], 236489515, '9');
}
//-------------------------------------
void fillPerson(Person* person, unsigned int id, unsigned char age)
{ // initiate 1 person
	person->m_id = id;
	person->m_age = age;

	int r = rand() % (NAME_ARR_SIZE);
	for (int i = 0; i < r; i++) {
		r = rand() % 26;
		char c = (char)('a' + (char)r);
		if (i == 0)
			c = (char)toupper(c);
		person->m_name[i] = c;
	}
}
//-------------------------------
void printPersons(Person persons[])
{ // print all persons
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("id: %d\nage: %c\nname: ", persons[i].m_id, persons[i].m_age);

		for (int j = 0; j < 16; j++)
			printf("%c", persons[i].m_name[j]);
		printf("\n\n");
	}
	printf("=================================================\n");
}
