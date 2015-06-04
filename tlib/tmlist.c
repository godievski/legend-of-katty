#include "tlib.h"

TMList *
t_mlist_new ()
{
  TMList *list;
  list = malloc (sizeof (TMList));
  list->start = NULL;
  list->end = NULL;
  list->length = 0;
}

int
t_mlist_get_length (TMList * list)
{
  return list->length;
}

tpointer
t_mlist_pop (TMList * list)
{
  TList *head;
  tpointer ret;
  if (list->start == NULL)
    return NULL;
  head = list->start;
  ret = head->data;
  list->start = head->next;
  list->start->prev = NULL;
  free (head);
  return ret;
}

void
t_mlist_prepend (TMlist * list, tpointer data)
{
  list->start = t_list_prepend (list->start, data);
}

void
t_mlist_append (TMList * list, tpointer data)
{
  TList * new_list;
  new_list = t_list_new ();
  new_list = t_list_prepend (new_list, data);
  if (list->end)
    list->end->next = new_list;
  else
    list->start = new_list;
  new_list->prev = list->end;
  list->end = new_list;
}
