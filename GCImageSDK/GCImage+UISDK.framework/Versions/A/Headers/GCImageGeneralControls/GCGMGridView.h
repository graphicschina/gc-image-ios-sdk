//
//  GMGridView.h
//  GMGridView
//
//  Created by Gulam Moledina on 11-10-09.
//  Copyright (C) 2011 by Gulam Moledina.
//
//  Latest code can be found on GitHub: https://github.com/gmoledina/GMGridView
// 
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
// 
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
// 
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <UIKit/UIKit.h>
#import "GCGMGridView-Constants.h"
#import "GCGMGridViewCell.h"

@protocol GCGMGridViewDataSource;
@protocol GCGMGridViewActionDelegate;
@protocol GCGMGridViewSortingDelegate;
@protocol GCGMGridViewTransformationDelegate;
@protocol GCGMGridViewLayoutStrategy;

typedef enum
{
    GCGMGridViewStylePush = 0,
    GCGMGridViewStyleSwap
} GCGMGridViewStyle;

typedef enum
{
	GCGMGridViewScrollPositionNone,
	GCGMGridViewScrollPositionTop,
	GCGMGridViewScrollPositionMiddle,
	GCGMGridViewScrollPositionBottom
} GCGMGridViewScrollPosition;

typedef enum
{
    GCGMGridViewItemAnimationNone = 0,
    GCGMGridViewItemAnimationFade,
    GCGMGridViewItemAnimationScroll = 1<<7 // scroll to the item before showing the animation
} GCGMGridViewItemAnimation;

//////////////////////////////////////////////////////////////
#pragma mark Interface GCGMGridView
//////////////////////////////////////////////////////////////

@interface GCGMGridView : UIScrollView

// Delegates
@property (nonatomic, gm_weak) IBOutlet NSObject<GCGMGridViewDataSource> *dataSource;                    // Required
@property (nonatomic, gm_weak) IBOutlet NSObject<GCGMGridViewActionDelegate> *actionDelegate;            // Optional - to get taps callback & deleting item
@property (nonatomic, gm_weak) IBOutlet NSObject<GCGMGridViewSortingDelegate> *sortingDelegate;          // Optional - to enable sorting
@property (nonatomic, gm_weak) IBOutlet NSObject<GCGMGridViewTransformationDelegate> *transformDelegate; // Optional - to enable fullsize mode

// Layout Strategy
@property (nonatomic, strong) IBOutlet id<GCGMGridViewLayoutStrategy> layoutStrategy; // Default is GCGMGridViewLayoutVerticalStrategy

// Editing Mode
@property (nonatomic, getter=isEditing) BOOL editing; // Default is NO - When set to YES, all gestures are disabled and delete buttons shows up on cells
- (void)setEditing:(BOOL)editing animated:(BOOL)animated;

// Customizing Options
@property (nonatomic, gm_weak) IBOutlet UIView *mainSuperView;        // Default is self
@property (nonatomic) GCGMGridViewStyle style;                          // Default is GCGMGridViewStyleSwap
@property (nonatomic) NSInteger itemSpacing;                          // Default is 10
@property (nonatomic) BOOL centerGrid;                                // Default is YES
@property (nonatomic) UIEdgeInsets minEdgeInsets;                     // Default is (5, 5, 5, 5)
@property (nonatomic) CFTimeInterval minimumPressDuration;            // Default is 0.2; if set to 0, the view wont be scrollable
@property (nonatomic) BOOL showFullSizeViewWithAlphaWhenTransforming; // Default is YES - not working right now
@property (nonatomic) BOOL enableEditOnLongPress;                     // Default is NO
@property (nonatomic) BOOL disableEditOnEmptySpaceTap;                // Default is NO

@property (nonatomic, readonly) UIScrollView *scrollView __attribute__((deprecated)); // The grid now inherits directly from UIScrollView

// Reusable cells
- (GCGMGridViewCell *)dequeueReusableCell;                              // Should be called in GCGMGridView:cellForItemAtIndex: to reuse a cell
- (GCGMGridViewCell *)dequeueReusableCellWithIdentifier:(NSString *)identifier;

// Cells
- (GCGMGridViewCell *)cellForItemAtIndex:(NSInteger)position;           // Might return nil if cell not loaded yet

