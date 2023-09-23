#pragma once

#include "evpp/platform_config.h"

#ifdef __cplusplus
// @author dongfangzhou: delete [glog]
// #define GOOGLE_GLOG_DLL_DECL           // ʹ�þ�̬glog��ʱ�����붨�����
// #define GLOG_NO_ABBREVIATED_SEVERITIES // û�����������,��˵��Ϊ��Windows.h��ͻ

// #include <glog/logging.h>
// @author dongfangzhou: add [vector] used in [glog]
#include <vector>

#ifdef GOOGLE_STRIP_LOG

#if GOOGLE_STRIP_LOG == 0
#define LOG_TRACE LOG(INFO)
#define LOG_DEBUG LOG(INFO)
#define LOG_INFO  LOG(INFO)
#define DLOG_TRACE LOG(INFO) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define LOG_TRACE if (false) LOG(INFO)
#define LOG_DEBUG if (false) LOG(INFO)
#define LOG_INFO  if (false) LOG(INFO)
#define DLOG_TRACE if (false) LOG(INFO)
#endif

#if GOOGLE_STRIP_LOG <= 1
#define LOG_WARN  LOG(WARNING)
#define DLOG_WARN LOG(WARNING) << __PRETTY_FUNCTION__ << " this=" << this << " "
#else
#define LOG_WARN  if (false) LOG(WARNING)
#define DLOG_WARN if (false) LOG(WARNING)
#endif

#define LOG_ERROR LOG(ERROR)
#define LOG_FATAL LOG(FATAL)

#else
// @author dongfangzhou: add [DLOG_TRACE] [DLOG_WARN]
#define LOG_TRACE  if (false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_DEBUG  if (false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_INFO   if (false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_WARN              std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_ERROR             std::cout << __FILE__ << ":" << __LINE__ << " "
#define LOG_FATAL             std::cout << __FILE__ << ":" << __LINE__ << " "
#define DLOG_TRACE if (false) std::cout << __FILE__ << ":" << __LINE__ << " "
#define DLOG_WARN             std::cout << __FILE__ << ":" << __LINE__ << " "
#define CHECK_NOTnullptr(val) LOG_ERROR << "'" #val "' Must be non nullptr";
#endif
#endif // end of define __cplusplus

//#ifdef _DEBUG
//#ifdef assert
//#undef assert
//#endif
//#define assert(expr)  { if (!(expr)) { LOG_FATAL << #expr ;} }
//#endif