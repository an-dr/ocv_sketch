//
// Created by Andrey Gramakov on 27-Oct-18.
//

#include "opencv2/opencv.hpp"
#include "OcvCamera.h"
#include <stdio.h>
#include <string>
#include <vector>

using namespace cv;
using namespace std;

static Mat get_vessel_inbin()
{
    string ves_in = "C:/Users/dongr/Documents/GitHub/ocv_sketch/ves_in.png";
    Mat result;
    Mat img = imread(ves_in, IMREAD_COLOR);
    threshold(img, result, 100, 255, THRESH_BINARY);
    return result;
}

static Mat get_photo_inbin()
{
    OcvCamera c;
    Mat img = c.GetPhoto();
    Mat gray, bw;
    cvtColor(img, gray, COLOR_BGR2GRAY); // Convert the image to Gray
    threshold(gray, bw, 100, 255, THRESH_BINARY);
    return bw;

}

int main(int argc, char** argv)
{

//    OcvCamera c;
    int array[8][8] =
            {
                    {12, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},
                    {0, 0, 128, 128, 255, 255, 0, 128},

            };
    Mat picfromarr(8, 8, CV_8UC1, array);

////    cout << f.at<int>(0,3) << endl;
//
    while (true)
    {
////        imshow("Shot!",photo);
////        imshow("Shot!",photo_gray);
        imshow("Shot!", get_vessel_inbin());
        if (waitKey(10)==27)
            break; // stop capturing by pressing ESC
    }
}