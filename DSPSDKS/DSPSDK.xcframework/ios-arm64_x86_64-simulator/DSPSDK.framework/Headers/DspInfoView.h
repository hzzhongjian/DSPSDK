//
//  DspInfoView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/27.
//

#import <UIKit/UIKit.h>
#import <DSPSDK/DspViewBlocks.h>
NS_ASSUME_NONNULL_BEGIN

/// 激励视频和全屏视频下面的信息条
@interface DspInfoView : UIView

+(instancetype) create;
@property (weak, nonatomic) UIView *adView;
@property(nonatomic,strong) DspAdItem *adItem;
@property(nonatomic, copy, nullable)ClickAction clickAction;
//@property(nonatomic,copy)ClickReportFinishedBlk clickReportFinishedBlk;
//@property(nonatomic,copy)ClickReportFinishedBlk detailBtnClickReportFinishedBlk;

@end

NS_ASSUME_NONNULL_END
