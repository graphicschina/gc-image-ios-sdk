//
//  GCImageMacroFilterViewController.m
//  GCImageSDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCImageMacroFilterViewController.h"

#ifdef __IPHONE_7_0
# define STATUS_BAR_STYLE UIStatusBarStyleDefault
#else
# define STATUS_BAR_STYLE UIStatusBarStyleBlackTranslucent
#endif

@interface GCImageMacroFilterViewController () {
    GCImageFilterContext *filterContext;
    GCImageMacroFilter *imageMarcoFilter;
    NSMutableArray *macroFilterNames;
    UIButton *undoFilterButton;
    UIButton *redoFilterButton;
    UIButton *addFilterButton;
    UIButton *removeFilterButton;
    UIButton *resetFilterButton;
    NSInteger addedFilterIndex;
}

@property (nonatomic, gc_as_strongprop)UIImage *inputImage;
@property (nonatomic, gc_as_strongprop)UIImageView *imageView;

@end

@implementation GCImageMacroFilterViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    [[UIApplication sharedApplication] setStatusBarStyle:STATUS_BAR_STYLE animated:YES];
    
    [self setTitle:@"Image Macro Filter"];
    
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

    CGFloat y = self.imageView.frame.origin.y+CGRectGetHeight(self.imageView.frame)+10.0f;
    
    undoFilterButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [undoFilterButton setTitle:NSLocalizedString(@"Undo", nil) forState:UIControlStateNormal];
    [undoFilterButton addTarget:self action:@selector(handleUndoButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [undoFilterButton setFrame:CGRectMake(20, y, 160, 40)];
    [self.view addSubview:undoFilterButton];
    
    redoFilterButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [redoFilterButton setTitle:NSLocalizedString(@"Redo", nil) forState:UIControlStateNormal];
    [redoFilterButton addTarget:self action:@selector(handleRedoButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [redoFilterButton setFrame:CGRectMake(undoFilterButton.frame.origin.x+undoFilterButton.frame.size.width+20.0f, undoFilterButton.frame.origin.y, 160, 40)];
    [self.view addSubview:redoFilterButton];
    
    addFilterButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [addFilterButton setTitle:NSLocalizedString(@"Add Filter", nil) forState:UIControlStateNormal];
    [addFilterButton addTarget:self action:@selector(handleAddFilterButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [addFilterButton setFrame:CGRectMake(undoFilterButton.frame.origin.x, undoFilterButton.frame.origin.y+undoFilterButton.frame.size.height+20.0f, 110, 40)];
    [self.view addSubview:addFilterButton];
    
    removeFilterButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [removeFilterButton setTitle:NSLocalizedString(@"Remove Filter", nil) forState:UIControlStateNormal];
    [removeFilterButton addTarget:self action:@selector(handleRemoveFilterButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [removeFilterButton setFrame:CGRectMake(addFilterButton.frame.origin.x+addFilterButton.frame.size.width+20.0f, addFilterButton.frame.origin.y, 110, 40)];
    [self.view addSubview:removeFilterButton];
    
    resetFilterButton = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [resetFilterButton setTitle:NSLocalizedString(@"Reset", nil) forState:UIControlStateNormal];
    [resetFilterButton addTarget:self action:@selector(handleResetButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [resetFilterButton setFrame:CGRectMake(undoFilterButton.frame.origin.x, addFilterButton.frame.origin.y+addFilterButton.frame.size.height+20.0f, 110, 40)];
    [self.view addSubview:resetFilterButton];
    
    filterContext = [GCImageFilterContext sharedImageFilterContext];
    NSArray *filterNames = [[GCImageFilterContext sharedImageFilterContext] supportedImageFilterNames];
    
    macroFilterNames = [[NSMutableArray alloc] initWithCapacity:1];

    for (int i = 0; i < 5; i++) {
        if (filterNames) {
            index = arc4random() % [filterNames count]-1;

            if (index < [filterNames count]) {
                [macroFilterNames addObject:[filterNames objectAtIndex:index]];
            }
        }
    }
    
    imageMarcoFilter = [[GCImageMacroFilter alloc] initWithInputImage:self.inputImage names:macroFilterNames successWithUIImage:^(UIImage *filteredImage) {
        [self.imageView setImage:filteredImage];
    } failure:^(NSError *error) {
        
    }];
    
    addedFilterIndex = 0;
}

- (void)dealloc
{
    gc_as_release(_inputImage);
    gc_as_release(_imageView);

    gc_as_release(macroFilterNames);
    gc_as_release(imageMacroFilter);

    gc_as_superdealloc();
}

- (void)handleUndoButtonTapped:(id)sender
{
    if (imageMarcoFilter) {
        [imageMarcoFilter undoWithUIImage:^(UIImage *filteredImage) {
            [self.imageView setImage:filteredImage];
        } failure:^(NSError *error) {
            NSLog(@"Undo with error: %@", error);
        }];
        
        if (![imageMarcoFilter canUndo]) {
            [undoFilterButton setEnabled:NO];
            [redoFilterButton setEnabled:YES];
        }
        else {
            [undoFilterButton setEnabled:YES];
        }
    }
}

- (void)handleRedoButtonTapped:(id)sender
{
    if (imageMarcoFilter) {
        [imageMarcoFilter redoWithUIImage:^(UIImage *filteredImage) {
            [self.imageView setImage:filteredImage];
        } failure:^(NSError *error) {
            NSLog(@"Undo with error: %@", error);
        }];
    }
    
    if (![imageMarcoFilter canRedo]) {
        [redoFilterButton setEnabled:NO];
        [undoFilterButton setEnabled:YES];
    }
    else {
        [redoFilterButton setEnabled:YES];
    }
}

- (void)handleAddFilterButtonTapped:(id)sender
{
    __weak typeof(self) weakSelf = self;
    
    if (imageMarcoFilter) {
        NSArray *filterNames = [[GCImageFilterContext sharedImageFilterContext] supportedImageFilterNames];
        __strong typeof(self) strongSelf = weakSelf;
        
        addedFilterIndex = arc4random() % [filterNames count]-1;
        
        if (addedFilterIndex < [filterNames count]) {
            [imageMarcoFilter addFilterByName:[filterNames objectAtIndex:addedFilterIndex] successWithUIImage:^(UIImage *filteredImage) {
                [strongSelf.imageView setImage:filteredImage];
            } failure:^(NSError *error) {
                NSLog(@"Undo with error: %@", error);
            }];
        }

        [undoFilterButton setEnabled:YES];
    }
}

- (void)handleRemoveFilterButtonTapped:(id)sender
{
    __weak typeof(self) weakSelf = self;
    
    if (imageMarcoFilter) {
        NSArray *filterNames = [[GCImageFilterContext sharedImageFilterContext] supportedImageFilterNames];
        __strong typeof(self) strongSelf = weakSelf;
        
        if (addedFilterIndex < [filterNames count]) {
            [imageMarcoFilter removeFilterByName:[filterNames objectAtIndex:addedFilterIndex] successWithUIImage:^(UIImage *filteredImage) {
                [strongSelf.imageView setImage:filteredImage];
            } failure:^(NSError *error) {
                NSLog(@"Undo with error: %@", error);
            }];
        }
        
        if ([imageMarcoFilter filterCount] <= 0) {
            [undoFilterButton setEnabled:NO];
            [redoFilterButton setEnabled:NO];
        }
    }
}

- (void)handleResetButtonTapped:(id)sender
{
    if (imageMarcoFilter) {
        [imageMarcoFilter reset];
        [undoFilterButton setEnabled:NO];
        [redoFilterButton setEnabled:NO];
        [self.imageView setImage:self.inputImage];
    }
}

@end
