//
//  DspAdCard.h
//  DSPSDK
//
//  Created by Robin on 2021/1/18.
//

#import <DSPSDK/DspObject.h>

NS_ASSUME_NONNULL_BEGIN

@interface DspAdCard : DspObject

@property(nonatomic,assign) NSInteger show_time;
@property(nonatomic,copy) NSString *title;
@property(nonatomic,copy) NSString *desc;
@property(nonatomic,copy) NSString *image_log;
@property(nonatomic,copy) NSString *button_text;
@property(nonatomic,copy) NSString *title_Size;
@property(nonatomic,copy) NSString *title_Color;
@property(nonatomic,copy) NSString *desc_Size;
@property(nonatomic,copy) NSString *desc_Color;


@end

NS_ASSUME_NONNULL_END
