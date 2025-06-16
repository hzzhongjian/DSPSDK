//
//  DspFeedAdView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/25.
//

#import <DSPSDK/DspView.h>
#import <DSPSDK/DspViewDelegate.h>
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DspFeedAdViewPlayerStatus) {
    DspFeedAdViewPlayerStatusUnknown = 0,
    DspFeedAdViewPlayerStatusReadyToPlay = 1,
    DspFeedAdViewPlayerStatusFailed = 2
};

@class DspFeedAdView;

@protocol DspFeedAdViewDelegate <DspViewDelegate>

- (void)feedAdViewRenderSuccess:(DspFeedAdView *)dspFeedAdView;

- (void)feedAdViewRenderFail:(DspFeedAdView *)dspFeedView error:(NSError *)error;

@optional

// 视频播放状态回传
- (void)feedAdView:(DspFeedAdView *)dspFeedAdView statusChanged:(DspFeedAdViewPlayerStatus)status;

// 视频播放展示失败
- (void)feedAdView:(DspFeedAdView *)dspFeedAdView
displayFailWithError:(NSError *_Nullable)error;

// 视频播放变化时间
- (void)feedAdView:(DspFeedAdView *)dspFeedAdView playProgressChanged:(NSTimeInterval)times;

// 视频播放完成
- (void)feedAdViewVideoViewPlayFinished:(DspFeedAdView *)dspFeedAdView;


@end

@interface DspFeedAdView : DspView

@property(nonatomic,weak) id<DspFeedAdViewDelegate> delegate;

// 设置视频播放是否静音
@property (nonatomic, assign) BOOL videoMuted;

- (NSString *)identifier;

- (void)render;

- (void)setBidEcpm:(NSInteger)ecpm;

- (void)setBidEcpm:(NSInteger)ecpm highestLossEcpm:(NSInteger)highestLossEcpm;

- (NSInteger)getEcpm;

@end

NS_ASSUME_NONNULL_END
