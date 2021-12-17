/*
 * This file is part of the DrantWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import "DrantWebImageCompat.h"

@interface UIImage (drantForceDecode)

+ (nullable UIImage *)decodedImageWithImage:(nullable UIImage *)image;

+ (nullable UIImage *)decodedAndScaledDownImageWithImage:(nullable UIImage *)image;

@end
