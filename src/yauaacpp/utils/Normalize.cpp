//
// Created by sunxg on 22-2-4.
//

#include "Normalize.h"
#include <utf8.h>
#include "tool/tool.h"

namespace ycpp {
    std::wregex Normalize::DEVICE_CLEANUP_PATTERN_1(L"- +");
    std::wregex Normalize::DEVICE_CLEANUP_PATTERN_2(L" +-");
    std::wregex Normalize::DEVICE_CLEANUP_PATTERN_3(L" +");
    std::wregex Normalize::DEVICE_CLEANUP_PATTERN_4(L"( -| )+");

    std::string charToString(uint16_t c){
        std::vector<uint16_t> v;
        v.push_back(c);
        std::string s;
        utf8::utf16to8(v.begin(),v.end(),std::back_inserter(s));
        return s;
    }

    std::string Normalize::brand(const std::string &brand) {
        if (brand.empty()) {
            return "";
        }
        if (brand.size() <= 3) {
            return tolowers(brand);
        }


        std::wstring nameChars;
        utf8::utf8to16(brand.begin(),brand.end(),std::back_inserter(nameChars));

        std::stringstream o;
        std::vector<uint16_t> wordBuilder;
        int lowerChars = 0;
        bool wordHasNumbers = false;
        for (size_t i = 0; i < nameChars.size(); i++) {
            wchar_t thisChar = nameChars[i];
            if (std::isdigit(thisChar)) {
                wordHasNumbers = true;
            }

            if (isTokenSeparator(thisChar)) {
                if (wordBuilder.size() <= 3 || wordHasNumbers) {
                    std::transform(wordBuilder.begin(), wordBuilder.end(), wordBuilder.begin(), toupper);
                }
                std::string s;
                utf8::utf16to8(wordBuilder.begin(),wordBuilder.end(),std::back_inserter(s));
                o << s.c_str();
                wordBuilder.clear();
                lowerChars = 0; // Next word
                wordHasNumbers = false;
                o << charToString(thisChar).c_str();
            } else {
                if (wordBuilder.empty()) { // First letter of a word
                    wordBuilder.push_back((uint16_t)std::toupper(thisChar));
                } else {
                    bool isUpperCase = std::isupper(thisChar);

                    if (isUpperCase) {
                        if (lowerChars >= 3) {
                            wordBuilder.push_back(thisChar);
                        } else {
                            wordBuilder.push_back((uint16_t)std::tolower(thisChar));
                        }
                        lowerChars = 0;
                    } else {
                        wordBuilder.push_back((uint16_t)std::tolower(thisChar));
                        lowerChars++;
                    }
                }
                // This was the last letter?
                if (i == (nameChars.size()-1)) {
                    if (wordBuilder.size() <= 3 || wordHasNumbers) {
                        std::transform(wordBuilder.begin(), wordBuilder.end(), wordBuilder.begin(), toupper);
                    }
                    std::string s;
                    utf8::utf16to8(wordBuilder.begin(),wordBuilder.end(),std::back_inserter(s));
                    o << s.c_str();
                    wordBuilder.clear();
                    lowerChars = 0; // Next word
                    wordHasNumbers = false;
                }
            }
        }

        std::string s = o.str();
        return trim(s);
    }

