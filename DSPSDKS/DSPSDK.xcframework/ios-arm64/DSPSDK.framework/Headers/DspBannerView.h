//
//  DspBannerView.h
//  DSPSDK
//
//  Created by Robin on 2021/1/24.
//

#import <DSPSDK/DspView.h>
#import <DSPSDK/DspViewDelegate.h>
NS_ASSUME_NONNULL_BEGIN

@interface DspBannerView : DspView
@property(nonatomic,weak) id<DspViewDelegate> delegate;
@property(nonatomic,copy) NSString *imageUrl;
@end

NS_ASSUME_NONNULL_END
