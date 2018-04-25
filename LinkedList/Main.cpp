#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "List.h"
#include <iostream>

int main()
{
	element_of_list* list=0;
	int v;
	char x = 'x';
	printf("[p] - print list, [d] - deleting from list, [i] - inserting to list, [l] - length of list, [s] - search in list, [e] - exit\n");
	while (x != 'e')
	{
		printf("enter command: ");
		cin >> x;
		if (x == 'p') PrintList(list);
		else if (x == 'd')
		{
			printf("Enter the value: ");
			scanf("%d", &v);
			list = Delete(list, v);
		}
		else if (x == 'i')
		{
			printf("Enter the value: ");
			scanf("%d", &v);
			list=Insert(list, v);
		}
		else if (x == 'l')
		{
			printf("The length of the list: ");
			printf("%d\n", Length(list));
		}
		else if (x == 's')
		{
			printf("Enter the value: ");
			scanf("%d", &v);
			element_of_list* target = Search(list, v);
			if (target) cout << target->value << endl;
		}
	}
	return 0;
}
