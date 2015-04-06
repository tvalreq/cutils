# cutils #

**cutils** is a set of utils for C programs.

## List ##

##### STRUCTURE #####

```C
typedef struct item {
    CONTENT_TYPE content;
    struct item* next;
} item_t;
```

Previously, you have to define the macro `CONTENT_TYPE` in order to determine the type of the item content. For example:

```C
#define CONTENT_TYPE uint32_t
```

##### MACROS #####

- `LIST_APPEND(head,node)` appends a new item `node` into the list pointed by `head`.
- `LIST_ADD(node1,node2)` adds `node2` item in the list just between `node1` and `node1->next`. **alpha...**
- `LIST_REMOVE(head,node)` remove the item `node` from the list pointed by `head`.
- `LIST_COUNT(head,counter)` counts in `counter` the number of items contained in the list pointed by `head`. **alpha...**


    



