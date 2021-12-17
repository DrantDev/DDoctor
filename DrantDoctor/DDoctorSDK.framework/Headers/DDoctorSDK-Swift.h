// Generated by Apple Swift version 5.4.2 (swiftlang-1205.0.28.2 clang-1205.0.19.57)
#ifndef DDOCTORSDK_SWIFT_H
#define DDOCTORSDK_SWIFT_H
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wgcc-compat"

#if !defined(__has_include)
# define __has_include(x) 0
#endif
#if !defined(__has_attribute)
# define __has_attribute(x) 0
#endif
#if !defined(__has_feature)
# define __has_feature(x) 0
#endif
#if !defined(__has_warning)
# define __has_warning(x) 0
#endif

#if __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <Foundation/Foundation.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if !defined(SWIFT_TYPEDEFS)
# define SWIFT_TYPEDEFS 1
# if __has_include(<uchar.h>)
#  include <uchar.h>
# elif !defined(__cplusplus)
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
# endif
typedef float swift_float2  __attribute__((__ext_vector_type__(2)));
typedef float swift_float3  __attribute__((__ext_vector_type__(3)));
typedef float swift_float4  __attribute__((__ext_vector_type__(4)));
typedef double swift_double2  __attribute__((__ext_vector_type__(2)));
typedef double swift_double3  __attribute__((__ext_vector_type__(3)));
typedef double swift_double4  __attribute__((__ext_vector_type__(4)));
typedef int swift_int2  __attribute__((__ext_vector_type__(2)));
typedef int swift_int3  __attribute__((__ext_vector_type__(3)));
typedef int swift_int4  __attribute__((__ext_vector_type__(4)));
typedef unsigned int swift_uint2  __attribute__((__ext_vector_type__(2)));
typedef unsigned int swift_uint3  __attribute__((__ext_vector_type__(3)));
typedef unsigned int swift_uint4  __attribute__((__ext_vector_type__(4)));
#endif

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif
#if !defined(SWIFT_CLASS_PROPERTY)
# if __has_feature(objc_class_property)
#  define SWIFT_CLASS_PROPERTY(...) __VA_ARGS__
# else
#  define SWIFT_CLASS_PROPERTY(...)
# endif
#endif

