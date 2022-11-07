#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define EMPTY_LIST NULL

typedef struct cstd_list_s {
  char *data;
  struct cstd_list_s *next;

  struct cstd_list_s *(*push_back)(struct cstd_list_s *, const char *);
  struct cstd_list_s *(*push_front)(struct cstd_list_s *, const char *);

  int (*len)(struct cstd_list_s *);
  struct cstd_list_s *(*at)(struct cstd_list_s *, size_t);
  
  struct cstd_list_s *(*pop_front)(struct cstd_list_s *);
  struct cstd_list_s *(*pop_back)(struct cstd_list_s *);
} clist;

clist *new_clist(const char *d);
int clist_destroy(clist *l);

void clist_display(clist *l);

clist *cstd_list_pop_front(clist *l);
clist *cstd_list_pop_back(clist *l); 

clist *cstd_list_push_front(clist *l, const char *d); 
clist *cstd_list_push_back(clist *l, const char *d); 

clist *cstd_list_at(clist *l, size_t index); 
int cstd_list_length(clist *l); 
int is_clist_empty(clist *l); 
