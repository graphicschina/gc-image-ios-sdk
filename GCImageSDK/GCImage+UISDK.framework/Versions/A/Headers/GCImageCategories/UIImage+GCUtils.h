//
//  UIImage+GCUtils.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-8-7.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @brief  The class is a UIImage category to provide some facility class methods and instance methods for
 *          handling custom UIImage.
 *
 *  @since v1.0.0
 */
@interface UIImage (GCUtils)

+ (UIImage *)imageWithColor:(UIColor *)color inRect:(CGRect)inRect;
+ (UIImage *)createImageInSize:(CGSize)size isTransparent:(BOOL)isTransparent;
+ (UIImage *)drawImage:(UIImage*)image inImage:(UIImage*)inImage atPoint:(CGPoint)point;
+ (CGAffineTransform)preferredCIImageTransformFromUIImage:(UIImageOrientation)imageOrientation imageSize:(CGSize)imageSize;

// Create Image
+ (UIImage *)imageFromView:(UIView *)theView withSize:(CGSize)size;

// Customize Image
- (UIImage *)blurredImageWithRadius:(CGFloat)radius
                         iterations:(NSUInteger)iterations
                          tintColor:(UIColor *)tintColor;

- (UIImage *)applyBlurWithRadius:(CGFloat)blurRadius tintColor:(UIColor *)tintColor saturationDeltaFactor:(CGFloat)saturationDeltaFactor maskImage:(UIImage *)maskImage;

@end
