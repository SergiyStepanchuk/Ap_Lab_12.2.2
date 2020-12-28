// Lab_12_2_2
#include <iostream>
using namespace std;

struct S {
	S* next = nullptr;
	int num;
};

void list_factory(const int &count, S *next, int i = 0) {
	cout << "Input " << i << " num: "; cin >> next->num; 
	i++;
	if (i < count)
	{
		next->next = new S();
		list_factory(count, next->next, i);
	}	
}

void list_draw(const S* list) {
	cout << list->num << endl;
	if (list->next != nullptr)
		list_draw(list->next);
}

void list_swap_custom(S *&cur, S *&previous) {
	swap(cur, previous);
	swap(previous->next, cur->next);

	if (cur->next->next && cur->next->next->next)
		list_swap_custom(cur->next->next, cur->next->next->next);
}

void delete_list(S* &list) {
	if (list->next)
		delete_list(list->next);
	delete list;
	list = nullptr;
}

void main() {
	int size;
	cout << "Input list size: "; cin >> size;
	S* start = new S();
	list_factory(size, start);
	list_draw(start);
	list_swap_custom(start, start->next);
	cout << endl;
	list_draw(start);
	delete_list(start);
}