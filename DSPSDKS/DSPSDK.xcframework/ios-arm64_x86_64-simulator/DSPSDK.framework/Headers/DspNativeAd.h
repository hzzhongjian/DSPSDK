//
//  DspNativeAd.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/2/6.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DspAdInteractionType) {
    DspAdInteractionType_Unknown,
    DspAdInteractionType_App,
    DspAdInteractionType_Web,
    DspAdInteractionType_DeepLink,
    DspAdInteractionType_AppStore, // 预留类型
};

typedef NS_ENUM(NSInteger, DspAdMaterialType) {
    DspAdMaterialTypeUnknown = 0, // unknown
    DspAdMaterialTypeVideo = 1, // video
    DspAdMaterialTypeSingle = 2, // single image
    DspAdMaterialTypeAtlas = 3, // multiple image, 预留类型
};


@class DspNativeAd;
@class DspVideoView;
@class DspAdTagView;

@protocol DspNativeAdDelegate <NSObject>

@optional

- (void)dspNativeAdDidClick:(DspNativeAd *)nativeAd withView:(UIView *_Nullable)view;

- (void)dspNativeAdDidShowOtherController:(DspNativeAd *)nativeAd;

- (void)dspNativeAdDidCloseOtherController:(DspNativeAd *)nativeAd;

- (void)dspNativeAdDidShow:(DspNativeAd *)nativeAd;

- (void)dspNativeAdVideoReadyToPlay:(DspNativeAd *)nativeAd;

- (void)dspNativeAdVideoStartPlay:(DspNativeAd *)nativeAd;

- (void)dspNativeAdVideoPlayFinished:(DspNativeAd *)nativeAd;

- (void)dspNativeAdVideoPlayError:(DspNativeAd *)nativeAd;

@end

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


@end

NS_ASSUME_NONNULL_END
