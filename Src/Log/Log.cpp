#include <Log/log.h>

void Log::log(const std::string& str, LOG_LEVEL level)
{
    if (level > m_level) {
        return;
    }
    
    time_t timer;
    time(&timer);
    struct tm* ptm = gmtime(&timer);
    
    std::ostringstream oss;
    oss << ptm->tm_year + 1900 << ":" << ptm->tm_mon + 1  << ":"
        << ptm->tm_mday        << ":" << ptm->tm_hour << ":"
        << ptm->tm_min       << ":" << ptm->tm_sec  << ":"
        << " <" << level << "> " << str << std::endl;

    m_mutex.lock();
    std::ofstream  file(m_logName, std::ios::out|std::ios::app);
    file << oss.str();
    file.close();
    m_mutex.unlock();
    
    return;
}
void Log::logDump()
{
    unsigned int len = getFileSize(m_logName);
    if (len > m_fileDumpLimit) {
        m_mutex.lock();
        
        time_t timer;
        time(&timer);
        struct tm* ptm = gmtime(&timer);
    
        std::ostringstream oss;
        oss << "." << ptm->tm_year + 1900 << ptm->tm_mon + 1
            << ptm->tm_mday << ptm->tm_hour << ptm->tm_min;

        std::string backFileName = m_logName + ".bak" + oss.str();
        std::ifstream ifs (m_logName);
        std::ofstream ofs (backFileName);

        std::filebuf* inbuf  = ifs.rdbuf();
        std::filebuf* outbuf = ofs.rdbuf();

        char c = inbuf->sbumpc();
        while (c != EOF)
        {
            outbuf->sputc (c);
            c = inbuf->sbumpc();
        }
        ofs.close();
        ifs.close();

        std::ofstream file(m_logName, std::ios::trunc|std::ios::out);
        file << "old log already dumped!!!" << std::endl;
        file.close();
        m_mutex.unlock();
    }
    return;
}
