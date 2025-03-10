//
//  DspNativeAdManager.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/2/7.
//

#import <DSPSDK/DspAd.h>

NS_ASSUME_NONNULL_BEGIN

@class DspNativeAdManager;
@class DspNativeAd;

@protocol DspNativeAdManagerDelegate <DspAdDelegate>

- (void)dspNativeAdManagerSuccessToLoad:(DspNativeAdManager *)adsManager nativeAds:(NSArray<DspNativeAd *> *)nativeAds;

@end

@interface DspNativeAdManager : DspAd

@property (nonatomic, weak) id <DspNativeAdManagerDelegate> delegate;

// 设置视频播放是否静音
@property (nonatomic, assign) BOOL videoMuted;

@property (nonatomic, assign) CGSize adSize;

@end

NS_ASSUME_NONNULL_END
