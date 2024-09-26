//
//  NativeExpressViewCell.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/17.
//

#import "NativeExpressViewCell.h"

@implementation NativeExpressViewCell
-(instancetype)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier{
    if (self = [super initWithStyle:style reuseIdentifier:reuseIdentifier]) {
        self.selectionStyle = UITableViewCellSelectionStyleNone;
    }
    return self;
}

-(void)refreshWithAd:(DspFeedAdView *)adView{
    UIView *view = [self.contentView viewWithTag:100];
    [view removeFromSuperview];
    adView.tag = 100;
//    [feedAd setVideoSoundEnable:soundEnable];
//    adView.frame = self.contentView.bounds;
    [self.contentView addSubview:adView];
}

@end
