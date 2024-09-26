//
//  DspFullScreenVideoAd.h
//  DSPSDK
//
//  Created by Rare on 2022/1/14.
//

#import <DSPSDK/DspAd.h>
#import <DSPSDK/DSPSDKEnum.h>

NS_ASSUME_NONNULL_BEGIN
@class DspFullScreenVideoAd;
@protocol DspFullScreenVideoAdDelegate <DspAdDelegate>
@optional
//广告加载成功
//- (void)dspFullScreenVideoAdDidLoad:(DspFullScreenVideoAd *)ad;

//广告加载失败
//- (void)dspFullScreenVideoAdDidLoadFail:(DspFullScreenVideoAd *)ad error:(nullable NSError *)error;

//广告展示
- (void)dspFullScreenVideoAdDidShow:(DspFullScreenVideoAd *)ad;

- (void)dspFullScreenVideoDidRewardEffective:(nonnull DspFullScreenVideoAd *)ad;
//广告点击
- (void)dspFullScreenVideoAdDidClick:(DspFullScreenVideoAd *)ad;

//广告关闭
- (void)dspFullScreenVideoAdDidClose:(DspFullScreenVideoAd *)ad;

//广告错误
- (void)dspFullScreenVideoAdDidFail:(DspFullScreenVideoAd *)ad error:(nullable NSError *)error;

//广告播放状态回调
- (void)dspFullScreenVideoAd:(DspFullScreenVideoAd *)ad  playerStatusChanged:(DSPMediaPlayerStatus)playerStatus;

//广告详情页打开
- (void)dspFullScreenVideoAdDetailDidPresent:(DspFullScreenVideoAd *)ad;

//广告详情页关闭
- (void)dspFullScreenVideoAdDetailDidClose:(DspFullScreenVideoAd *) ad;

@end

@interface DspFullScreenVideoAd : DspAd
//- (void)loadAd;
@property(nonatomic,weak) id<DspFullScreenVideoAdDelegate> delegate;

- (void)presentFullScreenVideoAdFromRootViewController:(UIViewController *)viewController;
@end

NS_ASSUME_NONNULL_END
