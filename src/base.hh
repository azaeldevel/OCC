
#ifndef OCTETOS_CC_BASE
#define OCTETOS_CC_BASE

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

	size_t lengTarget = length(target);
	if(lengTarget == 0) return false;

	if(lengInitial != lengTarget) return false;

	for(size_t i = 0; i < lengInitial; i++)
	{
		if(initial[i] != target[i]) return false;		
	}
	
	return true;
}


}

#endif