/*
 * This file is part of the DrantWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "DrantWebImageCompat.h"

#if DRANT_UIKIT || DRANT_MAC

#import "DrantWebImageManager.h"

// These methods are used to support canceling for UIView image loading, it's designed to be used internal but not external.
// All the stored operations are weak, so it will be dalloced after image loading finished. If you need to store operations, use your own class to keep a strong reference for them.
@interface UIView (drantWebCacheOperation)

/**
 *  Set the image load operation (storage in a UIView based weak map table)
 *
 *  @param operation the operation
 *  @param key       key for storing the operation
 */
- (void)d_setImageLoadOperation:(nullable id<DrantWebImageOperation>)operation forKey:(nullable NSString *)key;

/**
 *  Cancel all operations for the current UIView and key
 *
 *  @param key key for identifying the operations
 */
- (void)d_cancelImageLoadOperationWithKey:(nullable NSString *)key;

/**
 *  Just remove the operations corresponding to the current UIView and key without cancelling them
 *
 *  @param key key for identifying the operations
 */
- (void)d_removeImageLoadOperationWithKey:(nullable NSString *)key;

@end

#endif
