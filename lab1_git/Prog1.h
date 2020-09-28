namespace Prog1
{
	struct element
	{
		double val; // значение
		int j; // номер элемента в строке
		struct element* next; // указатель на следующий элемент в строке
	};
	struct Line
	{
		int n; // количество элементов в строке
		element* el; // указатель на элемент
	};

	template <class T>
	int getNum(T& a)
	{
		std::cin >> a;
		if (!std::cin.good())
			return -1;
		return 1;
	}

	Line* input(int&);
	void output(const char*, Line a[], int);
	Line* erase(Line*&, int);
	void New_matrix(Line*&, int);
}
