#include "StackL.h"

StackL::StackL()
{
	head = nullptr;
	count = 0;
}

bool StackL::empty()
{
	return head == nullptr;
}

size_t StackL::size()
{
	return count;
}

void StackL::push(TInfo elem)
{
	ptrNODE newNODE = new NODE(elem, head);
	head = newNODE;
	count++;
	std::cout << "Ёлемент " << newNODE->info << " был добавлен в стек\n";

}

void StackL::pop()
{
	if (empty())
		std::cout << "Stack is empty!\n";
	else
	{
		ptrNODE tmp = head;
		head = head->next;
		std::cout << "Ёлемент "<< tmp->info <<" удален из стека\n";
		delete tmp;
		count--;
	}
}

TInfo StackL::top()
{
	if (!empty())
		return head->info;
	else
		std::cout << "ERROR!\n";
}

void StackL::view()
{

	if (!empty())
	{
		ptrNODE tmp = head;
		while (tmp)
		{
			std::cout << tmp->info << ' ';
			tmp = tmp->next;
		}
	}
	else
		std::cout << "Stack is empty!\n";
}

void StackL::clear()
{
	while (!empty())
	{
		pop();
	}
}

StackL::~StackL()
{
	clear();
	delete head;
}
