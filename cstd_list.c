#include "./cstd_list.h"

int is_clist_empty(clist *l)
{
    return (l == EMPTY_LIST ? 1 : 0);
}

int cstd_list_length(clist *l)
{
    int i;

    if (is_clist_empty(l)) {
        return (0);
    }
    for (i = 1; l->next != EMPTY_LIST; ++i, l = l->next);
    return (i);
}

clist *cstd_list_push_back(clist *l, const char *d)
{
    clist *save = l;

    if (is_clist_empty(l)) {
        return (EMPTY_LIST);
    }
    for (; l->next != EMPTY_LIST; l = l->next);
    l->next = new_clist(d);
    return (save);
}

clist *cstd_list_push_front(clist *l, const char *d)
{
    clist *new_node = new_clist(d);

    if (is_clist_empty(l)) {
        return (EMPTY_LIST);
    }
    if (!new_node) {
        return (l);
    }
    new_node->next = l;
    return (new_node);
}

clist *cstd_list_at(clist *l, size_t index)
{
    if (is_clist_empty(l)) {
        return (EMPTY_LIST);
    }
    for (size_t i = 0; l->next != EMPTY_LIST; ++i, l = l->next) {
        if (i == index) {
            return (l);
        }
    }
    return (EMPTY_LIST);
}

clist *cstd_list_pop_back(clist *l)
{
    char b = 'p';
    clist *save = l;

    write(1, &b, 1);
    if (is_clist_empty(l)) {
        return (EMPTY_LIST);
    }
    for (; l->next != EMPTY_LIST; l = l->next);
    free(l->data);
    return (save);
}

clist *cstd_list_pop_front(clist *l)
{
    clist *save = l->next;

    if (is_clist_empty(l))
      return (EMPTY_LIST);
    if (l->data != EMPTY_LIST) {
        free(l->data);
    }
    free(l);
    return (save);
}

void clist_display(clist *l)
{
    char *esp = ", ";

    while (l != EMPTY_LIST) {
        write(1, l->data, strlen(l->data));
        if (l->next == EMPTY_LIST) {
            break;
        }
        write(1, esp, 2);
        l = l->next;
    }
    putchar('\n');
}

clist *new_clist(const char *d)
{
    clist *new_node = malloc(sizeof(clist));

    if (!new_node) {
        return (EMPTY_LIST);
    }
    new_node->data = strdup(d);
    new_node->next = EMPTY_LIST;
    new_node->push_back = &cstd_list_push_back;
    new_node->push_front = &cstd_list_push_front;
    new_node->len = &cstd_list_length;
    new_node->pop_back = &cstd_list_pop_back;
    new_node->pop_front = &cstd_list_pop_front;
    new_node->at = &cstd_list_at;
    return (new_node);
}

// returns freed node number
int clist_destroy(clist *l)
{
    char a = 'a';
    char b = 'b';
    char c = 'c';

    size_t i = 0;
    for (i = 0; l != EMPTY_LIST; i++) {
        if (l->data != NULL) {
            write(1, &b, 1);
        }
        l = l->pop_front(l);
        write(1, &c, 1);
      }
      return (i);
}
