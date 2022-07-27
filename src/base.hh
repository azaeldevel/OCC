
#ifndef OCTETOS_CC_BASE
#define OCTETOS_CC_BASE

#include <cstddef>


namespace oct::cc
{

template<typename C>
inline bool is_whitespace(C c)
{
	return c == ' ' or c == '\t' or c == '\n';
}

template<typename C> 
size_t length(const C* str)
{
	size_t i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	return i;
}

template<typename C> 
bool equal(const C* initial, const C* target)
{
	size_t lengInitial = length(initial);
	if(lengInitial == 0) return false;
	//if(initial[lengInitial] != '\0') return false;
	
	size_t lengTarget = length(target);
	if(lengTarget == 0) return false;
	//if(target[lengTarget] != '\0') return false;

	if(lengInitial != lengTarget) return false;

	for(size_t i = 0; i < lengInitial; i++)
	{
		if(initial[i] != target[i]) return false;		
	}
	
	return true;
}


template<typename C> size_t copy(const C* origin, size_t leng,C** dest)
{
	if(origin[leng] != '\0') return 0;
	if(not origin) return 0;
	if(not dest) return 0;
		
	size_t i = 0;
	for(;i < leng; i++)
	{
		(*dest)[i] = origin[i];
	}
	(*dest)[leng] = '\0';

	return leng;
}


}

#endif