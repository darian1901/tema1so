#ifndef LL_HEADER
#define LL_HEADER

#include <stdlib.h>
#include <stdio.h>

typedef struct llist {
	char* key;
	char* value;

	struct llist* next;
} LinkedList;

LinkedList* initializeWithFirstElement(char* key, char* value)
{
	LinkedList* l = (LinkedList*)calloc(1, sizeof(LinkedList));
	if (!l) {
		return NULL;
	}

	l->key = strdup(key);
	l->value = strdup(value);

	l->next = NULL;

	return l;
}

int addElement(LinkedList** l, char* key, char* value)
{
	LinkedList* tmp;
	tmp = NULL;
	tmp = (*l);
	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	tmp->next = (LinkedList*)calloc(1, sizeof(LinkedList));
	if (!(tmp->next)) {
		return 12;
	}

	tmp->next->key = strdup(key);
	tmp->next->value = strdup(value);

	tmp->next->next = NULL;

	return 0;
}

char* findValueFromKey(LinkedList* l, char* key)
{
	LinkedList* tmp;
	tmp = l;
	
	while (tmp != NULL) {
		printf("%s\n", tmp->key);
		if (strcmp(tmp->key, key) == 0) {
			return tmp->value;
		} else {
			tmp = tmp->next;
		}
	}

	return NULL;
}

void deleteLastElement(LinkedList** l)
{
	if ((*l)->next == NULL) {
		free((*l)->key);
		free((*l)->value);
		free((*l));

		(*l) = NULL;
	} else {
		LinkedList* tmp;
		tmp = (*l);

		while (tmp->next->next != NULL) {
			tmp = tmp->next;
		}

		free(tmp->next->key);
		free(tmp->next->value);
		free(tmp->next);

		tmp->next = NULL;
	}
}

void freeList(LinkedList** l)
{
	while ((*l) != NULL) {
		deleteLastElement(l);
	}
}

/* DEBUGGING FUNCTIONS */
void printList(LinkedList* l)
{
	LinkedList* tmp;
	tmp = l;

	if (tmp == NULL) {
		printf("(empty)\n");
		return;
	}
	
	while (tmp != NULL) {
		printf("%s %s\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}

	return;
}


#endif