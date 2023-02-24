//
// Created by sunxg on 22-2-15.
//

#include "yauaacpp_def.h"
#include "dir.h"
#include <dirent.h>
#include <sys/stat.h>
#include "tool.h"
#include <iostream>
#include <fstream>

namespace ycpp{
    bool resolve_dir(const DirExt & dirExt, std::list<std::shared_ptr<Resource>> & files){
        DIR *dp = opendir(dirExt.getPath().c_str());
        if(dp == nullptr)
            return false;
        struct dirent *dirp;
        while ((dirp = readdir(dp)) != nullptr)
        {
            if (dirp->d_type == DT_REG && ends_with(std::string(dirp->d_name),dirExt.getExt()))
            {
                files.emplace_back(std::make_shared<Resource>(dirExt.getPath(),dirp->d_name));
            }
        }
        closedir(dp);
        return true;
    }

    long Resource::contentLength() {
        struct stat statbuf;
        int ret;

        ret = stat(getPathName().c_str(),&statbuf);//调用stat函数

        if(ret != 0) return -1;//获取失败。

        return statbuf.st_size;//返回文件大小。

    }

    std::istream * Resource::getInputStream() {
        if(is == nullptr)
            is = new std::fstream(getPathName().c_str(), std::ios::in | std::ios::binary);
        if(is->is_open())
            return is;

        return nullptr;
    }

    Resource::~Resource() {
        if(is)
            delete is;
    }

    std::string Resource::getDescription() const {
        std::string stream_status;
        if(is){
            if(is->is_open())
                stream_status = "stream is opened";
            else
                stream_status = "stream open failure";
        } else
            stream_status = "no stream";

        return getPathName() + "(" + stream_status + ")";
    }

    bool DirExt::empty() const {
        std::string path = first;
        return first.empty()||trim(path).empty();
    }

    std::shared_ptr<Resource> DirExt::convertToResource() const {
        return std::make_shared<Resource>(first,second);
    }
}

