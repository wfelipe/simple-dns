

struct head
{
	struct head *next, *prev;
};

#define LIST_INIT(name) { &(name), &(name) }

#define LIST(name) \
	struct list name = LIST_INIT(name)

static inline void INIT_LIST (struct list *l)
{
	l->next = l;
	l->prev = l;
}

static inline void __list_add (struct list *new,
			       struct list *prev,
			       struct list *next)
{
	next->prev = new;
	new->next = next;
	new->prev = prev;
	prev->next = new;
}

static inline void list_add (struct list *new,
			     struct list *l)
{
	__list_add (new, head, head->next);
}
