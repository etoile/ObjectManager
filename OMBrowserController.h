/*
	Copyright (C) 2011 Quentin Mathe

	Author:  Quentin Mathe <quentin.mathe@gmail.com>
	Date:  November 2011
	License:  Modified BSD  (see COPYING)
 */

#import <Foundation/Foundation.h>
#import <AppKit/AppKit.h>
#import <EtoileFoundation/EtoileFoundation.h>
#ifndef GNUSTEP
#import <EtoileFoundation/GNUstep.h>
#endif
#import <CoreObject/CoreObject.h>
#import <EtoileUI/EtoileUI.h>
#import <EtoileUI/CoreObjectUI.h>
#import "OMController.h"

/** The controller to supervise the whole ObjectManager window */
@interface OMBrowserController : OMController <ETEditionCoordinator>
{
	ETLayoutItemGroup *contentViewItem;
	ETLayoutItemGroup *sourceListItem;
	ETLayoutItem *viewPopUpItem;
	ETLayoutItem *statusLabelItem;
	id <ETCollection> browsedGroup;

}

/** @taskunit Accessing UI Objects */

@property (nonatomic, retain) ETLayoutItemGroup *contentViewItem;
@property (nonatomic, readonly) ETLayoutItemGroup *contentViewWrapperItem;
@property (nonatomic, retain) ETLayoutItemGroup *sourceListItem;
@property (nonatomic, readonly) ETLayoutItemGroup *topBarItem;
@property (nonatomic, retain) ETLayoutItem *viewPopUpItem;
@property (nonatomic, readonly) ETLayoutItem *tagFilterFieldItem;
@property (nonatomic, readonly) ETLayoutItemGroup *tagFilterEditorItem;

/** @taskunit Accessing Model Objects */

@property (nonatomic, retain) id <ETCollection> browsedGroup;
@property (nonatomic, readonly) COSmartGroup *allObjectGroup;

/** @taskunit Selection */

@property (nonatomic, readonly) id selectedObject;

- (id) selectedObjectInContentView;
- (id) selectedObjectsInSourceList;

/** @taskunit Notifications */

- (void) sourceListSelectionDidChange: (NSNotification *)aNotif;
- (void) tagFilterEditorSelectionDidChange: (NSNotification *)aNotif;

/** @taskunit Edition Coordinator */

- (void) didBecomeFocusedItem: (ETLayoutItem *)anItem;
- (void) didResignFocusedItem: (ETLayoutItem *)anItem;

/** @taskunit Presentation */

- (void) showTagFilterEditor;
- (void) hideTagFilterEditor;
- (BOOL) isInspectorHidden;
- (void) showInspector;
- (void) hideInspector;

/** @taskunit Object Insertion and Deletion Actions */

/**
 * We use a dedicated -addNewObject: action and not add: to force this action 
 * message to be dispatched on OMBrowserController rather than directly on 
 * OMBrowserContentController in the responder chain.
 *
 * EtoileUI requires that children doesn't access or depend their parent 
 * related aspects (all requests must be sent downwards in the item tree). So 
 * OMBrowserController can access OMBrowserContentController, but the reverse 
 * is not true.
 */
- (IBAction) addNewObject: (id)sender;
- (IBAction) addNewObjectFromTemplate: (id)sender;
- (IBAction) addNewTag: (id)sender;
- (IBAction) addNewGroup: (id)sender;
- (IBAction) duplicate: (id)sender;
/**
 * We use a dedicated -delete: action and not remove: to force this action 
 * message to be dispatched on OMBrowserController rather than directly on 
 * OMBrowserContentController in the responder chain.
 *
 * See explanations in -addNewObject:.
 */
- (IBAction) delete: (id)sender;

/** @taskunit Presentation Actions */

- (IBAction) changePresentationViewFromPopUp: (id)sender;
- (IBAction) changePresentationViewFromMenuItem: (id)sender;
- (IBAction) changeInspectorViewFromMenuItem: (id)sender;
- (IBAction) toggleInspector: (id)sender;

/** @taskunit Other Object Actions */

- (IBAction) doubleClick: (id)sender;
- (IBAction) search: (id)sender;
- (IBAction) filter: (id)sender;
- (IBAction) resetTagFiltering: (id)sender;
- (IBAction) open: (id)sender;
- (IBAction) markVersion: (id)sender;
- (IBAction) revertTo: (id)sender;
- (IBAction) browseHistory: (id)sender;
- (IBAction) import: (id)sender;
- (IBAction) export: (id)sender;
- (IBAction) selectAllExceptInSourceList: (id)sender;

@end
