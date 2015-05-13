//
//  GCThemeManager.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-7-8.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @brief  The protocol for handling the theme change.
 *
 *  @since v1.0.0
 */
@protocol GCThemeProtocol <NSObject>

/*!
 *  @brief  The protocol method to handle theme change.
 *
 *  @since v1.0.0
 */
- (void)doChangeTheme;

@end

/*!
 *  @brief  The class for managing themes.
 *
 *  @since v1.0.0
 */
@interface GCThemeManager : NSObject

@property (nonatomic, gc_as_strongprop) NSString *currentThemeName; // The current theme name.

/*!
 *  @brief  The singleton class method to initialization.
 *
 *  @return The instance of GCThemeManager.
 *
 *  @since v1.0.0
 */
+ (GCThemeManager *)sharedThemeManager;

/*!
 *  @brief  The instance method to get the image object with specified theme name and image name.
 *
 *  @param themeName The theme name.
 *  @param imageName The image name.
 *
 *  @return The image object.
 *
 *  @since v1.0.0
 */
- (UIImage *)imageNamedFromTheme:(NSString *)themeName imageName:(NSString *)imageName;

/*!
 *  @brief  The instance method to get the controls path for a specified theme.
 *
 *  @param themeName The theme name.
 *
 *  @return The path which all control info is in.
 *
 *  @since v1.0.0
 */
- (NSString *)themeControlPathByName:(NSString *)themeName;

/*!
 *  @brief  The instance method to get the image path for a specified theme.
 *
 *  @param themeName The theme name.
 *
 *  @return The image path.
 *
 *  @since v1.0.0
 */
- (NSString *)themeImagePathByName:(NSString *)themeName;

/*!
 *  @brief  The instance method to get theme path.
 *
 *  @return The theme path.
 *
 *  @since v1.0.0
 */
- (NSString *)themePath;

/*!
 *  @brief  The instance method to load theme data from the specified path in the local storage.
 *
 *  @param path The path in the local storage.
 *
 *  @since v1.0.0
 */
- (void)loadThemeDataFromPath:(NSString *)path;

/*!
 *  @brief  The instance method to get theme parameters for a specified control.
 *
 *  @param controlName The control name.
 *
 *  @return The dictionary for parameters.
 *
 *  @since v1.0.0
 */
- (NSDictionary *)themeParametersByControl:(NSString *)controlName;

/*!
 *  @brief  The instance method to get all supported theme names.
 *
 *  @return The array of theme names.
 *
 *  @since v1.0.0
 */
- (NSArray *)themeNames;

@end
