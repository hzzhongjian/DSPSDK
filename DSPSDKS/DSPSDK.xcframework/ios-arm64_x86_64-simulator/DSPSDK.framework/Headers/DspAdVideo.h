//
//  DspAdVideo.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>


NS_ASSUME_NONNULL_BEGIN

@interface DspAdVideo : DspObject

/// 视频地址（激励视频，全屏视频）
@property (nonatomic, copy) NSString *url;

@property (nonatomic, copy) NSString *idea_url;

@property (nonatomic, copy) NSString *cover;

/// 总时间长
@property (nonatomic, assign) NSInteger duration;

@property (nonatomic, assign) NSInteger file_size;

/// 发奖所需要的时间（激励视频）
@property (nonatomic, assign) NSInteger valid_duration;

/// 可跳过的时间（激励视频和全屏视频）
@property (nonatomic, assign) NSInteger skip_duration;

///type==1时为激励浏览类，url为目标地址
///validDuration==0时客户端控制0S跳过
@property (nonatomic, copy) NSString *type;

/// 自动跳转地址(h5)
@property (nonatomic, copy) NSString *auto_jump_url;

@end

NS_ASSUME_NONNULL_END
