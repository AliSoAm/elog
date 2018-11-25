#include "elog/logger.hpp"

#define IF_LOG_(instance, severity)     if (elog::get<instance>().checkSeverity(severity))
#define IF_LOG(severity)                IF_LOG_(ELOG_DEFAULT_INSTANCE, severity)
//////////////////////////////////////////////////////////////////////////
// Main logging macros

#define LOG_(instance, severity)        IF_LOG_(instance, severity) (elog::get<instance>()) += elog::Record(severity, __func__, __LINE__, __FILE__)
#define LOG(severity)                   LOG_(ELOG_DEFAULT_INSTANCE, severity)

#define LOG_VERBOSE                     LOG(elog::VERBOSE)
#define LOG_DEBUG                       LOG(elog::DEBUG)
#define LOG_INFO                        LOG(elog::INFO)
#define LOG_WARNING                     LOG(elog::WARNING)
#define LOG_ERROR                       LOG(elog::ERROR)
#define LOG_FATAL                       LOG(elog::FATAL)
#define LOG_NONE                        LOG(elog::NONE)

#define LOG_VERBOSE_(instance)          LOG_(instance, elog::VERBOSE)
#define LOG_DEBUG_(instance)            LOG_(instance, elog::DEBUG)
#define LOG_INFO_(instance)             LOG_(instance, elog::INFO)
#define LOG_WARNING_(instance)          LOG_(instance, elog::WARNING)
#define LOG_ERROR_(instance)            LOG_(instance, elog::ERROR)
#define LOG_FATAL_(instance)            LOG_(instance, elog::FATAL)
#define LOG_NONE_(instance)             LOG_(instance, elog::NONE)

#define LOGV                            LOG_VERBOSE
#define LOGD                            LOG_DEBUG
#define LOGI                            LOG_INFO
#define LOGW                            LOG_WARNING
#define LOGE                            LOG_ERROR
#define LOGF                            LOG_FATAL
#define LOGN                            LOG_NONE

#define LOGV_(instance)                 LOG_VERBOSE_(instance)
#define LOGD_(instance)                 LOG_DEBUG_(instance)
#define LOGI_(instance)                 LOG_INFO_(instance)
#define LOGW_(instance)                 LOG_WARNING_(instance)
#define LOGE_(instance)                 LOG_ERROR_(instance)
#define LOGF_(instance)                 LOG_FATAL_(instance)
#define LOGN_(instance)                 LOG_NONE_(instance)

//////////////////////////////////////////////////////////////////////////
// Conditional logging macros

#define LOG_IF_(instance, severity, condition)  if (condition) do {LOG_(instance, severity)} while (0)
#define LOG_IF(severity, condition)             LOG_IF_(ELOG_DEFAULT_INSTANCE, severity, condition)

#define LOG_VERBOSE_IF(condition)               LOG_IF(elog::VERBOSE, condition)
#define LOG_DEBUG_IF(condition)                 LOG_IF(elog::DEBUG, condition)
#define LOG_INFO_IF(condition)                  LOG_IF(elog::INFO, condition)
#define LOG_WARNING_IF(condition)               LOG_IF(elog::WARNING, condition)
#define LOG_ERROR_IF(condition)                 LOG_IF(elog::ERROR, condition)
#define LOG_FATAL_IF(condition)                 LOG_IF(elog::FATAL, condition)
#define LOG_NONE_IF(condition)                  LOG_IF(elog::NONE, condition)

#define LOG_VERBOSE_IF_(instance, condition)    LOG_IF_(instance, elog::VERBOSE, condition)
#define LOG_DEBUG_IF_(instance, condition)      LOG_IF_(instance, elog::DEBUG, condition)
#define LOG_INFO_IF_(instance, condition)       LOG_IF_(instance, elog::INFO, condition)
#define LOG_WARNING_IF_(instance, condition)    LOG_IF_(instance, elog::WARNING, condition)
#define LOG_ERROR_IF_(instance, condition)      LOG_IF_(instance, elog::ERROR, condition)
#define LOG_FATAL_IF_(instance, condition)      LOG_IF_(instance, elog::FATAL, condition)
#define LOG_NONE_IF_(instance, condition)       LOG_IF_(instance, elog::NONE, condition)

#define LOGV_IF(condition)                      LOG_VERBOSE_IF(condition)
#define LOGD_IF(condition)                      LOG_DEBUG_IF(condition)
#define LOGI_IF(condition)                      LOG_INFO_IF(condition)
#define LOGW_IF(condition)                      LOG_WARNING_IF(condition)
#define LOGE_IF(condition)                      LOG_ERROR_IF(condition)
#define LOGF_IF(condition)                      LOG_FATAL_IF(condition)
#define LOGN_IF(condition)                      LOG_NONE_IF(condition)

#define LOGV_IF_(instance, condition)           LOG_VERBOSE_IF_(instance, condition)
#define LOGD_IF_(instance, condition)           LOG_DEBUG_IF_(instance, condition)
#define LOGI_IF_(instance, condition)           LOG_INFO_IF_(instance, condition)
#define LOGW_IF_(instance, condition)           LOG_WARNING_IF_(instance, condition)
#define LOGE_IF_(instance, condition)           LOG_ERROR_IF_(instance, condition)
#define LOGF_IF_(instance, condition)           LOG_FATAL_IF_(instance, condition)
#define LOGN_IF_(instance, condition)           LOG_NONE_IF_(instance, condition)
