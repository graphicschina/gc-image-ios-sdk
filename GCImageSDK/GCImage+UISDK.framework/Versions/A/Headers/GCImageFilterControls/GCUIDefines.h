/*
 *  GCUIDefines.h
 *  Common
 *
 *  GCImageSDK
 *
 *  Created by Graphics China on 2014-7-9.
 *  Copyright 2014~2015 Graphics China. All rights reserved.
 */

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#ifdef __IPHONE_7_0
# define STATUS_BAR_STYLE UIStatusBarStyleLightContent
#else
# define STATUS_BAR_STYLE UIStatusBarStyleBlackTranslucent
#endif

#define HIRESDEVICE (((int)rintf([[[UIScreen mainScreen] currentMode] size].width/[[UIScreen mainScreen] bounds].size.width )>1))

#define kGCDefaultTargetImageSizeForHigh CGSizeMake(2048.0, 2048.0)
#define kGCDefaultTargetImageSizeForStandard CGSizeMake(1800.0, 1800.0)
#define kGCDefaultTargetImageSizeForLow CGSizeMake(1248, 1248.0)

#define kGCCameraHighResolution CGSizeMake(2048.0, 2048.0)
#define kGCCameraMediumResolution CGSizeMake(1800, 1800.0)
#define kGCCameraLowResolution CGSizeMake(800, 800.0)

#define kGCDefaultAlbumNameInAssertsLibrary @"Graphics China"

#define kGCImageFilterCategoryCity @"City"
#define kGCImageFilterCategoryColor @"Color"
#define kGCImageFilterCategoryBlend @"Blend"
#define kGCImageFilterCategoryFrame @"Frame"
