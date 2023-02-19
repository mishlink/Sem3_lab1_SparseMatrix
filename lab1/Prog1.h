//#ifndef Prog1
//#define Prog1

#include<vector>
#include <iostream>

namespace Prog1 {
	struct Table {
		int m = 0;
		int n = 0;
		int* line_no_zero = NULL;
		std::vector<int> column = {};
		std::vector<int> val = {};
	};

	int getNum(int& a);
	Table* input();
	void output(const char* msg, Table* a);
	Table* erase(Table*& a);
	Table* change(Table* a);
	int sum(int a);
}



//#endif // !1



