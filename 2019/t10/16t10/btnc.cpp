#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class node {
public:
	int data;
	node *link;
	node();
	node(int d);
};

node::node() {
	data = -1;
	link = NULL;
};

node::node(int d) {
	data = d;
	link = NULL;
};

class stack {
private:
	node *pHead;
	int count;
public:
	stack();

	void push(int d);

	node *pop();

	int top();

	bool isEmpty();

	bool isFull();

	int size();

	~stack();
};

stack::stack() {
	pHead = NULL;
	count = 0;
};

void stack::push(int d) {
	if (pHead == NULL)
	{
		pHead = new node(d);
		if (pHead != NULL)
			++count;
	}
	else
	{
		node *pTemp = pHead;
		pHead = new node(d);
		if (pHead != NULL)
		{
			pHead->link = pTemp;
			++count;
		}
	}
};

node* stack::pop() {
	if (pHead != NULL)
	{
		node *pTemp = pHead;
		pHead = pHead->link;
		pTemp->link = NULL;
		--count;
		return pTemp;
	}
	return NULL;
};

int stack::top() {
	if (pHead != NULL)
		return pHead->data;
	return -1;
};

bool stack::isEmpty() {
	if (pHead == NULL)
		return true;
	return false;
};

bool stack::isFull() {
	node *pTemp = new node();
	if (pTemp == NULL)
	{
		delete pTemp;
		return true;
	}
	return false;
};

stack::~stack() {
	node *pTemp;
	while (pHead != NULL)
	{
		pTemp = pHead;
		pHead = pHead->link;
		delete pTemp;
	}
};

int stack::size() {
	return count;
};

bool isExpressionBalanced(string input) {
    stack *s = new stack;
    for (int i=0; i<input.length(); i++)
    {

        if      ((input[i] == ')' || input[i] == ']' || input[i] == '}') && s->isEmpty()) return false;
        else if ( input[i] == '(' || input[i] == '[' || input[i] == '{') s->push(input[i]);
        else if ((input[i] == ')' && s->top() == '(')||
                 (input[i] == ']' && s->top() == '[')||
                 (input[i] == '}' && s->top() == '{')  ) s->pop();
        else    return false;
    }
    return s->isEmpty();
}

int main()
{

return 0;
}