#if __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if __has_attribute(swift_name)
# define SWIFT_COMPILE_NAME(X) __attribute__((swift_name(X)))
#else
# define SWIFT_COMPILE_NAME(X)
#endif
#if __has_attribute(objc_method_family)
# define SWIFT_METHOD_FAMILY(X) __attribute__((objc_method_family(X)))
#else
# define SWIFT_METHOD_FAMILY(X)
#endif
#if __has_attribute(noescape)
# define SWIFT_NOESCAPE __attribute__((noescape))
#else
# define SWIFT_NOESCAPE
#endif
#if __has_attribute(ns_consumed)
# define SWIFT_RELEASES_ARGUMENT __attribute__((ns_consumed))
#else
# define SWIFT_RELEASES_ARGUMENT
#endif
#if __has_attribute(warn_unused_result)
# define SWIFT_WARN_UNUSED_RESULT __attribute__((warn_unused_result))
#else
# define SWIFT_WARN_UNUSED_RESULT
#endif
#if __has_attribute(noreturn)
# define SWIFT_NORETURN __attribute__((noreturn))
#else
# define SWIFT_NORETURN
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if __has_attribute(objc_subclassing_restricted)
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
#  define SWIFT_CLASS_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif
#if !defined(SWIFT_RESILIENT_CLASS)
# if __has_attribute(objc_class_stub)
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME) __attribute__((objc_class_stub))
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) __attribute__((objc_class_stub)) SWIFT_CLASS_NAMED(SWIFT_NAME)
# else
#  define SWIFT_RESILIENT_CLASS(SWIFT_NAME) SWIFT_CLASS(SWIFT_NAME)
#  define SWIFT_RESILIENT_CLASS_NAMED(SWIFT_NAME) SWIFT_CLASS_NAMED(SWIFT_NAME)
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
# define SWIFT_PROTOCOL_NAMED(SWIFT_NAME) SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM_ATTR)
# if defined(__has_attribute) && __has_attribute(enum_extensibility)
#  define SWIFT_ENUM_ATTR(_extensibility) __attribute__((enum_extensibility(_extensibility)))
# else
#  define SWIFT_ENUM_ATTR(_extensibility)
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name, _extensibility) enum _name : _type _name; enum SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# if __has_feature(generalized_swift_name)
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) enum _name : _type _name SWIFT_COMPILE_NAME(SWIFT_NAME); enum SWIFT_COMPILE_NAME(SWIFT_NAME) SWIFT_ENUM_ATTR(_extensibility) SWIFT_ENUM_EXTRA _name : _type
# else
#  define SWIFT_ENUM_NAMED(_type, _name, SWIFT_NAME, _extensibility) SWIFT_ENUM(_type, _name, _extensibility)
# endif
#endif
#if !defined(SWIFT_UNAVAILABLE)
# define SWIFT_UNAVAILABLE __attribute__((unavailable))
#endif
#if !defined(SWIFT_UNAVAILABLE_MSG)
# define SWIFT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
#endif
#if !defined(SWIFT_AVAILABILITY)
# define SWIFT_AVAILABILITY(plat, ...) __attribute__((availability(plat, __VA_ARGS__)))
#endif
#if !defined(SWIFT_WEAK_IMPORT)
# define SWIFT_WEAK_IMPORT __attribute__((weak_import))
#endif
#if !defined(SWIFT_DEPRECATED)
# define SWIFT_DEPRECATED __attribute__((deprecated))
#endif
#if !defined(SWIFT_DEPRECATED_MSG)
# define SWIFT_DEPRECATED_MSG(...) __attribute__((deprecated(__VA_ARGS__)))
#endif
#if __has_feature(attribute_diagnose_if_objc)
# define SWIFT_DEPRECATED_OBJC(Msg) __attribute__((diagnose_if(1, Msg, "warning")))
#else
# define SWIFT_DEPRECATED_OBJC(Msg) SWIFT_DEPRECATED_MSG(Msg)
#endif
#if !defined(IBSegueAction)
# define IBSegueAction
#endif
#if __has_feature(modules)
#if __has_warning("-Watimport-in-framework-header")
#pragma clang diagnostic ignored "-Watimport-in-framework-header"
#endif
@import CoreGraphics;
@import Foundation;
@import ImSDK;
@import ObjectiveC;
@import TXLiteAVSDK_Professional;
@import UIKit;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"
#if __has_warning("-Wpragma-clang-attribute")
# pragma clang diagnostic ignored "-Wpragma-clang-attribute"
#endif
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma clang diagnostic ignored "-Wnullability"

#if __has_attribute(external_source_symbol)
# pragma push_macro("any")
# undef any
# pragma clang attribute push(__attribute__((external_source_symbol(language="Swift", defined_in="DDoctorSDK",generated_declaration))), apply_to=any(function,enum,objc_interface,objc_category,objc_protocol))
# pragma pop_macro("any")
#endif




@class NSNumber;
@class NSString;
@class NSBundle;
@class NSCoder;

SWIFT_CLASS("_TtC10DDoctorSDK13CommentBaseVC")
@interface CommentBaseVC : UIViewController
- (void)viewWillAppear:(BOOL)animated;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10DDoctorSDK9CommentVC")
@interface CommentVC : CommentBaseVC
- (void)viewDidLoad;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)coder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10DDoctorSDK33DGElasticPullToRefreshLoadingView")
@interface DGElasticPullToRefreshLoadingView : UIView
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10DDoctorSDK39DGElasticPullToRefreshLoadingViewCircle")
@interface DGElasticPullToRefreshLoadingViewCircle : DGElasticPullToRefreshLoadingView
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)tintColorDidChange;
- (void)layoutSubviews;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end


SWIFT_CLASS("_TtC10DDoctorSDK26DGElasticPullToRefreshView")
@interface DGElasticPullToRefreshView : UIView
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)observeValueForKeyPath:(NSString * _Nullable)keyPath ofObject:(id _Nullable)object change:(NSDictionary<NSKeyValueChangeKey, id> * _Nullable)change context:(void * _Nullable)context;
- (void)layoutSubviews;
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
@end



SWIFT_CLASS("_TtC10DDoctorSDK19DrantAccountManager")
@interface DrantAccountManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end



