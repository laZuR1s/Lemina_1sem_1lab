#pragma once

const size_t MaxSize = 100;
using TInfo = int;
using Array = TInfo[MaxSize];

struct StackV
{
private:
	Array elements;
	int head;
public:
	StackV();
	bool empty();
	size_t size();
	bool full();
	void push(TInfo elem);
	void pop();
	TInfo top();
	void view();
	void clear();
};