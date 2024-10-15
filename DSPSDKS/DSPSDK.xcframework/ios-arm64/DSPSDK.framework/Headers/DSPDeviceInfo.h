//
//  DSPDeviceInfo.h
//  DSPSDK
//
//  Created by Robin on 2021/1/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(NSInteger, DSPAPPSTATUS){
    //  1 未安装
    //  2 已安装但版本号过低 (安卓)
    //  3 已安装但签名错误  (安卓)
    //  4 已安装且版本号、签名正常
    //  5 媒体未配置LSApplicationQueriesSchemes （iOS）
    DSPAPPSTATUS_NotInstalled = 1,
    DSPAPPSTATUS_LowVersion,
    DSPAPPSTATUS_SignError,
    DSPAPPSTATUS_Available,
    DSPAPPSTATUS_ConfigIncomplete,

};

@interface DSPDeviceInfo : NSObject
+(NSDictionary*) Info;
+ (NSString *)UUID;
+ (NSString *)removeUUID;

/// 以@{<NSString*> : <NSNumber*>}的形式返回所需app的安装状态，需媒体根据文档配置好LSApplicationQueriesSchemes
+(NSDictionary *)shareAppsStatus;
/// 将shareAppsStatus以@{@"type":app_name,@"inst_status": app_atatus}的json形式返回，给接口用
+(NSString *)shareAppsStatusJsonString;
@end

NS_ASSUME_NONNULL_END
