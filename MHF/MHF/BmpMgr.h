#pragma once
class Bmp;

class BmpMgr
{
public:
	BmpMgr();
	~BmpMgr();

public:
	HDC FindImage(const TCHAR* ImageKey);
public:
	void InsertBmp(const TCHAR* pImageKey, const TCHAR*  pFilePath);
	void Release();
public:
	static BmpMgr* getInstance();
	void DestroyInstance();
private:
	static BmpMgr*	instance;
	map<const TCHAR*, Bmp*> MapBit;

};

