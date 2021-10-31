#ifndef TEX_H
#define TEX_H

#include <SFML/Graphics.hpp>

// A Texture to make it's look
class Texture : public sf::Texture
{
private:
    bool ready;
    bool in_use;
    std::string img_path;
public:
    // Is the Texture ready to use?
    bool isReady();
    // Is the Texture being used?
    bool isUsing();
    // Load the Texture from Path
    bool loadFromPath();
    Texture(std::string &path);
    // Get the Path of the Texture
    std::string getPath();
    // Set the Textures Usage. Use only if the Texture is REALLY not used.
    void setUsage(bool use);
};

#endif