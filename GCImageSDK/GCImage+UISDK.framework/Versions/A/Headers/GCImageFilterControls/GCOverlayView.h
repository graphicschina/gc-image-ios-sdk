//
//  GCOverlayView.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-8-4.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCThemeManager.h"

/*!
 *  @brief  The abstract class for control panel to hold a group of controls. The controls is usaully used to
 *          change parameters of a image filter.
 *
 *  @since v1.0.0
 */
@interface GCOverlayView : UIView <GCThemeProtocol>

@property (nonatomic, gc_as_strongprop) UIImage *backgroundImage; // The background image of the control panel.
@property (nonatomic, gc_as_strongprop) UIView *rootView; // The super view.
@property (nonatomic, gc_as_strongprop) NSString *parameterKey; // The parameter key for the control panel.
@property (nonatomic, copy) ParameterValueChangedInControlBlock parameterValueChanged; // The block to handle the parameter change of a image filter.

/*!
 *  @brief  The initialization method.
 *
 *  @param attributes The attributes to define the control panel.
 *
 *  @return The instance of GCBlurOverlayView.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes;

/*!
 *  @brief  The initialization method.
 *
 *  @param attributes      The attributes to define the control panel.
 *  @param parameters      The parameters for the controls in the control panel.
 *  @param superview       The superview of the control panel.
 *  @param backgroundImage The background image for iOS blur effect.
 *
 *  @return The instance of GCBlurOverlayView.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes parameters:(NSDictionary *)parameters superview:(UIView *)superview backgroundImage:(UIImage *)backgroundImage;

/*!
 *  @brief  The instance method to show the control panel.
 *
 *  @since v1.0.0
 */
- (void)show;

/*!
 *  @brief  The instance method to hide the control panel.
 *
 *  @since v1.0.0
 */
- (void)hide;

/*!
 *  @brief  The instance method to change its property according to the specified theme.
 *
 *  @since v1.0.0
 */
- (void)doChangeTheme;

@end
