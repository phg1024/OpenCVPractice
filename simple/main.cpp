#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    Mat img = imread(argv[1], CV_LOAD_IMAGE_UNCHANGED);
    if( img.empty() ) {
        cerr << "Error: image cannot be loaded." << endl;
        return -1;
    }

    namedWindow(argv[1], CV_WINDOW_AUTOSIZE);
    imshow(argv[1], img);

    waitKey(0);

    destroyWindow(argv[1]);
    return 0;
}
