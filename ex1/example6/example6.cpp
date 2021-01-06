// example2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height);

int main()
{
    const string filename = "example6.ppm";

    const int image_width = 128;
    const int image_height = 128;

    vector<uint8_t> buffer(image_width * image_height * 3);

    for (int row = 0; row < image_height; ++row)
    {
        for (int col = 0; col < image_width; ++col)
        {
            const int offset = (col + image_width * row) * 3;

            const int checkerwidth = 32;
            if (((col / checkerwidth) % 2) ^ ((row / checkerwidth) % 2))
            {
                buffer[offset] = 0xD4;
                buffer[offset + 1] = 0xB9;
                buffer[offset + 2] = 0x96;
            }
            else
            {
                buffer[offset] = 0xA0;
                buffer[offset + 1] = 0x78;
                buffer[offset + 2] = 0x55;
            }
            //bool flag;
            //if (col % checkerwidth)
            //{
            //    flag = true;
            //}
            //else
            //{
            //    flag = false;
            //}
            //if (flag == true)
            //{
            //    buffer[offset] = 0xA0;
            //    buffer[offset + 1] = 0x78;
            //    buffer[offset + 2] = 0x55;
            //}
            //else
            //{
            //    buffer[offset] = 0xD4;
            //    buffer[offset + 1] = 0xB9;
            //    buffer[offset + 2] = 0x96;
            //}
            //if (col < 32 || row < 32)
            //{
            //    buffer[offset] = 0xA0;
            //    buffer[offset + 1] = 0x78;
            //    buffer[offset + 2] = 0x55;
            //}
            //else
            //{
            //    buffer[offset] = 0xD4;
            //    buffer[offset + 1] = 0xB9;
            //    buffer[offset + 2] = 0x96;
            //}
            //if (col % checkerwidth == 5 || row % checkerwidth == 5)
            //{
            //    buffer[offset] = 0xA0;
            //    buffer[offset + 1] = 0x78;
            //    buffer[offset + 2] = 0x55;
            //}
            //else
            //{
            //    buffer[offset] = 0xD4;
            //    buffer[offset + 1] = 0xB9;
            //    buffer[offset + 2] = 0x96;
            //}

        }
    }

    writePPM(filename, buffer, image_width, image_height);

    return 0;
}

void writePPM(const string& filename, const vector<uint8_t>& pixels, const int& width, const int& height)
{
    ofstream ofile(filename);

    ofile << "P3\n" << width << ' ' << height << "\n255" << "\n";

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
        }
        ofile << "\n";
    }
    ofile << flush;
}