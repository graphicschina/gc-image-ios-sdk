//
//  AMSmoothAlertView.h
//  AMSmoothAlertViewDemo
//
//  Created by AMarliac on 2014-04-24.
//  Contributor: Everest Liu
//  Copyright (c) 2014 AMarliac. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <GPUImage/GPUImage.h>

#import "GCAMBouncingView.h"
#import "GCAMSmoothAlertConstants.h"

@class GCAMSmoothAlertView;

typedef void (^dismissAlertWithButton)(GCAMSmoothAlertView *, UIButton *);

@protocol GCAMSmoothAlertViewDelegate;

@interface GCAMSmoothAlertView : UIView


@property (nonatomic, assign) float cornerRadius;
@property (nonatomic, assign) bool isDisplayed;
@property (nonatomic, assign) GCAnimationType animationType;
@property (nonatomic, gc_as_strongprop) UILabel * titleLabel;
@property (nonatomic, gc_as_strongprop) UILabel * textLabel;
@property (nonatomic, gc_as_strongprop) UIButton *defaultButton;
@property (nonatomic, gc_as_strongprop) UIButton *cancelButton;
@property (nonatomic, gc_as_strongprop) UIImageView *logoView;
@property (nonatomic, gc_as_strongprop) UIFont *titleFont;
@property (nonatomic, gc_as_strongprop) UIFont *textFont;
@property (nonatomic, gc_as_strongprop) UIImage *backgroundImage;
@property (nonatomic, gc_as_weakprop) id<GCAMSmoothAlertViewDelegate> delegate;
@property (nonatomic, copy) dismissAlertWithButton completionBlock;

- (id) initDropAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type;
- (id) initDropAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type andColor:(UIColor*) color;
- (id) initFadeAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type;
- (id) initFadeAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type andColor:(UIColor*) color;
- (id) initDropAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton  andBackgroundImage:(UIImage *)backgroundImage forAlertType:(GCAlertType) type;

// init with completion block

- (id) initDropAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type withCompletionHandler:(dismissAlertWithButton) completionHandler;
- (id) initDropAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type andColor:(UIColor*) color withCompletionHandler:(dismissAlertWithButton) completionHandler;
- (id) initFadeAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type withCompletionHandler:(dismissAlertWithButton) completionHandler;
- (id) initFadeAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton forAlertType:(GCAlertType) type andColor:(UIColor*) color withCompletionHandler:(dismissAlertWithButton) completionHandler;
- (id) initDropAlertWithTitle:(NSString*) title andText:(NSString*) text andCancelButton:(BOOL)hasCancelButton  andBackgroundImage:(UIImage *)backgroundImage forAlertType:(GCAlertType) type withCompletionHandler:(dismissAlertWithButton) completionHandler;

- (void) setCornerRadius:(float)cornerRadius;
- (void) setTitleText:(NSString*) string;
- (void) setMessageText:(NSString*) string;
- (void) show;
- (void) dismissAlertView;
- (void) handleButtonTouched:(id) sender;


@end

@protocol GCAMSmoothAlertViewDelegate <NSObject>

@optional
-(void) alertView:(GCAMSmoothAlertView *)alertView didDismissWithButton:(UIButton *)button;
-(void) alertViewWillShow:(GCAMSmoothAlertView *)alertView;
-(void) alertViewDidShow:(GCAMSmoothAlertView *)alertView;
-(void) alertViewWillDismiss:(GCAMSmoothAlertView *)alertView;
-(void) alertViewDidDismiss:(GCAMSmoothAlertView *)alertView;

@end