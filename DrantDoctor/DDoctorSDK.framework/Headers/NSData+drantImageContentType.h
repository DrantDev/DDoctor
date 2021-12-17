/*
 * This file is part of the DrantWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 * (c) Fabrice Aneche
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "DrantWebImageCompat.h"

typedef NS_ENUM(NSInteger, DImageFormat) {
    DImageFormatUndefined = -1,
    DImageFormatJPEG = 0,
    DImageFormatPNG,
    DImageFormatGIF,
    DImageFormatTIFF,
    DImageFormatWebP,
    DImageFormatHEIC
};

@interface NSData (hhImageContentType)

/**
 *  Return image format
 *
 *  @param data the input image data
 *
 *  @return the image format as `HHImageFormat` (enum)
 */
+ (DImageFormat)d_imageFormatForImageData:(nullable NSData *)data;

/**
 Convert HHImageFormat to UTType

 @param format Format as HHImageFormat
 @return The UTType as CFStringRef
 */
+ (nonnull CFStringRef)d_UTTypeFromHHImageFormat:(DImageFormat)format;

@end
