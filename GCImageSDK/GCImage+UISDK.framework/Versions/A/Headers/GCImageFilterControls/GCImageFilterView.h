//
//  GCImageFilterView.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-8-3.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GCImageFilterContext;
@class GCImageFilter;
@class GCTitleViewToolbar;

/*!
 *  @brief  The block for saving the filtered image.
 *
 *  @param filteredImage The filtered image.
 *
 *  @since v1.0.0
 */
typedef void(^GCImageFilterViewSaveImageCompletionHandler)(UIImage *filteredImage);

/*!
 *  @brief  The block for showing/hiding the title view.
 *
 *  @param hidden Whether showing the title view.
 *
 *  @since v1.0.0
 */
typedef void(^GCImageFilterViewHideTitleView)(BOOL hidden);

/*!
 *  @brief  The class for a view to provide a complete UI for filtering image.
 *
 *  @since v1.0.0
 */
@interface GCImageFilterView : UIView

@property (nonatomic, gc_as_strongprop)UIImage *inputImage; // The input image.
@property (nonatomic, gc_as_strongprop)GCTitleViewToolbar *titleToolbar; // The title view toolbar.
@property (nonatomic, assign)CGAffineTransform preferredCIImageTransform; // The preferred image transform for rendering image with CIContext.
@property (nonatomic, copy)GCImageFilterViewSaveImageCompletionHandler completionHandler; // The block for saving the filtered image.
@property (nonatomic, copy)GCImageFilterViewHideTitleView hideTitleViewHandler; // The block for showing/hiding the title view.
@property (nonatomic, assign)CGFloat navigationBarHeight; // The navigation bar height.
@property (nonatomic, assign)CGFloat statusBarHeight; // The status bar height.

/*!
 *  @brief  The initialization method.
 *
 *  @param frame             The frame for the view.
 *  @param completionHandler The block for saving the filtered image.
 *
 *  @return The instance of GCImageFilterView.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithFrame:(CGRect)frame completionHandler:(GCImageFilterViewSaveImageCompletionHandler)completionHandler;

/*!
 *  @brief  The initialization method.
 *
 *  @param frame             The frame for the view.
 *  @param inputImage        The input image.
 *  @param completionHandler The block for saving the filtered image.
 *
 *  @return The instance of GCImageFilterView.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithFrame:(CGRect)frame inputImage:(UIImage *)inputImage completionHandler:(GCImageFilterViewSaveImageCompletionHandler)completionHandler;

/*!
 *  @brief  The instance method to change the current theme. The change will be done with GCSettingsContext
 *          internally.
 *
 *  @since v1.0.0
 */
- (void)changeTheme;

/*!
 *  @brief  The instance method to handle the view size changed(iOS8) or the orientation changed(iOS7 and
 *          earlier).
 *
 *  @param viewSize   The new view size.
 *  @param inputImage The input image.
 *
 *  @since v1.0.0
 */
- (void)handleViewTransition:(CGSize)viewSize inputImage:(UIImage *)inputImage;

/*!
 *  @brief  The instance method to referesh any changes about the image filter.
 *
 *  @since v1.0.0
 */
- (void)refreshFilterPreferences;

/*!
 *  @brief  The instance method to save the filtered image into the photo library and a specified album.
 *
 *  @param albumName The sepcified ablum name.
 *
 *  @since v1.0.0
 */
- (void)saveFilteredImageToAssetLibrary:(NSString *)albumName;

/*!
 *  @brief  The instance method to complete the filtering process, and return the filtered image back to
 *          the caller.
 *
 *  @param completionHandler The block to handle the completion of filtering action.
 *
 *  @since v1.0.0
 */
- (void)completeImageFiltering:(GCImageFilterViewSaveImageCompletionHandler)completionHandler;

/*!
 *  @brief  The instance method to get a screenshot of the GLKView for producing a iOS blur effect.
 *
 *  @return The image for GLKView screenshot.
 *
 *  @since v1.0.0
 */
- (UIImage *)glkViewImage;

@end
