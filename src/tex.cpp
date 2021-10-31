#include "tex.hpp"

Texture::Texture(std::string &path)
{
    img_path = path;
    loadFromPath();
}

bool Texture::isReady()
{
    return ready;
}

bool Texture::isUsing()
{
    return in_use;
}

bool Texture::loadFromPath()
{
    ready = loadFromFile(img_path);
}

std::string Texture::getPath()
{
    return img_path;
}

void Texture::setUsage(bool use)
{
    in_use = use;
}