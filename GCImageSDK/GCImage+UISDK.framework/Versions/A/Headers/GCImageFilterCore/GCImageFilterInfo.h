//
//  GCImageFilterInfo.h
//  GCImageSDK
//
//  Created by Graphics China on 14-7-11.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @brief  The class to represent a image filter, including name, description, display name, parameters, etc.
 *
 *  @since v1.0.0
 */
@interface GCImageFilterInfo : NSObject

@property (nonatomic, gc_as_strongprop)NSString *filterName;               // Unique name for identify a filter.
@property (nonatomic, gc_as_strongprop)NSString *filterDescription;        // Description.
@property (nonatomic, gc_as_strongprop)NSString *filterDisplayName;        // Full name for display.
@property (nonatomic, gc_as_strongprop)NSString *filterIconPath;           // Local path for icon.
@property (nonatomic, gc_as_strongprop)NSDictionary *filterParameters;     // Filter parameters.
@property (nonatomic, gc_as_strongprop)NSDictionary *filterOverlayControl; // A group of controls on a overlay.
@property (nonatomic, gc_as_strongprop)NSArray *filterControls;            // Controls for changing filter parameters.
@property (nonatomic, gc_as_strongprop)NSString *filterCategoryName;       // Category name.
@property (nonatomic, gc_as_strongprop)UIImage *filterIconImage;           // Customized icon image.

@end
