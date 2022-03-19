#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

typedef struct hashmap {
	LinkedList** hm_arr;
	int hashModulus;
} HashMap;

unsigned long long int hashCode(char* key)
{
	unsigned long long int hc;
	int i;
	int len;
	len = strlen(key);
	hc = key[0] >> len;

	for (i = 1; i < len; ++i) {
		hc += ((key[i] * len) * (i + 2));
	}

	return hc;
}

HashMap* CreateHashMap(int hashModulus)
{
	HashMap* hm = (HashMap*)calloc(1, sizeof(HashMap));
	if (!hm) {
		return NULL;
	}

	hm->hashModulus = hashModulus;

	hm->hm_arr = (LinkedList**)calloc(hashModulus, sizeof(LinkedList*));
	if (!hm->hm_arr) {
		return NULL;
	}

	return hm;
}

int addElement(HashMap* hm, char* key, char* value)
{
	int hc_mod;
	int ret;

	hc_mod = hashCode(key) % (hm->hashModulus);

	if (hm->hm_arr[hc_mod] == NULL) {
		hm->hm_arr[hc_mod] = initializeWithFirstElement(key, value);
		if (!hm->hm_arr[hc_mod]) {
			return 12;
		}
	} else {
		ret = addElementLL(&(hm->hm_arr[hc_mod]), key, value);
		if (ret == 12) {
			return ret;
		}
	}

	return 0;
}

char* findValueFromKey(HashMap* hm, char* key) {
	int hc_mod;
	
	hc_mod = hashCode(key) % (hm->hashModulus);
	printf("hcm %d\n", hc_mod);

	return findValueFromKeyLL(hm->hm_arr[hc_mod], key);
}

void freeHashMap(HashMap** hm) {
	int i;

	for (i = 0; i < (*hm)->hashModulus; ++i) {
		if ((*hm)->hm_arr[i] != NULL) {
			freeList(&((*hm)->hm_arr[i]));
		}
	}

	free((*hm)->hm_arr);
	free((*hm));
}
