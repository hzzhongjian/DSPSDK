---
title: DSPSDK 接入文档
---


## SDK 集成

* 接入完成后，在正式上线前需要提供测试包，测试广告正常展现
* SDK 不支持模拟器运行，需要使用真机调试，运行结果一切以真机为准

### 运行环境

* SDK可运行在iOS11.0及其以上版本

### 引入framework

#### 1. CocoaPods接入方式

```pod
pod 'DSPSDK'
```
#### 2.手动方式

1.下载SDK文件，解压后直接将 DSPSDKS 文件夹拖入工程即可。

2.前往项目的Build Setting中的Enable Bitcode设置为NO

3.Build Settings中Other Linker Flags 增加参数-ObjC，字母o和c大写

4.引入库依赖

- CoreGraphics.framework
- Security.framework
- UIKit.framework
- WebKit.framework
- Foundation.framework
- MobileCoreServices.framework
- SystemConfiguration.framework
- CoreTelephony.framework
- AdSupport.framework
- CoreData.framework
- StoreKit.framework
- AVFoundation.framework
- MediaPlayer.framework
- CoreMedia.framework
- Accelerate.framework
- CoreLocation.framework
- CoreMotion.framework
- libz.tbd
- libresolv.9.tbd
- libsqlite3.tdb
- libc++.tbd
- libc++abi.tbd

5.升级SDK的同学必须同时更新xcframework和bundle文件，否则可能出现部分页面无法展示的问题，老版本升级的同学需要重新引入DSPSDK.xcframework，拖入完请确保Copy Bundle Resources中有DSPSDKBundle.bundle,否则可能出现icon图片加载不出来的情况。



### SDK初始化

先引入头文件
```objc
#import <DSPSDK/DSPSDK.h>
```

#### 初始化接入示例
```objc
[DSPSDKConfig registerSDK:@{@"appId": Appid,
                            @"universal_link": @"123123123123",
                            @"wx_app_id": @"321321321321",
                            @"can_cache_video": @1}];
```
|方法名|介绍|
|---------|:--------:|
| appId | 设置媒体ID（必填，String类型） |
| can_cache_video | 控制是否可以缓存视频，1 为开启视频缓存(推荐) 0为关闭是否缓存 |                                               
| wx_app_id | wxOpenId：微信开放平台的应用ID |
| universal_link | 在微信开放平台配置的Universal Link域名 |

:::Tip
媒体有使用原生跳转到微信小程序页面的需求，则需要单独导入WechatOpenSDK 在工程的 Podfile 里面添加以下代码：
pod 'WechatOpenSDK'
:::

#### 获取SDK版本号

```objc
[DSPSDKConfig SDKVersion]
```

#### 开启SDK打印日志
```objc
[DSPSDKConfig shared].level = DSPAdSDKLogLevelDebug;
```

## 广告接入

### 开屏广告

#### 引入头文件

```objc
#import <DSPSDK/DspSplashAd.h>
```

#### 开屏广告加载
```objc
self.dspSplashAd = [[DspSplashAd alloc] init];
self.dspSplashAd.zjad_id = Appid; // AppId
self.dspSplashAd.ad_id = adId; // 请求的广告位ID
self.dspSplashAd.ad_type = DspADType_Splash; // 请求的广告类型
self.dspSplashAd.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.dspSplashAd.falling = 1; // 是否禁止掉落动画，如果值大于0就开启，否则关闭
self.dspSplashAd.falling_rate = 30; // 设置红包雨效果展示的概率, 取值范围[0-100]
self.dspSplashAd.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width] 
};
// 请求加载数据
[self.dspSplashAd loadAdDate:params];
```

#### 开屏广告的展示

```objc
if(self.dspSplashAd){
    [[UIApplication sharedApplication].keyWindow.rootViewController.view addSubview:self.dspSplashAd.splashView];
}
```

#### 开屏广告代理回调 - DspSplashAdDelegate

