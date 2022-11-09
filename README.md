# cstd_list
C Linked lists can be hard sometimes. Why not just having a std::list that allocates everything for us ?

Here is an implementation of the std::list\<std::string\> c++ equivalent (for `char *` only)

## Usage

Here is a minimal usage example :

```c
#include "cstd_list.h"
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac < 2) {
        perror("Empty list");
        return (1);
    }

    clist *list = new_clist(av[1]);

    for (int i = 2; i < ac; ++i) {
        list->push_back(list, av[i]);
    }

    clist_display(list);
    clist_destroy(list);
    return (0);
}
```

```bash
>> ./a.out hello everyone I love C
hello, everyone, I, love, C
```

## Methods

Those are the methods integrated in a `clist` object :
```c
// adds data to the end of current_list
clist *push_back(clist *current_list, const char *data);

// adds data to the front of current_list
clist *push_front(clist *current_list, const char *data);

// returns the length of current_list
int len(clist *current_list);

// returns the index' node of current_list
clist *at(clist *current_list, size_t index);

// removes the front node of current_list
clist *pop_front(clist *current_list);

// removes the back node of current_list
clist *pop_back(clist *current_list);
```

Here are the functions provided by the lib :
```c
// creates a new list with the first node containing data
clist *new_clist(const char *data);

// frees the entire current_list and returns the number of freed nodes
int clist_destroy(clist *current_list);

// display each node of current_list
void clist_display(clist *current_list);

// returns true if current_list is empty
int is_clist_empty(clist *current_list);
```

## The structure

Here is the main `clist` object :
```c
typedef struct cstd_list_s {
    // variables
    char *data;                 // contains the main std::string object
    struct cstd_list_s *next;   // ptr to next node

    // methods
    // see previous chapter
} clist;
```

To access the data, just call the `data` property :
```c
int main(void) {
    char *a = "hello";
    clist *list = new_node(a);

    printf("%s\n", list->data);
    return (0);
}
```

