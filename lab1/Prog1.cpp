


#include "Prog1.h"
#include <iostream>


namespace Prog1{
	int getNum(int& a)
	{
		std::cin >> a;
		if (std::cin.good() == false)
			return -1;
		return 1;
	}
	Table* input() {
		const char* pr = "";
		Table* table = new Table;
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of lines: ";
			pr = "You are wrong; repeat please!";
			if (getNum(table->m) < 0) {
				delete table;
				return NULL;
			}
		} while (table->m < 1);
		pr = "";
		do {
			std::cout << pr << std::endl;
			std::cout << "Enter number of items in lines: ";
			pr = "You are wrong; repeat please!";
			if (getNum(table->n) < 0) {
				delete table;
				return NULL;
			}
		} while (table->n < 1);

		table->line_no_zero = new int[table->m];
		int val;
		int k = 0;
		for (int i = 0; i < table->m; i++) {
			pr = "";
			std::cout << "Enter items for matrix line #" << (i + 1) << ":" << std::endl;
			for (int j = 0; j < table->n; j++) {
				if (getNum(val) < 0) {
					erase(table);
					return NULL;
				}
				if (val != 0)
				{
					table->val.push_back(val);
					table->column.push_back(j);
					k++;
				}
			}
			table->line_no_zero[i] = k;
		}
		return table;
	}
	void output(const char* msg, Table* a)
	{
		int i, j, k = 0;
		std::cout << msg << ":\n";
		for (i = 0; i < a->m; ++i) {
			int p = 0;
			for (j = 0; j < a->n; ++j)
				if (k < a->line_no_zero[i] && a->column[k] == j) {
					std::cout << a->val[k] << " ";
					k++;
				}
				else {
					std::cout << 0 << " ";
				}
			std::cout << std::endl;
		}
	}

	Table* erase(Table*& table)
	{
		delete[] table->line_no_zero;
		table->column.clear();
		table->val.clear();
		delete table;
		return NULL;
	}

	Table* change(Table* a) {
		Table* new_table = new Table;
		new_table->m = a->m;
		new_table->n = a->n;

		std::vector <int>::iterator iter;

		int p = 0;
		for (iter = a->column.begin(); iter != a->column.end(); iter++)
		{
			new_table->column.push_back(a->column[p]);
			p++;
		}

		p = 0;
		for (iter = a->val.begin(); iter != a->val.end(); iter++)
		{
			new_table->val.push_back(a->val[p]);
			p++;
		}

		new_table->line_no_zero = new int[a->m];

		for (p = 0; p < a->m; p++)
		{
			new_table->line_no_zero[p] = a->line_no_zero[p];
		}

		for (int i = a->m - 1; i >= 0; i--)
		{
			int j = a->line_no_zero[i] - 1;
			int last_sum = a->val[j];
			while (i == 0 && j >= 0 || i > 0 && j >= a->line_no_zero[i - 1])
			{
				if (sum(a->val[j]) != last_sum){
					for (int t = i; t < new_table->m; t++) {
						new_table->line_no_zero[t]--;
					}
					new_table->val.erase(new_table->val.begin() + j);
					new_table->column.erase(new_table->column.begin() + j);
				}
				j--;
			}
		}
		return new_table;
	}
	int sum(int a) {
		int s = 0;
		while (a > 0)
		{
			s += a % 10;
			a /= 10;
		}
		return s;
	}
}