```objc

// 开屏广告加载成功
- (void)dspAdLoadSuccessful:(DspAd *)dspAd;

// 开屏广告加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error;

//开屏广告成功展示
- (void)dspSplashAdSuccessPresentScreen:(DspSplashAd *)dspSplashAd;

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

// 落地页打开的事件回调
- (void)dspSplashAdDetailViewShow:(DspSplashAd *)dspSplashAd;

// 开屏广告详情页关闭的事件回调
- (void)dspAdDetailClosed:(DspAd *)dspAd adView:(UIView *)adView;

```

#### 获取开屏广告eCPM价格，单位为分
```objc
[self.dspSplashAd getEcpm]
```

#### 开屏广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[self.dspSplashAd setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 开屏广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[self.dspSplashAd biddingLoss:1001 winPrice:firstPrice adnType:4];
```

|联盟平台|adnType|
|---------|:--------:|
| 优量汇 | 1 |
| 穿山甲 | 2 |
| 众简 | 3 |
| 快手 | 4 |
| Mintegral | 9 |
| YM | 14 |
| Sigmob | 10 |
| WW | 0 |
| Google | 23 |
| 百度 | 6 |
| Gromore | 26 |
| 倍孜 | 24 |
| WM | 25 |
| Pangle | 29 |
| Tanx | 31 |
| 趣盟 | 33 |
| 章鱼 | 30 |
| 移卡 | 35 |
| 奇运 | 40 |
| Taku | 41 |

======================================================

### 插屏广告

#### 引入头文件

```objc
#import <DSPSDK/DspInterstitialAdDelegate.h>
```

#### 插屏广告的加载
```objc
self.dspInterstitialAd = [[DspInterstitialAdDelegate alloc] init];
self.dspInterstitialAd.zjad_id = Appid; // AppId
self.dspInterstitialAd.ad_id = adId; // 请求的广告位ID
self.dspInterstitialAd.ad_type = DspADType_Interstitial; // 请求的广告类型
self.dspInterstitialAd.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.dspInterstitialAd.falling = 1; // 是否禁止掉落动画，如果值大于0就开启，否则关闭
self.dspInterstitialAd.falling_rate = 30; // 设置红包雨效果展示的概率, 取值范围[0-100]
self.dspInterstitialAd.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width] 
};
// 请求加载数据
[self.dspInterstitialAd loadAdDate:params];
```

#### 插屏广告的展示

```objc
if(self.dspInterstitialAd){
    [self.dspInterstitialAd presentAdFromRootViewController:viewController];
}
```

#### 插屏广告代理回调 - DspInterstitialAdDelegate

```objc

// 插屏广告加载成功
- (void)dspAdLoadSuccessful:(DspAd *)dspAd;

// 插屏广告加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error;

//插屏广告成功展示回调
- (void)dspInterstitialAdDidPresentScreen:(DspInterstitialAd*) dspInterstitialAd;

// 插屏广告已经发奖回调
- (void)dspInterstitialAdDidRewardEffective:(nonnull DspInterstitialAd *)provider;

// 插屏广告点击回调
- (void)dspInterstitialAdDidClick:(DspInterstitialAd *)dspInterstitialAd;

// 插屏广告关闭回调
- (void)dspInterstitialAdDidClose:(DspInterstitialAd *)dspInterstitialAd;

// 插屏广告失败回调
- (void)dspInterstitialAdDidFail:(DspInterstitialAd *)dspInterstitialAd error:(NSError * __nullable)error

// 插屏广告详情页打开的事件回调
- (void)dspInterstitialAdDetailViewDidShow:(DspInterstitialAd *)dspInterstitialAd;

// 插屏广告详情页关闭的事件回调
- (void)dspAdDetailClosed:(DspAd *)dspAd adView:(UIView *)adView;

```

#### 获取插屏广告eCPM价格，单位为分
```objc
[self.dspInterstitialAd getEcpm]
```

#### 插屏广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[self.dspInterstitialAd setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 插屏广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[self.dspInterstitialAd biddingLoss:1001 winPrice:firstPrice adnType:4];
```

===========================================================

### 激励视频

#### 引入头文件
```objc
#import <DSPSDK/DspRewardVideoAd.h>
```

