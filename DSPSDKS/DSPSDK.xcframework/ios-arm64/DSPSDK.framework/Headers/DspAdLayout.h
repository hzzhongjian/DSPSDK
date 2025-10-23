//
//  DspAdLayout.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN


/// center: 纯图
extern NSString * _Nonnull  const Dsp_Location_Center;

/// left: 左图右文
extern NSString * _Nonnull  const Dsp_Location_Left;

/// top: 上图下文
extern NSString * _Nonnull  const Dsp_Location_Top;

/// right: 右图左文
extern NSString * _Nonnull  const Dsp_Location_Right;

/// bottom: 下图上文
extern NSString * _Nonnull  const Dsp_Location_Bottom;

/// img_txtfloat: 图片 + 文字浮层（竖版图片）
extern NSString * _Nonnull  const Dsp_Location_img_txtfloat;

/// video_txtfloat: 视频 + 文字浮层
extern NSString * _Nonnull  const Dsp_Location_video_txtfloat;


extern NSString * _Nonnull  const Dsp_Location_portrait;

/// upimg_downtxt: 上图下文（横板图片）
extern NSString * _Nonnull  const Dsp_Location_upimg_downtxt;

/// upvideo_downcard: 上视频下卡片
extern NSString * _Nonnull  const Dsp_Location_upvideo_downcard;

extern NSString * _Nonnull  const Dsp_Location_landscape;

/// leftimg_righttxt: 左图右文（竖版图片）
extern NSString * _Nonnull  const Dsp_Location_leftimg_righttxt;

/// leftvideo_rightcard: 左视频右卡片
extern NSString * _Nonnull  const Dsp_Location_leftvideo_rightcard;

/// video_txtdown: 视频 + 文字底栏
extern NSString * _Nonnull  const Dsp_Location_video_txtdown;

extern NSString * _Nonnull  const Dsp_Location_img_txtdown;


/// 布局信息

@interface DspAdLayout : DspObject

@property (nonatomic, copy) NSString *content_edge;

/// 模板样式
// left: 左图右文
// top: 上图下文
// right: 右图左文
// bottom: 下图上文
// center: 纯图
// img_txtfloat: 图片 + 文字浮层（竖版图片）
// upimg_downtxt: 上图下文（横板图片）
// leftimg_righttxt: 左图右文（竖版图片）
// video_txtfloat: 视频 + 文字浮层
// video_txtdown: 视频 + 文字底栏
// upvideo_downcard: 上视频下卡片
// leftvideo_rightcard: 左视频右卡片
@property (nonatomic, copy) NSString *image_location;

/// 图片宽高比例 16x8
@property (nonatomic, copy) NSString *image_radio;

/// 图片尺寸大小 200x200
@property (nonatomic, copy) NSString *image_size;

/// 模板样式尺寸 200x200
@property (nonatomic, copy) NSString *location_size;

@property (nonatomic, copy) NSString *title_Size;

@property (nonatomic, copy) NSString *title_Color;

@property (nonatomic, copy) NSString *desc_Size;

@property (nonatomic, copy) NSString *desc_Color;

@end

NS_ASSUME_NONNULL_END
