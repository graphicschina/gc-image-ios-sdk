//
//  GCSlider.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-7-9.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCThemeManager.h"
#import "../GCImageGeneralControls/GCASValueTrackingSlider.h"

/*!
 *  @brief  The block to handle the slider value change.
 *
 *  @param CGFloat The value of the slider.
 *
 *  @since v1.0.0
 */
typedef void (^GCSliderValueChangedBlock)(CGFloat);

/*!
 *  @brief  The class for changing a parameter of a image filter.
 *
 *  @since v1.0.0
 */
@interface GCSlider : GCASValueTrackingSlider <GCThemeProtocol>

@property (nonatomic, gc_as_strongprop) NSString *parameterKey; // The parameter key for the control.
@property (nonatomic, copy) GCSliderValueChangedBlock sliderValueChanged; // The block to handle the slider value change.

/*!
 *  @brief  The initialization method.
 *
 *  @param attributes The attributes to define the slider control.
 *
 *  @return The instance of GCSlider.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes;

/*!
 *  @brief  The initialization method.
 *
 *  @param attributes      The attributes to define the slider control.
 *  @param parameters      The parameters for the slider control.
 *
 *  @return The instance of GCSlider.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes parameters:(NSDictionary *)parameters;

/*!
 *  @brief  The instance method to change its property according to the specified theme.
 *
 *  @since v1.0.0
 */
- (void)doChangeTheme;

@end
