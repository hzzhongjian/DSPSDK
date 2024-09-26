//
//  DspFeedAdView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/25.
//

#import <DSPSDK/DspView.h>
#import <DSPSDK/DspViewDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@class DspFeedAdView;

@protocol DspFeedAdViewDelegate <DspViewDelegate>

-(void) feedAdViewRenderSuccess:(DspFeedAdView*) dspFeedAdView;
-(void) feedAdViewRenderFail:(DspFeedAdView *)dspFeedView error:(NSError *)error;

@optional

@end

@interface DspFeedAdView : DspView

@property(nonatomic,weak) id<DspFeedAdViewDelegate> delegate;
-(NSString *)identifier;

-(void) render;
- (void)setBidEcpm:(NSInteger)ecpm;

- (NSInteger)getEcpm;
@end

NS_ASSUME_NONNULL_END
