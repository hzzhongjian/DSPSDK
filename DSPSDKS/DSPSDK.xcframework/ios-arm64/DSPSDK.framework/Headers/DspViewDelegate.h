//
//  DspViewDelegate.h
//  DSPSDK
//
//  Created by 麻明康 on 2024/1/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@class DspView;
@protocol DspViewDelegate <NSObject>

@optional

-(void) dspViewDidShow:(DspView*) dspView;
-(void) dspViewDidDisappear:(DspView*) dspView;
-(void) dspViewDidClosed:(DspView*) dspView showTimes:(NSInteger) showTimes;
-(void) dspViewDidClicked:(DspView*) dspView response:(nullable NSDictionary *)response;

@end

NS_ASSUME_NONNULL_END
