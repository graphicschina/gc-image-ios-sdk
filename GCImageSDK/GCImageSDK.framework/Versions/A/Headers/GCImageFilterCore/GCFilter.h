//
//  GCFilter.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-11.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GCARCMacros.h"

@class GCFilterFinder;

/*!
 *  @brief  GCFilter is a abstract class with two important properties input and output image.
 *
 *  @since v1.0.0
 */
@interface GCFilter : NSObject

@property (nonatomic, gc_as_strongprop) UIImage *inputImage; // The input image
@property (nonatomic, gc_as_strongprop) UIImage *outputImage; // The filted output image
@property (nonatomic, gc_as_strongprop) GCFilterFinder *filterFinder; // Internal use only

@end
