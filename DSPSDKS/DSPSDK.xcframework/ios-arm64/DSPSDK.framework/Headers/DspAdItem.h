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
NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, DspMediaType){
    DspMediaTypeImage = 0,
    DspMediaTypeVideo,
};

@interface DspAdItem : DspObject

@property(nonatomic,copy) NSString *zjad_id;
@property(nonatomic,copy) NSString *ad_id;
@property(nonatomic,copy) NSString *trade_id;
@property(nonatomic,copy) NSString *ad_type;
@property(nonatomic,copy) NSString *ad_item_id;
@property(nonatomic,copy) NSString *order_no;
@property(nonatomic,copy) NSString *company_name;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,copy) NSString *desc;
@property(nonatomic,copy) NSString *logo;
@property(nonatomic,copy) NSString *icon;
@property(nonatomic,copy) NSString *image;
//@property(nonatomic,copy) NSString *image_thumb;
@property(nonatomic,assign) NSInteger valid_duration;
//int 类型，单位分，-1 为非 bidding，大于等于0 bidding 价格
@property(nonatomic,assign) NSInteger price;

@property(nonatomic,assign) NSInteger bidEcpm;

@property(nonatomic,assign) BOOL area_enable;

@property(nonatomic,strong) DspAdCard *card_info;
@property(nonatomic,strong) DspAdVideo *video;
@property(nonatomic,strong) DspAdAction *click_action;
@property(nonatomic,strong) DspAdLayout *adLayout;
@property (nonatomic, copy) NSArray *click_notice_urls;
@property (nonatomic, copy) NSArray *impress_notice_urls;


#warning 新增参数


// screen_show 广告在屏幕显示形式
// full 全屏
// half 半屏
//"screen_show": "",
/// 是否全屏 ，全屏/半屏
@property (nonatomic, strong) NSString *screen_show;

///是否展示挽留页
@property (nonatomic, assign) BOOL is_show_retain_page;

///是否展示结束页
@property (nonatomic, assign) BOOL is_show_end_page;

/// 是否需要发奖
@property (nonatomic, assign) BOOL is_award;

@property (nonatomic, assign) DspMediaType mediaType;

@end

NS_ASSUME_NONNULL_END
