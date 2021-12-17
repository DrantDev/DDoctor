/*
 * This file is part of the DrantWebImage package.
 * (c) Olivier Poitrey <rs@dailymotion.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

#import <Foundation/Foundation.h>
#import "DrantWebImageCompat.h"
#import "DrantWebImageOperation.h"

typedef NS_OPTIONS(NSUInteger, DrantWebImageDownloaderOptions) {
    /**
     * Put the download in the low queue priority and task priority.
     */
    DrantWebImageDownloaderLowPriority = 1 << 0,
    
    /**
     * This flag enables progressive download, the image is displayed progressively during download as a browser would do.
     */
    DrantWebImageDownloaderProgressiveDownload = 1 << 1,

    /**
     * By default, request prevent the use of NSURLCache. With this flag, NSURLCache
     * is used with default policies.
     */
    DrantWebImageDownloaderUseNSURLCache = 1 << 2,

    /**
     * Call completion block with nil image/imageData if the image was read from NSURLCache
     * (to be combined with `DrantWebImageDownloaderUseNSURLCache`).
     */
    DrantWebImageDownloaderIgnoreCachedResponse = 1 << 3,
    
    /**
     * In iOS 4+, continue the download of the image if the app goes to background. This is achieved by asking the system for
     * extra time in background to let the request finish. If the background task expires the operation will be cancelled.
     */
    DrantWebImageDownloaderContinueInBackground = 1 << 4,

    /**
     * Handles cookies stored in NSHTTPCookieStore by setting 
     * NSMutableURLRequest.HTTPShouldHandleCookies = YES;
     */
    DrantWebImageDownloaderHandleCookies = 1 << 5,

    /**
     * Enable to allow untrusted SSL certificates.
     * Useful for testing purposes. Use with caution in production.
     */
    DrantWebImageDownloaderAllowInvalidSSLCertificates = 1 << 6,

    /**
     * Put the download in the high queue priority and task priority.
     */
    DrantWebImageDownloaderHighPriority = 1 << 7,
    
    /**
     * Scale down the image
     */
    DrantWebImageDownloaderScaleDownLargeImages = 1 << 8,
};

typedef NS_ENUM(NSInteger, DrantWebImageDownloaderExecutionOrder) {
    /**
     * Default value. All download operations will execute in queue style (first-in-first-out).
     */
    DrantWebImageDownloaderFIFOExecutionOrder,

    /**
     * All download operations will execute in stack style (last-in-first-out).
     */
    DrantWebImageDownloaderLIFOExecutionOrder
};

FOUNDATION_EXPORT NSString * _Nonnull const DrantWebImageDownloadStartNotification;
FOUNDATION_EXPORT NSString * _Nonnull const DrantWebImageDownloadStopNotification;

typedef void(^DrantWebImageDownloaderProgressBlock)(NSInteger receivedSize, NSInteger expectedSize, NSURL * _Nullable targetURL);

typedef void(^DrantWebImageDownloaderCompletedBlock)(UIImage * _Nullable image, NSData * _Nullable data, NSError * _Nullable error, BOOL finished);

typedef NSDictionary<NSString *, NSString *> HHHTTPHeadersDictionary;
typedef NSMutableDictionary<NSString *, NSString *> HHHTTPHeadersMutableDictionary;

typedef HHHTTPHeadersDictionary * _Nullable (^DrantWebImageDownloaderHeadersFilterBlock)(NSURL * _Nullable url, HHHTTPHeadersDictionary * _Nullable headers);

/**
 *  A token associated with each download. Can be used to cancel a download
 */
@interface DrantWebImageDownloadToken : NSObject <DrantWebImageOperation>

/**
 The download's URL. This should be readonly and you should not modify
 */
@property (nonatomic, strong, nullable) NSURL *url;
/**
 The cancel token taken from `addHandlersForProgress:completed`. This should be readonly and you should not modify
 @note use `-[DrantWebImageDownloadToken cancel]` to cancel the token
 */
@property (nonatomic, strong, nullable) id downloadOperationCancelToken;

@end


/**
 * Asynchronous downloader dedicated and optimized for image loading.
 */
@interface DrantWebImageDownloader : NSObject

/**
 * Decompressing images that are downloaded and cached can improve performance but can consume lot of memory.
 * Defaults to YES. Set this to NO if you are experiencing a crash due to excessive memory consumption.
 */
@property (assign, nonatomic) BOOL shouldDecompressImages;

/**
 *  The maximum number of concurrent downloads
 */
@property (assign, nonatomic) NSInteger maxConcurrentDownloads;

/**
 * Shows the current amount of downloads that still need to be downloaded
 */
@property (readonly, nonatomic) NSUInteger currentDownloadCount;

/**
 *  The timeout value (in seconds) for the download operation. Default: 15.0.
 */
@property (assign, nonatomic) NSTimeInterval downloadTimeout;

/**
 * The configuration in use by the internal NSURLSession.
 * Mutating this object directly has no effect.
 *
 * @see createNewSessionWithConfiguration:
 */
@property (readonly, nonatomic, nonnull) NSURLSessionConfiguration *sessionConfiguration;