#### 激励广告的加载
```objc
self.dspRewardVideoAd = [[DspRewardVideoAd alloc] init];
self.dspRewardVideoAd.zjad_id = Appid; // AppId
self.dspRewardVideoAd.ad_id = adId; // 请求的广告位ID
self.dspRewardVideoAd.ad_type = DspADType_RewardVideo; // 请求的广告类型
self.dspRewardVideoAd.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.dspRewardVideoAd.falling = 1; // 是否禁止掉落动画，如果值大于0就开启，否则关闭
self.dspRewardVideoAd.falling_rate = 30; // 设置红包雨效果展示的概率, 取值范围[0-100]
self.dspRewardVideoAd.user_id = @"18888888888"; // 用户的唯一标识
self.dspRewardVideoAd.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width] 
};
// 请求加载数据
[self.dspRewardVideoAd loadAdDate:params];
```

#### 激励广告的展示

```objc
if(self.dspRewardVideoAd){
    [self.dspRewardVideoAd showAdInViewController:viewController];
}
```

#### 激励广告代理回调 - DspRewardVideoAdProviderDelegate

```objc

// 激励广告加载成功
- (void)dspAdLoadSuccessful:(DspAd *)dspAd;

// 激励广告加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error;

// 激励广告视频加载成功
- (void)dspRewardVideoAdVideoDidLoad:(DspRewardVideoAd *)dspRewardVideoAd;

// 激励广告已展示
- (void)dspRewardVideoAdDidShow:(DspRewardVideoAd *)dspRewardVideoAd;

// 激励广告已关闭
- (void)dspRewardVideoAdDidClose:(DspRewardVideoAd *)dspRewardVideoAd;

// 激励广告点击
- (void)dspRewardVideoAdDidClicked:(DspRewardVideoAd *)dspRewardVideoAd;

// 激励广告已发奖
- (void)dspRewardVideoAdDidRewardEffective:(DspRewardVideoAd *)dspRewardVideoAd;

// 激励广告播放完成
- (void)dspRewardVideoAdDidPlayFinish:(DspRewardVideoAd *)dspRewardVideoAd;

// 激励广告播放失败
- (void)dspRewardVideoAd:(DspRewardVideoAd *)dspRewardVideoAd displayFailWithError:(nullable NSError *)error

// 落地页打开的事件回调
- (void)dspRewardVideoAdDetailViewShow:(DspRewardVideoAd *)dspRewardVideoAd;

// 落地页关闭的事件回调
- (void)dspAdDetailClosed:(DspAd *)dspAd adView:(UIView *)adView;
```

#### 获取激励广告eCPM价格，单位为分
```objc
[self.dspRewardVideoAd getEcpm]
```

#### 激励广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[self.dspRewardVideoAd setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 激励广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[self.dspRewardVideoAd biddingLoss:1001 winPrice:firstPrice adnType:4];
```

=====================================================

### 全屏视频

#### 引入头文件
```objc
#import <DSPSDK/DspFullScreenVideoAd.h>
```

#### 全屏视频广告的加载
```objc
self.fullVideoAd = [[DspFullScreenVideoAd alloc] init];
self.fullVideoAd.zjad_id = Appid; // AppId
self.fullVideoAd.ad_id = adId; // 请求的广告位ID
self.fullVideoAd.ad_type = DspADType_FullVideoAd; // 请求的广告类型
self.fullVideoAd.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.fullVideoAd.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width] 
};
// 请求加载数据
[self.fullVideoAd loadAdDate:params];
```

#### 全屏视频广告的展示

```objc
if(self.fullVideoAd){
    [self.fullVideoAd presentFullScreenVideoAdFromRootViewController:viewController];
}
```

#### 全屏视频广告代理回调 - DspFullScreenVideoAdDelegate

```objc

// 全屏视频广告加载成功
- (void)dspAdLoadSuccessful:(DspAd *)dspAd;

// 全屏视频广告加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error;

// 全屏视频广告已展示
- (void)dspFullScreenVideoAdDidShow:(DspFullScreenVideoAd *)ad;

// 全屏视频广告已关闭
- (void)dspFullScreenVideoAdDidClose:(DspFullScreenVideoAd *)ad;

