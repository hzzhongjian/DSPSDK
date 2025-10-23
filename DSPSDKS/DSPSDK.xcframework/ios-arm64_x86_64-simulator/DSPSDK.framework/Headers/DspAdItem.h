//
//  DspAdItem.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>
#import <DSPSDK/DspAdCard.h>
#import <DSPSDK/DspAdVideo.h>
#import <DSPSDK/DspAdAction.h>
#import <DSPSDK/DspAdLayout.h>
#import <DSPSDK/DspEventUrls.h>
#import <DSPSDK/DspAdSource.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DspMediaType){
    DspMediaTypeImage = 0,
    DspMediaTypeVideo,
};

@interface DspAdItem : DspObject

// 这是每个数据对象的完整数据，没有解析
@property (nonatomic, strong) NSDictionary *ad_data;

// 这个字段代表AppId
@property (nonatomic, copy) NSString *zjad_id;

// 广告位id
@property (nonatomic, copy) NSString *ad_id;

@property (nonatomic, copy) NSString *idea_no;

@property (nonatomic, copy) NSString *trade_id;

@property (nonatomic, copy) NSString *ad_type;

/// 广告编号--广告创意ID
@property (nonatomic, copy) NSString *ad_item_id;

/// 订单编号--广告编号
@property (nonatomic, copy) NSString *order_no;

@property (nonatomic, copy) NSString *company_name;

/// 标题，用于前端展示（自渲染、信息流、激励视频、全屏视频）
@property (nonatomic, copy) NSString *title;

/// 描述，用于前端展示（自渲染、信息流、激励视频、全屏视频）
@property (nonatomic, copy) NSString *desc;

/// Logo，用于前端展示（激励视频、全屏视频、自渲染Logo）
@property (nonatomic, copy) NSString *logo;

@property (nonatomic, copy) NSString *icon;

/// 主图，用于前端显示（自渲染、Banner、插屏、开屏、激励视频、全屏视频）
@property (nonatomic, copy) NSString *image;

@property (nonatomic, copy) NSString *image_thumb;

@property (nonatomic, assign) NSInteger valid_duration;

///int 类型，单位分，-1 固价(非竞价)
@property(nonatomic,assign) NSInteger price;

@property(nonatomic,assign) NSInteger bidEcpm;

/// 开屏是否限制热区，false 不限制点击热区
@property(nonatomic,assign) BOOL area_enable;

@property(nonatomic,strong) DspAdCard *card_info;

/// 视频对象
@property(nonatomic,strong) DspAdVideo *video;

/// 点击事件
@property(nonatomic,strong) DspAdAction *click_action;

/// 布局信息
@property(nonatomic,strong) DspAdLayout *adLayout;

@property (nonatomic, copy) NSArray *click_notice_urls;

@property (nonatomic, copy) NSArray *impress_notice_urls;

/// screen_show 广告在屏幕显示形式
/// full 全屏
/// half 半屏
/// "screen_show": "",
/// 是否全屏 ，全屏/半屏
@property (nonatomic, strong) NSString *screen_show;

///是否展示挽留页
@property (nonatomic, assign) BOOL is_show_retain_page;

/// 是否展示结束页
@property (nonatomic, assign) BOOL is_show_end_page;

/// 是否需要发奖
@property (nonatomic, assign) BOOL is_award;

/// 视频/图片
@property (nonatomic, assign) DspMediaType mediaType;

/// 上报地址
@property (nonatomic, strong) DspEventUrls *event_urls;

/// 用于用户上报透传参数
@property (nonatomic, strong) NSString *extra;

/// 用户user_id
@property (nonatomic, strong) NSString *user_id;

/// 设置广告logo+广告字样样式的
@property (nonatomic, strong) DspAdSource *ad_source;

/// 添加是否已经曝光的标识
@property (nonatomic, assign) BOOL hasReportExposure;

/// 用来记录摇一摇是否触发两次了，如果同一个广告超过两次，就不再触发了
@property (nonatomic, assign) NSInteger shakeTimes;

@end

NS_ASSUME_NONNULL_END
