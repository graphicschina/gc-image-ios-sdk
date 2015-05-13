//
//  AMBouncingView.h
//  AMSmoothAlertViewDemo
//
//  Created by AMarliac on 2014-04-25.
//  Copyright (c) 2014 AMarliac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "GCAMSmoothAlertConstants.h"

@interface GCAMBouncingView : UIView

@property (nonatomic, strong) UIImageView* image;

- (id)initSuccessCircleWithFrame:(CGRect)frame andImageSize:(int) imageSize forAlertType:(GCAlertType) type andColor:(UIColor*) color;
- (CGRect) newFrameWithWidth:(float) width andHeight:(float) height;

@end