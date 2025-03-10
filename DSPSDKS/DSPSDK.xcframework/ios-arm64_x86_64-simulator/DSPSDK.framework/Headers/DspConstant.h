//
//  DspConstant.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/2/19.
//

#ifndef DspConstant_h
#define DspConstant_h

// 一键关闭所有页面的通知key
#define kDspOneKeyCloseAllPageNotificationName @"DspOneKeyCloseAllPage"

/**
 微信opensdk状态
 0 无
 1: 错误或未集成
 2: 集成但没有微信
 3: 集成且有微信环境
 */
#define kDsp_WX_OPEN_SDK_STATUS @"ZJ_WX_OPEN_SDK_STATUS"
/**
 用户手指按下时的横坐标（相对于广告位左上角）
 */
#define kDsp_AD_CLICK_POINT_DOWN_X @"ZJ_AD_CLICK_POINT_DOWN_X"

/**
 用户手指按下时的纵坐标（相对于广告位左上角）
 */
#define kDsp_AD_CLICK_POINT_DOWN_Y @"ZJ_AD_CLICK_POINT_DOWN_Y"

/**
 用户手指离开屏幕时的横坐标（相对于广告位左上角）
 */
#define kDsp_AD_CLICK_POINT_UP_X @"ZJ_AD_CLICK_POINT_UP_X"

/**
 用户手指离开屏幕时的纵坐标（相对于广告位左上角）
 */
#define kDsp_AD_CLICK_POINT_UP_Y @"ZJ_AD_CLICK_POINT_UP_Y"

/**
 实际广告位宽度，单位像素
 */
#define kDsp_AD_WIDTH @"ZJ_AD_WIDTH"

/**
 实际广告位高度，单位像素
 */
#define kDsp_AD_HEIGHT @"ZJ_AD_HEIGHT"

/**
 点击时的时间戳(秒)
 */
#define kDsp_CLICK_TS @"ZJ_CLICK_TS"

/**
 用户手指按下时的横坐标（相对于屏幕左上角）
 */
#define kDsp_SCR_CLICK_POINT_DOWN_X @"ZJ_SCR_CLICK_POINT_DOWN_X"

/**
 用户手指按下时的纵坐标（相对于屏幕左上角）
 */
#define kDsp_SCR_CLICK_POINT_DOWN_Y @"ZJ_SCR_CLICK_POINT_DOWN_Y"

/**
 用户手指离开屏幕时的横坐标（相对于屏幕左上角）
 */
#define kDsp_SCR_CLICK_POINT_UP_X @"ZJ_SCR_CLICK_POINT_UP_X"

/**
 用户手指离开屏幕时的纵坐标（相对于屏幕左上角）
 */
#define kDsp_SCR_CLICK_POINT_UP_Y @"ZJ_SCR_CLICK_POINT_UP_Y"

/**
 上报时间戳(秒)
 */
#define kDsp_REPORT_TS @"ZJ_REPORT_TS"

/**
 上报时间戳(毫秒)
 */
#define kDsp_REPORT_MS @"ZJ_REPORT_MS"

/**
 触发该事件时的广告播放进度 时间格式 HH：mm：ss.SSS
 */
#define kDsp_PLAY_PROGRESS_PART_TIME @"ZJ_PLAY_PROGRESS_PART_TIME"

/**
 触发该事件时的广告播放进度，单位秒
 */
#define kDsp_PLAY_PROGRESS_TS @"ZJ_PLAY_PROGRESS_TS"

/**
 触发该事件时的广告播放进度，单位毫秒
 */
#define kDsp_PLAY_PROGRESS_MS @"ZJ_PLAY_PROGRESS_MS"

/**
 视频播放开始时间，单位为秒。如果视频从头开始播放，则为0。
 */
#define kDsp_PLAY_BEGIN_TS @"ZJ_PLAY_BEGIN_TS"

/**
 视频播放结束时间，单位为秒。如果视频播放到结尾，则等于视频总时长。
 */
#define kDsp_PLAY_END_TS @"ZJ_PLAY_END_TS"

/**
 视频是否从第一帧开始播放。从第一帧开始播放，则为1；否则，为0
 */
#define kDsp_PLAY_FIRST_FRAME @"ZJ_PLAY_FIRST_FRAME"

/**
 视频是否播放到最后一帧。播放到最后一帧，则为1；否则，为0。
 */
#define kDsp_PLAY_LAST_FRAME @"ZJ_PLAY_LAST_FRAME"

/**
 播放类型。1：第一次播放；2： 暂停后继续播放；3： 重新开始播放
 */
#define kDsp_PLAY_TYPE @"ZJ_PLAY_TYPE"

/**
 播放行为。1： 自动播放（推荐联网方式为wifi或4G时，设置视频自动播
 放）；2：点击播放
 */
#define kDsp_PLAY_BEHAVIOR @"ZJ_PLAY_BEHAVIOR"

/**
 播放状态。1： 正常播放；2 ：视频加载中；4：播放错误。
 */
#define kDsp_PLAY_STATUS @"ZJ_PLAY_STATUS"

