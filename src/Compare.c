#include "Compare.h"

int cmpById(const void* a, const void* b)
{ // compare by id (after casting)
	return (((struct Person*)a)->m_id - ((struct Person*)b)->m_id);
}
//-------------------------------
int cmpByAge(const void* a, const void* b)
{ // compare by age (after casting)
	return (((struct Person*)a)->m_age - ((struct Person*)b)->m_age);
}
//-----------------------------
int cmpByName(const void* a, const void* b)
{  // compare by name (after casting)
	return  (strcmp(((struct Person*)a)->m_name, ((struct Person*)b)->m_name));
}
//--------------------------------------------