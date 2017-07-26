#ifndef __SMART_PTR_H__
#define __SMART_PTR_H__
template <class T>
class SmartPtr {
private:
	T * ptr;
public:
	SmartPtr(T*);
	T* operator->() const;
	T operator*() const;
	~SmartPtr();
};
template<class T>
SmartPtr<T>::SmartPtr(T* ptr) {
	this->ptr = ptr;
}
template<class T>
T* SmartPtr<T>::operator->() const{
	return ptr;
}
template<class T>
T SmartPtr<T>::operator*() const{
	return *ptr;
}
template<class T>
SmartPtr<T>::~SmartPtr() {
	cout << "~SmartPtr()" << endl;
	delete ptr;
}

#endif