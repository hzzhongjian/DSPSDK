//
//  DspSplashAd.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspAd.h>
#import <DSPSDK/DspSplashView.h>
NS_ASSUME_NONNULL_BEGIN
@class DspSplashAd;
@protocol DspSplashAdDelegate <DspAdDelegate>


//开屏广告成功展示
-(void)dspSplashAdSuccessPresentScreen:(DspSplashAd *)dspSplashAd;

//开屏广告点击回调
- (void)dspSplashAdClicked:(DspSplashAd *)dspSplashAd;

// 开屏广告关闭回调
- (void)dspSplashAdClosed:(DspSplashAd *)dspSplashAd;


//  应用进入后台时回调
//  详解: 当点击下载应用时会调用系统程序打开，应用切换到后台
- (void)dspSplashAdApplicationWillEnterBackground:(DspSplashAd *)dspSplashAd;

// 开屏广告倒记时结束
- (void)dspSplashAdCountdownEnd:(DspSplashAd*)dspSplashAd;

//  开屏广告错误
- (void)dspSplashAdError:(DspSplashAd *)dspSplashAd withError:(NSError *)error;

@end

@interface DspSplashAd : DspAd

@property(nonatomic,weak) id<DspSplashAdDelegate> delegate;

@property(nonatomic,readonly,strong) DspSplashView *splashView;

@property(nonatomic,assign)BOOL hotspotButton;
@end

NS_ASSUME_NONNULL_END
