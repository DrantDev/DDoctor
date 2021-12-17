/*
 * This file is part of the DrantWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "DrantWebImageDownloader.h"
#import "DrantWebImageOperation.h"

FOUNDATION_EXPORT NSString * _Nonnull const DrantWebImageDownloadStartNotification;
FOUNDATION_EXPORT NSString * _Nonnull const DrantWebImageDownloadReceiveResponseNotification;
FOUNDATION_EXPORT NSString * _Nonnull const DrantWebImageDownloadStopNotification;
FOUNDATION_EXPORT NSString * _Nonnull const DrantWebImageDownloadFinishNotification;



/**
 Describes a downloader operation. If one wants to use a custom downloader op, it needs to inherit from `NSOperation` and conform to this protocol
 For the description about these methods, see `DrantWebImageDownloaderOperation`
 */
@protocol DrantWebImageDownloaderOperationInterface<NSObject>

- (nonnull instancetype)initWithRequest:(nullable NSURLRequest *)request
                              inSession:(nullable NSURLSession *)session
                                options:(DrantWebImageDownloaderOptions)options;

- (nullable id)addHandlersForProgress:(nullable DrantWebImageDownloaderProgressBlock)progressBlock
                            completed:(nullable DrantWebImageDownloaderCompletedBlock)completedBlock;

- (BOOL)shouldDecompressImages;
- (void)setShouldDecompressImages:(BOOL)value;

- (nullable NSURLCredential *)credential;
- (void)setCredential:(nullable NSURLCredential *)value;

- (BOOL)cancel:(nullable id)token;

@end


@interface DrantWebImageDownloaderOperation : NSOperation <DrantWebImageDownloaderOperationInterface, DrantWebImageOperation, NSURLSessionTaskDelegate, NSURLSessionDataDelegate>

/**
 * The request used by the operation's task.
 */
@property (strong, nonatomic, readonly, nullable) NSURLRequest *request;

/**
 * The operation's task
 */
@property (strong, nonatomic, readonly, nullable) NSURLSessionTask *dataTask;


@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 *  Was used to determine whether the URL connection should consult the credential storage for authenticating the connection.
 *  @deprecated Not used for a couple of versions
 */
@property (nonatomic, assign) BOOL shouldUseCredentialStorage __deprecated_msg("Property deprecated. Does nothing. Kept only for backwards compatibility");

/**
 * The credential used for authentication challenges in `-URLSession:task:didReceiveChallenge:completionHandler:`.
 *
 * This will be overridden by any shared credentials that exist for the username or password of the request URL, if present.
 */
@property (nonatomic, strong, nullable) NSURLCredential *credential;

/**
 * The DrantWebImageDownloaderOptions for the receiver.
 */
@property (assign, nonatomic, readonly) DrantWebImageDownloaderOptions options;

/**
 * The expected size of data.
 */
@property (assign, nonatomic) NSInteger expectedSize;

/**
 * The response returned by the operation's task.
 */
@property (strong, nonatomic, nullable) NSURLResponse *response;

/**
 *  Initializes a `DrantWebImageDownloaderOperation` object
 *
 *  @see DrantWebImageDownloaderOperation
 *
 *  @param request        the URL request
 *  @param session        the URL session in which this operation will run
 *  @param options        downloader options
 *
 *  @return the initialized instance
 */
- (nonnull instancetype)initWithRequest:(nullable NSURLRequest *)request
                              inSession:(nullable NSURLSession *)session
                                options:(DrantWebImageDownloaderOptions)options NS_DESIGNATED_INITIALIZER;

/**
 *  Adds handlers for progress and completion. Returns a tokent that can be passed to -cancel: to cancel this set of
 *  callbacks.
 *
 *  @param progressBlock  the block executed when a new chunk of data arrives.
 *                        @note the progress block is executed on a background queue
 *  @param completedBlock the block executed when the download is done.
 *                        @note the completed block is executed on the main queue for success. If errors are found, there is a chance the block will be executed on a background queue
 *
 *  @return the token to use to cancel this set of handlers
 */
- (nullable id)addHandlersForProgress:(nullable DrantWebImageDownloaderProgressBlock)progressBlock
                            completed:(nullable DrantWebImageDownloaderCompletedBlock)completedBlock;

/**
 *  Cancels a set of callbacks. Once all callbacks are canceled, the operation is cancelled.
 *
 *  @param token the token representing a set of callbacks to cancel
 *
 *  @return YES if the operation was stopped because this was the last token to be canceled. NO otherwise.
 */
- (BOOL)cancel:(nullable id)token;

@end
