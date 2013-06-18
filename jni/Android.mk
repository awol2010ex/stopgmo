LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../Classes/AppDelegate.cpp \
                   ../Classes/GameRoot.cpp \
                   ../Classes/Sneaky/SneakyButton.cpp \
                   ../Classes/Sneaky/SneakyButtonSkinnedBase.cpp \
                   ../Classes/Sneaky/SneakyJoystick.cpp \
                   ../Classes/Sneaky/SneakyJoystickSkinnedBase.cpp \
                   ../Classes/Scene/SceneGame.cpp \
                   ../Classes/Scene/HudLayer.cpp \
                   ../Classes/Scene/GameMap.cpp \
                   ../Classes/Scene/GameLayer.cpp \
                   ../Classes/Actor/Hero.cpp \
                   ../Classes/Actor/Enemy.cpp \
                   ../Classes/Actor/Carrot.cpp \
                   ../Classes/Actor/Weapon/Weapon.cpp \
                   ../Classes/Actor/Weapon/Bullet.cpp \
                   ../Classes/Actor/Weapon/Hoe.cpp 
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
