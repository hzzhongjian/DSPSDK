//
//  DspReportItem.h
//  DSPSDK
//
//  Created by Robin on 2021/1/22.
//

#import <DSPSDK/DspObject.h>
#import <DSPSDK/DspAdItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface DspReportItem : DspObject


- (NSDictionary *)getParamDic;

- (NSDictionary *)getParamDic:(DspAdItem *)adItem;

+ (instancetype)create:(DspAdItem *)adItem 
                 event:(nullable NSString *)event;

+ (instancetype)create:(DspAdItem *)adItem 
                 event:(NSString *)event
                   msg:(NSString *)msg;

- (DspAdItem *)getAdItem;

@end

NS_ASSUME_NONNULL_END
