//
//  GCImageMacroFilter.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-11.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCMacroFilter.h"

/*!
 *  @brief  The implementation class for defining image macro filter. There are usually
 *          more than one image filter in it. the image macro filter is used for
 *          undo/redo in a group of image filters.
 *
 *  @since v1.0.0
 */

@interface GCImageMacroFilter : GCMacroFilter

/*!
 *  @brief  The initialization method with a input image.
 *
 *  @param inputImage The input image.
 *
 *  @return The instance of GCImageMacroFilter.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage;

/*!
 *  @brief  The initialization method with a input image, a specified group of image filter name,
 *          and the blocks for both success and failure of execution of filter actions.
 *
 *  @param inputImage The input Image.
 *  @param names      The array of image filter name.
 *  @param success    The returned block with filtred UIImage object for execute filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @return The instance of GCImageMacroFilter.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage names:(NSArray *)names successWithUIImage:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The initialization method with a input image, a specified group of image filter name,
 *          and the blocks for both success and failure of execution of filter actions.
 *          NOTE: the success block returns a CIImage object.
 *
 *  @param inputImage The input Image.
 *  @param names      The array of image filter name.
 *  @param success    The returned block with filtred CIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @return The instance of GCImageMacroFilter.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage names:(NSArray *)names successWithCIImage:(void(^)(CIImage *filteredCIImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  Add a specified image filter to the image macro filter with the filter name, and the blocks
 *          for the blocks for both success and failure of execution of filter actions.
 *
 *  @param filterName The image filter name.
 *  @param success    The returned block with filtred UIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)addFilterByName:(NSString *)filterName successWithUIImage:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to add a specified image filter to the image macro filter with and the blocks
 *          the filter name, for the blocks for both success and failure of execution of filter actions.
 *          NOTE: the success block returns a CIImage object.
 *
 *  @param filterName The image filter name.
 *  @param success    The returned block with filtred CIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)addFilterByName:(NSString *)filterName successWithCIImage:(void(^)(CIImage *filteredCIImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to remove a specified image filter from the image macro filter with
 *          the filter name, and the blocks for the blocks for both success and failure of execution of
 *          filter actions.
 *
 *  @param filterName The image filter name.
 *  @param success    The returned block with filtred UIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)removeFilterByName:(NSString *)filterName successWithUIImage:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to remove a specified image filter from the image macro filter with
 *          the filter name, and the blocks for the blocks for both success and failure of execution of
 *          filter actions.
 *          NOTE: the success block returns a CIImage object.
 *
 *  @param filterName The image filter name.
 *  @param success    The returned block with filtred CIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)removeFilterByName:(NSString *)filterName successWithCIImage:(void(^)(CIImage *filteredCIImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to determine whether the image macro filter can be undo or not?
 *
 *  @return YES/NO indicating whether can be undo.
 *
 *  @since v1.0.0
 */
- (BOOL)canUndo;

/*!
 *  @brief  The instance method to determine whether the image macro filter can be redo or not?
 *
 *  @return YES/NO indicating whether can be redo.
 *
 *  @since v1.0.0
 */
- (BOOL)canRedo;

/*!
 *  @brief  The instance method to undo a filter in the image macro filter, and the blocks for
 *          the blocks for both success and failure of execution of filter actions.
 *
 *  @param success    The returned block with filtred UIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)undoWithUIImage:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to undo a filter in the image macro filter, and the blocks for
 *          the blocks for both success and failure of execution of filter actions.
 *          NOTE: the success block returns a CIImage object.
 *
 *  @param success    The returned block with filtred CIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)undoWithCIImage:(void(^)(CIImage *filteredCIImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to redo a filter in the image macro filter, and the blocks for
 *          the blocks for both success and failure of execution of filter actions.
 *
 *  @param success    The returned block with filtred UIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)redoWithUIImage:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to redo a filter in the image macro filter, and the blocks for
 *          the blocks for both success and failure of execution of filter actions.
 *          NOTE: the success block returns a CIImage object.
 *
 *  @param success    The returned block with filtred CIImage object for execution of filtering action
 *                    successfully.
 *  @param failure    The returned block with error for execute filtering action failed.
 *
 *  @since v1.0.0
 */
- (void)redoWithCIImage:(void(^)(CIImage *filteredCIImage))success failure:(void(^)(NSError *error))failure;

/*!
 *  @brief  The instance method to reset the image macro filter, i.e., remove all existing image filters.
 *
 *  @since v1.0.0
 */
- (void)reset;

/*!
 *  @brief  The instance method to get the count of image filters in the image macro filter.
 *
 *  @return The count of image filters.
 *
 *  @since v1.0.0
 */
- (NSInteger)filterCount;

/*!
 *  @brief  The instance method to get the current index of the image filters in the image macro filter.
 *
 *  @return The current filter index.
 *
 *  @since v1.0.0
 */
- (NSInteger)currentFilterIndex;

/*!
 *  @brief  The instance method to get the current image filter name in the image macro filter.
 *
 *  @return The current image filter name.
 *
 *  @since v1.0.0
 */
- (NSString *)currentFilterName;

/*!
 *  @brief  The instance method to make the image macro filter be available or not.
 *
 *  @param available The bool value indicating the image macro filter available or not.
 *
 *  @since v1.0.0
 */
- (void)setAvailable:(BOOL)available;

/*!
 *  @brief  The instance method to determine whether the image macro filter is available or not.
 *
 *  @return YES/NO indicating the image macro filter available or not.
 *
 *  @since v1.0.0
 */
- (BOOL)isAvailable;

@end