// 全屏视频广告点击
- (void)dspFullScreenVideoAdDidClick:(DspFullScreenVideoAd *)ad;

//全屏视频广告错误
- (void)dspFullScreenVideoAdDidFail:(DspFullScreenVideoAd *)ad error:(nullable NSError *)error;

//全屏视频广告播放状态回调
- (void)dspFullScreenVideoAd:(DspFullScreenVideoAd *)ad  playerStatusChanged:(DSPMediaPlayerStatus)playerStatus;

//全屏视频广告详情页打开
- (void)dspFullScreenVideoAdDetailDidPresent:(DspFullScreenVideoAd *)ad;

//全屏视频广告详情页关闭
- (void)dspFullScreenVideoAdDetailDidClose:(DspFullScreenVideoAd *) ad;


```

#### 获取全屏视频广告eCPM价格，单位为分
```objc
[self.fullVideoAd getEcpm]
```

#### 全屏视频广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[self.fullVideoAd setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 全屏视频广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[self.fullVideoAd biddingLoss:1001 winPrice:firstPrice adnType:4];
```

=============================================================

### 横幅广告Banner

#### 引入头文件
```objc
#import <DSPSDK/DspBannerAd.h>
```

#### 横幅广告广告的加载
```objc
self.bannerAd = [[DspBannerAd alloc] init];
self.bannerAd.zjad_id = Appid; // AppId
self.bannerAd.ad_id = adId; // 请求的广告位ID
self.bannerAd.ad_type = DspADType_Banner; // 请求的广告类型
self.bannerAd.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.bannerAd.size = CGSizeMake(KScreenSize.width, 200); // 设置横幅Banner的宽度和高度,宽度必须设置，高度可以设置为0，sdk会根据宽高比去布局
self.bannerAd.interval = 3;
self.bannerAd.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width] 
};
// 请求加载数据
[self.bannerAd loadAdDate:params];
```

#### 横幅广告的展示

```objc
if(self.bannerAd){
    [self.view addSubview:self.bannerAd.bannerView];
}
```

#### 横幅广告代理回调 - DspBannerAdDelegate

```objc

// banner广告加载成功
- (void)dspAdLoadSuccessful:(DspAd *)dspAd;

// banner广告加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error;

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
- (void)dspAdDetailClosed:(DspAd *)dspAd adView:(UIView *)adView;

- (void)bannerAdDidFail:(DspBannerAd *)dspBannerAd error:(NSError * __nullable)error;

/*
 * banner广告打开详情页回调
 */
- (void)bannerAdDetailViewShow:(DspBannerAd *)dspBannerAd;

```

#### 获取横幅广告eCPM价格，单位为分
```objc
[self.bannerAd getEcpm]
```

#### 横幅广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[self.bannerAd setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 横幅广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[self.bannerAd biddingLoss:1001 winPrice:firstPrice adnType:4];
```

=============================================================

### 信息流广告

#### 引入头文件
```objc
#import <DSPSDK/DspFeedAd.h>
```

#### 信息流广告的加载
```objc
self.dspFeedAd = [[DspFeedAd alloc] init];
self.dspFeedAd.zjad_id = Appid; // AppId
self.dspFeedAd.ad_id = adId; // 请求的广告位ID
self.dspFeedAd.ad_type = DspADType_Feed; // 请求的广告类型
self.dspFeedAd.videoMuted = NO;
self.dspFeedAd.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.dspFeedAd.adSize = CGSizeMake(KScreenSize.width, 200); // 设置信息流加载素材的宽度和高度
self.dspFeedAd.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width],
    @"ad_count":@(adCount)
};
// 请求加载数据
[self.dspFeedAd loadAdDate:params];
```

#### 信息流素材加载成功和失败的方法代理 DspFeedAdDelegate

```objc
// 加载成功
- (void)dspFeedAdLoadSuccess:(nonnull DspFeedAd *)dspFeedAd views:(nonnull NSArray<__kindof DspFeedAdView *> *)views

