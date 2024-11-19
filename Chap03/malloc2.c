#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
} student;

int main() {
	student *s;

	s = (student *) malloc(sizeof(student));

	if (s == NULL) {
		fprintf(stderr, "Out of Memory\n");
		exit(1);
	}

	strcpy(s->name, "Kim");
	s->age = 25;

	printf("Name : %s, Age : %d\n", s->name, s->age);

	free(s);

	return 0;
}
