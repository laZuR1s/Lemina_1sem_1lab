#include <iostream>
#include "StackL.h"
//#include "StackV.h"
#include <fstream>
#include <string>
#include<Windows.h>
#include<functional>

int formulaCalculate(std::string fileName, StackL st);

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message);
int main_menu();

int main()
{
	SetConsoleOutputCP(1251);
	StackL st;
	short mainMenuChoice = 1;
	do
	{
		mainMenuChoice=main_menu();
		if (mainMenuChoice == 1)
		{
			std::cout << "Введите элемент: ";
			int elem;
			validation(elem, [](int x) {return true; },"");
			st.push(elem);
		}
		else
			if (mainMenuChoice == 2)
			{
				st.pop();
			}
			else
				if (mainMenuChoice == 3)
				{
					st.clear();
					std::cout << "Стек полностью очищен\n";
				}
				else
					if (mainMenuChoice == 4)
					{
						std::cout << "Содержимое стека: ";
						st.view();
						std::cout << '\n';
					}
					else
						if (mainMenuChoice == 5)
						{
							std::cout << "Перед решением рекомендуется очистить стек, хотите это сделать?(+/-) \n";
							char c;
							validation(c, [](int x) {return true; }, "");
							if (c == '+')
							{
								st.clear();
								std::cout << "Стек полностью очищен\n\n";
							}

							std::cout<<"\nЧисловой ответ формулы: " << formulaCalculate("data.txt", st)<<'\n';
						}
	} while (mainMenuChoice != 6);

}

int formulaCalculate(std::string fileName, StackL st)
{
	std::ifstream file(fileName);

	//StackV st;
	char c;
	while (!file.get(c).eof())
	{
		if (c == 'M' || c == 'm' || c >= '0' && c <= '9')
		{
			st.push(c);
		}
		else
			if (c == ')')
			{
				char x = st.top(); st.pop();
				char y = st.top(); st.pop();
				char op = st.top(); st.pop();
				switch (op)
				{
				case 'M':
					if (x > y)
						st.push(x);
					else
						st.push(y);
					break;
				case 'm':
					if (x < y)
						st.push(x);
					else
						st.push(y);
					break;

				}
			}
	}
	file.close();
	int result = st.top() - '0';
	st.clear();
	return result;
}

template<typename T, typename Predicat>
void validation(T& x, Predicat condition, const char* message)
{
	std::cout << message << "\n>>> ";
	while (!(std::cin >> x && condition(x)))
	{
		std::cout << "Ошибка ввода!" << '\n';
		std::cin.clear();
		std::cin.ignore(std::cin.rdbuf()->in_avail());
		std::cout << message << "\n>>> ";
	}
}

int main_menu()
{
	std::cout << "\nМеню Стека\n";
	std::cout << "\n-----------------------------------------------------\n";
	std::cout << "1. Добавить элемент\n";
	std::cout << "2. Удалить элемет\n";
	std::cout << "3. Очистить\n";
	std::cout << "4. Просмотреть\n";
	std::cout << "5. Решить задачу\n";
	std::cout << "6. Выйти из программы\n";
	std::cout << "-----------------------------------------------------\n";

	std::function<bool(int)> foo;
	foo = [](int x)->bool {return x >= 1 && x <= 6; };
	int choice;
	validation(choice, foo, "");
	std::cin.ignore(std::cin.rdbuf()->in_avail());
	return choice;
}