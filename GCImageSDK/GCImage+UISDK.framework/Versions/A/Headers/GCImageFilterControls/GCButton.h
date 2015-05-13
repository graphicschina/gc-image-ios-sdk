//
//  GCButton.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-7-9.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "GCThemeManager.h"

/*!
 *  @brief  The class for the general button to be stylized with different theme.
 *
 *  @since v1.0.0
 */
@interface GCButton : UIButton <GCThemeProtocol>

@property (nonatomic, gc_as_strongprop) NSString *parameterKey; // The parameter key for the control.

/*!
 *  @brief  The initialization method.
 *
 *  @param attributes The attributes to define the control.
 *
 *  @return The instance of GCButton.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes;

/*!
 *  @brief  The initialization method.
 *
 *  @param attributes      The attributes to define the control.
 *  @param parameters      The parameters for the controls in the control.
 *
 *  @return The instance of GCButton.
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
