//
//  GCImageFilterToolbar.h
//  GCImageSDK
//
//  Created by Graphics China on 2015-2-16.
//  Copyright (c) 2014~2015 Graphics China. All rights reserved.
//

#import <UIKit/UIKit.h>

/*!
 *  @brief  The block for handling the tapped event of any buttons in the image filter toolbar.
 *
 *  @param sender The tapped button.
 *  @param index  The index of the tapped button in all buttons.
 *
 *  @since v1.0.0
 */
typedef void(^CGImageFilterToolbarButtonTappedHandler)(id sender, NSInteger index);

/*!
 *  @brief  The class for the image filter toolbar. The toolbar has five buttons, the filter button,
 *          the frame button, the crop button, and the apply filter button, the cancel filter button, etc.
 *
 *  @since v1.0.0
 */
@interface GCImageFilterToolbar : UIView

@property (nonatomic, assign)UIInterfaceOrientation orientation; // The curent orientation of the view controller.

/*!
 *  @brief  The initialization method.
 *
 *  @param frame                   The frame of the toolbar.
 *  @param buttonImages            The image array for all buttons with normal status in the toolbar.
 *  @param buttonSelectedImages    The image array for all buttons with selected status in the toolbar.
 *  @param separatorPortraitWidth  The separator width in the portrait orientation.
 *  @param separatorLandscapeWidth The separator width in the landscape orientation.
 *  @param margin                  The margin of the first button and the last button.
 *  @param buttonTappedHandler     The block for handling the button tapped in the toolbar.
 *
 *  @return The instance of GCImageFilterToolbar.
 *
 *  @since v1.0.0
 */
- (instancetype)initWithFrame:(CGRect)frame buttonImages:(NSArray *)buttonImages buttonSelectedImages:(NSArray *)buttonSelectedImages separatorPortraitWidth:(CGFloat)separatorPortraitWidth separatorLandscapeWidth:(CGFloat)separatorLandscapeWidth margin:(CGFloat)margin buttonTappedHandler:(CGImageFilterToolbarButtonTappedHandler)buttonTappedHandler;

/*!
 *  @brief  The instance method to make a button in the toolbar be visible or hidden.
 *
 *  @param hidden Whether the button is visible or hidden.
 *  @param index  The button index in the toolbar.
 *
 *  @since v1.0.0
 */
- (void)setButtonHidden:(BOOL)hidden atIndex:(NSInteger)index;

/*!
 *  @brief  The instance method to enable a button in the toolbar.
 *
 *  @param index  The button index in the toolbar.
 *
 *  @since v1.0.0
 */
- (void)enableButtonAtIndex:(NSInteger)index;

@end
