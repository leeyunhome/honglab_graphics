// ex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	ofstream ofname("example2.ppm");
	const int image_width = 128;
	const int image_height = 128;
	vector<uint8_t> buffer(image_width * image_height * 3);

	for (int j = 0; j < image_height; ++j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			const int offset = (i + image_width * j) * 3;
			if (j > image_height / 2)
			{
				buffer[offset] = 0;
				buffer[offset + 1] = 0;
				buffer[offset + 2] = 255;
			}
			else
			{
				buffer[offset] = 255;
				buffer[offset + 1] = 0;
				buffer[offset + 2] = 0;
			}
			
		}
	}
	
	ofname << "P3\n" << image_width << ' ' << image_height << "\n" << "255\n";

	for (int j = 0; j < image_height; ++j)
	{
		for (int i = 0; i < image_width; ++i)
		{
			const int offset = (i + image_width * j) * 3;
			for (int c = 0; c < 3; c++)
			{
				ofname << (int)buffer[offset + c];
				if (i < image_width - 1 || c < 2)
					ofname << " ";
			}
		}
		ofname << "\n";
	}

	ofname << flush;

	return 0;
}

