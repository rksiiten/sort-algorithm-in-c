#include <stdio.h>

int list[5];
int max = sizeof(list) / sizeof(list[0]);

void swapsort(int list[], int n)
{
	int i, j, dummy;
	
	system("cls");
	
	printf("\t=====================\n");
	printf("\t=  SORT OPERATION   =\n");
	printf("\t=====================\n");
	
	for (i = 0; i < n-1; i++)
	{
		for (j = i+1; j < n; j++)
		{
			if (list[i]>list[j])
			{
				dummy = list[i];
				list[i] = list [j];
				list[j] = dummy;
			}
		}
	}
	printf("\n\tSorting of Data Complete...");
	printf("\n\n\tIncreasing Order of Data:\n\n\t");
	for(i=0; i < n; i++)
	{
		printf(" %d ", list[i]);
		printf("|");
	}
	printf("\n\n\tPress any key to continue...");
	getch();
}

int insert()
{
	int idx;
	int ins;
	int item;
	char q;
	
	system("cls");
	
	printf("\t====================\n");
	printf("\t= INSERT OPERATION =\n");
	printf("\t====================\n");
	
	printf("\n\tDo you want to insert a data (Y/N)? ");
	scanf(" %c", &q);
	
	if(q == 'Y' || q == 'y')
	{
		printf("\n\n\tLocation of data where you want to insert: ");
		scanf("%d", &ins);
		
		printf("\n\tEnter data: ");
		scanf("%d", &item);
		
		for(idx = max; idx > ins; idx--)
		{
			list[idx] = list[idx - 1];
		}
		list[ins] = item;
		max += 1;

		printf("\n\n\tInsertion of Data Complete...");
	}
	else
	{
		printf("\n\n\tPress any key to continue...");
	}
	getch();
}

int delete_data()
{
	int idx;
	int del;
	char q;
	
	system("cls");
	
	printf("\t====================\n");
	printf("\t= DELETE OPERATION =\n");
	printf("\t====================\n");
	
	printf("\n\tDo you want to delete a data (Y/N)? ");
	scanf(" %c", &q);
	
	if(q == 'Y' || q == 'y')
	{
		printf("\n\n\tLocation of data you want to delete: ");
		scanf("%d", &del);
		
		for(idx = del; idx < max-1 ; idx++)
		{
			list[idx] = list[idx + 1];
		}
		max--;

		printf("\n\n\tDeletion of Data Complete...");
	}
	else
	{
		printf("\n\n\tPress any key to continue...");
	}
	getch();
}

int replace()
{
	int idx;
	int item;
	char q;
	
	system("cls");
	
	printf("\t=====================\n");
	printf("\t= REPLACE OPERATION =\n");
	printf("\t=====================\n");
	
	printf("\n\tDo you want to replace a data (Y/N)? ");
	scanf(" %c", &q);
	
	if(q == 'Y' || q == 'y')
	{
		printf("\n\n\tLocation of data you want to replace: ");
		scanf("%d", &idx);
		
		printf("\n\tEnter data: ");
		scanf("%d", &item);
		
		list[idx] = item; // replace the item
		
		printf("\n\n\tReplacement of Data Complete...");
	}
	else
	{
		printf("\n\n\tPress any key to continue...");
	}
	getch();
}

int search()
{
	int idx;
	int item;
	
	system("cls");
	
	printf("\t====================\n");
	printf("\t= SEARCH OPERATION =\n");
	printf("\t====================\n");
	
	printf("\n\tEnter a data to search: ");
	scanf("%d", &item);
	
	for(idx=0; idx < max; idx++){
		if(item == list[idx]){
			return idx; 
		}
	}
	return -1; // not found
}

void add()
{
	int idx;
	system("cls");
	
	printf("\t=====================\n");
	printf("\t=   ADD OPERATION   =\n");
	printf("\t=====================\n");
	
	printf("\n\tPlease Enter your Data:\n\n");
	for(idx=0; idx < 5 ; idx++){
		printf("\tEnter Data[%d]: ", idx+1);
		scanf("%d", &list[idx]);
	}
	printf("\n\tEntry of Data Complete...");
	printf("\n\n\tPress any key to continue...");
	getch();
}

void print()
{
	int idx;
	system("cls");

	printf("\t===================\n");
	printf("\t= PRINT OPERATION =\n");
	printf("\t===================\n");
	
	printf("\n\tContent of the List:\n\n\t");
	
	for(idx=0; idx < max; idx++)
	{
		printf(" %d ", list[idx]);
		printf("|");
	}
	
	printf("\n\n\n\tPress any key to continue...");
	getch();
}

int main()
{
	char option;
	int searchResult;
	
	system("cls");
	for(;;)
	{
		system("cls");
		printf("\t << LIST OPERATIONS >>\n\n");
		
		printf("\t    ===============\n");
		printf("\t    || (A)dd     ||\n");
		printf("\t    || (P)rint   ||\n");
		printf("\t    || (S)earch  ||\n");
		printf("\t    || (R)eplace ||\n");
		printf("\t    || (D)elete  ||\n");
		printf("\t    || (I)nsert  ||\n");
		printf("\t    || (W)Sort   ||\n");
		printf("\t    || (E)xit    ||\n");
		printf("\t    ===============\n");
		
		printf("\n\n\tPlease Select Operation: ");
		scanf(" %c", &option);
		
		switch(option)
		{
			case 'A' : case 'a':
				add();
				break;
			case 'P' : case 'p':
				print();
				break;
			case 'S': case 's':
				searchResult = search();
				
				if (searchResult == -1)
				{
					printf("\n\tItem NOT FOUND!");
				}
				else
				{
					printf("\n\tItem FOUND!");
					printf("\n\tItem found at location: %d", searchResult);
				}
				printf("\n\n\n\tPress any key to continue...");
				getch();
				break;
			case 'R' : case 'r':
				replace();
				break;
			case 'D' : case 'd':
				delete_data();
				break;
			case 'I' : case 'i':
				insert();
				break;
			case 'W' : case 'w':
				swapsort(list, max);
				break;
			case 'E' : case 'e':
				return 0;
				break;
		}
	}
}
