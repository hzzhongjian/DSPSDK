//
//  DspBannerAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/24.
//

#import <DSPSDK/DspAd.h>
#import <DSPSDK/DspBannerView.h>
NS_ASSUME_NONNULL_BEGIN

@class DspBannerAd;
@protocol DspBannerAdDelegate <DspAdDelegate>

/*
 bannerAdView曝光回调
 */
- (void)bannerAdWillBecomVisible:(DspBannerAd *)dspBannerAd;

/**
 关闭banner广告回调
 */
- (void)bannerAdDislike:(DspBannerAd *)dspBannerAd;

/**
 点击banner广告回调
 */
- (void)bannerAdDidClick:(DspBannerAd *)dspBannerAd;

/**
 关闭banner广告详情页回调
 */
- (void)bannerAdDidCloseOtherController:(DspBannerAd *)dspBannerAd;

- (void) bannerAdDidFail:(DspBannerAd*) dspBannerAd error:(NSError * __nullable)error;

@end

@interface DspBannerAd : DspAd
@property(nonatomic,weak) id<DspBannerAdDelegate> delegate;
@property(nonatomic,strong,readonly) DspBannerView  *bannerView;
@property(nonatomic,assign) CGSize  size;
@property(nonatomic,assign) NSInteger  interval;
@end

NS_ASSUME_NONNULL_END
