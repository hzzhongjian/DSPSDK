//
//  BannerViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/3/5.
//

#import "BannerViewController.h"
#import <DSPSDK/DspBannerAd.h>
@interface BannerViewController()<DspBannerAdDelegate>
{
    DspBannerAd *_bannerAd;
    CGSize _size;
    NSInteger _interval;
}
@end

@implementation BannerViewController

- (void)viewDidLoad{
    [super viewDidLoad];
    
}

-(void)loadAD{
    _bannerAd = [DspBannerAd new];
    _bannerAd.zjad_id = @"Z9663789745";
    _bannerAd.ad_id = @"J0695926914";
    _bannerAd.ad_type = DspADType_Banner;
    _bannerAd.size = CGSizeMake(KScreenSize.width, 200);
    _bannerAd.interval = 0;
    _bannerAd.delegate = self;
    NSDictionary *params = @{
        @"image_height":[NSNumber numberWithDouble:KScreenSize.width],
        @"image_width":[NSNumber numberWithDouble:200.]
    };
    [_bannerAd loadAdDate:params];
    [self addBannerView];
}

-(void)addBannerView{
    if(_bannerAd.bannerView&&![self.view.subviews containsObject:_bannerAd.bannerView]){
        CGFloat y = KScreenSize.height -200-SafeAreaBottomHeight-50;
        CGRect frame = CGRectMake(0, y, KScreenSize.width, 200);
        
        _bannerAd.bannerView.frame = frame;
        [self.view addSubview:_bannerAd.bannerView];
    }
}
/*
// Only override drawRect: if you perform custom drawing.
// An empty implementation adversely affects performance during animation.
- (void)drawRect:(CGRect)rect {
    // Drawing code
}
*/

- (void)bannerAdDidClick:(nonnull DspBannerAd *)dspBannerAd { 
    MKLog(@"=========%@", NSStringFromSelector(_cmd));
}

- (void)bannerAdDidCloseOtherController:(nonnull DspBannerAd *)dspBannerAd { 
    MKLog(@"=========%@", NSStringFromSelector(_cmd));
}

- (void)bannerAdDidFail:(nonnull DspBannerAd *)dspBannerAd error:(NSError * _Nullable)error { 
    MKLog(@"=========%@", NSStringFromSelector(_cmd));
    MKLog(@"======error:%@",error);
}

- (void)bannerAdDislike:(nonnull DspBannerAd *)dspBannerAd { 
    MKLog(@"=========%@", NSStringFromSelector(_cmd));
}

- (void)bannerAdWillBecomVisible:(nonnull DspBannerAd *)dspBannerAd { 
    MKLog(@"=========%@", NSStringFromSelector(_cmd));
}

@end
