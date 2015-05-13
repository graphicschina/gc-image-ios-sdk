//
//  GCImageFilter.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-11.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import "GCFilter.h"

/*!
 *  @brief  The class is to filter(apply an effect to) the input image and produce the filted output image.
 *          You can use GCImageFilterContext to query the name of all image filter categories and image filters first,
 *          and then create GCImageFilter by the name.
 *
 *  @since v1.0.0
 */
@interface GCImageFilter : GCFilter

/*!
 *  @brief  The class method to create GCImageFilter instance with a specified image filter name and a image as the input.
 *
 *  @param filterName The filter name. e.g., @"paris", @"london", @"instant", @"chrome", etc.
 *                    You can query all supported image filter names using methods in GCImageFilterContext
 *                    - (NSArray *)supportedImageFilterNames;
 *                    - (NSArray *)supportedImageFilterNamesByCategoryName:(NSString *)categoryName;
 *
 *  @param inputImage The input image will be filted.
 *
 *  @return The sepecified GCImageFilter instance.
 *
 *  @since v1.0.0
 */
+ (instancetype)filterWithName:(NSString *)filterName inputImage:(UIImage *)inputImage;

/*!
 *  @brief  The class method to create GCImageFilter instance with a specified image filter name and a image as the input,
 *          as well as the parameters dictionary for the image filter.
 *
 *  @param filterName The filter name. e.g., @"paris", @"london", @"instant", @"chrome", etc.
 *                    You can query all supported image filter names using methods in GCImageFilterContext
 *                    - (NSArray *)supportedImageFilterNames;
 *                    - (NSArray *)supportedImageFilterNamesByCategoryName:(NSString *)categoryName;
 *  @param inputImage The input image will be filted.
 *  @param parameters The dictionary contains key-value pairs for the filter parameters, e.g., @"filter_top_focus_level",
 *                    @"filter_bottom_focus_level", @"inputRotation", etc.
 *                    You can query all parameters using a method in GCImageFilterContext,
 *                    - (NSMutableDictionary *)supportedFilterParameter:(NSString *)filterName;
 *
 *  @return The sepecified GCImageFilter instance.
 *
 *  @since v1.0.0
 */
+ (instancetype)filterWithName:(NSString *)filterName inputImage:(UIImage *)inputImage parameters:(NSDictionary *)parameters;

/*!
 *  @brief  If the CGImageFilter instance you want to create is a blend or frame filter, and the there should be a more input parameter:blendImage.
 *          It is usually the blend image or the frame image. This class method to create GCImageFilter instance with a specified image filter
 *          name and a image as the input, as well as the parameters dictionary for the image filter.
 *
 *  @param filterName The filter name. e.g., @"postcard", @"polaroid", @"texturecolorburnblend", etc.
 *                    You can query all supported image filter names using methods in GCImageFilterContext
 *                    - (NSArray *)supportedImageFilterNames;
 *                    - (NSArray *)supportedImageFilterNamesByCategoryName:(NSString *)categoryName;
 *  @param inputImage The input image will be filted.
 *  @param parameters The dictionary contains key-value pairs for the filter parameters, e.g., @"filter_frame_name",
 *                    @"filter_frame_image", etc.
 *                    You can query all parameters using a method in GCImageFilterContext,
 *                    - (NSMutableDictionary *)supportedFilterParameter:(NSString *)filterName;
 *
 *  @return The sepecified GCImageFilter instance.
 *
 *  @since v1.0.0
 */
+ (instancetype)filterWithName:(NSString *)filterName inputImage:(UIImage *)inputImage blendImage:(UIImage *)blendImage parameters:(NSDictionary *)parameters;

/*!
 *  @brief  The instance method is to filter(apply an effect to) the input image and produce the filted output image.
 *          You can use GCImageFilterContext to query the name of all image filter categories and image filters first,
 *          and then create GCImageFilter by the name.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage;

/*!
 *  @brief  The instance method to create GCImageFilter instance with a specified image filter name and a image as the input,
 *          as well as the parameters dictionary for the image filter.
 *
 *  @param filterName The filter name. e.g., @"paris", @"london", @"instant", @"chrome", etc.
 *                    You can query all supported image filter names using methods in GCImageFilterContext
 *                    - (NSArray *)supportedImageFilterNames;
 *                    - (NSArray *)supportedImageFilterNamesByCategoryName:(NSString *)categoryName;
 *  @param inputImage The input image will be filted.
 *  @param parameters The dictionary contains key-value pairs for the filter parameters, e.g., @"filter_top_focus_level",
 *                    @"filter_bottom_focus_level", @"inputRotation", etc.
 *                    You can query all parameters using a method in GCImageFilterContext,
 *                    - (NSMutableDictionary *)supportedFilterParameter:(NSString *)filterName;
 *
 *  @return The sepecified GCImageFilter instance.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage parameters:(NSDictionary *)parameters;

/*!
 *  @brief  If the CGImageFilter instance you want to create is a blend or frame filter, and the there should be a more input parameter:blendImage.
 *          It is usually the blend image or the frame image. This instance method to create GCImageFilter instance with a specified image filter
 *          name and a image as the input, as well as the parameters dictionary for the image filter.
 *
 *  @param filterName The filter name. e.g., @"postcard", @"polaroid", @"texturecolorburnblend", etc.
 *                    You can query all supported image filter names using methods in GCImageFilterContext
 *                    - (NSArray *)supportedImageFilterNames;
 *                    - (NSArray *)supportedImageFilterNamesByCategoryName:(NSString *)categoryName;
 *  @param inputImage The input image will be filted.
 *  @param parameters The dictionary contains key-value pairs for the filter parameters, e.g., @"filter_frame_name",
 *                    @"filter_frame_image", etc.
 *                    You can query all parameters using a method in GCImageFilterContext,
 *                    - (NSMutableDictionary *)supportedFilterParameter:(NSString *)filterName;
 *
 *  @return The sepecified GCImageFilter instance.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithInputImage:(UIImage *)inputImage blendImage:(UIImage *)blendImage parameters:(NSDictionary *)parameters;

/*!
 *  @brief  The method is to do filter action with new parameters, and return back the filtered image or error. It returned a normal UIImage object
 *          for further usage.
 *
 *  @param parameters The new parameters, e.g., the changed parameters with UI controls(GCSlider)
 *  @param success    The returned block with filtered image after filtering successsfully.
 *  @param failure    The returned block with error if any failures during filtering action.
 *
 *  @since v1.0.0
 */
- (void)doFilterUIImage:(NSDictionary *)parameters success:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure;


/*!
 *  @brief  The method is to do filter action with new parameters, and return back the filtered image or error. It returned a CIImage object which
 *          can be in some special situations, e.g., using CIContext to render CIImage directly through Quartz 2D or OpenGL.
 *
 *  @param parameters The new parameters, e.g., the changed parameters with UI controls(GCSlider)
 *  @param success    The returned block with filtered image after filtering successsfully.
 *  @param failure    The returned block with error if any failures during filtering action.
 *
 *  @since v1.0.0
 */
- (void)doFilterCIImage:(NSDictionary *)parameters success:(void(^)(CIImage *filteredCIImage))success failure:(void(^)(NSError *error))failure;

@end
