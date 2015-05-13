//
//  GCImageFilterInCategoryViewController.m
//  GCImageSDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCImageViewController.h"
#import "GCImageFilterInCategoryViewController.h"

#ifdef __IPHONE_7_0
# define STATUS_BAR_STYLE UIStatusBarStyleDefault
#else
# define STATUS_BAR_STYLE UIStatusBarStyleBlackTranslucent
#endif

@interface GCImageFilterInCategoryViewController () <UITableViewDataSource, UITableViewDelegate> {
    NSArray *filters;
}

@property (nonatomic, strong)UITableView *tableView;

@end

@implementation GCImageFilterInCategoryViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    [[UIApplication sharedApplication] setStatusBarStyle:STATUS_BAR_STYLE animated:YES];
    
    [self setTitle:@"Image Filter"];
    
    filters = [[GCImageFilterContext sharedImageFilterContext] getAllImageFilterInfoInCategory:self.filterCategoryName];
    
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
    return [filters count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"Filter Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    
    GCImageFilterInfo *filterInfo = nil;
    
    if (indexPath.row < [filters count]) {
        filterInfo = [filters objectAtIndex:indexPath.row];
        [cell.textLabel setText:filterInfo.filterDisplayName];
    }
    
    return cell;
}

#pragma mark -
#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    GCImageFilterInfo *filterInfo = nil;
    
    if (indexPath.row < [filters count]) {
        filterInfo = [filters objectAtIndex:indexPath.row];
        
        GCImageViewController *filterViewController = gc_as_autorelease([[GCImageViewController alloc] init]);
        [filterViewController setFilterName:filterInfo.filterName];
        
        [self.navigationController pushViewController:filterViewController animated:YES];
    }
}

@end
