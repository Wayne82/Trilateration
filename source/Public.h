//
//  Public.h
//
//  Created by waynewang on 14/5/14.
//  Copyright (c) 2014 waynewang. All rights reserved.
//

#ifndef __PUBLIC__
#define __PUBLIC__

#if defined(TRILATERATION_IS_DLL)
#ifdef TRILATERATION_BUILD_DLL
#define EXPORT_API _declspec(dllexport)
#define EXPORT_TEMPLATE(a, b) template class EXPORT_API a; typedef a b;
#else
#define EXPORT_API _declspec(dllimport)
#define EXPORT_TEMPLATE(a, b) extern template class EXPORT_API a; typedef a b;
#endif
#else
#define EXPORT_API
#define EXPORT_TEMPLATE(a, b) typedef a b;
#endif

#endif // __PUBLIC__