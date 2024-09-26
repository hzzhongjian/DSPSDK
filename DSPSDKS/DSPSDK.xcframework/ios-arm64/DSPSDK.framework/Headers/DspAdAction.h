//
//  DspAdAction.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nonnull  const Action_H5 ;
extern NSString * _Nonnull  const Action_App ;
extern NSString * _Nonnull  const Action_Wechat_mini ;

@interface DspAdAction : DspObject

@property(nonatomic,copy) NSString *type;
@property(nonatomic,copy) NSString *schema;
@property(nonatomic,copy) NSString *app_store;

@property(nonatomic,copy) NSString *page;

@property(nonatomic,copy) NSString *appName;

@property(nonatomic,copy) NSString *apk_url;
@property(nonatomic,copy) NSString *apk_file_name;
@property(nonatomic,copy) NSString *package_name;

///微信小程序(新结构)
@property(nonatomic,copy) NSString *mini_appid;
///微信小程序
@property(nonatomic,copy) NSString *wechat_appid;
@property(nonatomic,copy) NSString *wechat_mini_id;
@property(nonatomic,copy) NSString *wechat_mini_path;
@property(nonatomic,copy) NSString *ios_universal_link;
@end

NS_ASSUME_NONNULL_END
