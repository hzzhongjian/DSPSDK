//
//  DspView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/19.
//

#import <UIKit/UIKit.h>
#import <DSPSDK/DspViewDelegate.h>
NS_ASSUME_NONNULL_BEGIN



@interface DspView : UIView
@property(nonatomic,strong) DspAdItem *adItem;
@property(nonatomic,weak) id<DspViewDelegate> delegate;

//-(BOOL) isShowingOnKeyWindow;

@property (nonatomic, assign) NSTimeInterval click_up_ms;

@property (nonatomic, assign) NSTimeInterval material_down_fin_ms;

@property (nonatomic, assign) NSInteger dpl_fail_reason;

- (NSDictionary *)reportParams;

@end

NS_ASSUME_NONNULL_END
