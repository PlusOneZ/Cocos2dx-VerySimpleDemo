//
// Created by Zhengyi on 2021/5/4.
//

#include "Player.h"

using namespace cocos2d;

Player *Player::create(const std::string &type) {
    auto player = new (std::nothrow) Player();
    if (!player)
        return nullptr;
    auto temp = Sprite::create(type + ".png");
    if (temp)
    {
        player->addChild(temp);
        player->autorelease();
        return player;
    }
    return nullptr;
}

void Player::listenToKeyboard(cocos2d::EventKeyboard::KeyCode keyCode,
                              cocos2d::Event *event) {

}
