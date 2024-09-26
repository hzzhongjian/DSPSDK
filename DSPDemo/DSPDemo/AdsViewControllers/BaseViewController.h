//
//  BaseViewController.h
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol AdLoadVCProtocol <NSObject>

-(void)loadAD;
-(void)showAD;

@end
@interface BaseViewController : UIViewController
@end

NS_ASSUME_NONNULL_END
