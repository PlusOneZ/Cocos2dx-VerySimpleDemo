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

    void listenToKeyPresses(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void listenToKeyReleases(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void update(float delta) override;

private:
    enum Key {W, A, S, D};
    static constexpr int StepLength = 10;

    float x = 520.;
    float y = 520.;
    bool keyPressed[4] = {};
};


#endif //NETWORKSMALLGAME_PLAYER_H
