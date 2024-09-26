//
//  BaseViewController.m
//  DSPDemo
//
//  Created by 麻明康 on 2024/1/16.
//

#import "BaseViewController.h"

@interface BaseViewController ()

@end

@implementation BaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    self.view.backgroundColor = [UIColor whiteColor];
    // Do any additional setup after loading the view.
    CGFloat btn_h = 45;
    CGFloat btn_w = 100;
    UIColor *btn_color = [UIColor brownColor];
    UIColor *text_color = [UIColor blackColor];
    UIFont *btn_font = [UIFont systemFontOfSize:14];
    
    UIButton *loadBtn = [UIButton buttonWithFrame:CGRectMake(KScreenSize.width/2-btn_h, 100, 100, btn_h) title:@"拉取广告" titleColor:text_color backgroundColor:btn_color font:btn_font normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(loadAD)];
    loadBtn.layer.cornerRadius = 5.;
    loadBtn.layer.borderWidth = 1.0;
    loadBtn.layer.borderColor = [UIColor blackColor].CGColor;
    loadBtn.layer.masksToBounds = YES;
    [self.view addSubview:loadBtn];
    
    UIButton *showBtn = [UIButton buttonWithFrame:CGRectMake(KScreenSize.width/2-btn_h, 250, 100, btn_h) title:@"展示广告" titleColor:text_color backgroundColor:btn_color font:btn_font normalImage:nil highlightedImage:nil backgroundImage:nil target:self selector:@selector(showAD)];
    showBtn.layer.cornerRadius = 5.;
    showBtn.layer.borderWidth = 1.0;
    showBtn.layer.borderColor = [UIColor blackColor].CGColor;
    showBtn.layer.masksToBounds = YES;
    [self.view addSubview:showBtn];
    
    

}

-(void)loadAD{
    MKLog(@"请在子类实现");
}

-(void)showAD{
    MKLog(@"请在子类实现");
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
