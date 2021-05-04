//
// Created by Zhengyi on 2021/5/4.
//

#ifndef NETWORKSMALLGAME_PLAYER_H
#define NETWORKSMALLGAME_PLAYER_H

#include "cocos2d.h"
#include "string"

class Player : public cocos2d::Sprite {
public:
    static Player* create(const std::string& type);

    void listenToKeyboard(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

};


#endif //NETWORKSMALLGAME_PLAYER_H