/// 呼叫类型
/// <ul>
///   <li>
///     child: 儿童
///   </li>
///   <li>
///     adult: 成人
///   </li>
/// </ul>
typedef SWIFT_ENUM(NSInteger, DrantCallType, open) {
  DrantCallTypeChild = 600000,
  DrantCallTypeAdult = 600002,
};


/// 用户信息
SWIFT_CLASS("_TtC10DDoctorSDK15DrantCallerInfo")
@interface DrantCallerInfo : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

/// 接通前的呼叫状态
/// <ul>
///   <li>
///     onStart: 呼叫开始
///   </li>
///   <li>
///     waitingDoctor: 等待空闲的医生
///   </li>
///   <li>
///     callFreeDoctor: 有医生空闲，开始呼叫
///   </li>
///   <li>
///     callConnect: 建立呼叫
///   </li>
///   <li>
///     didRing: 医生响铃，等待接受
///   </li>
/// </ul>
typedef SWIFT_ENUM(NSInteger, DrantCallingState, open) {
  DrantCallingStateOnStart = 0,
  DrantCallingStateWaitingDoctor = 1,
  DrantCallingStateCallFreeDoctor = 2,
  DrantCallingStateCallConnect = 3,
  DrantCallingStateDidRing = 4,
};


SWIFT_CLASS("_TtC10DDoctorSDK14DrantDateUtils")
@interface DrantDateUtils : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end





SWIFT_CLASS("_TtC10DDoctorSDK18DrantDeviceManager")
@interface DrantDeviceManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10DDoctorSDK21DrantFileCacheManager")
@interface DrantFileCacheManager : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end




/// Drant 定位
SWIFT_CLASS("_TtC10DDoctorSDK13DrantLocation")
@interface DrantLocation : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong, getter=default) DrantLocation * _Nonnull default_;)
+ (DrantLocation * _Nonnull)default SWIFT_WARN_UNUSED_RESULT;
/// 启用定位
/// \param lng 经度
///
/// \param lat 纬度
///
- (void)startLocationWithLng:(NSString * _Nonnull)lng lat:(NSString * _Nonnull)lat;
/// 关闭定位
- (void)closeLocation;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

typedef SWIFT_ENUM(NSInteger, DrantLoginCode, open) {
  DrantLoginCodeOK = 0,
  DrantLoginCodeNetError = -1,
};


SWIFT_CLASS("_TtC10DDoctorSDK26DrantMediaStatusCheckUtils")
@interface DrantMediaStatusCheckUtils : NSObject
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

@class UIWindow;
@class UICollectionView;
@class NSIndexPath;
@class UICollectionViewCell;
@class UIScrollView;

IB_DESIGNABLE
SWIFT_CLASS("_TtC10DDoctorSDK14DrantPagerView")
@interface DrantPagerView : UIView <UICollectionViewDataSource, UICollectionViewDelegate>
- (nonnull instancetype)initWithFrame:(CGRect)frame SWIFT_UNAVAILABLE;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)layoutSubviews;
- (void)willMoveToWindow:(UIWindow * _Nullable)newWindow;
- (void)prepareForInterfaceBuilder;
- (NSInteger)numberOfSectionsInCollectionView:(UICollectionView * _Nonnull)collectionView SWIFT_WARN_UNUSED_RESULT;
- (NSInteger)collectionView:(UICollectionView * _Nonnull)collectionView numberOfItemsInSection:(NSInteger)section SWIFT_WARN_UNUSED_RESULT;
- (UICollectionViewCell * _Nonnull)collectionView:(UICollectionView * _Nonnull)collectionView cellForItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (BOOL)collectionView:(UICollectionView * _Nonnull)collectionView shouldHighlightItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)collectionView:(UICollectionView * _Nonnull)collectionView didHighlightItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (BOOL)collectionView:(UICollectionView * _Nonnull)collectionView shouldSelectItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath SWIFT_WARN_UNUSED_RESULT;
- (void)collectionView:(UICollectionView * _Nonnull)collectionView didSelectItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)collectionView:(UICollectionView * _Nonnull)collectionView willDisplayCell:(UICollectionViewCell * _Nonnull)cell forItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)collectionView:(UICollectionView * _Nonnull)collectionView didEndDisplayingCell:(UICollectionViewCell * _Nonnull)cell forItemAtIndexPath:(NSIndexPath * _Nonnull)indexPath;
- (void)scrollViewDidScroll:(UIScrollView * _Nonnull)scrollView;
- (void)scrollViewWillBeginDragging:(UIScrollView * _Nonnull)scrollView;
- (void)scrollViewWillEndDragging:(UIScrollView * _Nonnull)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(CGPoint * _Nonnull)targetContentOffset;
- (void)scrollViewDidEndDecelerating:(UIScrollView * _Nonnull)scrollView;
- (void)scrollViewDidEndScrollingAnimation:(UIScrollView * _Nonnull)scrollView;
@end

