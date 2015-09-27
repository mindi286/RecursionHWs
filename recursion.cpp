#include <iostream>
using namespace::std;

struct node
{
	int data;
	node * p;
};
int length(const char * p);
int lengthR(const char * p);
int length(const node * st);
int lengthR(const node * st);
int sum(const int *p, int howMany);
int sumR(const int * p, int howMany);
int sum(const node * st);
int sumR(const node * st);
int sum(const char *);   // sum ASCII values
int sumR(const char *);  // sum ASCII value
int max(const char *);
int maxR(const char *);
int max(const int *, int howMany);
int maxR(const int * p, int howMany);
int max(const node *);
int maxR(const node *);


int length(const char * p)
{
	int ans = 0;
	for (int i = 0; p[i]; i++)
	{
		ans++;
	}
	return ans;
}
int lengthR(const char * p)
{
	if (*p == '\0') return 0;
	return 1 + lengthR(p + 1); //the first 1 is yourself. (count everyone else plus yourself)
}

int length(const node * st)
{
	const node * walker = st;
	int ans = 0;
	while (walker !=NULL)
	{
		walker = walker->p;
		ans++;
	}
	return ans;
}
int lengthR(const node * st)
{
	if (st == NULL) return 0;
	return 1 + lengthR(st->p); //can NEVER do ++ cuz it doesn't follow in a line like an array
}

int sum(const int *p, int howMany)
{
	int ans = 0;
	if (howMany == 0) return 0;
	for (int i = 0; i < howMany; i++)
	{
		ans = ans + p[i]; //i is the offset
	}
	return ans;
}
int sumR(const int * p, int howMany)
{
	if (*p == '\0') return 0;
	return 1 + sumR(p + howMany, howMany);
}

int sum(const node * st)
{
	const node * walker = st;
	int ans = 0;
	while (walker != NULL)
	{
		ans = ans + walker->data;
		walker = walker->p;
	}
	return ans;
}
int sumR(const node * st)
{
	if (st == NULL) return 0;
	return 1 + sumR(st->p);
}

int sum(const char *)   // sum ASCII values
{

}
int sumR(const char *)  // sum ASCII value
{

}

int max(const char *)
{

}
int maxR(const char *)
{

}

int max(const int *, int howMany)
{

}
int maxR(const int * p, int howMany)
{
	if (*p == '\0') return 0;
	return 1 + sumR(p + howMany, howMany);
}

int max(const node *)
{

}
int maxR(const node *)
{

}

void makeLinkedList(node * & start);
void printLinkedList(ostream &, const node *);
void deleteLinkedList(node *);

void main()
{
	cout << length("abcdefgh") << endl;
	cout << lengthR("abcd") << endl;
	node * st;	
	makeLinkedList(st);
	cout << st->p->p->data << endl; //arrow over to the 3rd step but instead of ->p need to ->data so it shows the data, not the address.
	cout << lengthR(st) << endl;
	printLinkedList(cout,st);
	
	deleteLinkedList(st);

}


void makeLinkedList(node * & start)
{
	//  make the linked list 7 -> 12 -> 6 -> 15 -> 3
	start = new node;
	start->data = 7;
	start->p = new node;
	start->p->data = 12;
	start->p->p = new node;
	start->p->p->data= 6;
	start->p->p->p = new node;
	start->p->p->p->data= 15;
	start->p->p->p->p= new node;
	start->p->p->p->p->data= 3;
    start->p->p->p->p->p= NULL;

}

void printLinkedList(ostream & out, const node * s)
{
	const node * walker = s;
	while ( walker != NULL)
	{
        out << walker->data << " ";
		walker = walker->p;
	}
	out << endl;
}

void deleteLinkedList(node *s)
{
	if ( s == NULL ) return; // 0 nodes
	if ( s->p == NULL )      // 1 node
	{
		delete s;
		return;
	}
	node * prev = s;
	node * current = prev->p;
	while ( current != NULL )
	{
       cout << "deleting " << prev-> data << endl;
       delete prev;
	   prev = current;
	   current = current->p;
	}
	cout << "deleting " << prev-> data << endl;
    delete prev;
	cout << "decestructor leaving " << endl;
}