//
//  DspFeedFullVideoAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/27.
//

#import <DSPSDK/DspAd.h>
#import <DSPSDK/DspFeedFullVideoView.h>
#import <DSPSDK/DSPSDKEnum.h>

NS_ASSUME_NONNULL_BEGIN
@class DspFeedFullVideoAd;


@protocol DspFeedFullVideoAdDelegate <DspAdDelegate>

//- (void)dspFeedFullVideoAdLoadSuccess:(DspFeedFullVideoAd *)adapter views:(NSArray<__kindof DspFeedFullVideoView *> *)views;
//
//- (void)dspFeedFullVideoAdViewRenderSuccess:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView;
//- (void)dspFeedFullVideoAdViewRenderFail:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView error:(NSError *_Nullable)error;
//
//
//- (void)dspFeedFullVideoAdViewWillShow:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView;
//
//
//- (void)dspFeedFullVideoAdViewStateDidChanged:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView state:(DSPMediaPlayerStatus)playerState;
//- (void)dspFeedFullVideoAdViewPlayerDidPlayFinish:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView;
//
//- (void)dspFeedFullVideoAdViewDidClick:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView;
//
//- (void)dspFeedFullVideoAdViewDetailViewWillPresentScreen:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView;
//
//- (void)dspFeedFullVideoAdViewDetailViewClosed:(DspFeedFullVideoAd *)adapter view:(DspFeedFullVideoView*) adView;

@end

@interface DspFeedFullVideoAd : DspAd

@property(nonatomic,weak) id<DspFeedFullVideoAdDelegate> delegate;
@property(nonatomic,strong,readonly) NSMutableArray  *views;
@property(nonatomic,assign) CGSize  adSize;
@end

NS_ASSUME_NONNULL_END