typedef SWIFT_ENUM(NSInteger, DrantPagerViewTransformerType, open) {
  DrantPagerViewTransformerTypeCrossFading = 0,
  DrantPagerViewTransformerTypeZoomOut = 1,
  DrantPagerViewTransformerTypeDepth = 2,
  DrantPagerViewTransformerTypeOverlap = 3,
  DrantPagerViewTransformerTypeLinear = 4,
  DrantPagerViewTransformerTypeCoverFlow = 5,
  DrantPagerViewTransformerTypeFerrisWheel = 6,
  DrantPagerViewTransformerTypeInvertedFerrisWheel = 7,
  DrantPagerViewTransformerTypeCubic = 8,
};


SWIFT_CLASS("_TtC10DDoctorSDK26DrantPhotoPickerController")
@interface DrantPhotoPickerController : UINavigationController
- (void)viewDidLoad;
- (nonnull instancetype)initWithNavigationBarClass:(Class _Nullable)navigationBarClass toolbarClass:(Class _Nullable)toolbarClass OBJC_DESIGNATED_INITIALIZER SWIFT_AVAILABILITY(ios,introduced=5.0);
- (nonnull instancetype)initWithRootViewController:(UIViewController * _Nonnull)rootViewController OBJC_DESIGNATED_INITIALIZER;
- (nonnull instancetype)initWithNibName:(NSString * _Nullable)nibNameOrNil bundle:(NSBundle * _Nullable)nibBundleOrNil OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
@end

@class DrantSDKOptions;
@class NSData;
@protocol DrantVideoDelegate;

SWIFT_CLASS("_TtC10DDoctorSDK8DrantSDK")
@interface DrantSDK : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong, getter=default) DrantSDK * _Nonnull default_;)
+ (DrantSDK * _Nonnull)default SWIFT_WARN_UNUSED_RESULT;
/// 初始化 SDK
/// \param option 可选的 SDK 配置
///
- (void)startWithOption:(DrantSDKOptions * _Nonnull)option;
/// 登录账户
/// \param userToken 用户的唯一标志
///
/// \param completion 完成的回调
///
- (void)loginWithUserToken:(NSString * _Nonnull)userToken completion:(void (^ _Nonnull)(NSString * _Nullable))completion;
/// 登录账号
/// \param uuid 用户的 唯一标志符
///
/// \param completion 完成回调
///
- (void)loginWithUuid:(NSInteger)uuid completion:(void (^ _Nonnull)(NSString * _Nullable))completion SWIFT_DEPRECATED_MSG("Use login(userToken: String, completion: @escaping DrantLoginHandler) instead.");
/// 退出登录
/// \param complet 登录状态回调， 如果为nil表示退出d成功
///
- (void)logoutWithComplete:(void (^ _Nullable)(NSString * _Nullable))complete;
/// 切换正式/测试环境，请勿调用
- (void)switchEnv:(BOOL)development;
/// 主叫发起通话
/// \param type 呼叫类型
///
- (void)startCall:(enum DrantCallType)type;
/// 更新APNS Token
/// \param token APNS Token
///
- (void)updateAPNSWithToken:(NSData * _Nonnull)token;
/// 获取当前 SDK 版本号
@property (nonatomic, readonly, copy) NSString * _Nonnull SDKVersion;
/// 是否登录成功
@property (nonatomic, readonly) BOOL isLogined;
/// 获取当前 token，未登录时为 nil
@property (nonatomic, readonly, copy) NSString * _Nullable userToken;
/// 添加视频监听
/// \param delegate 代理
///
- (void)addWithDelegate:(id <DrantVideoDelegate> _Nonnull)delegate;
- (void)removeWithDelegate:(id <DrantVideoDelegate> _Nonnull)delegate;
/// 添加支付宝支付调用接口
@property (nonatomic, copy) BOOL (^ _Nullable aliPayHook)(NSString * _Nonnull, NSString * _Nonnull, void (^ _Nonnull)(NSDictionary<NSString *, id> * _Nonnull));
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


