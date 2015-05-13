//
//  GCSettingsInfo.h
//  GCImageSDK
//
//  Created by Graphics China on 2014-7-12.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

typedef NS_ENUM(NSInteger, GCSettingsContextImageQuality) {
    kGCSettingsContextImageQualityLowDefinition = 0,
    kGCSettingsContextImageQualityStandardDefinition,
    kGCSettingsContextImageQualityHighDefinition,
};

typedef NS_ENUM(NSInteger, GCSettingsContextFilterToolbarLocateAtSide) {
    kGCSettingsContextFilterToolbarLocateAtLeft,
    kGCSettingsContextFilterToolbarLocateAtRight
};

// @"cube" @"push" @"moveIn" @"reveal" @"fade"(default) @"pageCurl" @"pageUnCurl" @"suckEffect" @"rippleEffect" @"oglFlip"

typedef NS_ENUM(NSInteger, GCSettingsContextFilterSelectionAnimation) {
    kGCSettingsContextFilterSelectionAnimationNone,
    kGCSettingsContextFilterSelectionAnimationRipple,
    kGCSettingsContextFilterSelectionAnimationCube,
    kGCSettingsContextFilterSelectionAnimationPush,
    kGCSettingsContextFilterSelectionAnimationMoveIn,
    kGCSettingsContextFilterSelectionAnimationReveal,
    kGCSettingsContextFilterSelectionAnimationFade,
    kGCSettingsContextFilterSelectionAnimationPageCurl,
    kGCSettingsContextFilterSelectionAnimationPageUnCurl,
    kGCSettingsContextFilterSelectionAnimationSuckEffect,
    kGCSettingsContextFilterSelectionAnimationOglFlip,
    kGCSettingsContextFilterSelectionAnimationCameraIrisHollowOpen,
    kGCSettingsContextFilterSelectionAnimationCameraIrisHollowClose,
    kGCSettingsContextFilterSelectionAnimationCurlDown,
    kGCSettingsContextFilterSelectionAnimationCurlUp,
    kGCSettingsContextFilterSelectionAnimationFlipFromLeft,
    kGCSettingsContextFilterSelectionAnimationFlipFromRight
};

typedef NS_ENUM(NSInteger, GCSettingsContextFilterSelectionAnimationDirection) {
    kGCSettingsContextFilterSelectionAnimationDirectionFromLeft,
    kGCSettingsContextFilterSelectionAnimationDirectionFromRight,
    kGCSettingsContextFilterSelectionAnimationDirectionFromTop,
    kGCSettingsContextFilterSelectionAnimationDirectionFromBottom
};

/*!
 *  @brief  The class for respresenting the settings data.
 *
 *  @since v1.0.0
 */
@interface GCSettingsInfo : NSObject

@property (nonatomic, assign)GCSettingsContextImageQuality imageQuality; // The image quality level.
@property (nonatomic, assign)GCSettingsContextFilterToolbarLocateAtSide filterToolbarLocateAtSide; // The toolbar location side.
@property (nonatomic, assign)GCSettingsContextFilterSelectionAnimation filterSelectionAnimation; // The animation type for the image filter selection.
@property (nonatomic, assign)GCSettingsContextFilterSelectionAnimationDirection filterSelectionAnimationDirection; // The animation subtype for the image filter selection.
@property (nonatomic, assign)double filterSelectionAnimationDuration; // The animation duration for the image filter selection.
@property (nonatomic, assign)BOOL isAutoSaveToAppAlbum; // Whether save the image filter to app album automatically.
@property (nonatomic, gc_as_strongprop)NSString *appAlbumName; // The app album name.
@property (nonatomic, assign)BOOL isSupportScreenRotation; // Whehter supports screen rotation.
@property (nonatomic, assign)double navigationBarTintColor; // The navigation bar tint color in hex value.
@property (nonatomic, assign)double filterCanvasBackgroundColor; // The filter canvas background color in hex value.
@property (nonatomic, assign)double filterSelectionGridBackgroundColor; // The filter selection grid view background color in hex value.
@property (nonatomic, assign)double filterCategoryToolbarBackgroundColor; // The filter toolbar background color in hex value.
@property (nonatomic, gc_as_strongprop)NSString *navigationBarBackgroundImageName; // The navigation background image name.
@property (nonatomic, assign)BOOL enableThemeSelection; // Whether the theme selection is enabled or not.
@property (nonatomic, assign)NSInteger currentThemeIndex; // The current theme index.
@property (nonatomic, assign)BOOL enableAboutSelection; // Whether about selection is enabled or not.

// The toolbar location side localized property name, e.g., @"When Landscape Toolbar Locate At"
@property (nonatomic, gc_as_strongprop)NSString *filterToolbarLocateAtSideLocalizedPropertyName;
// The toolbar location side localized property value, e.g., @"Left"
@property (nonatomic, gc_as_strongprop)NSString *filterToolbarLocateAtSideLocalizedPropertyValue;
// The filter selection animation type localized property name, e.g., @"Filter Selection Animation"
@property (nonatomic, gc_as_strongprop)NSString *filterSelectionAnimationLocalizedPropertyName;
// The filter selection animation type localized property value, e.g., @"Ripple"
@property (nonatomic, gc_as_strongprop)NSString *filterSelectionAnimationLocalizedPropertyValue;
// The filter selection animation subtype localized property name, e.g., @"Filter Selection Animation Direction"
@property (nonatomic, gc_as_strongprop)NSString *filterSelectionAnimationDirectionLocalizedPropertyName;
// The filter selection animation subtype localized property value, e.g., @"From Left"
@property (nonatomic, gc_as_strongprop)NSString *filterSelectionAnimationDirectionLocalizedPropertyValue;
// The current theme index localized property name, e.g., @"Theme Selection"
@property (nonatomic, gc_as_strongprop)NSString *currentThemeIndexLocalizedPropertyName;
// The current theme index localized property value, e.g., @"Cherry Pink"
@property (nonatomic, gc_as_strongprop)NSString *currentThemeIndexLocalizedPropertyValue;
// The image quality level localized property name, e.g., @"Image Quality"
@property (nonatomic, gc_as_strongprop)NSString *imageQualityLocalizedPropertyName;
// The image quality level localized property value, e.g., @"1800px (Standard)"
@property (nonatomic, gc_as_strongprop)NSString *imageQualityLocalizedPropertyValue;
// The filter selection animation duration localized property name, e.g., @"Filter Selection Animation Duration"
@property (nonatomic, gc_as_strongprop)NSString *filterSelectionAnimationDurationLocalizedPropertyName;
// The auto save to app album localized property name, e.g., @"Auto Save To App Album"
@property (nonatomic, gc_as_strongprop)NSString *autoSaveToAppAlbumLocalizedPropertyName;
// The support screen rotation localized property name, e.g., @"Support Screen Rotation"
@property (nonatomic, gc_as_strongprop)NSString *supportScreenRotationLocalizedPropertyName;
// The about localized property name, e.g., @"About"
@property (nonatomic, gc_as_strongprop)NSString *aboutLocalizedPropertyName;

/*!
 *  @brief  The initialization method to take the dictionary from the local storage for
 *          assigining all properties.
 *
 *  @param attributes The dictionary from the local storage.
 *
 *  @return The instance of GCSettingsInfo.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithAttributes:(NSDictionary *)attributes;

@end
