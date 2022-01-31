/* implements expanding storage as linked list 
   adds at front

*/

#include "list.h"

list::list(void) {
 thelist = NULL;
 size = 0;
}


void list::push(string x) { /* 'list' turns to 'x + list' */

  list_item *n;

  n = new list_item;
  n->info = x;
  n->next = thelist;
  thelist = n;
  size++;
//   cout << "list after pushing\n";
//   printlist(list);
}


string list::pop(void) { /* 'x + list' turns to 'list' */
  string x;
  list_item *tail;
  x = thelist->info;
  tail = thelist->next;
  delete thelist;
  thelist = tail;
  size--;
  return x; 
}

void list::other_print()
{
    other_print(thelist);
    cout << endl;
}

void list:: other_print(list_item* x)
{
    if (x == NULL)
    {
        cout << "||";
    }
   
    else
    {
        printlist(x -> next);
        cout << " <-- " << x->info;
    }
}

void list::printlist(list_item *x) {
  if (x == NULL) {
    cout << "||";
  }
  else {
    cout << x->info << " --> ";
    printlist(x -> next);
  }


}

void list::printlist()
{
    for (list_item* ptr = thelist; ptr != NULL; ptr = ptr->next)
    {
        cout << ptr->info << " --> ";
    }
    cout << "||" << endl;
}

int list::count(string x)
{
    int result = 0;

    for (list_item* ptr = thelist; ptr != NULL; ptr = ptr->next)
    {
        if (ptr->info == x)
        {
            result++;
        }
    }

    return result;
}

bool list::bottom(string& s)
{
    if (size != 0)
    {
        for (list_item* ptr = thelist; ptr != NULL; ptr = ptr->next)
        {
            if (ptr->next == NULL)
            {
                s = ptr->info;
                return true;
            }
        }

        return false;
    }

    return false;
}


list::~list() {
  cout << "calling empty via the destructor\n";
  empty();
}

void list::empty() {
  for(int i = size; i>0; i--) {
    pop();
  }
}