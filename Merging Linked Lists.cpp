#include <iostream>
#include <string>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct node
{
	float info;
	node* next;
};
node* l1;
node* l2;
node* head1, *head2;
node* temp1, *temp2;
struct node* listJoin(struct node* a, struct node* b);
void Insertl1();
void Clear();
void Insertl2();
void Display();
void Insert();
void Remove();
void Append();
int main()
{
	node* l1;
	l1 = new node;
	node* l2;
	l2 = new node;
	cout << "Add info in LinkedList1: "; // Initializing Data in L1
	cin >> l1->info;
	l1->next = NULL;
	temp1 = l1;
	head1 = l1;

	cout << "\nAdd info in LinkedList2: "; // Initializing Data in L2
	cin >> l2->info;
	l2->next = NULL;
	temp2 = l2;
	head2 = l2;
	node* n;
	system("cls");
	char op;
	do
	{
		cout << "1. Add info in Linked List 1\n";
		cout << "\n2. Add info in Linked List 2\n";
		cout << "\n3. Merge lists\n";
		cin >> op;
		system("cls");
		switch (op)
		{
		case '1':
			Insertl1();
			break;
		case '2':
			Insertl2();
			break;

		case '3':
			n = listJoin(l1, l2);
			cout << "Lists have merged into a big one\n";
			do
			{

				cout << "\n1. Add info\n";
				cout << "\n2. Display\n";
				cout << "\n3. Remove\n";
				cout << "\n4. Exit\n";
				cin >> op;
				system("cls");
				switch (op)
				{
				case '1':
					Append();
					break;
				case '2':
					Display();
					break;
				case '3':
					Remove();
					break;

				case '4':
					cout << "Are you sure you want to exit?(y/n)\t";
					cin >> op;
					if (op == 'y')
						return false;
					else
						break;
				default:
					cout << "Choose from the following\n";
				}
			} while (true);
		default:
			cout << "Choose from the following\n";
		}
	} while (true);
	
}

struct node* listJoin(node* a, node* b)
{
	node* n;
	a = head1;
	while (a->next != NULL)
		a = a->next;
	b = head2;
	a->next = b;
	n = head1;
	return n;
}
void Insertl1()
{
	l1 = new node;
	cout << "Add info: ";
	cin >> l1->info;
	l1->next = NULL;
	temp1->next = l1;
	temp1 = l1;
}
void Insertl2()
{
	l2 = new node;
	cout << "Add info: ";
	cin >> l2->info;
	l2->next = NULL;
	temp2->next = l2;
	temp2 = l2;
}
void Display()
{
	cout << "Displaying info\n";
	temp1 = head1;
	while (temp1 != NULL)
	{
		cout << temp1->info << endl;
		temp1 = temp1->next;
	}
	Clear();
}
void Remove()
{
	cout << "\nRemoving\n";
	temp1 = head1;
	if (temp1 == NULL)
	{
		cout << "There is nothing left to remove\n";
		return;
	}
	temp2 = head1->next;
	cout << "1. Remove by node number\n";
	cout << "2. Remove by node info\n";
	float nodenum, nodeinfo;
	int op;
	cin >> op;
	bool done = false;
	switch (op)
	{
	case 1:
		while (!done)
		{
			temp1 = head1;
			float count = 0;
			cout << "Which node do you want to remove? ";
			cin >> nodenum;
			if (nodenum == 0)
			{
				head1->next = temp2;
				head1 = temp2;
				delete(temp1);
				done = true;
			}
			else
			{
				while (temp1 != NULL)
				{
					temp1 = temp1->next;
					count++;
				}
				if (count > nodenum)
				{
					temp1 = head1;
					count = 1;
					while (count < nodenum)
					{
						temp1 = temp1->next;
						temp2 = temp2->next;
						count++;
					}
					temp1->next = temp2->next;
					delete(temp2);
					done = true;
					Clear();
				}
				else
				{
					cout << "Choose bewtween 0 and " << count-1 << endl;
				}
			}
		}
			break;
	case 2:
		cout << "Info of the node you want to remove: ";
		cin >> nodeinfo;
		if (nodeinfo == head1->info)
		{
			head1->next = temp2;
			head1 = temp2;
			delete(temp1);
			Clear();
			break;
		}
		else
		{
			while (temp2->info != nodeinfo)
			{
				temp1 = temp1->next;
				temp2 = temp2->next;
				if (temp2== NULL)
				{
					cout << "Info Not Found\n";
					Clear();
					return;
				}
			}
			temp1->next = temp2->next;
			delete(temp2);
		}
		Clear();
		break;
	}
}
void Append()
{
	cout << "\nAppending\n";
	node* n = new node;
	cout << "Data you want to write in the appended node: ";
	cin >> n->info;
	n->next = NULL;
	temp1 = head1;
	while (temp1->next != NULL)
	temp1 = temp1->next;
	temp1->next = n;
	temp1 = n;
	Clear();
}
void Insert()
{
	float nodenum, nodedata, count = 0;
	cout << "\nInserting\n";
	temp1 = head1;
	node* n = new node;
	cout << "At which node do you want to insert the node? ";
	cin >> nodenum;
	while (temp1 != NULL)
	{
		temp1 = temp1->next;
		count++;
	}
	if (count > nodenum)
	{
		temp1 = head1;
		count = 1;
		cout << "Data to be stored on this node: ";
		cin >> n->info;
		temp2 = head1->next;
		while (count != nodenum)
		{
			temp1 = temp1->next;
			temp2 = temp2->next;
			count++;
		}
		temp1->next = n;
		n->next = temp2;
	}
	else
	{
		cout << "Choose bewtween 0 and " << count - 1 << endl;
	}
	Clear();
}
void Clear()
{
	system("pause");
	system("cls");
}