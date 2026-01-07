//
//  DspAdSource.h
//  DSPSDK
//
//  Created by 麻明康 on 2025/5/16.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface DspAdSource : DspObject

@property (nonatomic, assign) int style;

@property (nonatomic, copy) NSString *bg_color;

@property (nonatomic, copy) NSString *title;

@property (nonatomic, copy) NSString *logo;

@property (nonatomic, copy) NSString *text_color;

+ (DspAdSource *)parseAdSource:(NSDictionary *)adSourceDict;

@end

NS_ASSUME_NONNULL_END
