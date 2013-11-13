//
//  IDMPhotoBrowser.h
//  IDMPhotoBrowser
//
//  Created by Michael Waterfall on 14/10/2010.
//  Copyright 2010 d3i. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import "IDMPhoto.h"
#import "IDMPhotoProtocol.h"
#import "IDMCaptionView.h"

// Delgate
@class IDMPhotoBrowser;
@protocol IDMPhotoBrowserDelegate <NSObject>
@optional
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didShowPhotoAtIndex:(NSUInteger)index;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didDismissAtPageIndex:(NSUInteger)index;
- (void)photoBrowser:(IDMPhotoBrowser *)photoBrowser didDismissActionSheetWithButtonIndex:(NSUInteger)buttonIndex photoIndex:(NSUInteger)photoIndex;
- (IDMCaptionView *)photoBrowser:(IDMPhotoBrowser *)photoBrowser captionViewForPhotoAtIndex:(NSUInteger)index;
@end

// IDMPhotoBrowser
@interface IDMPhotoBrowser : UIViewController <UIScrollViewDelegate, UIActionSheetDelegate> 

// Properties
@property (nonatomic, strong) id <IDMPhotoBrowserDelegate> delegate;

// Global
@property (nonatomic) BOOL autoHide;

//Top Toolbar customization
@property (nonatomic) BOOL displayTopToolbar;

//Bottom Toolbar customization
@property (nonatomic) BOOL displayToolbar;
@property (nonatomic) BOOL displayCounterLabel;
@property (nonatomic) BOOL displayArrowButton;
@property (nonatomic) BOOL displayActionButton;
@property (nonatomic, retain) NSArray *actionButtonTitles;
@property (nonatomic, weak) UIImage *leftArrowImage, *leftArrowSelectedImage;
@property (nonatomic, weak) UIImage *rightArrowImage, *rightArrowSelectedImage;

// View customization
@property (nonatomic) BOOL displayDoneButton;
@property (nonatomic) BOOL useWhiteBackgroundColor;
@property (nonatomic, weak) UIImage *doneButtonImage;
@property (nonatomic, weak) UIColor *trackTintColor, *progressTintColor;

@property (nonatomic, weak) UIImage *scaleImage;

// defines zooming of the background defauly 1.0
@property (nonatomic) float backgroundScaleFactor;

// animation time defult .28
@property (nonatomic) float animationDuration;

// Init
- (id)initWithPhotos:(NSArray *)photosArray;

// Init (animated)
- (id)initWithPhotos:(NSArray *)photosArray animatedFromView:(UIView*)view;

// Init with NSURL objects
- (id)initWithPhotoURLs:(NSArray *)photoURLsArray;

// Init with NSURL objects (animated)
- (id)initWithPhotoURLs:(NSArray *)photoURLsArray animatedFromView:(UIView*)view;

// Reloads the photo browser and refetches data
- (void)reloadData;

// Set page that photo browser starts on
- (void)setInitialPageIndex:(NSUInteger)index;

// Get IDMPhoto at index
- (id<IDMPhoto>)photoAtIndex:(NSUInteger)index;

// Dismiss Photo Browser
- (void)dismissPhotoBrowser;
- (void)dismissPhotoBrowser:(BOOL)animated;

// Customization Top toolbar item
- (void)addTopToolBarItem:(UIBarButtonItem *)item atPosition:(NSInteger)position;
- (void)addTopToolBarItem:(UIBarButtonItem *)item;
- (void)setTopToolBarItems:(NSArray *)items;

// Customization toolbar item
- (void)addToolBarItem:(UIBarButtonItem *)item atPosition:(NSInteger)position;
- (void)addToolBarItem:(UIBarButtonItem *)item;
- (void)setToolBarItems:(NSArray *)items;


// Change Sender View
//- (void)setSenderViewForAnimation:(UIView*)senderView;

@end