/**
 * Changes download operations execution order. Default value is `DrantWebImageDownloaderFIFOExecutionOrder`.
 */
@property (assign, nonatomic) DrantWebImageDownloaderExecutionOrder executionOrder;

/**
 *  Singleton method, returns the shared instance
 *
 *  @return global shared instance of downloader class
 */
+ (nonnull instancetype)sharedDownloader;

/**
 *  Set the default URL credential to be set for request operations.
 */
@property (strong, nonatomic, nullable) NSURLCredential *urlCredential;

/**
 * Set username
 */
@property (strong, nonatomic, nullable) NSString *username;

/**
 * Set password
 */
@property (strong, nonatomic, nullable) NSString *password;

/**
 * Set filter to pick headers for downloading image HTTP request.
 *
 * This block will be invoked for each downloading image request, returned
 * NHHictionary will be used as headers in corresponding HTTP request.
 */
@property (nonatomic, copy, nullable) DrantWebImageDownloaderHeadersFilterBlock headersFilter;

/**
 * Creates an instance of a downloader with specified session configuration.
 * @note `timeoutIntervalForRequest` is going to be overwritten.
 * @return new instance of downloader class
 */
- (nonnull instancetype)initWithSessionConfiguration:(nullable NSURLSessionConfiguration *)sessionConfiguration NS_DESIGNATED_INITIALIZER;

/**
 * Set a value for a HTTP header to be appended to each download HTTP request.
 *
 * @param value The value for the header field. Use `nil` value to remove the header.
 * @param field The name of the header field to set.
 */
- (void)setValue:(nullable NSString *)value forHTTPHeaderField:(nullable NSString *)field;

/**
 * Returns the value of the specified HTTP header field.
 *
 * @return The value associated with the header field field, or `nil` if there is no corresponding header field.
 */
- (nullable NSString *)valueForHTTPHeaderField:(nullable NSString *)field;

/**
 * Sets a subclass of `DrantWebImageDownloaderOperation` as the default
 * `NSOperation` to be used each time DrantWebImage constructs a request
 * operation to download an image.
 *
 * @param operationClass The subclass of `DrantWebImageDownloaderOperation` to set 
 *        as default. Passing `nil` will revert to `DrantWebImageDownloaderOperation`.
 */
- (void)setOperationClass:(nullable Class)operationClass;

/**
 * Creates a DrantWebImageDownloader async downloader instance with a given URL
 *
 * The delegate will be informed when the image is finish downloaded or an error has happen.
 *
 * @see DrantWebImageDownloaderDelegate
 *
 * @param url            The URL to the image to download
 * @param options        The options to be used for this download
 * @param progressBlock  A block called repeatedly while the image is downloading
 *                       @note the progress block is executed on a background queue
 * @param completedBlock A block called once the download is completed.
 *                       If the download succeeded, the image parameter is set, in case of error,
 *                       error parameter is set with the error. The last parameter is always YES
 *                       if DrantWebImageDownloaderProgressiveDownload isn't use. With the
 *                       DrantWebImageDownloaderProgressiveDownload option, this block is called
 *                       repeatedly with the partial image object and the finished argument set to NO
 *                       before to be called a last time with the full image and finished argument
 *                       set to YES. In case of error, the finished argument is always YES.
 *
 * @return A token (DrantWebImageDownloadToken) that can be passed to -cancel: to cancel this operation
 */
- (nullable DrantWebImageDownloadToken *)downloadImageWithURL:(nullable NSURL *)url
                                                   options:(DrantWebImageDownloaderOptions)options
                                                  progress:(nullable DrantWebImageDownloaderProgressBlock)progressBlock
                                                 completed:(nullable DrantWebImageDownloaderCompletedBlock)completedBlock;

/**
 * Cancels a download that was previously queued using -downloadImageWithURL:options:progress:completed:
 *
 * @param token The token received from -downloadImageWithURL:options:progress:completed: that should be canceled.
 */
- (void)cancel:(nullable DrantWebImageDownloadToken *)token;

/**
 * Sets the download queue suspension state
 */
- (void)setSuspended:(BOOL)suspended;

/**
 * Cancels all download operations in the queue
 */
- (void)cancelAllDownloads;

/**
 * Forces DrantWebImageDownloader to create and use a new NSURLSession that is
 * initialized with the given configuration.
 * @note All existing download operations in the queue will be cancelled.
 * @note `timeoutIntervalForRequest` is going to be overwritten.
 *
 * @param sessionConfiguration The configuration to use for the new NSURLSession
 */
- (void)createNewSessionWithConfiguration:(nonnull NSURLSessionConfiguration *)sessionConfiguration;

/**
 * Invalidates the managed session, optionally canceling pending operations.
 * @note If you use custom downloader instead of the shared downloader, you need call this method when you do not use it to avoid memory leak
 * @param cancelPendingOperations Whether or not to cancel pending operations.
 * @note Calling this method on the shared downloader has no effect.
 */
- (void)invalidateSessionAndCancel:(BOOL)cancelPendingOperations;

@end
