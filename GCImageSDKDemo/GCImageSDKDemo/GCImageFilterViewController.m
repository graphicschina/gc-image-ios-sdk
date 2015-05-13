//
//  GCImageFilterViewController.m
//  GCImageSDKDemo
//
//  Created by Graphics China on 2015-5-1.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <GCImageSDK/GCImageSDK.h>

#import "GCImageViewController.h"
#import "GCImageFilterViewController.h"

#ifdef __IPHONE_7_0
# define STATUS_BAR_STYLE UIStatusBarStyleDefault
#else
# define STATUS_BAR_STYLE UIStatusBarStyleBlackTranslucent
#endif

@interface GCImageFilterViewController () <UITableViewDataSource, UITableViewDelegate> {
    NSArray *filterNames;
}

@property (nonatomic, strong)UITableView *tableView;

@end

@implementation GCImageFilterViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    [[UIApplication sharedApplication] setStatusBarStyle:STATUS_BAR_STYLE animated:YES];
    
    [self setTitle:@"Image Filter"];
    
    filterNames = [[GCImageFilterContext sharedImageFilterContext] supportedImageFilterNames];
    
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
    return [filterNames count];
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identifier = @"Filter Cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identifier];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
    }
    
    NSString *filterName = nil;
    
    if (indexPath.row < [filterNames count]) {
        filterName = [filterNames objectAtIndex:indexPath.row];
        NSString *filterDisplayName = [[GCImageFilterContext sharedImageFilterContext] supportedFilterDisplayName:filterName];
        [cell.textLabel setText:filterDisplayName];
    }
    
    return cell;
}

#pragma mark -
#pragma mark - UITableViewDelegate

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *filterName = nil;
    
    if (indexPath.row < [filterNames count]) {
        filterName = [filterNames objectAtIndex:indexPath.row];
        
        GCImageViewController *filterViewController = gc_as_autorelease([[GCImageViewController alloc] init]);
        [filterViewController setFilterName:filterName];
        
        [self.navigationController pushViewController:filterViewController animated:YES];
    }
}

@end