// 加载失败
- (void)dspAdLoadFail:(nonnull DspAd *)dspAd error:(nonnull NSError *)error
```

#### 信息流广告的展示

```objc
// 从加载成功方法里面获取views，
for (int i = 0; i<views.count; i++) {
    views[i].rootViewController = self;
    views[i].delegate = self;
    [views[i] render]; 
    // 把views分别添加到要展示的地方   
}

```

#### 信息流代理回调 - DspFeedAdDelegate

```objc

// 信息流数据加载成功
- (void)dspFeedAdLoadSuccess:(DspFeedAd *)dspFeedAd views:(NSArray<__kindof DspFeedAdView *> *)views;

// 信息流view渲染成功
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewRenderSuccess:(DspFeedAdView *) dspFeedView;

// 信息流view渲染失败
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewRenderFail:(DspFeedAdView *)dspFeedView error:(NSError *)error;

// 信息流view展示
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidShow:(DspFeedAdView *)dspFeedView;

// 信息流view点击
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidClick:(DspFeedAdView *)dspFeedView;

// 信息流view关闭
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDislike:(DspFeedAdView *)dspFeedView withReason:(NSString*)reason;

// 信息流详情页打开
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd feedAdViewDidDetailViewShow:(DspFeedAdView *)dspFeedView;

// 信息流详情页关闭
- (void)dspAdDetailClosed:(nonnull DspAd *)dspAd adView:(nonnull UIView *)adView;

// 信息流播放状态回调
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd statusChanged:(DspFeedAdViewPlayerStatus)status feedAdView:(DspFeedAdView *)dspFeedView;

// 信息流曝光失败
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd
displayFailWithError:(NSError *_Nullable)error
       feedAdView:(DspFeedAdView *)dspFeedView;

// 信息流播放进度回调
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd playProgressChanged:(NSTimeInterval)times dspFeedView:(DspFeedAdView *)dspFeedView;

// 信息流视频播放完成
- (void)dspFeedAd:(DspFeedAd *)dspFeedAd videoPlayFinished:(DspFeedAdView *)dspFeedView;


```

#### 获取信息流广告eCPM价格，单位为分
```objc
// 获取的是每个DspFeedAdView对象的getEcpm
[feedAdView getEcpm]
```

#### 信息流广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[feedAdView setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 信息流广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[feedAdView biddingLoss:1001 winPrice:firstPrice adnType:4];
```

=============================================================

### 自渲染广告

#### 引入头文件
```objc
#import <DSPSDK/DspNativeAd.h>
#import <DSPSDK/DspNativeAdManager.h>
```

#### 自渲染广告的加载
```objc
self.nativeAdManager = [[DspNativeAdManager alloc] init];
self.nativeAdManager.zjad_id = Appid; // AppId
self.nativeAdManager.ad_id = adId; // 请求的广告位ID
self.nativeAdManager.ad_type = DspADType_Native; // 请求的广告类型
self.nativeAdManager.videoMuted = NO; // 设置视频是否静音，默认为静音
self.nativeAdManager.shake_power = @"15"; // 设置摇一摇力度，默认需要设置为15，0代表关闭
self.nativeAdManager.adSize = CGSizeMake(KScreenSize.width, 200); // 设置信息流加载素材的宽度和高度
self.nativeAdManager.delegate = self; // 设置代理回调
// 设置请求参数，图片的宽度，高度
NSDictionary *params = @{
    @"image_height":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.height],
    @"image_width":[NSNumber numberWithDouble:[UIScreen mainScreen].bounds.size.width],
    @"ad_count":@(adCount)
};
// 请求加载数据
[self.nativeAdManager loadAdDate:params];
```

#### 自渲染素材加载成功和失败的方法代理 DspNativeAdManagerDelegate

```objc
// 加载成功
- (void)dspNativeAdManagerSuccessToLoad:(DspNativeAdManager *)adsManager nativeAds:(NSArray<DspNativeAd *> *)nativeAds {
    self.datasource = nativeAds;
    [self.tableView reloadData];
}

// 加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error
```

#### 自渲染广告的展示

