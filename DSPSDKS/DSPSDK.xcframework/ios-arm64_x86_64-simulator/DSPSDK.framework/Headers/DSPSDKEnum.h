//
//  DSPSDKEnum.h
//  DSPSDK
//
//  Created by 麻明康 on 2023/12/22.
//

#ifndef DSPSDKEnum_h
#define DSPSDKEnum_h

typedef NS_ENUM(NSUInteger, DSPMediaPlayerStatus) {
    DSPMediaPlayerStatusDefalt = 0,         // 初始状态
    DSPMediaPlayerStatusLoading = 1,         // 加载中
    DSPMediaPlayerStatusPlaying = 2,         // 开始播放
    DSPMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
    DSPMediaPlayerStatusError = 4,           // 播放出错
    DSPMediaPlayerStatusStoped = 5,          // 播放停止
};

typedef NS_ENUM(NSInteger, DSPAdViewClickAction) {
    DSPAdViewClickAction_Regular = 1, // 常规点击
    DSPAdViewClickAction_Swipe = 2, // 滑动点击
    DSPAdViewClickAction_Shake = 3, // 摇一摇
    DSPAdViewClickAction_Twist = 4, // 扭一扭
    DSPAdViewClickAction_Custom = 5, // 自定义
};

#endif /* DSPSDKEnum_h */
