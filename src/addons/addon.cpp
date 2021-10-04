#include "addon.h"

template<typename Type>
Addon<Type>::Addon(Type t,AddonType at)
{
	tdata = t;
	atype = at;
}
template<typename Type>
Type* Addon<Type>::getData()
{
	return &tdata;
}
template<typename Type>
void Addon<Type>::setData(const Type newt)
{
	tdata = newt;
}
template<typename Type>
AddonType Addon<Type>::getAddonType()
{
	return atype;
}