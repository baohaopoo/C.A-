#pragma once
template<typename T>
void SafeDelete(T& obj) {
	if (obj)
	{
		delete obj;
		obj = nullptr;
	}
}