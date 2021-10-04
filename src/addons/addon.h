#ifndef ADDON_H
#define ADDON_H

enum AddonType
{
	Generic,
	Update,
	Texture,
	Sprite
};

class A{};

template<typename Type>
class Addon : public A
{
public:
	Addon(Type t,AddonType at);
	Type* getData();
	AddonType getAddonType();
	void setData(const Type newt);
private:
	Type tdata;
	AddonType atype;
};

#endif