/**
 视频播放场景。推荐场景如下：1： 在广告曝光区域播放；2 ： 全屏竖屏、
 只展示视频；3 ： 全屏竖屏、屏幕上方展示视频、下方展示广告推广目标网
 页（仅适用于交互类型是打开网页的广告，目标网页由点击上报返回数据中
 取得）4 ： 全屏横屏、只展示视频；5 ： 其它开发者自定义场景
 */
#define kDsp_PLAY_SCENE @"ZJ_PLAY_SCENE"

/**
 视频总时长，单位为秒
 */
#define kDsp_VIDEO_TIME @"ZJ_VIDEO_TIME"

/**
 坐标定义： 以屏幕左上角坐标为原点，距广告展示区域左上横像素距离
 */
#define kDsp_X1 @"ZJ_X1"

/**
 坐标定义： 以屏幕左上角坐标为原点，距广告展示区域左上纵像素距离
 */
#define kDsp_Y1 @"ZJ_Y1"

/**
 坐标定义： 以屏幕左上角坐标为原点，距广告展示区域右下横像素距离
 */
#define kDsp_X2 @"ZJ_X2"

/**
 坐标定义： 以屏幕左上角坐标为原点，距广告展示区域右下纵像素距离
 */
#define kDsp_Y2 @"ZJ_Y2"

/**
 所有广告素材下载完成时的当 前时间戳，精确到毫秒(展示 及后继事件可能
 存在)
 */
#define kDsp_MATERIAL_DOWN_FIN_MS @"ZJ_MATERIAL_DOWN_FIN_MS"

/**
 点击抬起时间戳，毫秒
 */
#define kDsp_CLICK_UP_MS @"ZJ_CLICK_UP_MS"

/**
 调起失败原因，调起失败时必填：1：被拦截，2：应用未安装，3：调起异
 常
 */
#define kDsp_DPL_FAIL_REASON @"ZJ_DPL_FAIL_REASON"

/**
 请求时预留的广告位高度 (展示及后继事件可能存在)
 */
#define kDsp_REQ_WIDTH @"ZJ_REQ_WIDTH"

/**
 请求时预留的广告位宽度 (展示及后继事件可能存在)
 */
#define kDsp_REQ_HEIGHT @"ZJ_REQ_HEIGHT"

/**
 竞价失败原因(枚举)：
 1001 竞争力不足，如不是本次竞价的最高出价方，可上报此竞败原因
 1002 无广告回包，如本次竞价中未返回广告，可上报此竞败原因
 1003 请求超时，可上报此竞败原因
 1004 有广告回包但未参与竞价
 1005 其他（有回包）
 */
#define kDsp_LOSS_CODE @"ZJ_LOSS_CODE"

/**
 竞胜者出价，单位为分
 */
#define kDsp_WIN_PRICE @"ZJ_WIN_PRICE"

/**
 竞败者出价，单位为分，最大竞败方的出价
 */
#define kDsp_LOSS_PRICE @"ZJ_LOSS_PRICE"

/**
 竞胜者平台：
 0 其它
 1 广点通
 2 穿山甲
 4 快手
 6 百度
 */
#define kDsp_ADN_TYPE @"ZJ_ADN_TYPE"

/**
 点击动作：1 常规点击2 滑动点击3 摇一摇4 扭一扭5 自定义手势
 */
#define kDsp_CLICK_ACTION @"ZJ_CLICK_ACTION"

/**
 摇一摇X轴方向
 */
#define kDsp_SHAKE_SHAKE_X @"ZJ_SHAKE_SHAKE_X"

/**
 摇一摇Y轴方向
 */
#define kDsp_SHAKE_SHAKE_Y @"ZJ_SHAKE_SHAKE_Y"

/**
 摇一摇Z轴方向
 */
#define kDsp_SHAKE_SHAKE_Z @"ZJ_SHAKE_SHAKE_Z"

/**
 扭一扭X轴方向
 */
#define kDsp_TWIST_TWIST_X @"ZJ_TWIST_TWIST_X"

/**
 扭一扭Y轴方向
 */
#define kDsp_TWIST_TWIST_Y @"ZJ_TWIST_TWIST_Y"

/**
 扭一扭Z轴方向
 */
#define kDsp_TWIST_TWIST_Z @"ZJ_TWIST_TWIST_Z"

/**
 msg
 */
#define kDsp_MESSAGE @"ZJ_MESSAGE"

/**
 * 点击并拉起落地页
 */
#define kDsp_CLICK_PULLUP_LANDINGPAGE @"ZJ_CLICK_PULLUP_LANDINGPAGE"

/**
 * 点击并拉起微信小程序
 */
#define kDsp_CLICK_PULLUP_WECHAT_MINI_PROGRAM @"ZJ_CLICK_PULLUP_WECHAT_MINI_PROGRAM"

/**
 * 点击并拉起Deeplink
 */
#define kDsp_CLICK_PULLUP_DEEPLINK @"ZJ_CLICK_PULLUP_DEEPLINK"

/**
 * 点击并拉起应用商店
 */
#define kDsp_CLICK_PULLUP_APPSTORE @"ZJ_CLICK_PULLUP_APPSTORE"



#endif /* DspConstant_h */
