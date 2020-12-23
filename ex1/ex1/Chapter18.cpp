// Chapter18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	FILE* fp = NULL;

	const int image_width = 2;
	const int image_height = 2;

	fp = fopen("2X2PPM.ppm", "w");
	if (fp == NULL)
	{
		printf("Cannot open file");
	}
	fprintf(fp, "P3\n");
	fprintf(fp, "%d %d\n", image_width, image_height);
	fprintf(fp, "%d\n", 255);
	fprintf(fp, "%d %d %d %d %d %d\n", 255, 0, 0, 0, 255, 0);
	fprintf(fp, "%d %d %d %d %d %d\n", 0, 0, 255, 0, 0, 0);
	//fwrite("P3", 2, 1, fp);

	fclose(fp);

	return 0;
}
