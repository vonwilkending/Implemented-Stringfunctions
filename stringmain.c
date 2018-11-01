#include <stdio.h>
#include <stdlib.h>
#include "stringbib.h"

int main(int argc, char const *argv[])
{
	if(argc != 3)
		{printf("Sie haben nicht die korrekte Anzahl von Argumenten eingegeben!\n");
		return EXIT_FAILURE;
	}

	char *stringcopy = copy(argv[1]);
	char *strswitch = twist(argv[1]);

	printf("String 1: %s hat die Länge: %d\n", argv[1], length(argv[1]));
	printf("Der kopierte String 1: %s\n",stringcopy);

	if(compare(argv[1],argv[2]) == 0)
		printf("String 1: %s und String 2: %s sind identisch\n", argv[1],argv[2]);

	else
		printf("String 1: %s und String 2: %s sind nicht identisch!\n",argv[1],argv[2]);

	printf("switchstring: %s\n", strswitch);

	if(haystackneedle(argv[1],argv[2]) == 0)
		printf("String 2: %s ist in String 1: %s enthalten.\n", argv[2],argv[1]);

	else
		printf("String 2: %s ist in String 1: %s nicht enthalten!\n", argv[2],argv[1]);

	return EXIT_SUCCESS;
}