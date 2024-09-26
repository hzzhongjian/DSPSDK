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
@end

NS_ASSUME_NONNULL_END
