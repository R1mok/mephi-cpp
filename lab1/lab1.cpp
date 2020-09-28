#include <iostream>
#include "Prog1.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
using std::cout;
using std::cin;
using std::endl;

namespace Prog1
{
#ifdef _DEBUG // нужно для того, чтобы проверять утечки памяти
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif
	Line* erase(Line*& lines, int m)
	{
		for (int i = 0; i < m; i++)
		{
			element* el = lines[i].el;
			while (el)
			{
				element* cur = el;
				el = el->next;
				delete cur;
			}
		}
		delete[] lines;
		return nullptr;
	}

	Line* input_element(Line*& lines, int i)
	{
		const char* pr;
		pr = "";
		int index = 0;
		do {
			cout << pr << endl;
			pr = "You are wrong; repeat please!";
			cout << "Enter index of item: ";
		} while (getNum(index) < 0);

		if (lines[i].el->val == NULL) // вставляется первый элмемент
		{
			double value;
			pr = "";
			do {
				cout << pr << endl;
				pr = "You are wrong; repeat please!";
				cout << "Enter value" << endl;
			} while (getNum(value) < 0);
			lines[i].el->j = index;
			lines[i].el->val = value;
			lines[i].el->next = nullptr;
		}
		else // если в строке уже есть элементы
		{
			element* el, * pred;
			el = lines[i].el;
			pred = el;
			while (el && index > el->j)
			{
				pred = el;
				el = el->next;
			}
			if (el && index == el->j) // если в строке уже есть элемент с таким индексом
			{
				cout << "Error. Duplicate of values" << endl;
				return nullptr;
			}
			element* NewEl;
			NewEl = DBG_NEW element;
			if (pred == el)
			{
				NewEl->next = pred;
				lines[i].el = NewEl;
			}
			else
			{
				NewEl->next = pred->next;
				pred->next = NewEl;
			}
			NewEl->j = index;
			double value;
			pr = "";
			do {
				cout << pr << endl;
				pr = "You are wrong; repeat please!";
				cout << "Enter value" << endl;
			} while (getNum(value) < 0);
			NewEl->val = value;
		}
	}

	Line* input_in_line(Line* &lines, int i)
	{
		const char* pr;
		pr = "";
		do {
			cout << pr << endl;
			cout << "Enter number of items in line #" << (i + 1) << " --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(lines[i].n) < 0) {
				erase(lines, i); // освободить занятую память
				return nullptr;
			}
		} while (lines[i].n < 1);

		try {
			lines[i].el = DBG_NEW element;
			lines[i].el->val = NULL;
			lines[i].el->next = nullptr;
		}
		catch (std::bad_alloc& ba) {
			cout << "------ too many items in matrix: " << ba.what() << endl;
			erase(lines, i);
			return nullptr;
		}
		pr = "";
		int count = 0;
		do {
			cout << pr << endl;
			pr = "You are wrong; repeat please!";
			cout << "Enter the count of items you want to insert in the row" << endl;
		} while ((getNum(count) < 0) || (count > lines[i].n));
		//cout << "Enter items for matrix line #" << (i + 1) << ":" << endl;
		for (int j = 0; j < count; ++j)
		{
			input_element(lines, i);
		}
	}

	Line* create_matrix(int& rm) // разбить функцию (добавление элемента)
	{
		const char* pr = ""; //  будущее сообщение об ошибке
		Line* lines = nullptr; // массив строк
		int m; // количество строк
		do {
			cout << pr << endl;
			cout << "Enter number of lines: --> ";
			pr = "You are wrong; repeat please!";
			if (getNum(m) < 0)
				return nullptr;
		} while (m < 1);
		try {
			lines = DBG_NEW Line[m];
		}
		catch (std::bad_alloc& ba) {
			cout << "------ too many rows in matrix: " << ba.what() << endl;
			return nullptr;
		}
		for (int i = 0; i < m; i++)
			input_in_line(lines, i);
		rm = m;
		return lines;
	}
	void output(const char* msg, Line* a, int m)
	{
		int i;
		cout << msg << ":\n";
		for (i = 0; i < m; ++i) 
		{
			element* el = a[i].el;
			if (el->val == NULL)
				continue;
			while (el != nullptr)
			{
				cout <<  el->j << ": " << el->val << " ";
				el = el->next;
			}
			cout << endl;
		}
	}
	void New_matrix(Line*& lines, int m) // выполнить преобразовании матрицы
	{
		for (int i = 0; i < m; ++i)
		{
			double max_el = -10e7, min_el = 10e7, ep = 10e-7;
			element* El = lines[i].el;
			while (El)
			{
				if (El->val - ep > max_el)
				{
					max_el = El->val;
				}
				if (El->val < min_el - ep)
				{
					min_el = El->val;
				}
				El = El->next;
			}
			El = lines[i].el;
			while (El)
			{
				if (fabs(El->val - max_el) <= ep)
				{
					El->val = min_el;
				}
				else if (fabs(El->val - min_el) <= ep)
				{
					El->val = max_el;
				}
				El = El->next;
			}
		}
		output("Changed matrix", lines, m);
	}
}

using namespace Prog1;

int main()
{
	setlocale(LC_ALL, "Russian");
	Line* arr = nullptr;
	int m;
	arr = create_matrix(m);
	if (!arr)
	{
		cout << "Incorrect data" << endl;
		return 1;
	}

	output("Sourced matrix", arr, m);
	New_matrix(arr, m); // преобразование матрицы
	erase(arr, m); // освобождение памяти
	_CrtDumpMemoryLeaks();
	return 0;
}
