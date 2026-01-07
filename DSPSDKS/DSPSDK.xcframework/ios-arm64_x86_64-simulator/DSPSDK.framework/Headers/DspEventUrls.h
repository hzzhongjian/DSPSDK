//
//  DspEventUrls.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/2/21.
//

#import <DSPSDK/DspObject.h>


NS_ASSUME_NONNULL_BEGIN

/// 上报地址
@interface DspEventUrls : DspObject

/// 曝光
@property (nonatomic, strong) NSArray<NSString *> *show;

/// 点击（宏替换）
@property (nonatomic, strong) NSArray<NSString *> *click;

/// 开始下载
@property (nonatomic, strong) NSArray<NSString *> *dl_start;

/// 下载成功
@property (nonatomic, strong) NSArray<NSString *> *dl_succ;

/// 安装开始
@property (nonatomic, strong) NSArray<NSString *> *inst_start;

/// 安装成功
@property (nonatomic, strong) NSArray<NSString *> *inst_succ;

/// 应用激活上报
@property (nonatomic, strong) NSArray<NSString *> *inst_open;

/// 上报(广告的一部分出现在可视区域时触发)
@property (nonatomic, strong) NSArray<NSString *> *sichtteil;

/// 上报(视频广告开始播放时触发)
@property (nonatomic, strong) NSArray<NSString *> *start;

/// Deeplink唤醒成功上报
@property (nonatomic, strong) NSArray<NSString *> *dpl_succ;

/// 上报(视频广告播放了25%时触发)
@property (nonatomic, strong) NSArray<NSString *> *first_quartile;

/// 上报(视频广告播放了50%时触发)
@property (nonatomic, strong) NSArray<NSString *> *mid_point;

/// 上报(视频广告播放了75%时触发)
@property (nonatomic, strong) NSArray<NSString *> *third_quartile;

/// 视频广告播放完成之后触发
@property (nonatomic, strong) NSArray<NSString *> *complete;

/// (用户点击暂停按钮停止播放视频广告时触发)
@property (nonatomic, strong) NSArray<NSString *> *pause;

/// (用户点击暂停按钮停止播放视频广告时触发)
@property (nonatomic, strong) NSArray<NSString *> *resume;

/// 用户主动关闭视频广告声音
@property (nonatomic, strong) NSArray<NSString *> *mute;

/// 用户主动开启视频广告声音
@property (nonatomic, strong) NSArray<NSString *> *unmute;

/// 重播视频
@property (nonatomic, strong) NSArray<NSString *> *replay;

/// 上滑事件
@property (nonatomic, strong) NSArray<NSString *> *up_scroll;

/// 下滑事件
@property (nonatomic, strong) NSArray<NSString *> *down_scroll;

/// 全屏
@property (nonatomic, strong) NSArray <NSString *> *fullscreen;

/// 退出全屏
@property (nonatomic, strong) NSArray<NSString *> *exit_fullscreen;

/// (关闭视频)
@property (nonatomic, strong) NSArray<NSString *> *close_linear;

/// 用户点击视频跳过按钮跳过视频播放)
@property (nonatomic, strong) NSArray<NSString *> *skip;

/// deeplink 唤醒失败上报
@property (nonatomic, strong) NSArray<NSString *> *dpl_fail;

/// deeplink 调用上报
@property (nonatomic, strong) NSArray<NSString *> *dpl_invoke;

/// 竞价成功上报
@property (nonatomic, strong) NSArray<NSString *> *compete_succ;

/// 竞价失败上报
@property (nonatomic, strong) NSArray<NSString *> *compete_fail;

/// 曝光失败上报
@property (nonatomic, strong) NSArray<NSString *> *show_fail;

/// 关闭广告上报
/// 图片，视频，所有广告类型，关闭广告都需要上报
@property (nonatomic, strong) NSArray<NSString *> *close;

/// 播放到指定秒上报, 3秒，5秒
@property (nonatomic, strong) NSArray<NSString *> *play_n_seconds;

+ (DspEventUrls *)parseEventUrls:(NSDictionary *)eventUrlsDict;

@end

NS_ASSUME_NONNULL_END
