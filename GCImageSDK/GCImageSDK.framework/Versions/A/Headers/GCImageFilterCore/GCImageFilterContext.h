//
//  GCImageFilterContext.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-7-12.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCDefines.h"
#import "GCFilterContext.h"

@class GCOverlayView;

/*!
 *  @brief GCImageFilterContext provides a context for query all required info to create
 *         GCImageFilter instance or set parameters of the GCImageFilter object, etc.
 *
 *         There're two approaches provided in GCImageFilterContext to access
 *         the info about image filters,
 *
 *         1. Get all image filter category info, and all image filter info
 *            in each category with GCImageFilterCategoryInfo and
 *            GCImageFilterInfo.
 *         2. Get a image filter category name or a image filter name first,
 *            and then retrieve other info by the name.
 *
 *  @since v1.0.0
 */

@interface GCImageFilterContext : GCFilterContext

/*!
 *  @brief The singleton class method to create a shared instance.
 *
 *  @return GCImageFilterContext instance.
 *
 *  @since v1.0.0
 */
+ (instancetype)sharedImageFilterContext;

/*!
 *  @brief The instance method to query all supported image filter categories which
 *          is represented by GCImageFilterCategoryInfo.
 *
 *  @return An array of GCImageFilterCategoryInfo objects.
 *
 *  @since v1.0.0
 */
- (NSArray *)getAllImageFilterCategoryInfo;

/*!
 *  @brief The instance method to query all supported image filters in a specified category.
 *
 *  @param filterCategoryName The filter category name, e.g., @"city", @"color", @"frame",
 *                            @"blend", @"blur", etc.
 *
 *  @return An array of CGImageFilterInfo objects.
 *
 *  @since v1.0.0
 */
- (NSArray *)getAllImageFilterInfoInCategory:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to query all supported image filter categories which
 *          represented by NSString.
 *  @return An array of NSString objects, e.g., "city", "frame", "color", @"blend",
 *          @"blur", etc.
 *
 *  @since v1.0.0
 */
- (NSArray *)supportedImageFilterCategoryNames;

/*!
 *  @brief The instance method to query all supported image filters in a specified category.
 *
 *  @param filterCategoryName The filter category name, e.g., @"city", @"color", @"frame", @"blend",
 *                      @"blur", etc.
 *
 *  @return An array of NSString objects.
 *
 *  @since v1.0.0
 */
- (NSArray *)supportedImageFilterNamesByCategoryName:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to query all supported image filter names of all categories,
 *         such as, @"paris", @"instant", @"postcard", @"polaroid", @"texturecolorburnblend",
 *         @"kaleidoscope", @"fisheye", @"tiltshift", etc.
 *
 *  @return An array of NSString objects.
 *
 *  @since v1.0.0
 */
- (NSArray *)supportedImageFilterNames;

/*!
 *  @brief The instance method to query the parameters supported by a specified image filter.
 *
 *  @param filterName The image filter name, such as @"kaleidoscope", @"tiltshift", etc.
 *
 *  @return A dictionary of the image filter parameters.
 *
 *  @since v1.0.0
 */
- (NSMutableDictionary *)supportedFilterParameters:(NSString *)filterName;

/*!
 *  @brief The instance method to get the ranges of each parameter supported by a specified image filter.
 *
 *  @param filterName The image filter name, such as @"kaleidoscope", @"tiltshift", etc.
 *
 *  @return An array of the image filter parameter ranges, and each range is a dictionary with maximum and minimum values.
 *
 *  @since v1.0.0
 */
- (NSArray *)supportedFilterParameterRanges:(NSString *)filterName;

/*!
 *  @brief The instance method to get the panel control with several controls to change parameters
 *          for a specified image filter if there is.
 *
 *  @param filterName   The image filter name, such as @"kaleidoscope", @"tiltshift", etc.
 *  @param valueChanged The returned block with values of the image filter parameters which is changed
 *                       in the controls in the panel.
 *
 *  @return The instance of panel control, e.g., GCGeneralOverlayView(simi-trasparent panel) or
 *          GCBlurOverlayView(panel with iOS blur effect). Both of them are derived from GCOverlayView.
 *
 *  @since v1.0.0
 */
- (GCOverlayView *)supportedFilterOverlayControl:(NSString *)filterName valueChanged:(ParameterValueChangedInControlBlock)valueChanged;

/*!
 *  @brief The instance method to get the several controls to change parameters
 *          for a specified image filter if there is.
 *
 *  @param filterName The image filter name, such as @"kaleidoscope", @"tiltshift", etc.
 *
 *  @return A array of instances of a control(s), e.g., GCSlider. Each one for
 *                       a parameters of the image filter.
 *
 *  @since v1.0.0
 */
- (NSArray *)supportedFilterControls:(NSString *)filterName;

