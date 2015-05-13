//
//  GCDefines.h
//  Common
//
//  GCImageSDK
//
//  Created by Graphics China on 2013-01-20.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <UIKit/UIKit.h>

#define IS_IPHONE4 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size) : NO)
#define IS_IPHONE6 ([UIScreen instancesRespondToSelector:@selector(nativeBounds)] ? floor([[UIScreen mainScreen] nativeBounds].size.width) > 700 && floor([[UIScreen mainScreen] nativeBounds].size.width) < 800 && floor([[UIScreen mainScreen] nativeBounds].size.height) > 1330 && floor([[UIScreen mainScreen] nativeBounds].size.height) < 1335 : NO)
#define IS_IPHONE6PLUS ([UIScreen instancesRespondToSelector:@selector(nativeBounds)] ? floor([[UIScreen mainScreen] nativeBounds].size.width) > 1000 && floor([[UIScreen mainScreen] nativeBounds].size.width) < 1090, floor([[UIScreen mainScreen] nativeBounds].size.height) > 1900 && floor([[UIScreen mainScreen] nativeBounds].size.height) < 1930 : NO)
#define IS_IPHONE6_NORMAL_MODE ([UIScreen instancesRespondToSelector:@selector(bounds)] ? floor([[UIScreen mainScreen] bounds].size.width) > 370 && floor([[UIScreen mainScreen] bounds].size.width) < 380, floor([[UIScreen mainScreen] bounds].size.height) > 660 && floor([[UIScreen mainScreen] bounds].size.height) < 670 : NO)
#define IS_IPHONE6_ZOOM_IN_MODE ([UIScreen instancesRespondToSelector:@selector(bounds)] ? floor([[UIScreen mainScreen] bounds].size.width) > 310 && floor([[UIScreen mainScreen] bounds].size.width) < 325, floor([[UIScreen mainScreen] bounds].size.height) > 560 && floor([[UIScreen mainScreen] bounds].size.height) < 575 : NO)
#define IS_IPHONE6PLUS_NORMAL_MODE ([UIScreen instancesRespondToSelector:@selector(bounds)] ? floor([[UIScreen mainScreen] bounds].size.width) > 410 && floor([[UIScreen mainScreen] bounds].size.width) < 420, floor([[UIScreen mainScreen] bounds].size.height) > 730 && floor([[UIScreen mainScreen] bounds].size.height) < 740 : NO)
#define IS_IPHONE6PLUS_ZOOM_IN_MODE ([UIScreen instancesRespondToSelector:@selector(bounds)] ? floor([[UIScreen mainScreen] bounds].size.width) > 370 && floor([[UIScreen mainScreen] bounds].size.width) < 380, floor([[UIScreen mainScreen] bounds].size.height) > 660 && floor([[UIScreen mainScreen] bounds].size.height) < 670 : NO)

#define IS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)

#define IS_IOS_8 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0f)
#define IS_IOS_7 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 7.0f)
#define IS_IOS_6 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 6.0f)
#define IS_IOS_5 ([[[UIDevice currentDevice] systemVersion] floatValue] >= 5.0f)

/*!
 *  @brief  Block is used to change a filter parameter with a value from UI Control(e.g. GCSlider).
 *  The parameters of a filter object are set(change) through the use of key-value pairs.
 *
 *  @param key   parameter key(literal name) string
 *  @param value parameter value string
 *
 *  @since v1.0.0
 */
typedef void (^ParameterValueChangedInControlBlock)(id key, CGFloat value);