    std::string Normalize::cleanupDeviceBrandName(const std::string &_deviceBrand, const std::string &_deviceName) {
        std::wstring deviceName;
        std::wstring deviceBrand;
        utf8::utf8to32(_deviceName.begin(),_deviceName.end(),std::back_inserter(deviceName));
        utf8::utf8to32(_deviceBrand.begin(),_deviceBrand.end(),std::back_inserter(deviceBrand));
        replaceString(deviceName, L"'", L" ");
        replaceString(deviceName, L"_", L" ");

        deviceName = std::regex_replace(deviceName,DEVICE_CLEANUP_PATTERN_1,std::wstring(L"-"));
        deviceName = std::regex_replace(deviceName,DEVICE_CLEANUP_PATTERN_2,std::wstring(L"-"));
        deviceName = std::regex_replace(deviceName,DEVICE_CLEANUP_PATTERN_3,std::wstring(L" "));

        std::wstring lowerDeviceName = tolowers(deviceName);

        if (!deviceBrand.empty()) {
            std::wstring lowerDeviceBrand = tolowers(deviceBrand);

            // In some cases it does start with the brand but without a separator following the brand
            if (starts_with(lowerDeviceName,lowerDeviceBrand)) {
                deviceName = replaceString(deviceName, L"_", L" ");
                // (?i) means: case insensitive
                //?diffrent for java/c++ deviceName = deviceName.replaceAll("(?i)^" + Pattern.quote(deviceBrand) + "([^ ].*)$", Matcher.quoteReplacement(deviceBrand) + " $1");
                std::wregex regex(L"(?i)^" + deviceBrand + L"([^ ].*)$");
                deviceName = std::regex_replace(deviceName,regex,deviceBrand + std::wstring(L" $1"));
                deviceName = std::regex_replace(deviceName,DEVICE_CLEANUP_PATTERN_4,std::wstring(L" "));
            } else {
                deviceName = deviceBrand + L' ' + deviceName;
            }
        }
        std::string _result = Normalize::brand(wstring_to_string(deviceName));
        std::wstring result = string_to_wstring(_result);

        if (result.find('I') != result.npos) {
            result = replaceString(result, L"Ipad", L"iPad");
            result = replaceString(result, L"Ipod", L"iPod");
            result = replaceString(result, L"Iphone", L"iPhone");
            result = replaceString(result, L"IOS ", L"iOS ");
        }

        std::wstring mozilla = L"Mozilla";
        if(result.length() > mozilla.length() && ends_with(result,mozilla)) {
            size_t newLength = result.length() - mozilla.length();
            if (result[newLength-1] == '-') {
                newLength--;
            }
            while (result[newLength-1] == ' ') {
                newLength--;
            }
            result = result.substr(0, newLength);
        }

        return wstring_to_string(result);
    }

    std::wstring Normalize::replaceString(const std::wstring & input, const std::wstring & searchFor, const std::wstring & replaceWith) {
        //startIdx and idxSearchFor delimit various chunks of input; these
        //chunks always end where searchFor begins
        size_t startIdx = 0;
        size_t idxSearchFor = input.find(searchFor, startIdx);
        if (idxSearchFor == std::wstring::npos) {
            return input;
        }
        std::wstring result;

        while (idxSearchFor != std::wstring::npos) {
            //grab a part of input which does not include searchFor
            result.append(input, startIdx, idxSearchFor);
            //add replaceWith to take place of searchFor
            result.append(replaceWith);

            //reset the startIdx to just after the current match, to see
            //if there are any further matches
            startIdx = idxSearchFor + searchFor.length();
            idxSearchFor = input.find(searchFor, startIdx);
        }
        //the chunk will go to the end of input
        result.append(input.substr(startIdx));
        return result;
    }

    bool Normalize::isLowerCase(const std::string &_text) {
        std::wstring text = string_to_wstring(_text);
        for(wchar_t c:text){
            if(std::isupper(c))
                return false;
        }
        return true;
    }

    std::string Normalize::email(const std::string &email) {
        std::wstring cleaned;
        utf8::utf8to32(email.begin(),email.end(),std::back_inserter(cleaned));
        cleaned = replaceString(cleaned, L"[at]", L"@");
        cleaned = replaceString(cleaned, L"[\\xc3\\xa07]", L"@");
        cleaned = replaceString(cleaned, L"[dot]", L".");
        cleaned = replaceString(cleaned, L"\\", L" ");
        cleaned = replaceString(cleaned, L" at ", L"@");
        cleaned = replaceString(cleaned, L"dot", L".");
        cleaned = replaceString(cleaned, L" dash ", L"-");
        cleaned = replaceString(cleaned, L" ", L"");
        std::string s;
        utf8::utf32to8(cleaned.begin(),cleaned.end(),std::back_inserter(s));
        return s;
    }
}