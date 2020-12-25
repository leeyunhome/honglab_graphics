// example7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height);

int main()
{
	const string filename("example7.ppm");

	const float image_width = 128.0;
	const float image_height = 128.0;

	vector<uint8_t> buffer(image_width * image_height * 3);

	for (int row = 0; row < image_height; ++row)
	{
		// Linear interplation
		const float alpha = (float)row / (image_height - 1); // 0.0f <= alpha <= 1.0f
		for (int col = 0; col < image_width; ++col)
		{
			const int offset = (col + image_width * row) * 3;
			buffer[offset] = static_cast<uint8_t>(255 * (1.0f - alpha));
			buffer[offset + 1] = 0;
			buffer[offset + 2] = static_cast<uint8_t>(255 * alpha);
		}
	}
	//for (float row = 0.0; row < image_height; ++row)
	//	for (float col = 0.0; col < image_width; ++col)
	//	{
	//		const float offset = (col + image_width * row) * 3;
	//		//buffer[offset] = (uint8_t)(255.0 * (255.0 -row));
	//		//buffer[offset + 1] = 0;
	//		//buffer[offset + 2] = 0;

	//		//buffer[offset] = 0;
	//		//buffer[offset + 1] = (uint8_t)(255.0 * row + 255.0 * (image_height - row));
	//		//buffer[offset + 2] = (uint8_t)(255.0 * row + 255.0 * (image_height - row));

	//		//if (row > image_height / 2)
	//		//{
	//		//	buffer[offset] = (uint8_t)(255.0 * row);
	//		//	buffer[offset + 1] = 0;
	//		//	buffer[offset + 2] = (uint8_t)(255.0 * (125.0 - row));
	//		//}
	//		//else
	//		//{
	//		//	buffer[offset] = (uint8_t)(255.0 * (125.0 - row));
	//		//	buffer[offset + 1] = 0;
	//		//	buffer[offset + 2] = (uint8_t)(255.0 * row);
	//		//}
	//	}

	writePPM(filename, buffer, image_width, image_height);

	return 0;
}

void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height)
{
	ofstream ofile(filename);

	ofile << "P3\n" << width << ' ' << height << "\n" << "255\n";

	for (int row = 0; row < height; ++row)
	{
		for (int col = 0; col < width; ++col)
		{
			const int offset = (col + width * row) * 3;

			for (int c = 0; c < 3; ++c)
			{
				ofile << (int)pixels[offset + c];
				if (col < width - 1 || c < 2)
				{
					ofile << " ";
				}
			}
			ofile << "\n";
		}
	}
		
	ofile << flush;

}