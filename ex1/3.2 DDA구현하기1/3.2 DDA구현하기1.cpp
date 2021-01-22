// 3.2 DDA구현하기1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class RGB
{
public:
    RGB() :r(0), g(0), b(0) {}

    RGB(const uint8_t& r_, const uint8_t& g_, const uint8_t& b_)
        : r(r_), g(g_), b(b_)
    {}

public:
    uint8_t r, g, b;
};

class PixelBuffer
{
public:
    PixelBuffer(const int& width_, const int& height_)
        : width(width_), height(height_), buffer(width* height)
    {}

    void clear(const RGB& rgb)
    {
        fill(buffer.begin(), buffer.end(), rgb);
    }

    void drawPixel(const int& i, const int& j, const RGB& rgb)
    {
        buffer[i + width * j] = rgb;
    }

    // Easy to understand but unoptimized implementation
    void drawLineTest1(int x0, int y0, int x1, int y1, const RGB& rgb)
    {
        if (x0 > x1)
        {
            cout << "swap called" << endl;
            std::swap(x0, x1);
            //...
        }

        //...
        float y = y0;
        for (int x = x0; x <= x1; x++)
        {
            //drawPixel(x, round(y), rgb);
            //...
            int steps = std::abs(x1 - x0);
            cout << steps << endl;
            float x_inc = x1 / steps;
            const float y_inc = (float)(y1 - y0) / 4.0f;
            //x = x + x_inc;
            //y = y + y_inc;
            cout << y << endl;
            drawPixel(x, round(y), rgb);
            y += y_inc;

        }
    }

    void writePPM(const string& filename)
    {
        ofstream ofile(filename);

        ofile << "P3\n" << width << ' ' << height << "\n" << "255\n";

        for (int j = 0; j < height; j++)
        {
            for (int i = 0; i < width; i++)
            {
                const int offset = i + width * j;
                ofile << (int)buffer[offset].r << " " << (int)buffer[offset].g << " " << (int)buffer[offset].b;
                if (i < width - 1)
                    ofile << " ";
            }
            ofile << "\n";
        }

        ofile << flush;
    }

public:
    int width, height;
    vector<RGB> buffer;
};

int main()
{
    PixelBuffer pixel_buffer(5, 5);
    pixel_buffer.clear(RGB(255, 255, 255));

    // Case 1: 4 - 0 > 2 - 1
    pixel_buffer.drawLineTest1(0, 1, 4, 2, RGB(0, 0, 0));

    // Case 2: 9 - 7 < 3 - 0
    //pixel_buffer.drawLineTest1(2, 0, 4, 3, RGB(0,0,0)); 

    pixel_buffer.writePPM("ex2_DDA.ppm");

    return 0;
}
