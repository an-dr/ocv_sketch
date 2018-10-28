//
// Created by Andrey Gramakov on 28-Oct-18.
//

#include "OcvCamera.h"

OcvCamera::OcvCamera()
        :cam_num(0) { }

OcvCamera::OcvCamera(int cam_num)
        :cam_num(cam_num) { }

void OcvCamera::SetCameraNumber(int n)
{
    cam_num = n;
    cap.release();
}

bool OcvCamera::Open()
{
    return cap.open(cam_num);
}

void OcvCamera::ShowWindowWithStream()
{
    if(!cap.open(cam_num))
        return;
    for(;;)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty())
            break; // end of video stream
        imshow("Stop capturing by pressing ESC", frame);
        if (waitKey(10)==27)
            break; // stop capturing by pressing ESC
    }
}

Mat OcvCamera::GetPhoto() {
    cap.open(cam_num);
    Mat frame;
    cap >> frame;
    return frame;
}