```objc
// 从加载成功方法里面获取views，
DspNativeAd *nativeAd = self.datasource[indexPath.row];
    nativeAd.delegate = self;
    if (nativeAd.materialType == DspAdMaterialTypeSingle) {
        UIImageView *imageView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, CGRectGetWidth(cell.frame) / 3 * 1, CGRectGetHeight(cell.frame))];
        NSData *data = [NSData dataWithContentsOfURL:[NSURL URLWithString:nativeAd.image]];
        imageView.image = [UIImage imageWithData:data];
        [cell addSubview:imageView];
        
        UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetWidth(cell.frame) / 3 * 1 + 10, 0, CGRectGetWidth(cell.frame) / 3 * 2 - 10, 30)];
        titleLabel.text = nativeAd.title;
        [cell addSubview:titleLabel];
        
        UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(titleLabel.frame), CGRectGetHeight(cell.frame) - 30, CGRectGetWidth(titleLabel.frame), 30)];
        descLabel.text = nativeAd.adDesc;
        [cell addSubview:descLabel];
        // logo+广告字样
        DspAdTagView *logoView = nativeAd.logoView;
        [logoView setFrame:CGRectMake(CGRectGetWidth(cell.frame) - 44 - 10, CGRectGetHeight(cell.frame) - 18, 44, 18)];
        [cell addSubview:logoView];
        // 绑定可点击视图
        [nativeAd registerContainer:cell withClickableViews:@[imageView, titleLabel, descLabel, logoView]];
        // 绑定数据
        [nativeAd refreshData:nativeAd];
    } else {
        if (_videoView) {
            [_videoView close];
        }
        // 获取视频播放视图
        _videoView = nativeAd.videoAdView;
        [_videoView setFrame:CGRectMake(0, 0, CGRectGetWidth(cell.frame) / 3 * 1, CGRectGetHeight(cell.frame))];
        nativeAd.delegate = self;
        [_videoView start];
        [cell addSubview:_videoView];
        
        UILabel *titleLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetWidth(cell.frame) / 3 * 1 + 10, 0, CGRectGetWidth(cell.frame) / 3 * 2 - 10, 30)];
        titleLabel.text = nativeAd.title;
        [cell addSubview:titleLabel];
        
        UILabel *descLabel = [[UILabel alloc] initWithFrame:CGRectMake(CGRectGetMinX(titleLabel.frame), CGRectGetHeight(cell.frame) - 30, CGRectGetWidth(titleLabel.frame), 30)];
        descLabel.text = nativeAd.adDesc;
        [cell addSubview:descLabel];
        
        DspAdTagView *logoView = nativeAd.logoView;
        [logoView setFrame:CGRectMake(CGRectGetWidth(cell.frame) - 44 - 10, CGRectGetHeight(cell.frame) - 18, 44, 18)];
        [cell addSubview:logoView];
        [nativeAd registerContainer:cell withClickableViews:@[_videoView, titleLabel, descLabel, logoView]];
        [nativeAd refreshData:nativeAd];

```

#### 自渲染代理回调 - DspNativeAdManagerDelegate

```objc

// 自渲染数据加载成功
- (void)dspNativeAdManagerSuccessToLoad:(DspNativeAdManager *)adsManager nativeAds:(NSArray<DspNativeAd *> *)nativeAds;

// 自渲染数据加载失败
- (void)dspAdLoadFail:(DspAd *)dspAd error:(NSError *)error

```

#### 自渲染代理回调 - DspNativeAdDelegate

```objc
// 自渲染视图点击回调
- (void)dspNativeAdDidClick:(DspNativeAd *)nativeAd withView:(UIView *_Nullable)view

// 自渲染详情页已经展示
- (void)dspNativeAdDidShowOtherController:(DspNativeAd *)nativeAd

// 自渲染详情页关闭
- (void)dspNativeAdDidCloseOtherController:(DspNativeAd *)nativeAd

// 自渲染视图已经展示
- (void)dspNativeAdDidShow:(DspNativeAd *)nativeAd

// 视频准备播放
- (void)dspNativeAdVideoReadyToPlay:(DspNativeAd *)nativeAd

// 视频开始播放
- (void)dspNativeAdVideoStartPlay:(DspNativeAd *)nativeAd

// 视频播放完成
- (void)dspNativeAdVideoPlayFinished:(DspNativeAd *)nativeAd

```

