#include "stdafx.h"
#include "BmpMgr.h"
#include"Bmp.h"
#include "Functional.h"

BmpMgr* BmpMgr::instance = nullptr;
BmpMgr::BmpMgr()
{
}


BmpMgr::~BmpMgr()
{
	Release();
}

HDC BmpMgr::FindImage(const TCHAR * ImageKey)
{
	if (MapBit.empty())
		return nullptr;

	auto iterfind = find_if(MapBit.begin(), MapBit.end(), [&ImageKey](auto& MyPair) {

		return !lstrcmp(ImageKey, MyPair.first);
	});

	if (MapBit.end() == iterfind)
		return nullptr;

	return iterfind->second->GetmemDC();
}

void BmpMgr::InsertBmp(const TCHAR * pImageKey, const TCHAR * pFilePath)
{
	if (true == MapBit.insert({ pImageKey,nullptr }).second) {
		MapBit[pImageKey] = new Bmp;
		MapBit[pImageKey]->LoadBmp(pFilePath);
	}
}

void BmpMgr::Release()
{
	for_each(MapBit.begin(), MapBit.end(), [](auto& MyPair) {
		SafeDelete(MyPair.second);
	});

	MapBit.clear();
}

BmpMgr * BmpMgr::getInstance()
{
	if (nullptr == instance)
		instance = new BmpMgr;

	return instance;
}

