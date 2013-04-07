LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := hellocpp_shared

LOCAL_MODULE_FILENAME := libhellocpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/CharacterNameScene.cpp\
                   ../../Classes/GameDataModel.cpp\
                   ../../Classes/HelloWorldScene.cpp\
                   ../../Classes/NewGameIntroScene.cpp\
                   ../../Classes/ScenarioConfig.cpp\
                   ../../Classes/ScenarioModel.cpp\
                   ../../Classes/ScenarioScene.cpp\
                   ../../Classes/StoryConfig.cpp\
                   ../../Classes/StoryController.cpp\
                   ../../Classes/StoryModel.cpp\
                   ../../Classes/StoryScene.cpp\
                   ../../Classes/TextWallLayer.cpp\
                   ../../Classes/TileMapConfig.cpp\
                   ../../Classes/TileMapLayer.cpp\
                   ../../Classes/TileMapModel.cpp\

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)

