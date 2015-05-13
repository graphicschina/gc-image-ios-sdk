//
//  GCImageFilterCategoryControl.h
//  GCImageSDK
//
//  Created by Graphics China on 2015-2-16.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCImageFilterBaseControl.h"

@class GCImageFilterCategoryInfo;

/*!
 *  @brief  The class for handling the image filter category info with a UI control.
 *
 *  @since v1.0.0
 */
@interface GCImageFilterCategoryControl : GCImageFilterBaseControl

@property (nonatomic, gc_as_strongprop)GCImageFilterCategoryInfo *imageFilterCategoryInfo; // The image filter category info.

@end
