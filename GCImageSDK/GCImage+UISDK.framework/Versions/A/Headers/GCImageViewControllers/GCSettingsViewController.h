//
//  GCSettingsViewController.h
//  GCImageSDK
//
//  Created by Graphics China on 2015-2-19.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @brief  The block for handle the dismiss event of settings view controller.
 *
 *  @since v1.0.0
 */
typedef void(^CGSettingsViewControllerDismissHandler)(void);

/*!
 *  @brief  The class of view contoller provides a interface for user to change many parameters for 
 *          the image filtering.
 *
 *  @since v1.0.0
 */
@interface GCSettingsViewController : UIViewController

@property (nonatomic, copy)CGSettingsViewControllerDismissHandler dismissHandler; // The block to handle dismission of the view controller.

/*!
 *  @brief  The initialization method to take a image as the background for iOS blur effect,
 *          and a block to notify the caller about the dismission.
 *
 *  @param background     The background image.
 *  @param dismissHandler The block to notify the caller about the dismission.
 *
 *  @return The instance of GCSettingsViewController.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithBackground:(UIImage *)background dismissHandler:(CGSettingsViewControllerDismissHandler)dismissHandler;

@end
