#include "stringbib.h"

void get_string(char* string){

	int i=0;
	char c;

	printf("Bitte geben Sie einen beliebig langen String ein:\n");
	scanf("%c",&c);

	while(c!='\n'){

		string[i] = c;
		i++;
		c = getchar();
	}

	string[i] = '\0';
}

void put_string_it(char* string){

	for(int i=0; string[i] != '\0'; i++){
		printf("%c", string[i]);
	}
}

void put_string_rek(char* string){

	if(*string != '\0'){

		printf("%c",*string);
		put_string_rek(string+1);
	}
}

unsigned int length(const char* s){

	int length = 0;
	int i=0;

	while(s[i] != '\0'){

		length++;
		i++;
	}

	return length;
}

char* copy(const char* quelle){

	char *ziel = malloc((length(quelle)+1)*sizeof(char));

	for(int i=0; i<=length(ziel)+1; i++){
		ziel[i] = quelle[i];
		printf("%c",ziel[i]);}

	return ziel;
}

int compare(const char* string1, const char* string2){

	if(length(string1) != length(string2))
		return -1;

	for(int i=0; string1[i] != '\0' && string2[i] != '\0';i++){
		if(string1[i] != string2[i])
			return -1;
	}

	return 0;
}

char* twist(const char* quelle){

	char *twiststring = malloc((length(quelle)+1)*sizeof(char));

	for(int i=0; i<length(quelle)+1; i++){

		if(quelle[i] <= 90 && quelle[i] >= 65)
			twiststring[i] = quelle[i]+32;

		if(quelle[i] >= 97 && quelle[i] <= 122)
			twiststring[i] = quelle[i]-32;
	}

	return twiststring;
}

char* reverse_string(char* string){

	char* reversed_string = malloc(sizeof(string)*sizeof(char));

	int i=0, start=0, end;

	while(string[i] != '\0'){

		if(string[i+1] == '\0'){
			end = i;

			while(start <= i){

				reversed_string[start] = string[end];
				++start; --end;
			}
		}

		i++;
	}

	reversed_string[i] = '\0';

	return reversed_string;
}

char* stringfusion(char* string1, char* string2){

	int startstr2;
	char* new_string = malloc((sizeof(string1)+sizeof(string2))*sizeof(char));

	for(int i=0; string1[i] != '\0'; i++){
		new_string[i] = string1[i];

		if(string1[i+1] == '\0'){
			startstr2 = i+1;
			for(int j=0; string2[j] != '\0'; j++, startstr2++){
				new_string[startstr2] = string2[j];
			}
		}
	}

	new_string[startstr2] = '\0';
	return new_string;
}

int haystackneedle(const char* haystack, const char* needle){

	if(length(needle) > length(haystack))
		return -1;

	int needlelength = length(needle);
	int j=0;

	for(int i=0; i<=length(haystack);i++){

		if(haystack[i] == needle[j]){
			j++;

			if(needle[j] != haystack[i+1])
				j=0;
		}

		if(j == needlelength-1)
			return 0;
	}

	return -1;
}