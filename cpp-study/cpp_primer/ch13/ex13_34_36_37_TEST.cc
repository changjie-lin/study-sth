#include "ex13_34_36_37.h"

int main()
{
	Message firstMail("Hello World!");
	Message welcomeCpp("Welcome to C++ land!");
	Folder inbox;

	firstMail.print_debug();
	firstMail.save(inbox);
	inbox.print_debug();

	welcomeCpp.save(inbox);
	inbox.print_debug();

	Message hiAgain(firstMail); // copy constructor
	hiAgain.print_debug();
	firstMail.print_debug();

	hiAgain = welcomeCpp; // copy-assignment operator
	hiAgain.print_debug();
	firstMail.print_debug();
	inbox.print_debug();

	Folder archive;
	firstMail.save(archive);
	firstMail.remove(inbox);
	inbox.print_debug();

}
