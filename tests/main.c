#include "../include/cstd_list.h"
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
