//
//  DspAdVideo.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface DspAdVideo : DspObject

@property(nonatomic,copy) NSString *url;
@property(nonatomic,copy) NSString *cover;
@property(nonatomic,assign) NSInteger duration;
@property(nonatomic,assign) NSInteger file_size;
@property(nonatomic,assign) NSInteger valid_duration;
@property(nonatomic,assign) NSInteger skip_duration;
///type==1时为激励浏览类，url为目标地址
///validDuration==0时客户端控制0S跳过
@property(nonatomic,copy) NSString *type;

@end

NS_ASSUME_NONNULL_END
