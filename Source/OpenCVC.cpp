//
//  OpenCVC.cpp
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//
//
// ▶️ 2023 0402  Michel Safars Making some modifications
// will use Emoticon to highligth my changes


#include <opencv2/opencv.hpp>
#include "OpenCVC.h"
#include "CVCPrivate.h"

// MARK: High GUI

void CVCdestroyAllWindows(void)
{
	cv::destroyAllWindows();
}

void CVCimshow(const char *windowName, CVCMat image)
{
	cv::imshow(windowName, ConstCVCMatRef(image));
}

int CVCwaitKey(int delay)
{
	return cv::waitKey(delay);
}


//----------------------
CVCVideoCapture CVCVideoCaptureCreate(int camNo) // 🔴⚠️ Updated Void by "int NumCam) so I can Choose the Webcam
{
	try {
		cv::VideoCapture* videoCapture = new cv::VideoCapture(camNo); // 🔴⚠️ 0 was hardoced une autre Webcam !!
		return (CVCVideoCapture)videoCapture; // CVCVideoCapture qui est donc le nom de l'alias d'un pointeur, donc renvoie un pointeur
	}
	catch (...) {}

	return NULL; // pointeur null
}
//----------------------


void CVCVideoCaptureFree(CVCVideoCapture videoCapture) { // FREE
	// safety check
	if (videoCapture == NULL) {
		return;
	}

	delete (cv::VideoCapture*)videoCapture; // ▶️▶️ so Free in "CVCVideoCaptureFree" means Delete
}

bool CVCVideoCaptureIsOpened(CVCVideoCapture videoCapture) // ▶️ IsOpened
{
	return ((cv::VideoCapture*)videoCapture)->isOpened();
}

bool CVCVideoCaptureRead(CVCVideoCapture videoCapture, CVCMat image) // Read
{
	return ((cv::VideoCapture*)videoCapture)->read(CVCMatRef(image));
}
