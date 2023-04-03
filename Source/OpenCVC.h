//
//  OpenCVC.h
//  OpenCV-C
//
//  Created by Gerrit Goossen on 5/10/21.
//  Copyright (c) 2021 Gamma Ray Digital, Inc. All rights reserved.
//
// Appended by Michel Safars 2023 0402
// Some comments are French when it's just to help me understand as I'm not familiar with  C/C++
// Also used Emoticon to point my changes

#ifndef OPENCVC_H
#define OPENCVC_H

#include <ctype.h>
#include <stdbool.h>

#include "CVCTypes.h"
#include "CVCBase.h"
#include "CVCCore.h"
#include "CVCImgCodecs.h"
#include "CVCImgProc.h"
#include "CVCObjectDetect.h"
#include "CVCPhoto.h"
#include "CVCStitching.h"

// high gui functions
CVC_EXPORT void CVCdestroyAllWindows(void);
CVC_EXPORT void CVCimshow(const char *windowName, CVCMat image);
CVC_EXPORT int CVCwaitKey(int delay);

// ▶️ video functions
typedef void* CVCVideoCapture; // ▶️ un alias de type est créé pour représenter un pointeur générique en C/C++ (void*), sous le nom CVCVideoCapture qui est donc le nom de l'alias

CVC_EXPORT CVCVideoCapture CVCVideoCaptureCreate(int camNo); //  ⚠️ Added WebCamNumber CamNo, Originaly CVCVideoCaptureCreate(void)- ▶️ retourne un objet CVCVideoCapture, don cun pointeur

CVC_EXPORT void CVCVideoCaptureFree(CVCVideoCapture videoCapture); // ▶️ CVCVideoCapture is a Ptr
CVC_EXPORT bool CVCVideoCaptureIsOpened(CVCVideoCapture videoCapture);
CVC_EXPORT bool CVCVideoCaptureRead(CVCVideoCapture videoCapture, CVCMat image);

#endif /* OPENCVC_H */
