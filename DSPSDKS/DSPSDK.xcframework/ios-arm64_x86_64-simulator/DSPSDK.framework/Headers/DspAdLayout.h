//
//  DspAdLayout.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN
extern NSString * _Nonnull  const Dsp_Location_Center;
extern NSString * _Nonnull  const Dsp_Location_Left;
extern NSString * _Nonnull  const Dsp_Location_Top;
extern NSString * _Nonnull  const Dsp_Location_Right;
extern NSString * _Nonnull  const Dsp_Location_Bottom;

extern NSString * _Nonnull  const Dsp_Location_img_txtfloat;
extern NSString * _Nonnull  const Dsp_Location_video_txtfloat;
extern NSString * _Nonnull  const Dsp_Location_portrait;


extern NSString * _Nonnull  const Dsp_Location_upimg_downtxt;
extern NSString * _Nonnull  const Dsp_Location_upvideo_downcard;
extern NSString * _Nonnull  const Dsp_Location_landscape;


extern NSString * _Nonnull  const Dsp_Location_leftimg_righttxt;
extern NSString * _Nonnull  const Dsp_Location_leftvideo_rightcard;

extern NSString * _Nonnull  const Dsp_Location_video_txtdown;
extern NSString * _Nonnull  const Dsp_Location_img_txtdown;

@interface DspAdLayout : DspObject

@property(nonatomic,copy) NSString *content_edge;
@property(nonatomic,copy) NSString *image_location;
@property(nonatomic,copy) NSString *image_size;
@property(nonatomic,copy) NSString *title_Size;
@property(nonatomic,copy) NSString *title_Color;
@property(nonatomic,copy) NSString *desc_Size;
@property(nonatomic,copy) NSString *desc_Color;

@end

NS_ASSUME_NONNULL_END
