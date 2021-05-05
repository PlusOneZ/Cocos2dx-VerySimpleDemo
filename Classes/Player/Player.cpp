//
// Created by Zhengyi on 2021/5/4.
//

#include "Player.h"

using namespace cocos2d;

Player *Player::create(const std::string &type) {
    auto player = new(std::nothrow) Player();
    if (!player)
        return nullptr;

    Vector<SpriteFrame *> vecFrame{};
    vecFrame.pushBack(
            SpriteFrame::create(type + "1.png", Rect(0, 0, 100, 100)));
    vecFrame.pushBack(
            SpriteFrame::create(type + "2.png", Rect(0, 0, 100, 100)));
    auto animation = Animation::createWithSpriteFrames(vecFrame, 0.3);
    animation->setLoops(-1);
    auto action = Animate::create(animation);

    auto temp = Sprite::create(type + "1.png");

    if (temp && action) {
        action->retain();
        temp->runAction(action);
        player->addChild(temp);
        player->setPosition(player->x, player->y);
        player->autorelease();
        return player;
    }
    return nullptr;
}

void Player::listenToKeyPresses(cocos2d::EventKeyboard::KeyCode keyCode,
                                cocos2d::Event *event) {
//    CCLOG("%d", keyCode);
    using K = cocos2d::EventKeyboard::KeyCode;
    if (keyCode == K::KEY_D) {
        keyPressed[D] = true;
    }
    if (keyCode == K::KEY_A) {
        keyPressed[A] = true;
    }
    if (keyCode == K::KEY_W) {
        keyPressed[W] = true;
    }
    if (keyCode == K::KEY_S) {
        keyPressed[S] = true;
    }
}

void Player::listenToKeyReleases(cocos2d::EventKeyboard::KeyCode keyCode,
                                 cocos2d::Event *event) {
//    CCLOG("%d", keyCode);
    using K = cocos2d::EventKeyboard::KeyCode;
    if (keyCode == K::KEY_D) {
        keyPressed[D] = false;
    }
    if (keyCode == K::KEY_A) {
        keyPressed[A] = false;
    }
    if (keyCode == K::KEY_W) {
        keyPressed[W] = false;
    }
    if (keyCode == K::KEY_S) {
        keyPressed[S] = false;
    }
}


void Player::update(float delta) {
    if (keyPressed[W]) {
        y += StepLength;
    }
    if (keyPressed[A]) {
        x -= StepLength;
    }
    if (keyPressed[S]) {
        y -= StepLength;
    }
    if (keyPressed[D]) {
        x += StepLength;
    }

    setPosition(x, y);
}

