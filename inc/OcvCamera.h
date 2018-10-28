//
// Created by Andrey Gramakov on 28-Oct-18.
//

#ifndef OCV_SKETCH_OCVCAMERA_H
#define OCV_SKETCH_OCVCAMERA_H

#include "opencv2/opencv.hpp"
using  namespace cv;

class OcvCamera
{
private:
    int cam_num;
    VideoCapture cap; // capture object
    bool Open();
public:
    OcvCamera();
    explicit OcvCamera(int cam_num);
    void SetCameraNumber(int n);
    void ShowWindowWithStream();
    Mat GetPhoto();
};

#endif //OCV_SKETCH_OCVCAMERA_H
