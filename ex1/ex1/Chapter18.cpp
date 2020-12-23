// Chapter18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int main()
{
	FILE* fp = NULL;

	fp = fopen("2X2PPM.ppm", "w");
	if (fp == NULL)
	{
		printf("Cannot open file");
	}
	fwrite("P3", 2, 1, fp);

	fclose(fp);

	return 0;
}
