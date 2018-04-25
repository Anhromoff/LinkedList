#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct element_of_list 
{
	int value; 
	element_of_list* next_element; // pointer to the next element

	// default constructor
	element_of_list()
	{
		next_element = 0;
	}

	// constructor with value
	element_of_list(int v)
	{
		value = v;
		next_element = 0;
	}
};

// Printing the list
void PrintList(element_of_list* first_element) 
{
	// head of list is null
	if (!first_element) 
	{
		printf("The list is empty!\n");
		return; 
	}
	else
	{
		printf("List:\n");
		element_of_list* current_element = first_element; // start from the first element

		// going through the whole list and printing values
		while (current_element) 
		{
			printf("%d ", current_element->value); 
			current_element = current_element->next_element; // next element becomes current
		}
		printf("\n");
	}
}

element_of_list* Delete(element_of_list* first_element, int v)
{
	if (!first_element)
	{
		cout << "list is empty" << endl;
		return 0;
	}
	else
	{
		// deleting first element
		if (first_element->value == v)
		{
			element_of_list* temp = first_element;
			first_element=first_element->next_element; // second element becomes first
			delete temp;
			return first_element;
		}
		// deleting inner element
		else
		{
			element_of_list* iter = first_element;

			// searching for the value
			while (iter->next_element)
			{
				if (iter->next_element->value == v)
				{
					element_of_list* temp = iter->next_element;
					iter->next_element = iter->next_element->next_element; // pointer to next becomes pointer to next after the next
					delete temp;
					return first_element;
				}
				iter = iter->next_element;
			}
		}
		cout << "not found" << endl;
		return first_element;
	}
}

element_of_list* Insert(element_of_list* first_element, int v)
{ 
	if (!first_element) return new element_of_list(v);
	else
	{
		element_of_list* iter = first_element;
		while (iter->next_element) iter = iter->next_element;
		iter->next_element = new element_of_list(v);
		return first_element;
	}
}

// counting length of the list
int Length(element_of_list* first_element) 
{
	int l = 0; //counter

	if (!first_element) 
	{
		return 0;
	}
	else
	{
		element_of_list* current_element = first_element; 
										 
		while (current_element) // пока не дойдем до конца списка
		{
			l++;
			current_element = current_element->next_element; // следующий элемент списка становится текущим
		}
		return l;
	}
}

// searching for element with value v
element_of_list* Search(element_of_list* first_element,int v)
{
	if (!first_element)
	{
		cout << "list is empty" << endl;
		return 0;
	}
	else
	{
		element_of_list* iter = first_element;
		if (iter->value == v) return iter;
		else
		{
			while (iter->next_element)
			{
				if (iter->next_element->value == v) return iter->next_element;
				iter = iter->next_element;
			}
			cout << "not found" << endl;
			return 0;
		}
	}
}

#endif
