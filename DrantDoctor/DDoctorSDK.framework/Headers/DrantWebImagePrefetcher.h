/*
 * This file is part of the DrantWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "DrantWebImageManager.h"

@class DrantWebImagePrefetcher;

@protocol DrantWebImagePrefetcherDelegate <NSObject>

@optional

/**
 * Called when an image was prefetched.
 *
 * @param imagePrefetcher The current image prefetcher
 * @param imageURL        The image url that was prefetched
 * @param finishedCount   The total number of images that were prefetched (successful or not)
 * @param totalCount      The total number of images that were to be prefetched
 */
- (void)imagePrefetcher:(nonnull DrantWebImagePrefetcher *)imagePrefetcher didPrefetchURL:(nullable NSURL *)imageURL finishedCount:(NSUInteger)finishedCount totalCount:(NSUInteger)totalCount;

/**
 * Called when all images are prefetched.
 * @param imagePrefetcher The current image prefetcher
 * @param totalCount      The total number of images that were prefetched (whether successful or not)
 * @param skippedCount    The total number of images that were skipped
 */
- (void)imagePrefetcher:(nonnull DrantWebImagePrefetcher *)imagePrefetcher didFinishWithTotalCount:(NSUInteger)totalCount skippedCount:(NSUInteger)skippedCount;

@end

typedef void(^DrantWebImagePrefetcherProgressBlock)(NSUInteger noOfFinishedUrls, NSUInteger noOfTotalUrls);
typedef void(^DrantWebImagePrefetcherCompletionBlock)(NSUInteger noOfFinishedUrls, NSUInteger noOfSkippedUrls);

/**
 * Prefetch some URLs in the cache for future use. Images are downloaded in low priority.
 */
@interface DrantWebImagePrefetcher : NSObject

/**
 *  The web image manager
 */
@property (strong, nonatomic, readonly, nonnull) DrantWebImageManager *manager;

/**
 * Maximum number of URLs to prefetch at the same time. Defaults to 3.
 */
@property (nonatomic, assign) NSUInteger maxConcurrentDownloads;

/**
 * DrantWebImageOptions for prefetcher. Defaults to DrantWebImageLowPriority.
 */
@property (nonatomic, assign) DrantWebImageOptions options;

/**
 * Queue options for Prefetcher. Defaults to Main Queue.
 */
@property (strong, nonatomic, nonnull) dispatch_queue_t prefetcherQueue;

@property (weak, nonatomic, nullable) id <DrantWebImagePrefetcherDelegate> delegate;

/**
 * Return the global image prefetcher instance.
 */
+ (nonnull instancetype)sharedImagePrefetcher;

/**
 * Allows you to instantiate a prefetcher with any arbitrary image manager.
 */
- (nonnull instancetype)initWithImageManager:(nonnull DrantWebImageManager *)manager NS_DESIGNATED_INITIALIZER;

/**
 * Assign list of URLs to let DrantWebImagePrefetcher to queue the prefetching,
 * currently one image is downloaded at a time,
 * and skips images for failed downloads and proceed to the next image in the list.
 * Any previously-running prefetch operations are canceled.
 *
 * @param urls list of URLs to prefetch
 */
- (void)prefetchURLs:(nullable NSArray<NSURL *> *)urls;

/**
 * Assign list of URLs to let DrantWebImagePrefetcher to queue the prefetching,
 * currently one image is downloaded at a time,
 * and skips images for failed downloads and proceed to the next image in the list.
 * Any previously-running prefetch operations are canceled.
 *
 * @param urls            list of URLs to prefetch
 * @param progressBlock   block to be called when progress updates; 
 *                        first parameter is the number of completed (successful or not) requests, 
 *                        second parameter is the total number of images originally requested to be prefetched
 * @param completionBlock block to be called when prefetching is completed
 *                        first param is the number of completed (successful or not) requests,
 *                        second parameter is the number of skipped requests
 */
- (void)prefetchURLs:(nullable NSArray<NSURL *> *)urls
            progress:(nullable DrantWebImagePrefetcherProgressBlock)progressBlock
           completed:(nullable DrantWebImagePrefetcherCompletionBlock)completionBlock;

/**
 * Remove and cancel queued list
 */
- (void)cancelPrefetching;


@end
