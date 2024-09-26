//
//  DspRewardVideoAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/27.
//

#import <DSPSDK/DspAd.h>

NS_ASSUME_NONNULL_BEGIN
@class DspRewardVideoAd;
@protocol DspRewardVideoAdProviderDelegate <DspAdDelegate>

- (void)dspRewardVideoAdVideoDidLoad:(DspRewardVideoAd *)dspRewardVideoAd;

- (void)dspRewardVideoAdDidShow:(DspRewardVideoAd *)dspRewardVideoAd;

- (void)dspRewardVideoAdDidClose:(DspRewardVideoAd *)dspRewardVideoAd;

- (void)dspRewardVideoAdDidClicked:(DspRewardVideoAd *)dspRewardVideoAd;

- (void)dspRewardVideoAdDidRewardEffective:(DspRewardVideoAd *)dspRewardVideoAd;

- (void)dspRewardVideoAdDidPlayFinish:(DspRewardVideoAd *)dspRewardVideoAd;

- (void)DspRewardVideoAd:(DspRewardVideoAd *)dspRewardVideoAd didFailWithError:(NSError *)error;

- (void)dspRewardVideoAd:(DspRewardVideoAd *)dspRewardVideoAd displayFailWithError:(nullable NSError *)error;

@end
@interface DspRewardVideoAd : DspAd
@property(nonatomic,weak) id<DspRewardVideoAdProviderDelegate> delegate;
- (void) showAdInViewController:(UIViewController *)viewController;

@property (nonatomic,assign)BOOL videoMuted;
@end

NS_ASSUME_NONNULL_END
