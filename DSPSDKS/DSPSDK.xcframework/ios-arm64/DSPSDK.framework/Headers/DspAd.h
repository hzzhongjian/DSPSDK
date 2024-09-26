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
@property(nonatomic,copy) NSString *ad_type;
@property(nonatomic,copy) NSString *lv_url;
@property(nonatomic,copy) NSString *lv_sd;
@property(nonatomic,copy) NSString *shake_power;

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
@end

NS_ASSUME_NONNULL_END
