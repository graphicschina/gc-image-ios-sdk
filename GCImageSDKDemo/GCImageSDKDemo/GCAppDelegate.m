//
//  GCAppDelegate.m
//  GCImageSDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCViewController.h"
#import "GCAppDelegate.h"

@interface GCAppDelegate ()

@property (nonatomic, strong) GCViewController *viewController;

@end

@implementation GCAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];

    GCViewController *viewController = gc_as_autorelease([[GCViewController alloc] init]);
    [self setViewController:viewController];
    
    UINavigationController *navigationController = gc_as_autorelease([[UINavigationController alloc] initWithRootViewController:self.viewController]);
    
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
