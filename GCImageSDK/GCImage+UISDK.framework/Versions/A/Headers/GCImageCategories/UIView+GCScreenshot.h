//
//  UIView+Screenshot.h
//  Video Blurring
//
//  Created by Mike Jaoudi on 12/11/13.
//  Copyright (c) 2013 Mike Jaoudi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIView (GCScreenshot)

- (UIImage *)convertViewToImage;
- (UIImage *)convertViewToImage:(CGRect)rect;
- (UIImage *)screenImage;

@end
