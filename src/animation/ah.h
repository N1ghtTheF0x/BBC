#ifndef ANIMATIONHANDLER_H
#define ANIMATIONHANDLER_H

#include <vector>
#include <SFML/Graphics.hpp>

class Animation
{
public:
    Animation(unsigned int sF,unsigned int eF,float d);
    unsigned int getLenght();
    unsigned int getStartF();
    unsigned int getEndF();
    float getDur();
private:
    unsigned int startFrame;
    unsigned int endFrame;

    float duration;
};

class AnimationHandler
{
private:
    std::vector<Animation> animations;
    float currentTime;

    int currentAnimation;

    sf::IntRect bounds;
    sf::IntRect frameSize;
public:
    void AddAnim(Animation& anim);
    void update(const float dt);
    void changeAnim(unsigned int animNum);

    AnimationHandler();
    AnimationHandler(const sf::IntRect& fS);
};

#endif