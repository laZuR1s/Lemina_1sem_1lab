#pragma once

#include <iostream>

using TInfo = int;

struct NODE
{
	TInfo info;
	NODE* next;
	NODE(TInfo info, NODE* ptr = nullptr)
	{
		this->info = info;
		next = ptr;
	}
	~NODE()
	{
		next = nullptr;
	}
};

