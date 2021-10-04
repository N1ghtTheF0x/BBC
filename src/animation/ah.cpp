#include "ah.h"

Animation::Animation(unsigned int sF,unsigned int eF,float d)
{
    startFrame = sF;
    endFrame = eF;
    duration = d;
}

unsigned int Animation::getLenght()
{
    return endFrame - startFrame + 1;
}

unsigned int Animation::getStartF()
{
    return startFrame;
}

unsigned int Animation::getEndF()
{
    return endFrame;
}

float Animation::getDur()
{
    return duration;
}

AnimationHandler::AnimationHandler()
{
    currentTime = 0.0f;
    currentAnimation = -1;
}
AnimationHandler::AnimationHandler(const sf::IntRect& fS)
{
    frameSize = fS;
    currentTime = 0.0f;
    currentAnimation = -1;
}

void AnimationHandler::update(const float dt)
{
    if(currentAnimation >= animations.size() || currentAnimation < 0) return;

    float duration = animations[currentAnimation].getDur();

    if(int((currentTime + dt) / duration) > int(currentTime / duration))
    {
        int frame = int((currentTime +dt) / duration);

        frame %= animations[currentAnimation].getLenght(); 

        sf::IntRect rect = frameSize;
        rect.left = rect.width * frame;
        rect.top = rect.height * currentAnimation;
        bounds = rect;
    }

    currentTime += dt;

    if(currentTime > duration * animations[currentAnimation].getLenght())
    {
        currentTime = 0.0f;
    }
}

void AnimationHandler::AddAnim(Animation& anim)
{
    animations.push_back(anim);
}

void AnimationHandler::changeAnim(unsigned int animID)
{
    if(currentAnimation == animID || animID >= animations.size() || animID < 0) return;

    currentAnimation = animID;

    sf::IntRect rect = frameSize;
    rect.top = rect.height * animID;
    bounds = rect;
    currentTime = 0.0f;
}