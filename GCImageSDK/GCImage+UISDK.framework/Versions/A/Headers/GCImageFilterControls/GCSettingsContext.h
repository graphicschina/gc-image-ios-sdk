//
//  GCSettingsContext.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-7-12.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCSettingsInfo.h"

/*!
 *  @brief  The class for saving the settings info into the local file system, and loading them back.
 *
 *  @since v1.0.0
 */
@interface GCSettingsContext : NSObject

/*!
 *  @brief  The singleton class method for initialization.
 *
 *  @return The instance of GCSettingsContext.
 *
 *  @since v1.0.0
 */
+ (instancetype)sharedSettingsContext;

/*!
 *  @brief  The instance method to load settings data from the local storage.
 *
 *  @return The settings info.
 *
 *  @since v1.0.0
 */
- (GCSettingsInfo *)loadSettingsInfo;

/*!
 *  @brief  The instance method to save settings data to the local storage.
 *
 *  @param settingsInfo The settings info.
 *
 *  @since v1.0.0
 */
- (void)saveSettingsInfo:(GCSettingsInfo *)settingsInfo;

/*!
 *  @brief  The instance method to load the localized string value for a specified image quality level.
 *
 *  @param imageQualityLevel The image quality level.
 *
 *  @return The string value for the image quality level.
 *
 *  @since v1.0.0
 */
- (NSString *)loadImageQualityLocalizedValue:(GCSettingsContextImageQuality)imageQualityLevel;

/*!
 *  @brief  The instance method to load the localized string value for a specified location side.
 *
 *  @param side The toolbar location side.
 *
 *  @return The string value for the toolbar location side.
 *
 *  @since v1.0.0
 */
- (NSString *)loadFilterToolbarLocateAtSideLocalizedValue:(GCSettingsContextFilterToolbarLocateAtSide)side;

/*!
 *  @brief  The instance method to load the localized string value for a specified animation type.
 *
 *  @param animation The specified animation type.
 *
 *  @return The string value for the specified animation type.
 *
 *  @since v1.0.0
 */
- (NSString *)loadFilterSelectionAnimationLocalizedValue:(GCSettingsContextFilterSelectionAnimation)animation;

/*!
 *  @brief  The instance method to load the localized string value for a specified animation subtype.
 *
 *  @param direction The specified animation subtype.
 *
 *  @return The string value for the specified animation subtype.
 *
 *  @since v1.0.0
 */
- (NSString *)loadFilterSelectionAnimationDirectionLocalizedValue:(GCSettingsContextFilterSelectionAnimationDirection)direction;

@end
