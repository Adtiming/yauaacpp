//
// Created by sunxg on 22-2-15.
//

#ifndef YAUAACPP_DIR_H
#define YAUAACPP_DIR_H

#include <string>
#include <list>

namespace ycpp{
    class Resource{
    private:
        Resource(){is = nullptr;}
        std::fstream * is;
    public:
        std::string path;
        std::string name;
    public:
        Resource(const std::string & path,const std::string & name ):is(nullptr),path(path),name(name){}
        ~Resource();;
        std::string getPathName() const {return path+"/"+name;}
        std::string getFilename() const {return name;}
        long contentLength();
        std::istream * getInputStream();
        std::string getDescription() const;;
    };

    class DirExt : public std::pair<std::string,std::string>{
    public:
        bool isResource;

        DirExt(const std::string & path, const std::string & ext,bool isResource = false):std::pair<std::string,std::string>(path,ext),isResource(isResource){}
        const std::string getPath() const {return first;}
        const std::string getExt() const {return second;}
        bool operator == (const DirExt & r) const {
            return first==r.first && second==r.second;
        }
        const std::string toString() const {
            return first+"/*"+second;
        }
        bool empty() const; //允许 ext 为空

        std::shared_ptr<Resource> convertToResource() const;
    };

    bool resolve_dir(const DirExt & dirExt, std::list<std::shared_ptr<Resource>> & files);
}

#endif //YAUAACPP_DIR_H
