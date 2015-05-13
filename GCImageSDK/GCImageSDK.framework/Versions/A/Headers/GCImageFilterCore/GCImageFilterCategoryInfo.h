//
//  GCImageFilterCategoryInfo.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-11.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

/*!
 *  @brief  The class to represent a image filter category, including name, description, display name, etc.
 *
 *  @since v1.0.0
 */
@interface GCImageFilterCategoryInfo : NSObject

@property (nonatomic, gc_as_strongprop)NSString *filterCategoryName;         // Unique name to identify a filter category.
@property (nonatomic, gc_as_strongprop)NSString *filterCategoryDisplayName;  // Full name for display.
@property (nonatomic, gc_as_strongprop)NSString *filterCategoryDescription;  // Description.
@property (nonatomic, gc_as_strongprop)NSString *filterCategoryIconPath;     // Local path for icon.
@property (nonatomic, gc_as_strongprop)NSArray *imageFilterInfos;            // All image filters grouped in the category.

@end
