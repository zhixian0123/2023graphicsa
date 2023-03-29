#include <opencv/highgui.h>
int main()
{
    IplImage*img = cvLoadImage("shiba.jpg");
    cvShowImage("week07",img);
    cvWaitKey(0);
}
