//
//  DspAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <Foundation/Foundation.h>
#import <DSPSDK/DspAdItem.h>
#import <DSPSDK/DspAdTypes.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN
@class DspAd;
@protocol DspAdDelegate <NSObject>

@optional
-(void) dspAdLoadSuccessful:(DspAd*) dspAd;
-(void) dspAdLoadFail:(DspAd*) dspAd error:(NSError*) error;
-(void) dspAdDetailClosed:(DspAd*) dspAd adView:(UIView*) adView;

@end

@interface DspAd : NSObject

@property(nonatomic,copy) NSString *zjad_id;
@property(nonatomic,copy) NSString *trade_id;
@property(nonatomic,copy) NSString *ad_id;
@property(nonatomic,copy) NSString *ad_type; // 广告类型
@property(nonatomic,copy) NSString *lv_url; // 设置兜底视频
@property(nonatomic,copy) NSString *lv_sd; // 跳过的时间
@property(nonatomic,copy) NSString *shake_power; // 摇一摇

@property(nonatomic,weak) UIViewController* rootViewController;


@property(nonatomic,weak) id<DspAdDelegate> delegate;

-(void) loadAdDate:(nullable NSDictionary*) params;

-(void) loadAdDataComplete:(NSArray<DspAdItem*>*) adItems;
-(void) loadAdDataErrorCode:(NSInteger) code msg:(NSString*) msg;

-(void) clickAction:(DspAdItem*) adItem response:(nullable NSDictionary *)response;
-(void) clickAction:(DspAdItem*) adItem response:(nullable NSDictionary *)response rootViewController:(nullable UIViewController*) rootViewController;

-(void) dspAdDetailClosed:(DspAdItem*) adItem;
-(void) excuteDspAdDetailClosedWithView:(nullable UIView*) adView;

/// 只有广告加载成功后，才能获取到ECPM
- (NSInteger)getEcpm;

/**
 *  bidding 竞胜之后调用, 需要在调用广告 show 之前调用
 *  @param ecpm - 曝光扣费, 单位分，若优量汇竞胜，在广告曝光时回传，必传
 *  针对本次曝光的媒体期望扣费，常用扣费逻辑包括一价扣费与二价扣费，当采用一价扣费时，胜者出价即为本次扣费价格；当采用二价扣费时，第二名出价为本次扣费价格.
 */
- (void)setBidEcpm:(NSInteger)ecpm;

/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
- (void)biddingLoss:(NSInteger)lossCode
           winPrice:(NSInteger)winPrice
            adnType:(NSInteger)adnType;

@end

NS_ASSUME_NONNULL_END