@interface DrantSDK (SWIFT_EXTENSION(DDoctorSDK))
/// 获取病历详情
/// \param userToken 当前人的唯一标志
///
/// \param medicId 病历id
///
///
/// returns:
/// url
- (NSString * _Nonnull)getMedicDetailWithUserToken:(NSString * _Nonnull)userToken medicId:(NSString * _Nonnull)medicId SWIFT_WARN_UNUSED_RESULT;
/// 获取病历列表
/// \param userToken 当前人的唯一标志
///
///
/// returns:
/// url
- (NSString * _Nonnull)getMedicListWithUserToken:(NSString * _Nonnull)userToken SWIFT_WARN_UNUSED_RESULT;
/// 获取所有病历列表
/// \param userToken 主账户的唯一标志
///
///
/// returns:
/// url
- (NSString * _Nonnull)getAllMedicsWithUserToken:(NSString * _Nonnull)userToken SWIFT_WARN_UNUSED_RESULT;
@end


@interface DrantSDK (SWIFT_EXTENSION(DDoctorSDK))
/// 主动发起多人通话
/// \param type 呼叫类型
///
/// \param callee 被呼叫人的信息
///
- (void)startTeamCall:(enum DrantCallType)type callee:(DrantCallerInfo * _Nonnull)callee;
@end



@interface DrantSDK (SWIFT_EXTENSION(DDoctorSDK))
/// 指定人发起呼叫
/// <ul>
///   <li>
///     Parameters:
///   </li>
/// </ul>
- (void)callWithUserToken:(NSString * _Nonnull)userToken;
@end


@interface DrantSDK (SWIFT_EXTENSION(DDoctorSDK))
/// 发起呼叫
/// \param uuid 呼叫人uuid
///
- (void)startNewCall:(NSInteger)uuid SWIFT_DEPRECATED_MSG("Use call(userToken : String) instead.");
@end

@class VideoOptions;
@class MessageOptions;
@class UsercenterOptions;

/// 全局配置
SWIFT_CLASS("_TtC10DDoctorSDK15DrantSDKOptions")
@interface DrantSDKOptions : NSObject
SWIFT_CLASS_PROPERTY(@property (nonatomic, class, readonly, strong, getter=default) DrantSDKOptions * _Nonnull default_;)
+ (DrantSDKOptions * _Nonnull)default SWIFT_WARN_UNUSED_RESULT;
/// hud 自动显示的时间
@property (nonatomic) NSTimeInterval hudDisTime;
/// 调试模式(打印日志)
@property (nonatomic) BOOL isDebug;
/// 是否开启测试服
@property (nonatomic) BOOL isDevelopment;
/// 产品 id
@property (nonatomic, copy) NSString * _Nonnull productId;
/// 推送证书名
@property (nonatomic, copy) NSString * _Nullable cerName;
/// 视频开始后180s显示换医生
@property (nonatomic) NSInteger changeDoctorTime;
/// 音视频配置
@property (nonatomic, strong) VideoOptions * _Nonnull mVideoOptions;
/// 信息流配置
@property (nonatomic, strong) MessageOptions * _Nonnull mMessageOptions;
/// 个人中心配置
@property (nonatomic, strong) UsercenterOptions * _Nonnull mUserCenterOptions;
- (nonnull instancetype)initWithProductId:(NSString * _Nonnull)productId isDebug:(BOOL)isDebug isDevelop:(BOOL)isDevelop OBJC_DESIGNATED_INITIALIZER;
- (void)setUserExtensionWithUserExtension:(NSString * _Nonnull)userExtension;
- (void)setCallExtensionWithCallExtension:(NSString * _Nonnull)callExtension;
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end



