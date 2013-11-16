/*
	Copyright (C) 2013 Quentin Mathe

	Author:  Quentin Mathe <quentin.mathe@gmail.com>
	Date:  October 2013
	License:  Modified BSD  (see COPYING)
 */

#import "COObject+ObjectManager.h"

@implementation COObject (ObjectManager)

- (NSDate *) modificationDate
{
	return [[self persistentRoot] modificationDate];
}

- (NSDate *) creationDate
{
	return [[self persistentRoot] creationDate];
}

- (NSNumber *) exportSize
{
	return [[[self persistentRoot] attributes] objectForKey: COPersistentRootAttributeExportSize];
}

- (NSNumber *) usedSize
{
	return [[[self persistentRoot] attributes] objectForKey: COPersistentRootAttributeUsedSize];
}

- (NSString *) sizeDescription
{
	ETByteSizeFormatter *formatter = AUTORELEASE([ETByteSizeFormatter new]);
	NSString *description = [formatter stringForObjectValue: [self usedSize]];
	
	if ([[self persistentRoot] isCopy])
	{
		description = [description stringByAppendingFormat: _(@" (%@ exported)"),
			[formatter stringForObjectValue: [self exportSize]]];
	}
	return description;
}

@end
