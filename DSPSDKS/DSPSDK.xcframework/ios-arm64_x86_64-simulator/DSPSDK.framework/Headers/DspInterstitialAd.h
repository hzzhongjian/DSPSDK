//
//  DspInterstitialAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/23.
//

#import <DSPSDK/DspAd.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN
@class DspInterstitialAd;
@protocol DspInterstitialAdDelegate <DspAdDelegate>

- (void) dspInterstitialAdDidPresentScreen:(DspInterstitialAd*) dspInterstitialAd;

- (void)dspInterstitialAdDidRewardEffective:(nonnull DspInterstitialAd *)provider;

- (void) dspInterstitialAdDidClick:(DspInterstitialAd*) dspInterstitialAd;

- (void) dspInterstitialAdDidClose:(DspInterstitialAd*) dspInterstitialAd;


- (void) dspInterstitialAdDidFail:(DspInterstitialAd*) dspInterstitialAd error:(NSError * __nullable)error;

@end
@interface DspInterstitialAd : DspAd

@property(nonatomic,weak) id<DspInterstitialAdDelegate> delegate;
-(void)presentAdFromRootViewController:(UIViewController*)  viewController;
@end

NS_ASSUME_NONNULL_END
