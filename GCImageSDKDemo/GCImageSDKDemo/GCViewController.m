//
//  GCViewController.m
//  GCImage+UISDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCImageFilterViewController.h"
#import "GCImageMacroFilterViewController.h"
#import "GCImageFilterCategoryViewController.h"
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
    [mode1Button setTitle:@"Image Filter Category" forState:UIControlStateNormal];
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
    [mode2Button setTitle:@"Image Filter" forState:UIControlStateNormal];
    [mode2Button setBackgroundColor:[UIColor redColor]];
    
    [mode2Button setFrame:CGRectMake((self.view.frame.size.width-kGCImageUISDKDemoViewDefaultButtonWidth)/2, mode1Button.frame.origin.y+mode1Button.frame.size.height+20.0f, kGCImageUISDKDemoViewDefaultButtonWidth, kGCImageUISDKDemoViewDefaultButtonHeight)];
    
    [mode2Button setClipsToBounds:YES];
    [mode2Button.layer setCornerRadius:5.0f];
    [mode2Button addTarget:self action:@selector(handleMode2ButtonTapped:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:mode2Button];
    
    UIButton *mode3Button = [UIButton buttonWithType:UIButtonTypeCustom];
    [mode3Button setTitle:@"Image Macro Filter" forState:UIControlStateNormal];
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
    GCImageFilterCategoryViewController *viewController = gc_as_autorelease([[GCImageFilterCategoryViewController alloc] init]);
    
    [self.navigationController pushViewController:viewController animated:YES];
}

- (void)handleMode2ButtonTapped:(id)sender
{
    GCImageFilterViewController *viewController = gc_as_autorelease([[GCImageFilterViewController alloc] init]);
    
    [self.navigationController pushViewController:viewController animated:YES];
}

- (void)handleMode3ButtonTapped:(id)sender
{
    GCImageMacroFilterViewController *viewController = gc_as_autorelease([[GCImageMacroFilterViewController alloc] init]);
    
    [self.navigationController pushViewController:viewController animated:YES];
}

@end