/*!
 *  @brief The instance method to get the full path of the icon file for the specified image filter
 *          in the local file system.
 *          NOTE: as showed in the demo app(CoGraphics), we usaully use the filted thumbnail image for
 *                the image filter icon.
 *
 *  @param filterName The image filter name, such as @"paris", @"instant", etc.
 *
 *  @return The full path of the icon file in the local file system.
 *
 *  @since v1.0.0
 */
- (NSString *)supportedFilterIconPath:(NSString *)filterName;

/*!
 *  @brief The instance method to get the full description of the image filter.
 *
 *  @param filterName The image filter name, such as @"paris", @"instant", etc.
 *
 *  @return A NSString object for the full description.
 *
 *  @since v1.0.0
 */
- (NSString *)supportedFilterDescription:(NSString *)filterName;

/*!
 *  @brief The instance method to get the display name of the image filter for showing on
 *          a UI control as usaul.
 *
 *  @param filterName The image filter name, such as @"paris", @"instant", etc.
 *
 *  @return A NSString object for the display name, e.g. @"Paries" or @"巴黎".
 *
 *  @since v1.0.0
 */
- (NSString *)supportedFilterDisplayName:(NSString *)filterName;

/*!
 *  @brief The instance method to get the full description of the image filter category.
 *
 *  @param filterCategoryName The image filter category name, such as @"color", @"frame", etc.
 *
 *  @return A NSString object for the full description of the image filter category.
 *
 *  @since v1.0.0
 */
- (NSString *)supportedFilterCategoryDescription:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to get the display name of the image filter category for showing
 *          on a UI control as usaul, e.g., a control for disabling/enabling a image filter category
 *          in the settings.
 *
 *  @param filterCategoryName The image filter category name, such as @"color", @"frame", etc.
 *
 *  @return A NSString object for the display name, e.g. @"Frame" or @"边框".
 *
 *  @since v1.0.0
 */
- (NSString *)supportedFilterCategoryDisplayName:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to get the full path of the icon file for the specified image filter
 *          category in the local file system.
 *
 *  @param filterCategoryName The image filter category name, such as @"color", @"frame", etc.
 *
 *  @return The full path of the icon file in the local file system.
 *
 *  @since v1.0.0
 */
- (NSString *)supportedFilterCategoryIconPath:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to enable a specified image filter, e.g., it can be used for
 *           showing/hidding the image filter on the UI.
 *
 *  @param filterName The image filter name, such as @"paris", @"instant", etc.
 *
 *  @since v1.0.0
 */
- (void)enableImageFilterWithName:(NSString *)filterName;

/*!
 *  @brief The instance method to disable a specified image filter, e.g., it can be used for
 *         showing/hidding the image filter on the UI.
 *
 *  @param filterName, such as @"paris", @"instant", etc.
 *
 *  @since v1.0.0
 */
- (void)disableImageFilterWithName:(NSString *)filterName;

/*!
 *  @brief The instance method to determine if a specified image filter is set to be visible
 *          or invisible on UI.
 *
 *  @param filterName The image filter name, such as @"paris", @"instant", etc.
 *
 *  @return YES/NO to indicate visible or invisible.
 *
 *  @since v1.0.0
 */
- (BOOL)isImageFilterEnabled:(NSString *)filterName;

/*!
 *  @brief The instance method to enable a specified image filter category, e.g., it can be used
 *         for showing/hidding the image filter on the UI.
 *         NOTE: disable/enable a image filter category will disable/enable all image filters
 *               in the category as well.
 *
 *  @param filterCategoryName The image filter category name, such as @"color", @"frame", etc.
 *
 *  @since v1.0.0
 */
- (void)enableImageFilterCategoryWithName:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to disable a specified image filter category, e.g., it can be used
 *         for showing/hidding the image filter on the UI.
 *         NOTE: disable/enable a image filter category will disable/enable all image filters
 *               in the category as well.
 *
 *  @param filterCategoryName The image filter category name, such as @"color", @"frame", etc.
 *
 *  @since v1.0.0
 */
- (void)disableImageFilterCategoryWithName:(NSString *)filterCategoryName;

/*!
 *  @brief The instance method to determine if a specified image filter category is set to
 *         be visible or invisible on UI.
 *         NOTE: disable/enable a image filter category will disable/enable all image filters
 *               in the category as well.
 *
 *  @param filterCategoryName The image filter category name, such as @"color", @"frame", etc.
 *
 *  @return YES/NO to indicate visible or invisible.
 *
 *  @since v1.0.0
 */
- (BOOL)isImageFilterCategoryEnabled:(NSString *)filterCategoryName;

/*!
 *  @brief  The instance method to store the changed parameters from a control, such as slider
 *          for a specified filter.
 *
 *  @param filterName The image filter name whose parameters are changed.
 *  @param parameters The changed image filter parameters.
 *
 *  @since v1.0.0
 */
- (void)storeImageFilter:(NSString *)filterName parameters:(NSDictionary *)parameters;

@end