#### 获取自渲染广告eCPM价格，单位为分
```objc
// 获取DspNativeAd对象的价格
[nativeAd getEcpm]
```

#### 自渲染广告bidding竞胜方法回传
```objc
// 第一个参数：广告竞胜时的价格，
// 第二个参数：广告竞败的最高价格
[nativeAd setBidEcpm:self.eCPM highestLossEcpm:secondPrice];
```

#### 自渲染广告bidding竞败方法回传
```objc
/**
 竞价失败之后调用
 lossCode竞价失败原因(枚举):
 1001竞争力不足，如不是本次竞价的最高出价方，可上报此竟败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他(有回包)
 winPrice竞胜者出价，单位为分
 adnType 竞胜者平台，跟 pm type 保持一致
 */
[nativeAd biddingLoss:1001 winPrice:firstPrice adnType:4];
```

#### 自渲染数据模型
```objc
@interface DspNativeAd : NSObject

@property (nonatomic, weak) id <DspNativeAdDelegate> delegate;

// 广告标题
@property (nonatomic, copy) NSString *title;

// 广告描述
@property (nonatomic, copy) NSString *adDesc;

// 广告主图url
@property (nonatomic, copy) NSString *image;

// 预留参数，默认为0
@property (nonatomic, assign) CGFloat imageWidth;

// 预留参数，默认为0
@property (nonatomic, assign) CGFloat imageHeight;

// 预留字段
@property (nonatomic, strong) NSArray *imageArray;

// 广告图标url--对应logo字段，正方形的图片
@property (nonatomic, copy) NSString *icon;

// 广告来源，默认为“广告”，预留字段
@property (nonatomic, copy) NSString *adSourceName;

// 广告来源标识图片，预留字段
@property (nonatomic, copy) NSString *adSourceLogo;

// 用户点击交互类型
@property (nonatomic, assign) DspAdInteractionType interactionType;

// 资源类型
// 判断video.url是否为空，如果不为空就是视频类型，如果为空就是图片
@property (nonatomic, assign) DspAdMaterialType materialType;

@property (nonatomic, strong, readonly) DspAdTagView *logoView;

// 视频View，如果是视频类型，该属性可以正常使用，否则不要使用
@property (nonatomic, strong, readonly) DspVideoView *videoAdView;

// 视频广告时长
@property (nonatomic, assign) CGFloat videoDuration;

// 单位:分，只有视频资源下载成功后，这个才可能有值
@property (nonatomic, assign) NSInteger ecpm;

// 这个只是为了保存数据，不提供对外使用
@property (nonatomic, strong) DspAdItem *adItem;

// 设置点击区域，false代表所有都能点击，true只有视频或者图片不能点击,其他都能点击
@property (nonatomic, assign) BOOL area_enable;

// 设置视频播放是否静音
@property (nonatomic, assign) BOOL videoMuted;

@property (nonatomic, copy) void(^clickBlock)(DspAdItem *adItem, id responseObject);

- (void)refreshData:(DspNativeAd *)nativeAd;

// 设置点击事件
//@param containerView，container view of the native ad. 必传参数
//@param clickableViews，Array of views that are clickable. 可选参数
- (void)registerContainer:(__kindof UIView *)containerView withClickableViews:(NSArray<__kindof UIView *> *_Nullable)clickableViews;

/**
 Unregister ad view from the native ad.
 */
- (void)unregisterClickableViews;

- (void)setBidEcpm:(NSInteger)ecpm;

- (void)setBidEcpm:(NSInteger)ecpm highestLossEcpm:(NSInteger)highestLossEcpm;

- (NSInteger)getEcpm;

- (NSDictionary *)getExtraInfo;

@end
```

### 对接注意事项

* AppDelegate需要声明UIWindow属性，否则会造成SDK无法正常使用的风险，因为SDK要兼容iOS11及其以上版本
