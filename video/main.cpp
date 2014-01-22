#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    VideoCapture cap(0);

    if(!cap.isOpened()) {
        cout << "Cannot open the video camera!" << endl;
        return -1;
    }

    double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    cout << "Frame size: " << dWidth << "x" << dHeight << endl;

    Size frameSize(static_cast<int>(dWidth), static_cast<int>(dHeight));

    VideoWriter vwriter("./video.avi", CV_FOURCC('P', 'I', 'M', '1'), 24, frameSize, true);

    if( !vwriter.isOpened() ) {
        cerr << "Cannot open video to write!" << endl;
        return -1;
    }

    namedWindow("Video", CV_WINDOW_AUTOSIZE);

    while(1) {
        Mat frame;
        bool flag = cap.read(frame);

        if( !flag ) {
            cerr << "Cannot read a frame from video stream!" << endl;
            break;
        }

        vwriter.write(frame);
        imshow("Video", frame);

        if( waitKey(30) == 27 ) {
            cout << "exit." << endl;
            break;
        }
    }
    return 0;
}
