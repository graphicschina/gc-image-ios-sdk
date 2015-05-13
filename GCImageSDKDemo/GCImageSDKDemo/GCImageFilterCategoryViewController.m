//
//  GCImageFilterCategoryViewController.m
//  GCImageSDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCImageFilterInCategoryViewController.h"
#import "GCImageFilterCategoryViewController.h"

#ifdef __IPHONE_7_0
# define STATUS_BAR_STYLE UIStatusBarStyleDefault
#else
# define STATUS_BAR_STYLE UIStatusBarStyleBlackTranslucent
#endif

@interface GCImageFilterCategoryViewController () <UITableViewDataSource, UITableViewDelegate> {
    NSArray *filterCategories;
}

@property (nonatomic, strong)UITableView *tableView;

@end

@implementation GCImageFilterCategoryViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    [[UIApplication sharedApplication] setStatusBarStyle:STATUS_BAR_STYLE animated:YES];
    
    [self setTitle:@"Image Filter Category"];
    
    filterCategories = [[GCImageFilterContext sharedImageFilterContext] getAllImageFilterCategoryInfo];
    
    _tableView = [[UITableView alloc] initWithFrame:self.view.bounds style:UITableViewStylePlain];
    [self.tableView setDataSource:self];
    [self.tableView setDelegate:self];
    [self setView:self.tableView];
    
    [self.tableView reloadData];
}

- (void)dealloc
{
    gc_as_release(_tableView);
    gc_as_superdealloc();
}

#pragma mark -
#pragma mark - UITableViewDataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return [filterCategories count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"Filter Category Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    
    GCImageFilterCategoryInfo *categoryInfo = nil;
    
    if (indexPath.row < [filterCategories count]) {
        categoryInfo = [filterCategories objectAtIndex:indexPath.row];
        [cell.textLabel setText:categoryInfo.filterCategoryDisplayName];
    }
    
    return cell;
}

#pragma mark -
#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    GCImageFilterCategoryInfo *categoryInfo = nil;
    
    if (indexPath.row < [filterCategories count]) {
        categoryInfo = [filterCategories objectAtIndex:indexPath.row];
        
        GCImageFilterInCategoryViewController *filterViewController = gc_as_autorelease([[GCImageFilterInCategoryViewController alloc] init]);
        [filterViewController setFilterCategoryName:categoryInfo.filterCategoryName];
        
        [self.navigationController pushViewController:filterViewController animated:YES];
    }
}

@end
