#include "list.h"

list_t* list_new() {
	node_t* head = NULL;	
	head = malloc(sizeof(node_t));
	if (head == NULL)
		return 1;
	head->data = NULL;
	head->next = malloc(sizeof(node_t));
	head->next->data = NULL;
	head->next->next = NULL;
}

void list_delete(list_t* list) {
	free(list);
}

node_t* list_add_item(list_t* list, void* data) {
	node_t* new_node = malloc(sizeof(node_t));
	new_node->data = data;
	new_node->next = NULL;
	if (list->first_node == NULL) {
		list->last_node = new_node;
		list->first_node = new_node;
		list->first_node->next = list->last_node;
	}
	else {
		list->last_node->next = new_node;
		list->last_node = list->last_node->next;
	}
}

node_t* list_get(list_t* list, size_t i) {
	node_t* current = list->first_node;

	for (int count = 0; count < i; count++) {
		if (current->next != NULL) {
			current = current->next;
		}
		else {
			return NULL;
		}
	}
	return current;
}


void list_print_contents(list_t* list) {
	node_t* current = list->first_node;

	while (current != NULL) {
		printf(current->data);
		printf("\n");
		current = current->next;
	}
}

void list_reverse(list_t* list) {
	node_t* tracking = list->first_node->next->next;
	node_t* mod = list->first_node->next;
	node_t* prev = list->first_node;

	while (tracking != NULL) {
		mod->next = prev;
		prev = mod;
		mod = tracking;
		tracking = tracking->next;
	}

	mod->next = prev;
	prev = mod;
	mod = tracking;

	node_t* last_node = list->last_node;
	list->first_node->next = NULL;

	list->last_node = list->first_node;
	list->first_node = last_node;
}

int main() {
  list_t* list = list_new();
  
  char* one = "one";
  char* two = "two";
  char* three = "three";
  char* four = "four";
  char* five = "five";

  list_add_item(list, one);
  list_add_item(list, two);
  list_add_item(list, three);
  list_add_item(list, four);
  list_add_item(list, five);

  /* for (int i = 0; i < 9999999999999; ++i) {
	  list_add_item(list, "infinity!");
  }
  */

  printf("\nHere's us traversing through the list:\n");
  list_print_contents(list);

  printf("\nHere's us traversing through the list by repeated random access:\n");
  for (int i = 0; i < 5; ++i) {
    printf("%s\n", list_get(list, i)->data);
  }

  printf("\nHere's the same list backwards:\n");
  list_reverse(list);
  list_print_contents(list);

  // I encourage you to mess with this data structure a little bit. Try some
  // weird inputs. Try inserting elements in an infinite loop and see what
  // happens. Always push things to the limit. There are people who are
  // satisfied with what is comfortable and typical. Then there are the people
  // who want to go to the edges of the world just to see what it's like. In
  // life, there's nothing wrong with falling into the first camp. I suspect at
  // some point in our lives we all do. However in computer science, the desire
  // and ability to push things to the edge is what makes the difference between 
  // the developer and the engineer.

  list_delete(list);

  return 0;
}

