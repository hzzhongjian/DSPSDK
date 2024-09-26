//
//  DSPSDKConfig.h
//  DSPSDK
//
//  Created by Robin on 2021/1/17.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,DSPAdSDKLogLevel){
    DSPAdSDKLogLevelNone,
    DSPAdSDKLogLevelDebug,
    DSPAdSDKLogLevelWarning,
    DSPAdSDKLogLevelError,
};

@interface DSPSDKConfig : NSObject

+ (instancetype)shared;

/**
 * 获取 SDK 版本
 */

+ (NSString *)SDKVersion;

/**
 SDK 注册接口，请在 app 初始化时调用。
 @param config - 媒体配置
 
 @return 注册是否成功。
*/
+ (BOOL)registerSDK:(NSDictionary *)config;


@property (nonatomic, assign) DSPAdSDKLogLevel level;
@property(nonatomic,copy) NSString *token;
@property(nonatomic,readonly) NSString *xtoken;
@property(nonatomic,copy) NSString *app_id;
@property(nonatomic,copy) NSString *app_id_zj;
///数字版本号
@property(nonatomic) NSInteger version_code;
///版本号
@property (nonatomic, copy, readonly) NSString *sdk_ver;
@property (nonatomic, copy, readonly) NSString *sdk_ver_zj;
@property (strong, nonatomic) CLLocation *location;



@property (nonatomic, copy) NSString *wx_app_id;

@property (nonatomic, copy) NSString *universal_link;

@property (nonatomic, assign) BOOL can_cache_video;

@property (nonatomic, assign) BOOL disable_sdk_assetion;

@end

NS_ASSUME_NONNULL_END
