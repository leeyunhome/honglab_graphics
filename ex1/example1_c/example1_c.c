// example1_c.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
	const char* filename = "example1.ppm";
	FILE* file;

	if (NULL == (file = fopen(filename, "w")))
	{
		printf("Cannot open file");
		exit(EXIT_FAILURE);
	}

	fprintf(file, "%s\n", "P3");
	fprintf(file, "%d %d\n", 3, 2);
	fprintf(file, "%d\n", 255);
	fprintf(file, "%d %d %d %d %d %d %d %d %d\n", 255, 0, 0, 0, 255, 0, 0, 0, 255);
	fprintf(file, "%d %d %d %d %d %d %d %d %d", 0, 0, 255, 255, 0, 0, 0, 255, 0);

	fclose(file);

	return 0;
}
