//
//  DspFeedAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/25.
//

#import <DSPSDK/DspAd.h>
#import <DSPSDK/DspFeedAdView.h>

NS_ASSUME_NONNULL_BEGIN

@class DspFeedAd;

@protocol DspFeedAdDelegate <DspAdDelegate>

- (void)dspFeedAdLoadSuccess:(DspFeedAd *)dspFeedAd views:(NSArray<__kindof DspFeedAdView *> *)views;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewRenderSuccess:(DspFeedAdView *) dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewRenderFail:(DspFeedAdView *)dspFeedView error:(NSError *)error;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidShow:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidClick:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDislike:(DspFeedAdView *)dspFeedView withReason:(NSString*) reason;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidClosed:(DspFeedAdView *)dspFeedView;

/*
 * 落地页关闭的事件回调，
 * 推荐使用- (void)dspAdDetailClosed:(nonnull DspAd *)dspAd adView:(nonnull UIView *)adView
 */
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidCloseDetailController:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidDetailViewShow:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd statusChanged:(DspFeedAdViewPlayerStatus)status feedAdView:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd
displayFailWithError:(NSError *_Nullable)error
       feedAdView:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd playProgressChanged:(NSTimeInterval)times dspFeedView:(DspFeedAdView *)dspFeedView;

- (void)dspFeedAd:(DspFeedAd *)dspFeedAd videoPlayFinished:(DspFeedAdView *)dspFeedView;

@end

@interface DspFeedAd : DspAd

@property(nonatomic,weak) id<DspFeedAdDelegate> delegate;

@property(nonatomic,strong,readonly) NSMutableArray<DspFeedAdView*>  *views;

@property(nonatomic,assign) CGSize  adSize;

// 设置视频播放是否静音
@property (nonatomic, assign) BOOL videoMuted;

- (void)setBidEcpm:(NSInteger)ecpm DEPRECATED_MSG_ATTRIBUTE("use DspFeedAdView setBidEcpm instead.");

- (NSInteger)getEcpm DEPRECATED_MSG_ATTRIBUTE("use DspFeedAdView getEcpm instead.");
@end

NS_ASSUME_NONNULL_END
