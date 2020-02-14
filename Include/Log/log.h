#ifndef __MEDIA_RTSP_LOG_H__
#define __MEDIA_RTSP_LOG_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <mutex>
#include <time.h>
#include "Utils/fileUtils.h"

enum LOG_LEVEL
{
    ERROR = 0,
    WARN,
    INFO,
    DEBUG,
    TRACE
};

class Log
{
public:
    Log(){};
    
    Log(const std::string& file, unsigned int maxSize, unsigned int level)
    : m_logName(file),
      m_fileDumpLimit(maxSize),
      m_level(level)
    {}

    ~Log(){};
    
    void log(const std::string& str, LOG_LEVEL level=TRACE);
   
    void logDump();

    void error(const std::string& str)
    {
        log(str, ERROR);
    }

    void warn(const std::string& str)
    {
        log(str, WARN);
    }

    void info(const std::string& str)
    {
        log(str, INFO);
    }

    void debug(const std::string& str)
    {
        log(str, DEBUG);
    }

    void trace(const std::string& str)
    {
        log(str, TRACE);
    }

private:
    std::string m_logName;
    std::mutex  m_mutex; //protect logfile
    unsigned int m_fileDumpLimit;
    unsigned int m_level;
};

#endif
