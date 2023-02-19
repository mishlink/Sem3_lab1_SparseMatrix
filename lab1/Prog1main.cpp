#define __CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW


#include <iostream>
#include "Prog1.h"


using namespace Prog1;


int main()
{
	int k = 0;
 	Table* table = NULL;
	Table* new_table = NULL;

	table = input();
	if (!table) {
		std::cout << "incorrect data" << std::endl;
		_CrtDumpMemoryLeaks();
		return 1;
	}
	new_table = change(table);

	output("Sourced matrix", table);
	output("Sourced matrix2", new_table);
	erase(table);
	erase(new_table);

	_CrtDumpMemoryLeaks();
	return 0;
}