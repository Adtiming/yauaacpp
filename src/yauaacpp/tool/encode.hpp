/**
 * create: 2016-02-19
 * author: mr.wclong@yahoo.com
 */
#ifndef LIB_ENCODE_HPP
#define LIB_ENCODE_HPP
#include <stdint.h>

#include <string>

namespace lib {

    // same as 'md5sum' command, return 32bytes string
    std::string md5sum(const void* buf, int len);
    std::string md5sum(const char* file);

    // return raw result (little-endian 16bytes)
    uint8_t*    md5bin(const void* buf, int len, uint8_t* sum);

    enum url_escape_standard {
        url_rfc3986 = 0, url_html5 = 1
    };

    // escape an URL. for example url_encode("a string") == "a%20string"
    std::string url_encode(const std::string& url, url_escape_standard standard = url_rfc3986);
    std::string url_encode(const char* begin, const char* end, url_escape_standard standard = url_rfc3986);
    // unescape an URL. for example url_decode("a%20string") == "a string"
    std::string url_decode(const std::string& url, url_escape_standard standard = url_rfc3986);

//    // encode binary to base64 encoded string
//    std::string b64_encode(const void* buf, int len);
//    // decode base64 encoded string to binary
//    std::string b64_decode(const void* buf, int len);

}

#endif
