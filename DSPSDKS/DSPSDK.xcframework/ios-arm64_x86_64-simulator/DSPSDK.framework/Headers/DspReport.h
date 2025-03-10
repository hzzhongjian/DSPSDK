//
//  DspReport.h
//  DSPSDK
//
//  Created by Robin on 2021/1/22.
//

#import <Foundation/Foundation.h>
#import <DSPSDK/DspAdItem.h>

//#warnnig =============== 埋点事件上报改到这里 ===============

// 视频是否从第一帧开始播放。从第一帧开始播放为1;否则，为0
typedef NS_ENUM(NSInteger, ZJ_PLAY_FIRST_FRAME) {
    ZJ_PLAY_FIRST_FRAME_NO = 0,
    ZJ_PLAY_FIRST_FRAME_YES = 1
};

// 视频是否播放到最后一帧。播放到最后一帧，则为否则，为0。
typedef NS_ENUM(NSInteger, ZJ_PLAY_LAST_FRAME) {
    ZJ_PLAY_LAST_FRAME_NO = 0,
    ZJ_PLAY_LAST_FRAME_YES = 1,
};

// 播放类型。1:第一次播放;2:暂停后继续播放;3:重新开始播放
typedef NS_ENUM(NSInteger, ZJ_PLAY_TYPE) {
    ZJ_PLAY_TYPE_FIRST = 1,
    ZJ_PLAY_TYPE_RESUME = 2,
    ZJ_PLAY_TYPE_RENEW = 3,
};

// 播放行为。1: 自动播放(推荐联网方式为wifi或4(时，设置视频自动播放);2:点击播放
typedef NS_ENUM(NSInteger, ZJ_PLAY_BEHAVIOR) {
    ZJ_PLAY_BEHAVIOR_AUTO = 1,
    ZJ_PLAY_BEHAVIOR_CLICK = 2
};

// 播放状态。1:正常播放;2:视频加载中;4:播放错误。
typedef NS_ENUM(NSInteger, ZJ_PLAY_STATUS) {
    ZJ_PLAY_STATUS_NORMAL = 1,
    ZJ_PLAY_STATUS_LOADING = 2,
    ZJ_PLAY_STATUS_ERROR = 4
};

//视频播放场景。推荐场景如下:1:在广告曝光区播放;2: 全屏竖屏、只展示视频;3: 全屏竖屏、屏幕上方展示视频、下方展示广告推广目标网页(仅适用于交互类型是打开网页的广告，目标网页日日点击上报返回数据中取得)4: 全屏横屏、只展示视频;5: 其它开发者自定义场景
typedef NS_ENUM(NSInteger, ZJ_PLAY_SCENE) {
    ZJ_PLAY_SCENE_EXPOSURE_ZONE = 1,
    ZJ_PLAY_SCENE_FULL_SCREEN_PORTRAIT_ONLY_VIDEO = 2,
    ZJ_PLAY_SCENE_FULL_SCREEN_PORTRAIT_TOP_BOTTOM = 3,
    ZJ_PLAY_SCENE_FULL_SCREEN_LANDSCAPE_ONLY_VIDEO = 4,
    ZJ_PLAY_SCENE_CUSTOM = 5,
};

// 调起失败原因，调起失败时必填:1:被拦截，2:应用未安装，3:调起异常
typedef NS_ENUM(NSInteger, DPL_FAIL_REASON) {
    DPL_FAIL_REASON_UNKNOWN = 0,
    DPL_FAIL_REASON_HELD_UP = 1,
    DPL_FAIL_REASON_APP_NOT_INSTALL = 2,
    DPL_FAIL_REASON_TUNING_ANOMALY = 3,
};

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nonnull  const Dsp_Event_Load;

extern NSString * _Nonnull  const Dsp_Event_Show;

extern NSString * _Nonnull  const Dsp_Event_Click;

extern NSString * _Nonnull  const Dsp_Event_Error;

extern NSString * _Nonnull  const Dsp_Event_Other;

extern NSString * _Nonnull  const Dsp_Event_Start;

extern NSString * _Nonnull  const Dsp_Event_Finish;

extern NSString * _Nonnull  const Dsp_Event_Close;

extern NSString * _Nonnull  const Dsp_Event_AppStore_OPEN;

extern NSString * _Nonnull  const Dsp_Event_AppStore_Close;

extern NSString * _Nonnull  const Dsp_Event_AppStore_Loaded;

extern NSString * _Nonnull  const Dsp_Event_AppStore_Load_FAIL;


extern NSString * _Nonnull  const Dsp_EVENT_PAGE_OPEN;

extern NSString * _Nonnull  const Dsp_EVENT_PAGE_CLOSE;

extern NSString * _Nonnull  const Dsp_EVENT_PAGE_OPEN_FAIL;


@interface DspReport : NSObject

+ (void)reportImpressNotice:(DspAdItem *)adItem;

+ (void)reportClickNotice:(DspAdItem *)adItem;

+ (void)report:(DspAdItem *)adItem 
           api:(NSString *)api
        params:(nullable NSDictionary *)params;

/// 点击事件上报
/// - Parameters:
///   - adItem: 上报的aditem
///   - params: 其他自定义参数
///   - compliteBlock: 上报结束block，点击完后后需要通过response来决定跳转落地页的处理在此block中执行
+ (void)reportClickEvent:(DspAdItem *)adItem
                  params:(nullable NSDictionary *)params
           compliteBlock:(void (^)(NSURLSessionDataTask *task,id responseObject, NSError *error))compliteBlock;

+ (NSMutableDictionary *)getAllReportTimeStamp;

// 视频类
+ (NSMutableDictionary *)videoReportWithPlay_progress_part_time:(NSString *)play_progress_part_time
                    play_progress_ts:(long)play_progress_ts
                    play_progress_ms:(long)play_progress_ms
                       play_begin_ts:(long)play_begin_ts
                         play_end_ts:(long)play_end_ts
                    play_first_frame:(ZJ_PLAY_FIRST_FRAME)play_first_frame
                     play_last_frame:(ZJ_PLAY_LAST_FRAME)play_last_frame
                           play_type:(ZJ_PLAY_TYPE)play_type
                       play_behavior:(ZJ_PLAY_BEHAVIOR)play_behavior
                         play_status:(ZJ_PLAY_STATUS)play_status
                          play_scene:(ZJ_PLAY_SCENE)play_scene
                          video_time:(long)video_time;

// 其他类
+ (NSMutableDictionary *)otherCategoryWithX1:(long)x1
                                    y1:(long)y1
                                    x2:(long)x2
                                    y2:(long)y2
                  material_down_fin_ms:(long)material_down_fin_ms
                           click_up_ms:(long)click_up_ms
                       dpl_fail_reason:(DPL_FAIL_REASON)dpl_fail_reason
                             req_width:(long)req_width
                            req_height:(long)req_height;

@end

NS_ASSUME_NONNULL_END