// Actions
- (void)reloadData;
- (void)insertObjectAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)insertObjectAtIndex:(NSInteger)index withAnimation:(GCGMGridViewItemAnimation)animation;
- (void)removeObjectAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)removeObjectAtIndex:(NSInteger)index withAnimation:(GCGMGridViewItemAnimation)animation;
- (void)reloadObjectAtIndex:(NSInteger)index animated:(BOOL)animated;
- (void)reloadObjectAtIndex:(NSInteger)index withAnimation:(GCGMGridViewItemAnimation)animation;
- (void)swapObjectAtIndex:(NSInteger)index1 withObjectAtIndex:(NSInteger)index2 animated:(BOOL)animated;
- (void)swapObjectAtIndex:(NSInteger)index1 withObjectAtIndex:(NSInteger)index2 withAnimation:(GCGMGridViewItemAnimation)animation;
- (void)scrollToObjectAtIndex:(NSInteger)index atScrollPosition:(GCGMGridViewScrollPosition)scrollPosition animated:(BOOL)animated;

// Force the grid to update properties in an (probably) animated way.
- (void)layoutSubviewsWithAnimation:(GCGMGridViewItemAnimation)animation;

@end


//////////////////////////////////////////////////////////////
#pragma mark Protocol GCGMGridViewDataSource
//////////////////////////////////////////////////////////////

@protocol GCGMGridViewDataSource <NSObject>

@required
// Populating subview items 
- (NSInteger)numberOfItemsInGCGMGridView:(GCGMGridView *)gridView;
- (CGSize)GCGMGridView:(GCGMGridView *)gridView sizeForItemsInInterfaceOrientation:(UIInterfaceOrientation)orientation;
- (GCGMGridViewCell *)GCGMGridView:(GCGMGridView *)gridView cellForItemAtIndex:(NSInteger)index;

@optional
// Allow a cell to be deletable. If not implemented, YES is assumed.
- (BOOL)GCGMGridView:(GCGMGridView *)gridView canDeleteItemAtIndex:(NSInteger)index;

@end


//////////////////////////////////////////////////////////////
#pragma mark Protocol GCGMGridViewActionDelegate
//////////////////////////////////////////////////////////////

@protocol GCGMGridViewActionDelegate <NSObject>

@required
- (void)GCGMGridView:(GCGMGridView *)gridView didTapOnItemAtIndex:(NSInteger)position;

@optional
// Tap on space without any items
- (void)GCGMGridViewDidTapOnEmptySpace:(GCGMGridView *)gridView;
// Called when the delete-button has been pressed. Required to enable editing mode.
// This method wont delete the cell automatically. Call the delete method of the gridView when appropriate.
- (void)GCGMGridView:(GCGMGridView *)gridView processDeleteActionForItemAtIndex:(NSInteger)index;

- (void)GCGMGridView:(GCGMGridView *)gridView changedEdit:(BOOL)edit;

@end


//////////////////////////////////////////////////////////////
#pragma mark Protocol GCGMGridViewSortingDelegate
//////////////////////////////////////////////////////////////

@protocol GCGMGridViewSortingDelegate <NSObject>

@required
// Item moved - right place to update the data structure
- (void)GCGMGridView:(GCGMGridView *)gridView moveItemAtIndex:(NSInteger)oldIndex toIndex:(NSInteger)newIndex;
- (void)GCGMGridView:(GCGMGridView *)gridView exchangeItemAtIndex:(NSInteger)index1 withItemAtIndex:(NSInteger)index2;

@optional
// Sorting started/ended - indexes are not specified on purpose (not the right place to update data structure)
- (void)GCGMGridView:(GCGMGridView *)gridView didStartMovingCell:(GCGMGridViewCell *)cell;
- (void)GCGMGridView:(GCGMGridView *)gridView didEndMovingCell:(GCGMGridViewCell *)cell;
// Enable/Disable the shaking behavior of an item being moved
- (BOOL)GCGMGridView:(GCGMGridView *)gridView shouldAllowShakingBehaviorWhenMovingCell:(GCGMGridViewCell *)view atIndex:(NSInteger)index;

@end

//////////////////////////////////////////////////////////////
#pragma mark Protocol GCGMGridViewTransformationDelegate
//////////////////////////////////////////////////////////////

@protocol GCGMGridViewTransformationDelegate <NSObject>

@required
// Fullsize
- (CGSize)GCGMGridView:(GCGMGridView *)gridView sizeInFullSizeForCell:(GCGMGridViewCell *)cell atIndex:(NSInteger)index inInterfaceOrientation:(UIInterfaceOrientation)orientation;
- (UIView *)GCGMGridView:(GCGMGridView *)gridView fullSizeViewForCell:(GCGMGridViewCell *)cell atIndex:(NSInteger)index;

// Transformation (pinch, drag, rotate) of the item
@optional
- (void)GCGMGridView:(GCGMGridView *)gridView didStartTransformingCell:(GCGMGridViewCell *)cell;
- (void)GCGMGridView:(GCGMGridView *)gridView didEnterFullSizeForCell:(GCGMGridViewCell *)cell;
- (void)GCGMGridView:(GCGMGridView *)gridView didEndTransformingCell:(GCGMGridViewCell *)cell;

@end
