//
//  GCViewController.m
//  GCImage+UISDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImage+UISDK/GCImage+UISDK.h>

#import "GCViewController.h"

#define kGCImageUISDKDemoViewDefaultButtonWidth 300
#define kGCImageUISDKDemoViewDefaultButtonHeight 44
#define kGCImageUISDKDemoViewSmallButtonWidth 90
#define kGCImageUISDKDemoViewSmallButtonHeight 30

@interface GCViewController () <UITabBarControllerDelegate>

@end

@implementation GCViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    
    UIScrollView *scrollView = [[UIScrollView alloc] initWithFrame:self.view.bounds];
    [scrollView setContentSize:CGSizeMake(CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame)*2)];
    [self setView:scrollView];
    
    UIButton *mode1Button = [UIButton buttonWithType:UIButtonTypeCustom];
    [mode1Button setTitle:@"GCImagePickerViewController" forState:UIControlStateNormal];
    [mode1Button setBackgroundColor:[UIColor redColor]];
    
    if (IS_IOS_7) {
        [mode1Button setFrame:CGRectMake((self.view.frame.size.width-kGCImageUISDKDemoViewDefaultButtonWidth)/2, 20.0f, kGCImageUISDKDemoViewDefaultButtonWidth, kGCImageUISDKDemoViewDefaultButtonHeight)];
    }
    else {
        [mode1Button setFrame:CGRectMake((self.view.frame.size.width-kGCImageUISDKDemoViewDefaultButtonWidth)/2, 20.0f, kGCImageUISDKDemoViewDefaultButtonWidth, kGCImageUISDKDemoViewDefaultButtonHeight)];
    }
    
    [mode1Button setClipsToBounds:YES];
    [mode1Button.layer setCornerRadius:5.0f];
    [mode1Button addTarget:self action:@selector(handleMode1ButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:mode1Button];
    
    UIButton *mode2Button = [UIButton buttonWithType:UIButtonTypeCustom];
    [mode2Button setTitle:@"GCImageFilterViewController" forState:UIControlStateNormal];
    [mode2Button setBackgroundColor:[UIColor redColor]];
    
    [mode2Button setFrame:CGRectMake((self.view.frame.size.width-kGCImageUISDKDemoViewDefaultButtonWidth)/2, mode1Button.frame.origin.y+mode1Button.frame.size.height+20.0f, kGCImageUISDKDemoViewDefaultButtonWidth, kGCImageUISDKDemoViewDefaultButtonHeight)];
    
    [mode2Button setClipsToBounds:YES];
    [mode2Button.layer setCornerRadius:5.0f];
    [mode2Button addTarget:self action:@selector(handleMode2ButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:mode2Button];
    
    UIButton *mode3Button = [UIButton buttonWithType:UIButtonTypeCustom];
    [mode3Button setTitle:@"GCImageFilterView" forState:UIControlStateNormal];
    [mode3Button setBackgroundColor:[UIColor redColor]];
    [mode3Button setFrame:CGRectMake((self.view.frame.size.width-kGCImageUISDKDemoViewDefaultButtonWidth)/2, mode2Button.frame.origin.y+mode2Button.frame.size.height+20.0f, kGCImageUISDKDemoViewDefaultButtonWidth, kGCImageUISDKDemoViewDefaultButtonHeight)];
    [mode3Button setClipsToBounds:YES];
    [mode3Button.layer setCornerRadius:5.0f];
    [mode3Button addTarget:self action:@selector(handleMode3ButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:mode3Button];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];

}

- (void)dealloc
{
    gc_as_superdealloc();
}

- (void)handleMode1ButtonTapped:(id)sender
{
    GCImagePickerViewController *viewController = gc_as_autorelease([[GCImagePickerViewController alloc] init]);
    
    [self.navigationController pushViewController:viewController animated:YES];
}

- (void)handleMode2ButtonTapped:(id)sender
{
    UIImage *sampleImage = [UIImage imageNamed:@"sample_image2.jpg"];
    GCImageFilterViewController *viewController = gc_as_autorelease([[GCImageFilterViewController alloc] initWithInputImage:sampleImage completionHandler:^(UIImage *filteredImage) {
        
    }]);
    
    UINavigationController *navigationController = gc_as_autorelease([[UINavigationController alloc] initWithRootViewController:viewController]);
    
    [self presentViewController:navigationController animated:YES completion:^{
        
    }];
}

- (void)handleMode3ButtonTapped:(id)sender
{
    CGFloat navigationBarHeight = self.navigationController.navigationBar.frame.size.height;
    CGFloat statusBarHeight = [UIApplication sharedApplication].statusBarFrame.size.height;
    
    UIViewController *viewController1 = gc_as_autorelease([[UIViewController alloc] init]);
    GCImageFilterView *imageFilterView1 = nil;

    if (IS_IOS_7) {
        imageFilterView1 = [[GCImageFilterView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.view.bounds.size.width, self.view.bounds.size.height-navigationBarHeight-statusBarHeight) completionHandler:^(UIImage *filteredImage) {
            NSLog(@"Filtered image: %@", filteredImage);
        }];
    }
    else {
        imageFilterView1 = [[GCImageFilterView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.view.bounds.size.width, self.view.bounds.size.height-navigationBarHeight) completionHandler:^(UIImage *filteredImage) {
            NSLog(@"Filtered image: %@", filteredImage);
        }];
    }
    
    UIImage *sampleImage1 = [UIImage imageNamed:@"sample_image4.jpg"];
    [imageFilterView1 setInputImage:sampleImage1];
    [imageFilterView1 setNavigationBarHeight:navigationBarHeight];
    [imageFilterView1 setStatusBarHeight:statusBarHeight];
    [imageFilterView1 setContentMode:UIViewContentModeScaleAspectFit];
    [viewController1 setView:imageFilterView1];
    
    UIViewController *viewController2 = gc_as_autorelease([[UIViewController alloc] init]);
    GCImageFilterView *imageFilterView2 = nil;
    
    
    if (IS_IOS_7) {
        imageFilterView2 = [[GCImageFilterView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.view.bounds.size.width, self.view.bounds.size.height-navigationBarHeight-statusBarHeight) completionHandler:^(UIImage *filteredImage) {
            NSLog(@"Filtered image: %@", filteredImage);
        }];
    }
    else {
        imageFilterView2 = [[GCImageFilterView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, self.view.bounds.size.width, self.view.bounds.size.height-navigationBarHeight) completionHandler:^(UIImage *filteredImage) {
            NSLog(@"Filtered image: %@", filteredImage);
        }];
    }
    
    UIImage *sampleImage2 = [UIImage imageNamed:@"sample_image3.jpg"];
    [imageFilterView2 setInputImage:sampleImage2];
    [imageFilterView2 setNavigationBarHeight:navigationBarHeight];
    [imageFilterView2 setStatusBarHeight:statusBarHeight];
    [imageFilterView2 setContentMode:UIViewContentModeScaleAspectFit];
    [viewController2 setView:imageFilterView2];

    UITabBarController *tabViewController = gc_as_autorelease([[UITabBarController alloc] init]);
    [tabViewController setDelegate:self];
    [tabViewController setViewControllers:[NSArray arrayWithObjects:viewController1, viewController2, nil] animated:YES];
    
    UINavigationController *navigationController = gc_as_autorelease([[UINavigationController alloc] initWithRootViewController:tabViewController]);
    
    [self presentViewController:navigationController animated:YES completion:^{
        [viewController1.tabBarItem setTitle:@"Sample1"];
        [viewController1.tabBarItem setImage:[UIImage imageNamed:@"spotlight29.png"]];

        [viewController2.tabBarItem setTitle:@"Sample2"];
        [viewController2.tabBarItem setImage:[UIImage imageNamed:@"spotlight29.png"]];
    }];
}

- (void)tabBarController:(UITabBarController *)tabBarController didSelectViewController:(UIViewController *)viewController
{
    GCSettingsInfo *settingsInfo = [[GCSettingsContext sharedSettingsContext] loadSettingsInfo];
    [settingsInfo setEnableThemeSelection:YES];
    
    if (tabBarController.selectedIndex == 0) {
        [settingsInfo setNavigationBarTintColor:0xff88a4],
        [settingsInfo setFilterSelectionGridBackgroundColor:0xff88a4];
        [settingsInfo setFilterCanvasBackgroundColor:0x242424];
        [settingsInfo setFilterCategoryToolbarBackgroundColor:0xff7092];
    }
    else {
        [settingsInfo setNavigationBarTintColor:0x98c9bf],
        [settingsInfo setFilterSelectionGridBackgroundColor:0x98c9bf];
        [settingsInfo setFilterCanvasBackgroundColor:0x242424];
        [settingsInfo setFilterCategoryToolbarBackgroundColor:0xd3d3d3];
    }
    
    [[GCSettingsContext sharedSettingsContext] saveSettingsInfo:settingsInfo];
    
    [(GCImageFilterView *)(viewController.view) changeTheme];
}

@end
