//
//  GCMacroFilter.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-11.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GCARCMacros.h"

/*!
 *  @brief  The abstract class for defining macro filter. There are usually
 *          more than one filter in it. The macro filter is used for
 *          undo/redo in a group of filters.
 *
 *  @since v1.0.0
 */
@interface GCMacroFilter : NSObject

@property (nonatomic, gc_as_strongprop) UIImage *inputImage; // The input image
@property (nonatomic, gc_as_strongprop) UIImage *outputImage; // The filted output image

@end
