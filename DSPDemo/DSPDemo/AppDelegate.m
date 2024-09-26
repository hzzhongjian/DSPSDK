//
//  AppDelegate.m
//  DSPDemo
//
//  Created by 麻明康 on 2023/12/20.
//

#import "AppDelegate.h"
#import <DSPSDK/DSPSDK.h>
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [[MKConsole shared] setPrintSystemLog:YES];
    [DSPSDKConfig registerSDK:@{@"appId": @"zj_20201014iOSDEMO",
                                @"platform": @"ZJ",
                                @"is_enable": @1,
                                @"appName": @"IOSDEMO",
                                @"universal_link": @"123123123123",
                                @"wx_app_id": @"321321321321",
                                @"can_read_oaid": @0,
                                @"can_init": @0,
                                @"can_cache_video": @1,
                                @"domain_list_reward": @"https://incentive.8ziben.com;http://124.220.49.82;",
                                @"domain_list_zj_report": @"https://incentive.8ziben.com;http://124.220.49.82;",
                                @"domain_list_dsp": @"https://api-dsp.8ziben.com;http://dsp-test.8ziben.com;"}];
    NSLog(@"%@",[DSPSDKConfig SDKVersion]);
    return YES;
}


#pragma mark - UISceneSession lifecycle


- (UISceneConfiguration *)application:(UIApplication *)application configurationForConnectingSceneSession:(UISceneSession *)connectingSceneSession options:(UISceneConnectionOptions *)options {
    // Called when a new scene session is being created.
    // Use this method to select a configuration to create the new scene with.
    return [[UISceneConfiguration alloc] initWithName:@"Default Configuration" sessionRole:connectingSceneSession.role];
}


- (void)application:(UIApplication *)application didDiscardSceneSessions:(NSSet<UISceneSession *> *)sceneSessions {
    // Called when the user discards a scene session.
    // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
    // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
}


@end
