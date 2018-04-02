#include <stdio.h>
#include <stdlib.h>

// What's with the "list_" prefixed to everything? C has no support for modules,
// namespaces, classes, or any other form of automatic name management. I'd like
// to dress this up as something that makes you tougher, but I'm not sure how
// convincingly I can do that. On one hand, it brings you closer to the CPU
// because there are not even "objects" to name down there. On the other, it
// doesn't give you any more power than it would otherwise, it just makes your
// life more difficult.

struct node_t;

typedef struct node_t {
  // What's with the void*? Remember: types are a lie. There are only locations
  // in memory. void pointers are the closes C gets to memory management: it's a
  // raw location in memory, and it's the job of the programmer to know what to
  // do with it once they dereference it.
  void* data;
  struct node_t* next;
} node_t;

typedef struct {
  node_t* first_node;
  node_t* last_node;
} list_t;

// Returns a new empty list.
list_t* list_new();

// Destroys the list and all memory associated with it. Unfortunately this is a
// tricky function to test because, you guessed it, memory management is a lie.
// If nothing is keeping track of your memory, how do you when it's no longer in 
// use?
//
// (There are some techniques, but they're kinda advanced and somewhat
// imprecise. Check out the "valgrind" tool for an example.)
void list_delete(list_t* list);

// Insert the specified data at the end of the list. Returns the newly added
// node.
node_t* list_add_item(list_t* list, void* data);

// Fetches the element with offset i from the beginning of the list. Question:
// What should happen if i is greater than or equal to the length of the list?
// Remember: exceptions are a lie.
node_t* list_get(list_t* list, size_t i);

// This method is a little deceptive: what does it mean to print a void pointer 
// when all it is is a pointer to some location in memory whose structure you 
// don't know? I'll leave it to you to decide whatever is appropriate, but know 
// that there is no correct answer. Fortunately there's also no incorrect 
// answer.
void list_print_contents(list_t* list);

// This function should contain no calls to malloc().
void list_reverse(list_t* list);