/// 视频管理器代理
SWIFT_PROTOCOL("_TtP10DDoctorSDK18DrantVideoDelegate_")
@protocol DrantVideoDelegate <NSObject>
@optional
/// 主动视频时的呼叫状态变化
/// \param state 当前呼叫状态
///
- (void)callStateChange:(enum DrantCallingState)state;
/// 视频呼叫开始
/// \param orderId 当前订单ID
///
- (void)onStartWithOrderId:(NSString * _Nullable)orderId;
/// 通话已接通
- (void)callDidEstablish;
/// 视频页面回调
- (void)getChatParentView:(UIView * _Nonnull)view;
/// 呼叫失败（主叫）
/// \param error 错误信息
///
- (void)onFail:(NSInteger)errorCode errrorStr:(NSString * _Nullable)errrorStr;
- (void)onCancel;
/// 通话已结束 (接通之后才有结束)
- (void)callDidFinish;
/// 转呼医生
- (void)onExtensionDoctor;
/// 接收到呼叫(被呼叫方)
/// \param callID 呼叫的 id
///
- (void)onReceive:(NSString * _Nonnull)callID;
/// 收到视频呼入时的操作（被呼叫方）
/// \param accept 接受或者拒接
///
- (void)onResponse:(BOOL)accept;
/// 强制下线
- (void)onForceOffline;
@end


@class UIImage;
@class UITouch;
@class UIEvent;

/// A simple rating view that can set whole, half or floating point ratings.
IB_DESIGNABLE
SWIFT_CLASS("_TtC10DDoctorSDK15FloatRatingView")
@interface FloatRatingView : UIView
/// Sets the empty image (e.g. a star outline)
@property (nonatomic, strong) IBInspectable UIImage * _Nullable emptyImage;
/// Sets the full image that is overlayed on top of the empty image.
/// Should be same size and shape as the empty image.
@property (nonatomic, strong) IBInspectable UIImage * _Nullable fullImage;
/// Minimum rating.
@property (nonatomic) IBInspectable NSInteger minRating;
/// Max rating value.
@property (nonatomic) IBInspectable NSInteger maxRating;
/// Minimum image size.
@property (nonatomic) IBInspectable CGSize minImageSize;
/// Set the current rating.
@property (nonatomic) IBInspectable float rating;
/// Sets whether or not the rating view can be changed by panning.
@property (nonatomic) IBInspectable BOOL editable;
/// Ratings change by 0.5. Takes priority over floatRatings property.
@property (nonatomic) IBInspectable BOOL halfRatings;
/// Ratings change by floating point values.
@property (nonatomic) IBInspectable BOOL floatRatings;
- (nonnull instancetype)initWithFrame:(CGRect)frame OBJC_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder * _Nonnull)aDecoder OBJC_DESIGNATED_INITIALIZER;
- (void)layoutSubviews;
- (void)touchesBegan:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesMoved:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
- (void)touchesEnded:(NSSet<UITouch *> * _Nonnull)touches withEvent:(UIEvent * _Nullable)event;
@end


SWIFT_PROTOCOL("_TtP10DDoctorSDK23FloatRatingViewDelegate_")
@protocol FloatRatingViewDelegate
/// Returns the rating value when touch events end
- (void)floatRatingView:(FloatRatingView * _Nonnull)ratingView didUpdate:(float)rating;
@optional
/// Returns the rating value as the user pans
- (void)floatRatingView:(FloatRatingView * _Nonnull)ratingView isUpdating:(float)rating;
@end


SWIFT_CLASS("_TtC10DDoctorSDK14MessageOptions")
@interface MessageOptions : NSObject
/// 是否是Present显示
@property (nonatomic) BOOL isByPresent;
/// 信息流是否过滤医生总结
@property (nonatomic) BOOL isFilterSummary;
/// 信息流是否过滤药卡
@property (nonatomic) BOOL isFilterMedicinal;
/// 信息流默认头像
@property (nonatomic, copy) NSString * _Nonnull defaultDocHeader;
/// 信息流默认昵称
@property (nonatomic, copy) NSString * _Nonnull defaultDocName;
/// 信息流默认标题
@property (nonatomic, copy) NSString * _Nonnull messageTitle;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end







