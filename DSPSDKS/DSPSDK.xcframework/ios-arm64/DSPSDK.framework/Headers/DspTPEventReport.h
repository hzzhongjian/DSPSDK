//
//  DspTPEventReport.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/2/21.
//

#import <Foundation/Foundation.h>
#import <DSPSDK/DspReportItem.h>

NS_ASSUME_NONNULL_BEGIN

@interface DspTPEventReport : NSObject

+ (void)eventReport:(NSString *)eventReportUrl
             adItem:(nonnull DspReportItem *)adItem
      requestParams:(NSDictionary *)requestParams
              extra:(nonnull NSDictionary *)extra;

// 播放到指定秒上报
+ (void)play_n_seconds:(DspAdItem *)adItem
               seconds:(long)seconds
         requestParams:(NSDictionary *)requestParams
                 extra:(NSDictionary *)extra;

@end

NS_ASSUME_NONNULL_END
