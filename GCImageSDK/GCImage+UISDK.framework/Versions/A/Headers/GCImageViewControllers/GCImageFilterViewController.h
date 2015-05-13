//
//  GCImageFilterViewController.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-8.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @brief  The block is used for returning the filter image back.
 *
 *  @param filteredImage The filtered image.
 *
 *  @since v1.0.0
 */
typedef void(^GCImageFilterImageCompletionHandler)(UIImage *filteredImage);

/*!
 *  @brief  The class of filter view controller take a input image and filter it using the filter and
 *          provide a UI interface to interact with user for selecting image filter and parameters, etc.
 *
 *  @since v1.0.0
 */
@interface GCImageFilterViewController : UIViewController

@property (nonatomic, copy)GCImageFilterImageCompletionHandler completionHandler; // The block for returning the filter image back.

/*!
 *  @brief  The initialization method to take a input image and a block to return the filtered image back.
 *
 *  @param inputImage        The input image.
 *  @param completionHandler The block to return the filter image back.
 *
 *  @return The GCFilterViewController instance.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage completionHandler:(GCImageFilterImageCompletionHandler)completionHandler;

@end