typedef SWIFT_ENUM(NSInteger, PermissionType, open) {
  PermissionTypeLocationAlways = 0,
  PermissionTypeLocationWhenInUse = 1,
  PermissionTypeMicrophone = 2,
  PermissionTypeCamera = 3,
  PermissionTypePhotos = 4,
};

typedef SWIFT_ENUM(NSInteger, SkipType, open) {
  SkipTypePush = 0,
  SkipTypePresent = 1,
};


SWIFT_CLASS("_TtC10DDoctorSDK11TRTCManager")
@interface TRTCManager : NSObject
- (nonnull instancetype)init SWIFT_UNAVAILABLE;
+ (nonnull instancetype)new SWIFT_UNAVAILABLE_MSG("-init is unavailable");
@end


@interface TRTCManager (SWIFT_EXTENSION(DDoctorSDK)) <TRTCLogDelegate>
- (void)onLog:(NSString * _Nullable)log LogLevel:(TRTCLogLevel)level WhichModule:(NSString * _Nullable)module_;
@end




@interface TRTCManager (SWIFT_EXTENSION(DDoctorSDK)) <TIMConnListener>
- (void)onConnSucc;
- (void)onConnFailed:(int32_t)code err:(NSString * _Null_unspecified)err;
- (void)onDisconnect:(int32_t)code err:(NSString * _Null_unspecified)err;
@end


@interface TRTCManager (SWIFT_EXTENSION(DDoctorSDK)) <TIMUserStatusListener>
- (void)onForceOffline;
- (void)onReConnFailed:(int32_t)code err:(NSString * _Null_unspecified)err;
- (void)onUserSigExpired;
@end


@interface TRTCManager (SWIFT_EXTENSION(DDoctorSDK)) <TIMMessageListener>
- (void)onNewMessage:(NSArray * _Null_unspecified)msgs;
@end





@interface TRTCManager (SWIFT_EXTENSION(DDoctorSDK)) <TRTCCloudDelegate>
- (void)onEnterRoom:(NSInteger)result;
- (void)onError:(TXLiteAVError)errCode errMsg:(NSString * _Nullable)errMsg extInfo:(NSDictionary * _Nullable)extInfo;
@end































@class UITapGestureRecognizer;
@class NSTimer;

@interface UIView (SWIFT_EXTENSION(DDoctorSDK))
- (void)ddhandleToastTapped:(UITapGestureRecognizer * _Nonnull)recognizer;
- (void)ddtoastTimerDidFinish:(NSTimer * _Nonnull)timer;
@end





SWIFT_CLASS("_TtC10DDoctorSDK17UsercenterOptions")
@interface UsercenterOptions : NSObject
/// 是否隐藏会员信息
@property (nonatomic) BOOL enableVipInfo;
/// 是否隐藏个人中心入口
@property (nonatomic) BOOL hideUserCenter;
/// 是否展示激活码入口
@property (nonatomic) BOOL enableActivate;
/// 是否展示档案库入口
@property (nonatomic) BOOL enableMedical;
/// 档案库是否可以增加成员
@property (nonatomic) BOOL enableAddMemberInDoc;
/// 是否显示购买VIP入口
@property (nonatomic) BOOL enableBuyService;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end


SWIFT_CLASS("_TtC10DDoctorSDK12VideoOptions")
@interface VideoOptions : NSObject
/// 是否开启美颜
@property (nonatomic) BOOL allowBeauty;
/// 允许视频完成后评价
@property (nonatomic) BOOL allowEvaluate;
/// 选人页面是否显示增加成员入口
@property (nonatomic) BOOL allowAddMember;
/// 选人页面是否可以选择多人视频
@property (nonatomic) BOOL allowMulti;
/// 是否显示医生信息
@property (nonatomic) BOOL isShowDocInfo;
/// 可以关闭摄像头
@property (nonatomic) BOOL enableCloseCamera;
/// 不可关闭摄像头
@property (nonatomic) BOOL isCloseCameraCall;
- (nonnull instancetype)init OBJC_DESIGNATED_INITIALIZER;
@end

#if __has_attribute(external_source_symbol)
# pragma clang attribute pop
#endif
#pragma clang diagnostic pop
#endif