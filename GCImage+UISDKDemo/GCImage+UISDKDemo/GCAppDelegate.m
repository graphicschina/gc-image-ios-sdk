//
//  GCAppDelegate.m
//  GCImage+UISDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImage+UISDK/GCImage+UISDK.h>

#import "GCViewController.h"
#import "GCAppDelegate.h"

@interface GCAppDelegate ()

@property (nonatomic, gc_as_strongprop)GCViewController *viewController;

@end

@implementation GCAppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    GCSettingsInfo *settingsInfo = [[GCSettingsContext sharedSettingsContext] loadSettingsInfo];
    [settingsInfo setEnableThemeSelection:YES];
//    [settingsInfo setNavigationBarTintColor:0xff88a4],
//    [settingsInfo setFilterSelectionGridBackgroundColor:0xff88a4];
//    [settingsInfo setFilterCanvasBackgroundColor:0x242424];
//    [settingsInfo setFilterCategoryToolbarBackgroundColor:0xff7092];
    [[GCSettingsContext sharedSettingsContext] saveSettingsInfo:settingsInfo];

    GCViewController *imagePickerViewController = gc_as_autorelease([[GCViewController alloc] init]);
    [self setViewController:imagePickerViewController];
    
    GCPortraitNavigationController *navigationController = gc_as_autorelease([[GCPortraitNavigationController alloc] initWithRootViewController:self.viewController]);
    
    [self.window setRootViewController:navigationController];
    [self.window setBackgroundColor:[UIColor whiteColor]];
    [self.window makeKeyAndVisible];

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{
}

- (void)applicationDidEnterBackground:(UIApplication *)application
{
}

- (void)applicationWillEnterForeground:(UIApplication *)application
{
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
}

- (void)applicationWillTerminate:(UIApplication *)application
{
}

@end
