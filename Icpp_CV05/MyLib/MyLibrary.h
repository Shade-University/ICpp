#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#ifdef MYLIBRARY_EXPORT
#define MY_LIBRARY_DYNAMIC_LIB __declspec(dllexport)
#else
#define MY_LIBRARY_DYNAMIC_LIB _declspec(dllimport)
#endif

class MY_LIBRARY_DYNAMIC_LIB MyLibrary
{
public:
	void sayHello() const;
	void sayBye() const;
};


#endif // !MY_LIBRARY_H

