#include <iostream>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Mat image=imread("duck.jpg");

void CallBackFunc(int event,int x,int y,int flags,void* userdata)
{

	if( event == EVENT_LBUTTONDOWN)
	{
		cout<<"the left mouse button was clicked at ("<<x<<","<<y<<")"<<endl;
		circle(image, Point(x,y), 5, (255,0,0), -1,8);
		imshow("my window",image);


	}

	else if(event == EVENT_RBUTTONDOWN)
	{
		cout<<"the right mouse button was clicked at ("<<x<<","<<y<<")"<<endl;
		circle(image, Point(x,y), 5, (0,255,0), -1, 8);
		imshow("my window", image);
	}

	else if(event == EVENT_MBUTTONDOWN)
	{
		cout<<"the middle mouse button was clicked at ("<<x<<","<<y<<")"<<endl;
		circle(image, Point(x,y), 3, (0,255,255), 1,8);
		imshow("my window", image);


	}

	else if(event == EVENT_MOUSEMOVE)
	{
		cout<<"mouse moved over the window position ("<<x<<","<<y<<")"<<endl;
		circle(image, Point(x,y), 3, (0,0,255), 1,8);	
		imshow("my window", image);
	}

}

int main()
{

	namedWindow("my window",1);

	setMouseCallback("my window",CallBackFunc,NULL);
	imshow("my window",image);

	int x= waitKey(0);
	if((char)x==27)
		exit(0);
	return 0;
}


