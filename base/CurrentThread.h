//
// Created by zrzzzlll on 2020/9/24.
//

#ifndef MINI_MUDUO_BASE_CURRENTTHREAD_H_
#define MINI_MUDUO_BASE_CURRENTTHREAD_H_
#include <string>
namespace muduo{
    namespace CurrentThread{
        /*
         * 通过thread关键字缓存线程信息
         */
        extern __thread int t_cachedTid;
        extern __thread char t_tidString[32];
        extern __thread int t_tidStringLength;
        extern __thread const char* t_threadName;
        void cachedTid();
        /*
         * 获取当前线程一些信息：线程号,线程名字等给日志使用
         * 为了防止每次都使用系统调用来获取线程id
         * 所以通过__thread关键字来缓存线程id
         */
        inline int getTid(){
            if(__builtin_expect(t_cachedTid == 0,0)){
                cachedTid();
            }
            return t_cachedTid;
        }
        inline const char* getTidString(){
            return t_tidString;
        }
        inline int getTidStringLength(){
            return t_tidStringLength;
        }
        inline const char* getThreadName(){
            return t_threadName;
        };
        bool isMainThread();
        std::string stackTrace(bool demangle);
    }
}
#endif //MINI_MUDUO_BASE_CURRENTTHREAD_H_
