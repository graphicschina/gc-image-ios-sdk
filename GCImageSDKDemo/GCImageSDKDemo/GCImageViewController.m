//
//  GCImageViewController.m
//  GCImageSDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCImageViewController.h"

#ifdef __IPHONE_7_0
# define STATUS_BAR_STYLE UIStatusBarStyleDefault
#else
# define STATUS_BAR_STYLE UIStatusBarStyleBlackTranslucent
#endif

@interface GCImageViewController () {
    NSArray *filters;
    NSMutableDictionary *filterParameters;
    NSArray *filterParameterRanges;

    GCImageFilterContext *filterContext;
    GCImageFilter *imageFilter;

    NSMutableArray *parameterSliders;
}

@property (nonatomic, gc_as_strongprop)UIImage *inputImage;
@property (nonatomic, gc_as_strongprop)UIImageView *imageView;

@end

@implementation GCImageViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    [[UIApplication sharedApplication] setStatusBarStyle:STATUS_BAR_STYLE animated:YES];
    
    [self setTitle:self.filterName];
    
    CGFloat ratio = 1.0f;
    NSInteger index = arc4random() % 3;
    _inputImage = [UIImage imageNamed:[NSString stringWithFormat:@"sample_image%ld.jpg", index]];
    
    ratio = self.inputImage.size.width/self.inputImage.size.height;

    _imageView = [[UIImageView alloc] initWithImage:self.inputImage];
    
    if (ratio > 1.0f) {
        [self.imageView setFrame:CGRectMake(0.0f, 0.0f, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame)/ratio)];
    }
    else {
        [self.imageView setFrame:CGRectMake(0.0f, 0.0f, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame)*ratio)];
    }
    
    [self.imageView setContentMode:UIViewContentModeScaleAspectFit];
    [self.view addSubview:self.imageView];
    
    filterContext = [GCImageFilterContext sharedImageFilterContext];
    filterParameters = [filterContext supportedFilterParameters:self.filterName];
    filterParameterRanges = [filterContext supportedFilterParameterRanges:self.filterName];

    parameterSliders = [[NSMutableArray alloc] initWithCapacity:1];
    CGFloat y = self.imageView.frame.origin.y+CGRectGetHeight(self.imageView.frame)+10.0f;

    NSDictionary *parameterRange = [filterParameterRanges objectAtIndex:0];
    
    for (int i = 0; i < [filterParameters count]; i++) {
        UISlider *slider = [[UISlider alloc] initWithFrame:CGRectMake(10.0f, y, CGRectGetWidth(self.view.frame)-20.0f, 20.0f)];
        [slider addTarget:self action:@selector(handleSliderValueChanged:) forControlEvents:UIControlEventValueChanged];
        
        id parameterKey = [[filterParameters allKeys] objectAtIndex:i];
        NSDictionary *rangeValue = [parameterRange objectForKey:parameterKey];

        [slider setMaximumValue:((NSNumber *)[rangeValue objectForKey:@"maxinum_value"]).floatValue];
        [slider setMinimumValue:((NSNumber *)[rangeValue objectForKey:@"minimum_value"]).floatValue];
        [slider setValue:((NSNumber *)[filterParameters objectForKey:parameterKey]).floatValue];
        
        [parameterSliders addObject:slider];
        [self.view addSubview:slider];
        
        y += (CGRectGetHeight(slider.frame)+25.0f);
    }
    
    [self filterImageWithFilterName:self.filterName success:^(UIImage *filteredImage) {
        [self.imageView setImage:filteredImage];
    } failure:^(NSError *error) {
        
    }];
}

- (void)dealloc
{
    gc_as_release(_slider);
    gc_as_release(_inputImage);
    gc_as_release(_imageView);

    gc_as_release(filters);
    gc_as_release(filterParameters);
    gc_as_release(filterParameterRanges);
    gc_as_release(parameterSliders);
    gc_as_release(filterContext);
    gc_as_release(imageFilter);

    gc_as_superdealloc();
}

- (void)filterImageWithFilterName:(NSString *)filterName success:(void(^)(UIImage *filteredImage))success failure:(void(^)(NSError *error))failure
{
    imageFilter = [GCImageFilter filterWithName:filterName inputImage:self.inputImage parameters:filterParameters];

    [imageFilter doFilterUIImage:filterParameters success:^(UIImage *filteredImage) {
        if (success) {
            success(filteredImage);
        }
    } failure:^(NSError *error) {
        if (failure) {
            failure(error);
        }
    }];
}

#pragma mark -
#pragma mark - Slider Value Changed

- (void)handleSliderValueChanged:(id)sender
{
    NSInteger index = [parameterSliders indexOfObject:sender];
    CGFloat newValue = ((UISlider *)sender).value;
    
    if (index >= 0 && index < [parameterSliders count]) {
        id key = [[filterParameters allKeys] objectAtIndex:index];
        
        if (key) {
            [filterParameters setValue:[NSNumber numberWithFloat:newValue] forKey:key];
            [filterContext storeImageFilter:self.filterName parameters:filterParameters];

            [self filterImageWithFilterName:self.filterName success:^(UIImage *filteredImage) {
                [self.imageView setImage:filteredImage];
            } failure:^(NSError *error) {
                
            }];
        }
    }
}

@end
