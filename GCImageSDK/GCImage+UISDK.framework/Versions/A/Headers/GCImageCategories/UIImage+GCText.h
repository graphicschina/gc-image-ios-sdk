//
//  UIImage+GCText.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-8-5.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (GCText)

+ (UIImage *)imageFromString:(NSString *)string;
+ (UIImage *)drawText:(NSString *)text inImage:(UIImage *)inImage atPoint:(CGPoint)atPoint font:(UIFont *)font color:(UIColor *)color;

@end
