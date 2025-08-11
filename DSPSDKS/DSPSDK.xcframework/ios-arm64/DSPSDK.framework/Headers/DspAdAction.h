//
//  DspAdAction.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * _Nonnull const Action_H5;

extern NSString * _Nonnull const Action_App;

extern NSString * _Nonnull const Action_Wechat_mini;



@interface DspAdAction : DspObject

/// 点击类型（h5页面跳转、app下载安装包含dplink、wxmini 拉起微信小程序）
@property (nonatomic, copy) NSString *type;

/// URL Schema，用于App跳转
@property (nonatomic, copy) NSString *schema;

/// 跳转到应用市场的 Schema，用于拉起 App
@property (nonatomic, copy) NSString *app_store;

/// 拉起 App 的包名。优先级为根据包名检测是否已安装，已安装时根据schema->package_name顺序拉起。
/// 未安装时根据app_store拉起应用市场，app_store为空，根据apk_url下载
@property (nonatomic, copy) NSString *package_name;

/// type == h5 时跳转的页面地址
@property (nonatomic, copy) NSString *page;

@property (nonatomic, copy) NSString *app_name;

/// apk下载地址
@property (nonatomic, copy) NSString *apk_url;

/// 用于保存的apk的文件名
@property (nonatomic, copy) NSString *apk_file_name;


/// 微信小程序(新结构)
@property (nonatomic, copy) NSString *mini_appid;

/// 微信小程序 type == wxmini 时跳转的小程序原始ID
@property (nonatomic, copy) NSString *wechat_appid;

/// 微信小程序原始 ID
@property (nonatomic, copy) NSString *wechat_mini_id;

/// 微信小程序 appid
@property (nonatomic, copy) NSString *wechat_mini_appid;

/// 微信小程序路径（跳转地址）
/// 拉起小程序页面的可带参路径，不填默认拉起小程序首页，
/// 对于小游戏，可以只传入 query 部分，来实现传参效果，
/// 如：传入 "?foo=bar"
@property (nonatomic, copy) NSString *wechat_mini_path;

/// 微信ios版本 Universal Links 跳转方式
/// Universal Link 是 iOS9 推出的一项功能，使应用（微信，微博等）可以通过传统的HTTPS链接来启动APP
@property (nonatomic, copy) NSString *ios_universal_link;

/// h5类型
/// webview 使用内部跳转，browser 使用外部浏览器跳转
@property (nonnull, copy) NSString *h5_type;

@end

NS_ASSUME_NONNULL_END
