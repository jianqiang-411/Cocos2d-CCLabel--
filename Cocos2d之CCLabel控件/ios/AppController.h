//
//  Cocos2d_CCLabel__AppController.h
//  Cocos2d之CCLabel控件
//
//  Created by 杜 甲 on 13-6-23.
//  Copyright __MyCompanyName__ 2013年. All rights reserved.
//

@class RootViewController;

@interface AppController : NSObject <UIAccelerometerDelegate, UIAlertViewDelegate, UITextFieldDelegate,UIApplicationDelegate> {
    UIWindow *window;
    RootViewController    *viewController;
}

@property (nonatomic, retain) UIWindow *window;
@property (nonatomic, retain) RootViewController *viewController;

@end

