#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashmap.h"
#include "linked_list.h"

int main(int argc, char** argv)
{
	HashMap* hm;
	FILE* input_file;
	FILE* out_file;
	int i;
	
	char* flag_arg;
	flag_arg = NULL;

	hm = NULL;

	/* TESTING */
		hm = CreateHashMap(3);
		printf("%p\n", hm);

		addElement(hm, "DEF0", "0");
		addElement(hm, "DEF1", "1");

		printf("%s\n", findValueFromKey(hm, "DEF0"));
		printf("%s\n", findValueFromKey(hm, "DEF1"));

		freeHashMap(&hm);
	/* TESTING */

	for (i = 1; i < argc; ++i) {
		if (strcmp(argv[i], "-D") == 0) {
			// -D define
			flag_arg = strdup(argv[++i]);
			printf("def \"-D def\": %s\n", flag_arg);
		} else if (strncmp(argv[i], "-D", 2) == 0) {
			// -Ddefine
			flag_arg = strdup(argv[i] + 2);
			printf("def \"-Ddef\": %s\n", flag_arg);
		} else if (strcmp(argv[i], "-I") == 0) {
			// -I infile
			flag_arg = strdup(argv[++i]);
			printf("infile \"-I infile\": %s\n", flag_arg);
		} else if (strncmp(argv[i], "-I", 2) == 0) {
			// -Iinfile
			flag_arg = strdup(argv[i] + 2);
			printf("infile \"-Iinfile\": %s\n", flag_arg);
		} else if (strcmp(argv[i], "-o") == 0) {
			// -o out_file
			flag_arg = strdup(argv[++i]);
			printf("output file \"-o out_file\": %s\n", flag_arg);
		} else if (strncmp(argv[i], "-o", 2) == 0) {
			// -oout_file
			flag_arg = strdup(argv[i] + 2);
			printf("output file \"-oout_file\": %s\n", flag_arg);
		} else {
			printf("other arg\n");
		}
	}

	if (flag_arg) {
		free(flag_arg);
	}

	return 0;
}
